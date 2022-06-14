#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TCircLinkedList.h"

int main(){
    Circlist *list;
    struct aluno a,b,c,p;

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
    list_insert_sorted(list,c);
    list_insert_sorted(list,b);
    
    // list_find_mat(list,2,&p);

    // int pos;
    // list_get_pos(list,1,&pos);
    // printf("\n%d\n",pos);



    list_print(list);

    

    return 0;
}