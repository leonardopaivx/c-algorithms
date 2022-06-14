#include <stdio.h>
#include <stdlib.h>
#include "TMat2D.h"

int main(){

    // Criando Matrizes 2,2.
    TMat2D *mat1 = NULL, *mat2 = NULL;
    mat1 = mat2D_create(2,2);
    mat2 = mat2D_create(2,2);

    // Preenchendo as matrizes com valores aleatorios.
    mat2d_rand_fill(mat1,1,5);
    mat2d_rand_fill(mat2,5,10);
    
    // Imprimindo as matrizes.
    printf("\nImprimindo as matrizes mat1 e mat2:\n\n");
    mat2d_print(mat1);
    printf("\n");
    mat2d_print(mat2);

    // Preenchendo o primeiro elemento da mat1 com o valor 15.0.
    mat2d_fill(mat1,0,0,15.0);

    // Acessando o primeiro elemento da mat1.
    double e1;
    mat2d_access(mat1,0,0,&e1);
    printf("\nElemento 1 da mat1 apos a mudanca eh: %.1lf\n",e1);

    // Imprimindo as matrizes.
    printf("\nImprimindo as matrizes mat1 e mat2:\n\n");
    mat2d_print(mat1);
    printf("\n");
    mat2d_print(mat2);

    // Somando as matrizes.
    TMat2D *soma = NULL;
    soma = mat2D_create(2,2);
    mat2d_addition(mat1,mat2,soma);
    printf("\nSoma da mat1 e mat2:\n\n");
    mat2d_print(soma);

    // Multiplicando as matrizes.
    TMat2D *p = NULL, *mat3 = NULL, *mat4 = NULL;
    p = mat2D_create(2,2);
    mat3 = mat2D_create(2,3);
    mat4 = mat2D_create(3,2);
    mat2d_rand_fill(mat3,2,8);
    mat2d_rand_fill(mat4,4,10);
    mat2d_mult(mat3,mat4,p);

    printf("\nImprimindo as matrizes mat3 e mat4:\n\n");
    mat2d_print(mat3);
    printf("\n");
    mat2d_print(mat4);

    printf("\nProduto da mat3 e mat4:\n\n");
    mat2d_print(p);

    // Multiplicando mat3 por 5;
    printf("\n==== Multiplicando mat3 por 5 ====\n");
    TMat2D *p2;
    p2 = mat2D_create(2,3);
    printf("\nMat3:\n");
    mat2d_print(mat3);

    mat2d_mult_by_a_constant(mat3,5,p2);
    printf("\nRes:\n");
    mat2d_print(p2);

    // Calculando o traço da mat2.
    printf("\n==== Calculando traco da mat2 ====\n");
    double t;
    printf("\nMat2:\n");
    mat2d_print(mat2);

    mat2d_trace(mat2,&t);
    printf("\nO traco da mat2 eh: %.2lf\n",t);

    // Somando as linhas da mat3.
    printf("\n==== Somando as linhas da Mat3 ====\n");
    double s_linhas[2];
    printf("\nMat3:\n");
    mat2d_print(mat3);

    mat2d_sum_rows(mat3,s_linhas);
    printf("\n");
    for(int i = 0; i < 2; i++){
        printf("Soma da linha %d: %.2lf\n",i+1,s_linhas[i]);
    }

    // Somando as colunas da mat3
    printf("\n==== Somando as colunas da Mat3 ====\n");
    double s_cols[3];
    printf("\nMat3:\n");
    mat2d_print(mat3);

    mat2d_sum_columns(mat3,s_cols);
    printf("\n");
    for(int i = 0; i < 3; i++){
        printf("Soma da coluna %d: %.2lf\n",i+1,s_cols[i]);
    }


    mat2d_free(mat1);
    mat2d_free(mat2);
    mat2d_free(mat3);
    mat2d_free(mat4);
    mat2d_free(soma);
    mat2d_free(p);
    mat2d_free(p2);
    return 0;
}
