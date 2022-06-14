typedef struct TMat2D TMat2D;

TMat2D *mat2D_create(int nrow, int ncol);
int mat2d_fill(TMat2D *mat, int i, int j, double value);
int mat2d_access(TMat2D *mat, int i, int j,double *element);
int mat2d_rand_fill(TMat2D *mat, int n1, int n2);
int mat2d_addition(TMat2D *mat1, TMat2D *mat2, TMat2D *mat_sum);
int mat2d_mult(TMat2D *mat1, TMat2D *mat2, TMat2D *mult);
int mat2d_mult_by_a_constant(TMat2D *mat, double c, TMat2D *mult);
int mat2d_trace(TMat2D *mat, double *trace);
int mat2d_sum_rows(TMat2D *mat, double *r);
int mat2d_sum_columns(TMat2D *mat, double *r);
void mat2d_print(TMat2D *mat);
int mat2d_free(TMat2D *mat);
