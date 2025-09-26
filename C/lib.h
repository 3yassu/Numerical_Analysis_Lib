#ifndef N_ANALYSIS
#define N_ANALYSIS

typedef struct Factor{
	int flag;
	int pivot_index;
}Factor;

Factor *factor(**double A, int neq, *int cond, int pivot_index);
double *solve(**double A, int neq, int pivot_index, *double b);

double **newton_interpolation(double *x, double *y, int length);
doublew newton_solve(double x, double *coefs, double *x_vals, int length);
#endif
