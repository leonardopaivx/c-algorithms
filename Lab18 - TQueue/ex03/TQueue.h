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
int queue_free(TQueue *queue);

int queue_push(TQueue *queue, struct aluno al);
int queue_pop(TQueue *queue);
int queue_top(TQueue *queue, struct aluno *al);

int queue_empty(TQueue *queue);
int compactar_fila(TQueue *queue);
int queue_full(TQueue *queue);

#endif