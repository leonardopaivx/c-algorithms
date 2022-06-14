#ifndef _tstackh_
#define _tstackh_

typedef struct TStack TStack;

#define SUCCESS 0
#define INVALID_NULL_POINTER -1
#define OUT_OF_MEMORY -2
#define OUT_OF_RANGE -3
#define ELEM_NOT_FOUND -4
#define NOT_EMPTY -5
#define NOT_FULL -6


TStack *stack_create(int max);
int stack_free(TStack *st);

int stack_push(TStack *st, char c);
int stack_pop(TStack *st);
int stack_top(TStack *st, char *c);

int stack_empty(TStack *st);
int stack_full(TStack *st);

#endif