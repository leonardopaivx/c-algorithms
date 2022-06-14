#include <stdio.h>
#include "TStack.h"

int main()
{

   TStack *st;
   st = stack_create(20);     

   stack_push(st,'o'); 

   char c;

   
      
   int a = stack_top(st,&c);

   printf("\nC eh: %c\n",c);
   printf("%d", a);

   return 0;
}