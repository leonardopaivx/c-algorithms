#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "TMat2D.h"

struct TMat2D
{
    int nrows; // númemro de linhas ;
    int ncolumns; // número de colunas;
    double *data; // dados: local onde armazena os dados da matriz
};

// Função mat2D_create
// Desc - cria uma matriz de i linhas por j colunas que irá conter valores do tipo double.
// Entrada - 
// int nrow: valor inteiro para o número de linhas,
// int ncol: valor inteiro para o número de colunas,
// Retorno - 
// mat: matriz (TMat2D) alocada na heap. 
// Obs: Deverá ser criado um ponteiro para TMat2D e inicializado como NULL para receber 
// o retorno da função mat2D_create.
TMat2D *mat2D_create(int nrow, int ncol){
    TMat2D *mat;
    mat = malloc(sizeof(TMat2D));
    if (mat == NULL){
        return NULL;
    }

    mat->nrows  =  nrow;
    mat->ncolumns = ncol;
    mat->data = malloc(ncol*nrow*sizeof(double));
 
    if (mat->data == NULL){
        free(mat);
        return NULL;
    }
    
    return mat;
}

// Função mat2D_fill
// Desc - preenche um campo da matriz com um número do tipo double a partir dos valores de i e j.
// Entrada - 
// TMat2D *mat: matriz criada pela função mat2D_create(),
// int i: valor inteiro para o número de linhas,
// int j: valor inteiro para o número de colunas,
// double value: valor que irá ser inserido na matriz. 
// Retorno - 
//    0: sucesso
//   -1: erro
int mat2d_fill(TMat2D *mat, int i, int j, double value){
    if(mat == NULL){
        return -1;
    }else if(i > mat->nrows || j > mat->ncolumns || i < 0 || j < 0){
        return -1;
    }else{
        int pos;
        pos = j * mat->nrows + i;
        mat->data[pos] = value;
        return 0;
    }
}

// Função mat2D_access
// Desc - acessa um campo da matriz a partir dos valores de i e j.
// Entrada - 
// TMat2D *mat: matriz criada pela função mat2D_create(),
// int i: valor inteiro para o número de linhas,
// int j: valor inteiro para o número de colunas,
// double *element: endereço de memória de uma variável do tipo double que
// receberá o elemento da matriz requisitado pela função.
// Retorno - 
//    0: sucesso
//   -1: erro
int mat2d_access(TMat2D *mat, int i, int j,double *element){
    if(mat == NULL){
        return -1;
    }else if(i > mat->nrows || j > mat->ncolumns || i < 0 || j < 0){
        return -1;
    }else{
        int pos;
        pos = j * mat->nrows + i;
        *element = mat->data[pos];
        return 0;
    }
}

// Função mat2D_rand_fill
// Desc - preenche todos os campos de uma matriz com valores aleatórios no intervalo de n1 e n2.
// Entrada - 
// TMat2D *mat: matriz criada pela função mat2D_create(),
// int n1: valor inteiro que abre o intervalo numérico,
// int n2: valor inteiro que fecha o intervalo numérico,
// Retorno - 
//    0: sucesso
//   -1: erro
int mat2d_rand_fill(TMat2D *mat, int n1, int n2){
    if(mat == NULL){
        return -1;
    }else{
        srand(time(NULL)); 
        int i;
        int n_elements = mat->nrows * mat->ncolumns;
        for (i = 0; i < n_elements; i++){
            mat->data[i] = (n1) + (rand() % (n2-n1));     
        }
        return 0;
    }    
}

// Função mat2D_addition
// Desc - soma duas matrizes e armazena o resultado em uma terceira matriz.
// Entrada - 
// TMat2D *mat1: matriz criada pela função mat2D_create(),
// TMat2D *mat2: matriz criada pela função mat2D_create(),
// TMat2D *mat_sum: matriz criada pela função mat2D_create() que armazenará o resultado da soma de mat1 e mat2.
// Obs - todas as matrizes deverão ter o mesmo número de linhas e colunas, ou seja: 
// mat1 i,j mat2 i,j mat_sum i,j.
// Retorno - 
//    0: sucesso
//   -1: erro
int mat2d_addition(TMat2D *mat1, TMat2D *mat2, TMat2D *mat_sum){
    if(mat1 == NULL || mat2 == NULL){
        return -1;
    }else if(mat1->ncolumns =! mat2->ncolumns || mat1->nrows != mat2->nrows || mat_sum->nrows != mat1->nrows || mat_sum->ncolumns != mat1->ncolumns){
        return -1;
    }else{
        int n_elements = mat1->nrows * mat2->ncolumns;

        for(int i = 0; i < n_elements; i++){
            mat_sum->data[i] = mat1->data[i] + mat2->data[i];
        }

        return 0;
    }
}

// Função mat2D_mult
// Desc - multiplica duas matrizes e armazena o resultado em uma terceira matriz.
// Entrada - 
// TMat2D *mat1: matriz criada pela função mat2D_create(),
// TMat2D *mat2: matriz criada pela função mat2D_create(),
// TMat2D *mult: matriz criada pela função mat2D_create() que armazenará o resultado da multiplicação de mat1 e mat2.
// Obs - a multiplicação ocorrerá apenas se: o numero de colunas de mat1 for igual ao numero de linhas de mat2,
// o numero de linhas de mult for igual ao número de linhas de mat1 e o numero de colunas de mult for igual ao 
// numero de colunas de mat2, ou seja: 
// (mat1 i,j) m x p * (mat2 i,j) p x n = (mult i,j) m x n
//    0: sucesso
//   -1: erro
int mat2d_mult(TMat2D *mat1, TMat2D *mat2, TMat2D *mult){
    
    if(mat1 == NULL || mat2 == NULL || mult == NULL){
        return -1;
    }else if(mat1->ncolumns != mat2->nrows){
        return -2;
    }else if(mult->nrows != mat1->nrows || mult->ncolumns != mat2->ncolumns){
        return -3;
    }else{

    int row1, row2, col1, col2, i, j, k,pos1,pos2,pos3;
    double temp = 0;
    
    row1 = mat1->nrows;
    col1 = mat1->ncolumns;
    row2 = mat2->nrows;
    col2 = mat2->ncolumns;
 
    for(i = 0; i < row1; i++){
        for(j = 0; j < col2; j++){
            for(k = 0; k < col1; k++){
                pos1 = k * mat1->nrows + i;
                pos2 = j * mat2->nrows + k;
                temp += mat1->data[pos1] * mat2->data[pos2];
            }
            pos3 = j * mult->nrows + i;
            mult->data[pos3] = temp;           
            temp = 0;
        }
    }  
    return 0;
    }
}

// Função mat2d_mult_by_a_constant
// Desc - multiplica uma matriz por uma constante e armazena o resultado em outra matriz.
// Entrada - 
// TMat2D *mat: matriz criada pela função mat2D_create(),
// double c - constante que multiplicará cada elemento da matriz *mat,
// TMat2D *mult: matriz criada pela função mat2D_create() que armazenará o resultado da multiplicação de mat
// pela constante c.
// Obs - a matriz mult deverá ter o mesmo número de linhas e colunas que a matriz mat.
// Retorno - 
//    0: sucesso
//   -1: erro
int mat2d_mult_by_a_constant(TMat2D *mat, double c, TMat2D *mult){
    if(mat == NULL || mult == NULL){
        return -1;
    }else if(mat->nrows != mult->nrows || mat->ncolumns != mult->ncolumns){
        return -1;
    }else{
        int n_elements = mat->nrows * mat->ncolumns;

        for(int i = 0; i < n_elements; i++){
            mult->data[i] = mat->data[i] * c;
        }
        return 0;
    }
}

// Função mat2d_trace
// Desc - calcula o traço de uma matriz e armazena o resultado em uma variável do tipo double.
// Entrada - 
// TMat2D *mat: matriz criada pela função mat2D_create(),
// double *trace - endereço de memória de uma variável do tipo double que irá armazenar o calculo do traço da matriz mat.
// Retorno - 
//    0: sucesso
//   -1: erro
int mat2d_trace(TMat2D *mat, double *trace){
    if(mat == NULL){
        return -1;
    }else if(mat->nrows != mat->ncolumns){
        return -1;
    }else{
        int row,col,pos;
        row = mat->nrows;
        col = mat->ncolumns;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                pos = j * row + i;
                if(j == i){
                    *trace += mat->data[pos];
                }
            }
        }
        return 0;
    }
}

// retorna 0: sucesso
// retorna -1: erro
int mat2d_sum_rows(TMat2D *mat, double *r){
    if(mat == NULL){
        return -1;
    }else{
        int row,col,pos;
        double sum = 0;
        row = mat->nrows;
        col = mat->ncolumns;

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                pos = j * row + i;
                sum += mat->data[pos];
                r[i] = sum;
            }
            sum = 0;
        }
        return 0;
    }
}

// retorna 0: sucesso
// retorna -1: erro
int mat2d_sum_columns(TMat2D *mat, double *r){
    if(mat == NULL){
        return -1;
    }else{
        int row,col,pos;
        double sum = 0;
        row = mat->nrows;
        col = mat->ncolumns;

        for(int i = 0; i < col; i++){
            for(int j = 0; j < row; j++){
                pos = i * row + j;
                sum += mat->data[pos];
                r[i] = sum;
            }
            sum = 0;
        }
        return 0;
    }
}

// retorna Error: erro
void mat2d_print(TMat2D *mat){
    if(mat == NULL)
        printf("Error");
    else{
        int pos;
        for(int i = 0; i < mat->nrows; i++){
            for(int j = 0; j < mat->ncolumns; j++){
                pos = j * mat->nrows + i;
                printf("%.2lf ",mat->data[pos]);
            }
            printf("\n");
        }
    }       
}

// retorna 0: sucesso
// retorna -1: erro
int mat2d_free(TMat2D *mat){
    if (mat == NULL){
        return -1;
    } else{
      free(mat->data);
      free(mat);
      return 0;
    }
}
