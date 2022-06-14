#include <stdlib.h>
#include <stdio.h>
#include "TSULinkedList.h"

typedef struct list_node list_node;

struct list_node
{
    struct aluno data;
    list_node *next;
};

struct TLinkedList
{
    list_node *head;
    int size;
    int sorted;
};

TLinkedList *list_create(int sorted)
{
    TLinkedList *list;
    list = malloc(sizeof(TLinkedList));
    if (list != NULL)
    {
        list->head = NULL;
        list->size = 0;
        list->sorted = sorted;
    }
    return list;
}

int list_push_front(TLinkedList *list, struct aluno al)
{
    if (list == NULL)
    {
        return INVALID_NULL_POINTER;
    }else if(list->sorted){
        return ORDERED;
    }
    else
    {
        list_node *node;
        node = malloc(sizeof(list_node));
        if (node == NULL)
        {
            return OUT_OF_MEMORY;
        }
        node->data = al;
        node->next = list->head;
        list->head = node;

        list->size++;    
        return SUCCESS;
    }
}

int list_push_back(TLinkedList *list, struct aluno al)
{
    if (list == NULL)
    {
        return INVALID_NULL_POINTER;
    }else if(list->sorted){
        return ORDERED;
    }
    else
    {
        list_node *node;
        node = malloc(sizeof(list_node));
        if (node == NULL)
            return OUT_OF_MEMORY;
        node->data = al;
        node->next = NULL;
        if (list->head == NULL)
        { // a lista está vazia
            list->head = node;
        }
        else
        { // a lista tem pelo menos um nó
            list_node *aux;
            aux = list->head;
            while (aux->next != NULL)
            {
                aux = aux->next;
            }
            aux->next = node;
        }
        list->size++;  
        return SUCCESS;
    }
}

int list_print(TLinkedList *list)
{
    if (list == NULL)
    {
        return INVALID_NULL_POINTER;
    }
    else
    {
        list_node *aux;
        aux = list->head;
        printf("\nImprimindo a lista (tamanho %d)\n", list_size(list));

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
}

int list_free(TLinkedList *list)
{
    if (list == NULL)
    {
        return INVALID_NULL_POINTER;
    }
    else
    {
        list_node *aux;

        aux = list->head;
        while (aux != NULL)
        {
            list->head = aux->next;
            free(aux);
            aux = list->head;
        }

        // segunda forma
        // while (list->head != NULL)
        // {
        //     aux = list->head;
        //     list->head = list->head->next;
        //     free(aux);
        // }
        free(list);
        return SUCCESS;
    }
}


int list_size(TLinkedList *list){
    if (list == NULL){
        return INVALID_NULL_POINTER;
    } else {
       return list->size;
    }
}

int list_insert(TLinkedList *list, int pos, struct aluno al){
    if(list == NULL)
        return INVALID_NULL_POINTER;
    
    if(pos < 1)
        return OUT_OF_RANGE;
    
    if(list->sorted)
        return ORDERED;

    list_node *node;
    node = malloc(sizeof(list_node));
    if(node == NULL)
        return OUT_OF_MEMORY;
    node->data = al;

    int contador = 1;
    list_node *aux,*prev;
    aux = list->head;
    prev = NULL;

    if(pos == 1){
        if((list->head) == NULL){
            list->head = node;
            node->next = NULL;
        }else{
            node->next = list->head;
            list->head = node;
        }
    
    }else{
        while (aux != NULL)
        {
            prev = aux;
            aux = aux->next;
            contador = contador + 1;

            if(contador == pos){
                prev->next = node;
                node->next = aux;
                break;
            }
        }
    }
    list->size++;  
    return SUCCESS;
}

int list_insert_sorted(TLinkedList *list, struct aluno al){
    if (list == NULL)
        return INVALID_NULL_POINTER;
    if(list->sorted == 0)
        return UNORDERED;    
    list_node *node;
    node = malloc(sizeof(list_node));
    if (node == NULL)
        return OUT_OF_MEMORY;
    node->data = al;

    list_node *aux, *prev;

    prev = NULL;
    aux = list->head;
    while ( (aux != NULL) && (node->data.matricula > aux->data.matricula)){
        prev = aux;
        aux = aux->next;
    }
    if (prev == NULL) { // inserção na cabeça (lista vazia ou matricula de menor de valor da lista)
        node->next = aux;
        list->head = node;
    } else {
       prev->next = node;
       node->next = aux;
    }
    list->size++;  
    return SUCCESS;   
}

int list_pop_front(TLinkedList *list){
    if(list == NULL)
        return INVALID_NULL_POINTER;
    list->head = list->head->next;
    list->size--;  
    return SUCCESS;

}

int list_pop_back(TLinkedList *list){
    if(list == NULL)
        return INVALID_NULL_POINTER;
    list_node *aux,*prev;
    prev = NULL;
    aux = list->head;
    while(aux->next != NULL){
        prev = aux;
        aux = aux->next;
    }
    prev->next = NULL;
    
    free(aux);
    list->size--;  
    return SUCCESS;
}

int list_erase(TLinkedList *list, int pos){
    if(list == NULL)
        return INVALID_NULL_POINTER;
    if(pos == 1){
        list_pop_front(list); 
        return SUCCESS;
    }
    int size = list_size(list);
    if(pos == size){
        list_pop_back(list);
        return SUCCESS;
    }
             
    int cont = 1;
    list_node *aux,*prev;
    prev = NULL;
    aux = list->head;
    while(aux->next != NULL){
        
        if(cont == pos){
            prev->next = aux->next;
            break;
        }
        
        prev = aux;
        aux = aux->next;
        cont++;
    }
    free(aux);
    list->size--;  
    return SUCCESS;


}

int list_find_pos(TLinkedList *list, int pos, struct aluno *al){
    if(list == NULL)
        return INVALID_NULL_POINTER;

    int contador = 1;
    list_node *aux;
    aux = list->head;

    while(aux != NULL){
        
        if(contador == pos){
            *al = aux->data;
            return SUCCESS;
        }
        aux = aux->next;
        contador++;
    }
     return OUT_OF_RANGE;  
}

int list_find_mat(TLinkedList *list, int nmat, struct aluno *al){
    if(list == NULL)
        return INVALID_NULL_POINTER;
    list_node *aux;
    aux = list->head;

    while(aux != NULL){
        if(aux->data.matricula == nmat){
            *al = aux->data;
            return SUCCESS;
        }
        aux = aux->next;
    }
    return OUT_OF_RANGE;    
}

int list_front(TLinkedList *list, struct aluno *al){
    if(list == NULL)
        return INVALID_NULL_POINTER;
    *al = list->head->data;
    return SUCCESS;    
}

int list_back(TLinkedList *list, struct aluno *al){
    if(list == NULL)
        return INVALID_NULL_POINTER;
    list_node *aux;
    aux = list->head; 
    while(aux->next != NULL){
        aux = aux->next;
    }
    *al = aux->data;
    return SUCCESS;   
}

int list_get_pos(TLinkedList *list, int nmat, int *pos){
    if(list == NULL)
        return INVALID_NULL_POINTER;
    int cont = 1;    
    list_node *aux;
    aux = list->head;    

    while(aux != NULL){
        if(aux->data.matricula == nmat){
            *pos = cont;
            return SUCCESS;
        }
        aux = aux->next;
        cont++;
    }
    return OUT_OF_RANGE;
}