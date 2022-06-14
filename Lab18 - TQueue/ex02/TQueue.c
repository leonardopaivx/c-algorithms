#include <stdlib.h>
#include "TQueue.h"

typedef struct queue_node Queue_node;

struct queue_node
{
    struct aluno data;
    Queue_node *next;
};

struct TQueue
{
    Queue_node *end;
};

TQueue *queue_create(){
    TQueue *queue;
    queue = malloc(sizeof(TQueue));

    if(queue != NULL){
        queue->end = NULL;
    }
    return queue;
}

int queue_empty(TQueue *queue){
    if(queue == NULL)
        return INVALID_NULL_POINTER;
    if(queue->end == NULL)
        return 1;
    else
        return 0;        
}

int queue_push(TQueue *queue, struct aluno al){
    if(queue == NULL)
        return INVALID_NULL_POINTER;
    Queue_node *node;
    node = malloc(sizeof(Queue_node));
    node->data = al;    
    if(queue_empty(queue)){
        queue->end = node;
        node->next = queue->end;
        return SUCCESS;
    }
    node->next = queue->end->next;
    queue->end->next = node;
    queue->end = node;
    return SUCCESS;
}

int queue_pop(TQueue *queue){
    if(queue == NULL)
        return INVALID_NULL_POINTER;
    if(queue_empty(queue))
        return OUT_OF_RANGE;
    Queue_node *aux;    
    if(queue->end == queue->end->next){
        // se tiver um elemento
        aux = queue->end;
        queue->end = NULL;
        free(aux);
        return SUCCESS;
    }    
    aux = queue->end->next;
    queue->end->next = aux->next;
    free(aux);
    return SUCCESS;    
}

int queue_top(TQueue *queue, struct aluno *al){
    if(queue == NULL)
        return INVALID_NULL_POINTER;
    if(queue_empty(queue))
        return OUT_OF_RANGE;
    *al = queue->end->next->data;
    return SUCCESS;    
}

