#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "TVarSeqList.h" 

struct lista{
    int qtd;
    int elem_max;
    int elem_atual;
    struct aluno *dados;
};

Lista *cria_lista(int elem){
    Lista *li;
    li = (Lista*) malloc(sizeof(struct lista));
    if(li == NULL){
        return NULL;
    }

    li->qtd = 0;
    li->elem_atual = elem;
    li->elem_max = elem + elem;
    li->dados = malloc(elem*sizeof(struct aluno));

    return li;
}

// retorna 0: sucesso
// retorna -1: erro
int insere_lista_final(Lista *li, struct aluno al){
    if(li == NULL){
        return -1;
    }if(li->qtd == li->elem_atual){
        li->dados = realloc(li->dados,(li->elem_max)*sizeof(struct aluno));
        if(!li){
            return -1;
        }
        li->elem_max += li->elem_atual;
        // code
        li->dados[li->qtd] = al;
        li->qtd++;
        return 0;
    }

    li->dados[li->qtd] = al;
    li->qtd++;
    return 0;
}

// retorna 0: sucesso
// retorna -1: erro
int insere_lista_inicio(Lista *li, struct aluno al){
    if(li == NULL){
        return -1;
    }if(li->qtd == li->elem_atual){
         li->dados = realloc(li->dados,(li->elem_max)*sizeof(struct aluno));
        if(!li){
            return -1;
        }
        li->elem_max += li->elem_atual;
        //code
        for(int i = li->qtd-1; i>=0; i--){
        li->dados[i+1] = li->dados[i];
        }

        li->dados[0] = al;
        li->qtd++;
        return 0;
    }

    for(int i = li->qtd-1; i>=0; i--){
        li->dados[i+1] = li->dados[i];
    }

    li->dados[0] = al;
    li->qtd++;
    return 0;
}

// retorna 0: sucesso
// retorna -1: erro
int insere_lista_ordenada(Lista* li, struct aluno al){
    if(li == NULL)
        return -1;
    if(li->qtd == li->elem_atual){
        li->dados = realloc(li->dados,(li->elem_max)*sizeof(struct aluno));
        if(!li){
            return -1;
        }
        li->elem_max += li->elem_atual;
        //code
        int k,i = 0;
        while(i<li->qtd && li->dados[i].matricula < al.matricula)
            i++;
        for(k=li->qtd-1; k >= i; k--)
            li->dados[k+1] = li->dados[k];
        li->dados[i] = al;
        li->qtd++;
        return 0;
    }

    int k,i = 0;
    while(i<li->qtd && li->dados[i].matricula < al.matricula)
        i++;
    for(k=li->qtd-1; k >= i; k--)
        li->dados[k+1] = li->dados[k];
    li->dados[i] = al;
    li->qtd++;
    return 0;
}

// retorna 0: sucesso
// retorna -1: erro
int remove_lista_inicio(Lista *li){
    if(li == NULL)
        return -1;
    if(li->qtd == 0)
        return -1;    
    for(int k = 0; k < li->qtd-1; k++){
        li->dados[k] = li->dados[k+1];
    }
    li->qtd--;
    return 0;
}

// retorna 0: sucesso
// retorna -1: erro
int remove_lista_final(Lista *li){
    if(li == NULL)
        return -1;
    if(li->qtd == 0)
        return -1;    
    li->qtd--;
    return 0;
}

// retorna 0: sucesso
// retorna -1: erro
int remove_lista(Lista* li, int mat){
    if(li == NULL)
        return -1;
    if(li->qtd == 0)
        return -1;
    int k,i = 0;
    while(i<li->qtd && li->dados[i].matricula != mat)
        i++;
    if(i == li->qtd)//elemento nao encontrado
        return 0;
    for(k=i; k< li->qtd-1; k++)
        li->dados[k] = li->dados[k+1];
    li->qtd--;
    return 0;
}

// retorna 0: sucesso
// retorna -1: erro
int remove_lista_otimizado(Lista* li, int mat){
    if(li == NULL)      
        return -1;
    if(li->qtd == 0)
        return -1;
    int i = 0;
    while(i<li->qtd && li->dados[i].matricula != mat)
        i++;
    if(i == li->qtd)//elemento nao encontrado
        return 0;
    li->qtd--;
    li->dados[i] = li->dados[li->qtd];
    return 0;
}

// retorna 0: sucesso
// retorna -1: erro
int consulta_lista_pos(Lista *li, int pos, struct aluno *al){
    if(li == NULL || pos <= 0 || pos > li->qtd)
        return -1;
    *al = li->dados[pos-1];
    return 0;
}

// retorna 0: sucesso
// retorna -1: erro
int consulta_lista_mat(Lista *li, int mat, struct aluno *al){
    if(li == NULL)
        return -1;
    int i = 0;
    while(i < li->qtd && li->dados[i].matricula != mat){
        i++;
        if(i == li->qtd){
            return -1;
        }    
    }

    *al = li->dados[i];
    return 0;    

}

// retorna 0: sucesso
// retorna -1: erro
int tamanho_lista(Lista *li){
    if(li == NULL)
        return -1;
    else
        return li->qtd;
}

// retorna 0: sucesso
// retorna -1: erro
int lista_cheia(Lista* li){
    if(li == NULL)
        return -1;
    return (li->qtd == li->elem_atual);
}

// retorna 0: sucesso
// retorna -1: erro
int lista_vazia(Lista* li){
    if(li == NULL)
        return -1;
    return (li->qtd == 0);
}

void imprime_lista(Lista* li){
    if(li == NULL)
        printf("Erro");
    
    for(int i=0; i< li->qtd; i++){
        printf("Matricula: %d\n",li->dados[i].matricula);
        printf("Nome: %s\n",li->dados[i].nome);
        printf("Notas: %f %f %f\n",li->dados[i].n1,
        li->dados[i].n2,
        li->dados[i].n3);
        printf("-------------------------------\n");
    }
}

// retorna 0: sucesso
// retorna -1: erro
int compactar_lista(Lista *li){
    if(li == NULL)
        return -1;
    double qtd = li->qtd, elem_atual = li->elem_atual;       
    int n_elem = ceil(qtd/elem_atual)*elem_atual;
    li->dados = realloc(li->dados,n_elem*sizeof(struct aluno));
    li->elem_max = n_elem *2;
    return 0;
}

void libera_lista(Lista *li){
    free(li);
}
