#include <stdio.h>
#include "TStack.h"


int bemFormada (char s[]) 
{

   TStack *st;
   st = stack_create(50);

   for (int i = 0; s[i] != '\0'; i++) {
      char c;
      switch (s[i]) {
         case ')': if (stack_empty(st) == 0){
                     return -1;
                   }else{
             
                   stack_top(st, &c);
                   if (c != '('){
                      return -2;
                      break;
                   }

                   stack_pop(st);
                   break; 
                   }
                   
         case ']': if (stack_empty(st) == 0)  return -1;
                                
                   stack_top(st,&c);
                   if (c != '['){
                      return -1;
                      break;
                   } 
                   stack_pop(st);
                   break; 
                   
         default: stack_push(st,s[i]); 
      }
   }
   return stack_empty(st);
}


int main()
{
    char c[10];     
    scanf("%s",c);     
    int retorno = bemFormada(c);

    printf("%d",retorno);


    return 0;
}