#include <stdlib.h>
#include <math.h>
#include "TQueue.h"

struct TQueue
{
    int size;
    int elem_max;
    int elem_atual;
    struct aluno *dados;
};

TQueue *queue_create(int size){
    TQueue *queue;
    queue = malloc(sizeof(TQueue));

    if(queue == NULL){
        return NULL;
    }
    queue->size = 0;
    queue->elem_max = size + size;
    queue->elem_atual = size;
    queue->dados = malloc(size*sizeof(struct aluno));
}

int queue_empty(TQueue *queue){
    if(queue == NULL)
        return INVALID_NULL_POINTER;
    if(queue->size == 0)
        return 1;
    else
        return 0;        
}

int queue_push(TQueue *queue, struct aluno al){
    if(queue == NULL)
        return INVALID_NULL_POINTER;
    if(queue->size == queue->elem_atual){
        queue->dados = realloc(queue->dados,(queue->elem_max)*sizeof(struct aluno));
        if(!queue){
            return -1;
        }
        queue->elem_max += queue->elem_atual;
    }    
    queue->dados[queue->qtd] = al;
    queue->qtd++;

    return SUCCESS;
}

int queue_pop(TQueue *queue){
    if(queue == NULL)
        return INVALID_NULL_POINTER;
    if(queue->qtd == 0)
        return OUT_OF_RANGE;    
    for(int k = 0; k < queue->qtd-1; k++){
        queue->dados[k] = queue->dados[k+1];
    }
    queue->qtd--;
    return SUCCESS;    
}

int queue_top(TQueue *queue, struct aluno *al){
    if(queue == NULL)
        return INVALID_NULL_POINTER;
    if(queue_empty(queue))
        return OUT_OF_RANGE;
    *al = queue->dados[0];
    return SUCCESS;    
}

int compactar_fila(TQueue *queue){
    if(queue == NULL)
        return INVALID_NULL_POINTER;
    double qtd = queue->qtd, elem_atual = queue->elem_atual;       
    int n_elem = ceil(qtd/elem_atual)*elem_atual;
    queue->dados = realloc(queue->dados,n_elem*sizeof(struct aluno));
    queue->elem_max = queue *2;
    return SUCCESS;
}

int queue_full(TQueue *queue){
    if(queue == NULL)
        return INVALID_NULL_POINTER;
    return (queue->qtd == queue->elem_atual);
}