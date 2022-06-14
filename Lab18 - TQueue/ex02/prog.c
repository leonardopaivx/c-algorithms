#include <stdio.h>
#include <string.h>
#include "TQueue.h"

int main()
{   

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

    TQueue *queue;
    queue = queue_create();

    queue_push(queue,a);
    queue_push(queue,b);
    queue_push(queue,c);

    queue_pop(queue);

    queue_top(queue,&p);

    printf("\nNome: %s\n",p.nome);

    return 0;
}