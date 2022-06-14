#include <stdlib.h>
#include "TQueue.h"
#include "TSeqList.h"

struct TQueue{
    TSeqList *list;
};

TQueue *queue_create(){
    TQueue *q;
    q = malloc(sizeof(TQueue));
    if (q != NULL){
        q->list = list_create();
        if (q->list == NULL){
            free(q);
            return NULL;
        }
    }
    return q;
}

int queue_free(TQueue *q)
{
    if(q == NULL)
        return INVALID_NULL_POINTER;
    libera_lista(q->list);
    free(q);
    return SUCCESS;
}

int queue_push(TQueue *q, struct aluno al)
{
    if (q == NULL)
        return INVALID_NULL_POINTER;
    
    return list_push_back(q->list, al);

}

int stack_pop(TQueue *q)
{
    if (q == NULL)
        return INVALID_NULL_POINTER;

    return remove_lista_inicio(q->list);
}

int queue_top(TQueue *q, struct aluno *al)
{
    if (q == NULL)
        return INVALID_NULL_POINTER;
    int qtd = tamanho_lista(q->list);    
    if(qtd == 0)
        return OUT_OF_RANGE; 
    return consulta_lista_pos(st->list,1,*al);      
}

int queue_empty(TQueue *q)
{
    if (q == NULL)
        return INVALID_NULL_POINTER;
    return lista_vazia(q->list);    
}

int queue_full(TQueue *q)
{
    if (q == NULL)
        return INVALID_NULL_POINTER;
    return lista_cheia(q->list);     

}