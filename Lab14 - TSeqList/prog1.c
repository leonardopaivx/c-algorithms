#include <stdio.h>
#include <stdlib.h>
#include "TSeqList.h" 

int main(){
    struct aluno a[4] = {{2,"Andre",9.5,7.8,8.5},
    {4,"Ricardo",7.5,8.7,6.8},
    {1,"Bianca",9.7,6.7,8.4},
    {3,"Ana",5.7,6.1,7.4}};

    struct aluno b[4] = {{1,"Gabriel",9.5,7.8,8.5},
    {4,"Daniel",7.5,8.7,6.8},
    {2,"Marcelo",9.7,6.7,8.4},
    {3,"Carlos",5.7,6.1,7.4}};

    struct aluno suspenso;

    struct aluno lista_de_espera = {2,"Alex",5.7,6.1,9.4};
    
    Lista* li = cria_lista();
    
    // Inserindo os alunos da turma A.
    for(int i=0; i < 4; i++)
        insere_lista_ordenada(li,a[i]);
    imprime_lista(li);
    printf("\n\n\n");

    // Inserindo o Gabriel da turma B no final da lista.    
    insere_lista_final(li,b[0]);
    imprime_lista(li);
    printf("\n\n\n");

    // Removendo o Gabriel.
    remove_lista_final(li);
    imprime_lista(li);
    printf("\n\n\n");

    // Inserindo o Carlos da turma B no inicio da lista.
    insere_lista_inicio(li,b[3]);
    imprime_lista(li);
    printf("\n\n\n");

    // Removendo o Carlos.
    remove_lista_inicio(li);
    imprime_lista(li);
    printf("\n\n\n");

    // Recebendo o aluno suspenso pela posiçao na lista.
    consulta_lista_pos(li,2,&suspenso);
    printf("O aluno suspenso e: %s\n\n\n",suspenso.nome);

    // Recebendo o aluno suspenso pelo numero de matricula.
    consulta_lista_mat(li,2,&suspenso);
    printf("O aluno suspenso e: %s\n\n\n",suspenso.nome);

    // Removendo o aluno suspenso da lista.
    remove_lista(li,2);
    imprime_lista(li);
    printf("\n\n\n");

    // Inserindo um novo aluno na lista no lugar do aluno suspenso.
    insere_lista_ordenada(li,lista_de_espera);
    imprime_lista(li);
    printf("\n\n\n");

    // Quantidade de alunos.
    int qnt;
    qnt = tamanho_lista(li);
    printf("A turma esta com %d aluno(s)\n\n\n",qnt);

    // Turma cheia
    int full;
    full = lista_cheia(li);
    if(full)
        printf("A turma esta lotada\n\n\n");
    else
        printf("A turma nao esta lotada\n\n\n");
   
    // Turma vazia
    int emp;
    emp = lista_vazia(li);
    if(emp)
        printf("A turma esta vazia\n\n\n");
    else
        printf("A turma nao esta vazia\n\n\n");

    // Removendo todos os alunos
    printf("==== Removendo todos os alunos =====\n\n\n");
    for(int i = 0; i < 5; i++){
        if (remove_lista_otimizado(li,i)==-1)
            printf("Erro\n");
    }

    // Quantidade de alunos.
    int qnt2;
    qnt2 = tamanho_lista(li);
    printf("A turma esta com %d aluno(s)\n\n\n",qnt2);

     // Turma vazia
    int emp2;
    emp2 = lista_vazia(li);
    if(emp2)
        printf("A turma esta vazia\n\n\n");
    else
        printf("A turma nao esta vazia\n\n\n");
    
    libera_lista(li);
    return 0;
}


