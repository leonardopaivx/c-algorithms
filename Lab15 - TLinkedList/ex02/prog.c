#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TSULinkedList.h"

int main(){
    TLinkedList *list;
    int boolean;

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

    printf("\nA lista e ordenada? 1 para sim / 0 para nao: ");
    scanf("%d",&boolean);

    list = list_create(boolean);
    if (list == NULL){
       printf("ERRO!");
       exit(1);
    } 

    list_insert_sorted(list,b);
    list_insert_sorted(list,c);
    list_insert_sorted(list,a);

    list_print(list);    


    return 0;
}