#ifndef N_ANALYSIS
#define N_ANALYSIS

//typedef struct Factor{
//	int flag;
//	int *pivot;
//}Factor;

//typedef enum Norm{
//	INF,
//	NUM
//}Norm;
 

double norm(**double A, int size_w, int size_h); //Later add support for all p-norm
int *factor(**double A, int neq, *int cond, int pivot_index);
double *solve(**double A, int neq, int pivot_index, *double b);

double **newton_interpolation(double *x, double *y, int length);
double newton_solve(double x, double *coefs, double *x_vals, int length);
#endif
