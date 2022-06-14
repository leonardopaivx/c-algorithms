#define SUCCESS 0
#define INVALID_NULL_POINTER -1
#define OUT_OF_MEMORY -2
#define OUT_OF_RANGE -3
#define ELEM_NOT_FOUND -4

struct aluno{
    int matricula;
    char nome[30];
    float n1,n2,n3;
};

typedef struct circlist Circlist;

Circlist *list_create();
int list_free(Circlist *list);

int list_push_front(Circlist *list, struct aluno al);
int list_push_back(Circlist *list, struct aluno al);
int list_insert(Circlist *list, int pos, struct aluno al); 
int list_insert_sorted(Circlist *list, struct aluno al);
int list_size(Circlist *list);


int list_pop_front(Circlist *list);
int list_pop_back(Circlist *list);
int list_erase(Circlist *list, int pos);

int list_find_pos(Circlist *list, int pos, struct aluno *al);
int list_find_mat(Circlist *list, int nmat, struct aluno *al);
int list_front(Circlist *list, struct aluno *al);

int list_back(Circlist *list, struct aluno *al);
int list_get_pos(Circlist *list, int nmat, int *pos);
int list_print(Circlist *list);