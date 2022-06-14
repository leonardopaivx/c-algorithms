#include <stdlib.h>
#include <stdio.h>
#include "TCircLinkedList.h"

typedef struct clistnode Clist_node;

struct circlist{
    Clist_node *end;
};

struct clistnode
{
    struct aluno data;
    Clist_node *next;
};


Circlist *list_create(){
    Circlist *list;
    list = malloc(sizeof(Circlist));

    if (list != NULL){
        list->end = NULL;
    }

    return list;
}

int list_push_front(Circlist *list, struct aluno al){
    if (list == NULL)
        return INVALID_NULL_POINTER;

    Clist_node *node;

    if(list->end == NULL){

        node = malloc(sizeof(Clist_node));
        if (node == NULL)
        return OUT_OF_MEMORY;
        
        node->data = al;
        list->end = node;
        node->next = list->end;
        return SUCCESS;  
    }else{
        node = malloc(sizeof(Clist_node));
        if (node == NULL)
        return OUT_OF_MEMORY;
        
        node->data = al;
        node->next = list->end->next;
        list->end->next = node;
        return SUCCESS;
    }  
}

int list_push_back(Circlist *list, struct aluno al)
{
    if(list == NULL)
        return INVALID_NULL_POINTER;
    Clist_node *node;
    node = malloc(sizeof(Clist_node));
    if (node == NULL)
        return OUT_OF_MEMORY;
    node->data = al;
        
    if(list->end == NULL){
        list->end = node;
        node->next = list->end;
        return SUCCESS;
    }else{
        node->next = list->end->next;
        list->end->next = node;
        list->end = node;
        return SUCCESS;
    }
    return SUCCESS;   
}

int list_size(Circlist *list){
    if(list == NULL)
        return INVALID_NULL_POINTER;
    if(list->end == NULL)
        return 0;
    int cont = 1;    
    Clist_node *aux;   
    aux = list->end->next; 
    while(aux != list->end){
        aux = aux->next;
        cont++;
    }
    return cont;
}


int list_print(Circlist *list){
    if(list == NULL)
        return INVALID_NULL_POINTER;
    int size = list_size(list);
    Clist_node *aux;
    aux = list->end->next;
    printf("\nImprimindo a lista (tamanho %d)\n", list_size(list));
    
    for(int i = 0; i < size; i++){
        printf("\n------------------\n");
        printf("Matricula: %d\n", aux->data.matricula);
        printf("Nome: %s\n", aux->data.nome);
        printf("Notas: %f; %f; %f;\n", aux->data.n1, aux->data.n2, aux->data.n3);
        aux = aux->next;
    }
    printf("\nFim da lista \n");
    return SUCCESS;    
}

int list_free(Circlist *list){
    if(list == NULL)
        return INVALID_NULL_POINTER;
    Clist_node *aux;
    aux = list->end->next;
    while(aux != list->end){
        free(aux);
        aux = aux->next;
    }
    free(aux);
    free(list);
    return SUCCESS;
}

int list_insert(Circlist *list, int pos, struct aluno al){
    if(list == NULL)
        return INVALID_NULL_POINTER;
    if(pos < 1)
        return OUT_OF_RANGE;
    int size = list_size(list);    
    if(pos == 1)
        return list_push_front(list,al);
    if(pos-1 == size)
        return list_push_back(list,al);
            
    Clist_node *node, *aux;
    node = malloc(sizeof(Clist_node)); 
    if(node == NULL)
        return OUT_OF_MEMORY;
    
    node->data = al;
    aux = list->end->next;

    for(int i = 1; i<pos-1; i++){
        aux = aux->next;
    }

    node->next = aux->next;
    aux->next = node;
    return SUCCESS;
}

int list_pop_front(Circlist *list){
    if(list == NULL)
        return INVALID_NULL_POINTER;
    int size = list_size(list); 
    if(size == 0)
        return ELEM_NOT_FOUND;
    Clist_node *aux;    
    if(size == 1){
        aux = list->end;
        list->end = NULL;
        free(aux);
        return SUCCESS;
    }
    aux = list->end->next;
    list->end->next = aux->next;
    free(aux);
    return SUCCESS;
}

int list_pop_back(Circlist *list){
    if(list == NULL)
        return INVALID_NULL_POINTER;
    int size = list_size(list); 
    if(size == 0)
        return ELEM_NOT_FOUND;
    Clist_node *aux,*aux2;    
    if(size == 1){
        aux = list->end;
        list->end = NULL;
        free(aux);
        return SUCCESS;
    }
    aux = list->end;
    aux2 = list->end->next;
    for(int i = 2; i < size; i++){
        aux2 = aux2->next;
    }
    aux2->next = list->end->next;
    list->end = aux2;
    free(aux);
    return SUCCESS;   
}

int list_erase(Circlist *list, int pos){
    if(list == NULL)
        return INVALID_NULL_POINTER;
    int size = list_size(list); 
    if(size == 0)
        return ELEM_NOT_FOUND;
    if(size == 1 || pos == 1)
        return list_pop_front(list);
    if(pos == size)
        return list_pop_back(list);

    Clist_node *aux,*prev;
    aux = list->end->next;
    prev = list->end->next;

    for(int i = 1; i < pos; i++){
        aux = aux->next;
    } 

    for(int i = 1; i < pos-1; i++){
        prev = prev->next;
    }       

    prev->next = aux->next;
    free(aux);
    return SUCCESS;

}

int list_find_pos(Circlist *list, int pos, struct aluno *al){
    if(list == NULL)
        return INVALID_NULL_POINTER;
    int size = list_size(list); 
    if(size == 0)
        return ELEM_NOT_FOUND;
    if(pos > size)
        return ELEM_NOT_FOUND;    
    Clist_node *aux;
    aux = list->end->next;

    for(int i = 1; i < pos; i++){
        aux = aux->next;
    }

    *al = aux->data;   
    return SUCCESS; 
}

int list_find_mat(Circlist *list, int nmat, struct aluno *al){
    if(list == NULL)
        return INVALID_NULL_POINTER;
    int size = list_size(list); 
    if(size == 0)
        return ELEM_NOT_FOUND;

    Clist_node *aux;
    aux = list->end->next;    

    for(int i = 0; i < size; i++){
        if(aux->data.matricula == nmat){
            *al = aux->data;
            return SUCCESS;
        }
        aux = aux->next;
    }
    return ELEM_NOT_FOUND;
}

int list_front(Circlist *list, struct aluno *al){
    if(list == NULL)
        return INVALID_NULL_POINTER;
    int size = list_size(list); 
    if(size == 0)
        return ELEM_NOT_FOUND;
    *al = list->end->next->data;
    return SUCCESS;    
}

int list_back(Circlist *list, struct aluno *al){
    if(list == NULL)
        return INVALID_NULL_POINTER;
    int size = list_size(list); 
    if(size == 0)
        return ELEM_NOT_FOUND;
    *al = list->end->data;
    return SUCCESS;    
}

int list_get_pos(Circlist *list, int nmat, int *pos){
    if(list == NULL)
        return INVALID_NULL_POINTER;
    int size = list_size(list); 
    if(size == 0)
        return ELEM_NOT_FOUND;
    Clist_node *aux;
    aux = list->end->next;
    for(int i = 0; i < size; i++){
        if(aux->data.matricula == nmat){
            *pos = i+1;
            return SUCCESS;
        }
        aux = aux->next;
    }
    return ELEM_NOT_FOUND;    
}

int list_insert_sorted(Circlist *list, struct aluno al){
    if(list == NULL)
        return INVALID_NULL_POINTER;
    int size = list_size(list);    
    Clist_node *node;
    node = malloc(sizeof(Clist_node));
    if (node == NULL)
        return OUT_OF_MEMORY;
    node->data = al;
    if(size == 0){   
        list->end = node;
        node->next = list->end;
    }
    Clist_node *aux,*prev;
    aux = list->end->next;
    prev = list->end->next;
    int i = 1;

    for(int cont = 1; cont < size-1; cont++){
        prev = prev->next;
    }  

    while(i<size && (node->data.matricula > aux->data.matricula)){
        aux = aux->next;
        i++;
    }

    if((list->end->next->data.matricula) > (node->data.matricula)){
        node->next = list->end->next;
        list->end->next = node;
    }else if((list->end->data.matricula) < (node->data.matricula)){
        node->next = list->end->next;
        list->end->next = node;
        list->end = node;
    }else{
        prev->next = node;
        node->next = aux;
    }
    return SUCCESS;

}