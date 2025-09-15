#include <math.h>
#include <stdlib.h>
#include "lib.h"

Factor *factor(double **A, int neq, int *cond, int pivot_index){
	int flag = 0;
	int *pivots = (int*)malloc(sizeof(int)*neq);
	*(pivots + neq - 1) = 1;

}

double *solve(double **A, int neq, int pivot_index, *double b){

}

double **newton_interpolation(double *x, double *y, int length){
	double **coef = (double**)malloc(sizeof(double*)*length);
	for(int i = length; i > 0; i--){
		*(coef+length-i) = (double*)malloc(sizeof(double)*i);
		**(coef+length-i) = *(y+length-i);
	}
	for(int j = 1; j < length; j++)
		for(int i = 0; i < (length - j); i++)
			*(*(coef+i)+j) = (*(*(coef+i+1)+j-1)-*(*(coef+i)+j-1)) / (*(x+i+j)-*(x+i));
	return coef;
}

