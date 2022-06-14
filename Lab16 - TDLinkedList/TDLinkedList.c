#include <stdlib.h>
#include <stdio.h>
#include "TDLinkedList.h"

typedef struct DLNode DLNode;

struct DLNode
{
    struct aluno data;
    DLNode *prev;
    DLNode *next;
};

// estrutura do descritor da lista
struct TDLinkedList
{
    DLNode *begin;
    DLNode *end;
    int size;
};

TDLinkedList *list_create()
{
    TDLinkedList *list;
    list = malloc(sizeof(TDLinkedList));
    if (list != NULL)
    {
        list->begin = NULL;
        list->end = NULL;
        list->size = 0;
    }
    return list;
}

int list_push_front(TDLinkedList *list, struct aluno al)
{
    if (list == NULL)
        return INVALID_NULL_POINTER;

    DLNode *node;
    node = malloc(sizeof(DLNode));
    if (node == NULL)
        return OUT_OF_MEMORY;

    node->data = al;
    node->prev = NULL;
    node->next = list->begin;

    if (list->begin == NULL)
    { // a lista está vazia
        list->begin = node;
        list->end = node;
        list->size = 1;
    }
    else
    { // a lista possui um nó
        list->begin->prev = node;
        list->begin = node;
        list->size++;
    }
    return SUCCESS;
}

int list_push_back(TDLinkedList *list, struct aluno al){
    if (list == NULL)
        return INVALID_NULL_POINTER;
    DLNode *node;
    node = malloc(sizeof(DLNode));
    if (node == NULL)
        return OUT_OF_MEMORY;

    node->data = al;  
    node->prev = list->end;
    node->next = NULL;

    if(list->begin == NULL){
        list->begin = node;
        list->end = node;
        list->size = 1;
    }else{
        list->end->next = node;
        list->end = node;
        list->size++;
    }
    return SUCCESS;  

}

int list_print_forward(TDLinkedList *list)
{
    if (list == NULL)
        return INVALID_NULL_POINTER;
    DLNode *aux;
    aux = list->begin;
    printf("\nImprimindo a lista\n");

    while (aux != NULL)
    {
        printf("\n------------------\n");
        printf("Matricula: %d\n", aux->data.matricula);
        printf("Nome: %s\n", aux->data.nome);
        printf("Notas: %f; %f; %f;\n", aux->data.n1, aux->data.n2, aux->data.n3);

        aux = aux->next;
    }
    printf("\nFim da lista \n");
}

int list_print_reverse(TDLinkedList *list)
{
    if (list == NULL)
        return INVALID_NULL_POINTER;
    DLNode *aux;
    aux = list->end;
    printf("\nImprimindo a lista - reverso\n");

    while (aux != NULL)
    {
        printf("\n------------------\n");
        printf("Matricula: %d\n", aux->data.matricula);
        printf("Nome: %s\n", aux->data.nome);
        printf("Notas: %f; %f; %f;\n", aux->data.n1, aux->data.n2, aux->data.n3);

        aux = aux->prev;
    }
    printf("\nFim da lista \n");
}

int list_insert(TDLinkedList *list, int pos, struct aluno al)
{
    if (list == NULL)
        return INVALID_NULL_POINTER;
    // teste se a posição de inserção é válida
    if ((pos < 1) || (pos > list->size + 1))
        return OUT_OF_RANGE;

    DLNode *node;
    node = malloc(sizeof(DLNode));
    if (node == NULL)
        return OUT_OF_MEMORY;
    node->data = al;

    
    if (list->size == 0)
    { // a lista está vazia
        node->next = NULL;
        node->prev = NULL;
        list->begin = node;
        list->end = node;
        list->size = 1;
    }
    else if (pos == 1)
    { //insere no início da lista
        node->prev = NULL;
        node->next = list->begin;
        list->begin->prev = node;
        list->begin = node;
        list->size = list->size + 1;
    }
    else if (pos == list->size + 1)
    { // inserção no fim da lista
        node->next = NULL;
        node->prev = list->end;
        list->end->next = node;
        list->end = node;
        list->size++;
    }
    else
    {
        int cont;
        DLNode *aux;

        cont = 1;
        aux = list->begin;
        while (cont < pos - 1)
        {
            aux = aux->next;
            cont = cont + 1;
        }
        node->prev = aux;
        node->next = aux->next;
        aux->next->prev = node;
        aux->next = node;
        list->size++;
    }
    return SUCCESS;
}

int list_size(TDLinkedList *list){
    if (list == NULL)
        return INVALID_NULL_POINTER;
    return list->size;    
}

int list_pop_front(TDLinkedList *list){
    if (list == NULL)
        return INVALID_NULL_POINTER;
    if(list->begin == NULL)
        return ELEM_NOT_FOUND;     
    DLNode *aux;
    aux = list->begin;
    list->begin->next->prev = NULL;
    list->begin = list->begin->next;
    free(aux);   
    list->size--; 
    return SUCCESS;
}

int list_pop_back(TDLinkedList *list){
    if (list == NULL)
        return INVALID_NULL_POINTER;
    if(list->begin == NULL)
        return ELEM_NOT_FOUND; 
    DLNode *aux;
    aux = list->end;    
    aux->prev->next = NULL;
    list->end = aux->prev;
    free(aux);
    list->size--;
    return SUCCESS;
}

int list_erase(TDLinkedList *list, int pos){
    if (list == NULL)
        return INVALID_NULL_POINTER;
    if(list->begin == NULL)
        return ELEM_NOT_FOUND; 
    if(pos < 1 || pos > list->size)
        return OUT_OF_RANGE;
    if(pos == 1){
        list_pop_front(list);
        return SUCCESS;
    }
    if(pos == list->size){
        list_pop_back(list);
        return SUCCESS;
    }  
    int cont = 1;
    DLNode *aux;
    aux = list->begin;
    while(aux->next != NULL){

        if(cont == pos){
            aux->prev->next = aux->next;
            aux->next->prev = aux->prev;
            free(aux);
            list->size--;
            break;
        }

        aux = aux->next;
        cont++;
    } 
    return SUCCESS;     
}

int list_find_pos(TDLinkedList *list, int pos, struct aluno *al){
    if (list == NULL)
        return INVALID_NULL_POINTER;
    if(list->begin == NULL)
        return ELEM_NOT_FOUND; 
    int cont = 1;
    DLNode *aux;
    aux = list->begin;
    while(aux != NULL){
        if(cont == pos){
            *al = aux->data;
            return SUCCESS;
        }
        aux = aux->next;
        cont++;
    } 
    return ELEM_NOT_FOUND;   
}

int list_find_mat(TDLinkedList *list, int nmat, struct aluno *al){
    if (list == NULL)
        return INVALID_NULL_POINTER;
    if(list->begin == NULL)
        return ELEM_NOT_FOUND; 
    DLNode *aux;
    aux = list->begin;
    while(aux != NULL){
        if(aux->data.matricula == nmat){
            *al = aux->data;
            return SUCCESS;
        }
        aux = aux->next;
    }
    return ELEM_NOT_FOUND;
}

int list_front(TDLinkedList *list, struct aluno *al){
    if (list == NULL)
        return INVALID_NULL_POINTER;
    if(list->begin == NULL)
        return ELEM_NOT_FOUND; 
    *al = list->begin->data;
    return SUCCESS;    
}

int list_back(TDLinkedList *list, struct aluno *al){
    if (list == NULL)
        return INVALID_NULL_POINTER;
    if(list->begin == NULL)
        return ELEM_NOT_FOUND;
    *al = list->end->data;
    return SUCCESS;    
}

int list_get_pos(TDLinkedList *list, int nmat, int *pos){
    if (list == NULL)
        return INVALID_NULL_POINTER;
    if(list->begin == NULL)
        return ELEM_NOT_FOUND;
    int cont = 1;    
    DLNode *aux;
    aux = list->begin;
    while(aux != NULL){
        if(aux->data.matricula == nmat){
            *pos = cont;
            return SUCCESS;
        }
        aux = aux->next;
        cont++;
    }
    return ELEM_NOT_FOUND;    
}