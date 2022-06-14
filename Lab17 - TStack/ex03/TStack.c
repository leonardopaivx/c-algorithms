#include <stdlib.h>
#include "TStack.h"

// é possível criar a lista
struct TStack{
    int size;
    int max;
    char *data;
};

TStack *stack_create(int max){
    TStack *st;
    st = malloc(sizeof(struct TStack));
    if(st == NULL)
        return NULL;

    st->size = 0;
    st->max = max;
    st->data = malloc(max * sizeof(char));    

    return st;
}

int stack_free(TStack *st){
    if(st == NULL)
        return INVALID_NULL_POINTER;
    free(st);
    return SUCCESS;
}

int stack_full(TStack *st){
    if(st == NULL)
        return INVALID_NULL_POINTER;
    if(st->size == st->max)
        return SUCCESS;
    else
        return NOT_FULL;        
}

int stack_empty(TStack *st){
    if(st == NULL)
        return INVALID_NULL_POINTER;
    if(st->size == 0)
        return SUCCESS; 
    else
        return NOT_EMPTY;       
}

int stack_push(TStack *st, char c){
    if(st == NULL)
        return INVALID_NULL_POINTER;
    if(stack_full(st) == 0)
        return OUT_OF_MEMORY;

    st->data[st->size] = c;
    st->size++;   
    return SUCCESS;
}

int stack_pop(TStack *st){
    if(st == NULL)
        return INVALID_NULL_POINTER;
    if(stack_empty(st) == 0)
        return OUT_OF_RANGE;
    st->size--;
    return SUCCESS;  
}

int stack_top(TStack *st, char *c){
    if(st == NULL)
        return INVALID_NULL_POINTER;
    if(stack_empty(st) == 0)
        return OUT_OF_RANGE;
    *c = st->data[(st->size) - 1];
    return SUCCESS;
}