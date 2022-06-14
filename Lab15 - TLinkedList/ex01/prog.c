#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TLinkedList.h"

int main(){
    TLinkedList *list;
    struct aluno a,b,c;

    strcpy(a.nome,"Leonardo");
    a.matricula = 1;
    a.n1 = 9;    a.n2 = 8;    a.n3 = 10;

    strcpy(b.nome,"Rafael");
    b.matricula = 2;
    b.n1 = 2;    b.n2 = 10;    b.n3 = 7;

    strcpy(c.nome,"Gabriel");
    c.matricula = 3;
    c.n1 = 5.6;    c.n2 = 0;    c.n3 = 10;        

    list = list_create();
    if (list == NULL){
       printf("ERRO!");
       exit(1);
    } 

    list_insert_sorted(list,a);
    list_insert_sorted(list,b);
    list_insert_sorted(list,c);

    // list_erase(list,3);

    struct aluno procurado;
    int pos;

    list_find_mat(list,3,&procurado);

    // list_back(list,&procurado);
    list_get_pos(list,3,&pos);

    list_print(list);
    printf("\nO nome do aluno procurado e: %s\n",procurado.nome);
    printf("\nA pos do aluno procurado e: %d\n",pos);


    return 0;
}