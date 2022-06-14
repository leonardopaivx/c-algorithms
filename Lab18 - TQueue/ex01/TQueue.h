#ifndef _tqueueh_
#define _tqueueh_

#include "aluno.h"

typedef struct TQueue TQueue;

#define SUCCESS 0
#define INVALID_NULL_POINTER -1
#define OUT_OF_MEMORY -2
#define OUT_OF_RANGE -3
#define ELEM_NOT_FOUND -4

TQueue *queue_create();
int queue_free(TQueue *q);

int queue_push(TQueue *q, struct aluno al);
int queue_pop(TQueue *q);
int queue_top(TQueue *q, struct aluno *al);

int queue_empty(TQueue *q);
int queue_full(TQueue *q);

#endif