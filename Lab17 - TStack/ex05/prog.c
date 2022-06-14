#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "TStack.h"


char *infixaParaPosfixa (char *inf) {
   int n = strlen (inf);
   char *posf; 
   posf = malloc ((n+1) * sizeof (char));
   TStack *st;
   st = stack_create(100);
   stack_push(st,inf[0]);     // empilha '('

   int j = 0;
   for (int i = 1; inf[i] != '\0'; ++i) {
      switch (inf[i]) {
         char x;
         case '(': stack_push(st,inf[i]); 
                   break;
         case ')': stack_push(st,x);
                   while (x != '(') {
                      posf[j++] = x;
                      stack_push(st,x);
                      stack_pop(st);
                   }
                   stack_pop(st);
                   break;
         case '+': 
         case '-': stack_push(st,x);
                   while (x != '(') {
                      posf[j++] = x;
                      stack_push(st,x);
                      stack_pop(st);
                   }
                   stack_push(st,x);
                   stack_push(st,inf[i]); 
                   stack_pop(st);
                   break;
         // case '*':
         // case '/': x = desempilha ();
         //           while (x != '(' && x != '+' && x != '-') {
         //              posf[j++] = x;
         //              x = desempilha ();
         //           }
         //           empilha (x);
         //           empilha (inf[i]);
         //           break;
         default:  posf[j++] = inf[i];
      }
   }
   posf[j] = '\0';      
   return posf;
}  



int main()
{
    char c[10];   

    strcpy(c,"(A+B-C)");  
  
       
   infixaParaPosfixa(c); 

    printf("%s",c);


    return 0;
}