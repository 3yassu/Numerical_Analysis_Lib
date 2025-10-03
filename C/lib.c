#include <math.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include "lib.h"
/*
void mem_swap(void *a, void *b, size_t size){
	void *temp = malloc(size);
	if(temp == NULL){
		printf("No memory available");
	else{
		memcpy(temp, a, size);
		memcpy(a, b, size);
		memcpy(b, temp, size);
	}
} <- If I wanna i guess...
*/
void mem_swap(double *a, double *b);

int *factor(double **A, int neq, int *cond, int *pivots){
	int flag = 0;
	pivots[neq - 1] = 1;
	double Anorm = norm(A, neq, neq);
	if(neq == 1){
		if(A[0][0]) == 0
			flag = 1;
		else{
			*cond = 1;
		}
		return flag;
	}
	for(int i = 0; i < neq - 1; i++){
		
	}

}
double norm(**double A, int size_w, int size_h){ //Later add support for all p-norm but for now inf norm
	double max = 0, test = 0;
	for(int i = 0; i < size_h)
		max += A[i][0];
	for(int i = 1; i < size_w; i++){
		for(int j = 0; j < size_h; j++)
			test += A[i][j];
		if(test > max)
			max = test;
		test = 0;
	}
	return max
}

double *solve(double **A, int neq, int *pivots, *double b){
	double *sol = (double*)malloc(sizeof(double)*i);
	for(int i = 0; i < neq; i++)
		sol[i] = b[i];
	if(neq == 1)
		*sol /= **A;
	else{
		//Forward Elimination
		for(int i = 0; i < neq - 1; i++){
			int m = pivots[i];
			mem_swap(sol+m, sol+i);
			for(int j = i+1; j < neq;j++)
				sol[j] += A[j][i]*sol[i];
		}
		//Back Substitution
		sol[neq-1] /= A[neq-1][neq-1];
		for(int i = neq-2; i > -1; i--){
			float sum = 0;
			for(int j = i+1; j < neq; j++)
				sum += A[i, j]*sol[j];
			sol[i] = (sol[i]-sum)/A[i,i];
		}
	}
	return sol;
}

void mem_swap(double *a, double *b){
	double temp = *a;
	*a = *b;
	*b = temp;
}

double **newton_interpolation(double *x, double *y, int length){
	double **coef = (double**)malloc(sizeof(double*)*length);
	for(int i = length; i > 0; i--){
		coef[length-i] = (double*)malloc(sizeof(double)*i);
		*coef[length-i] = y[length-i];
	}
	for(int j = 1; j < length; j++)
		for(int i = 0; i < (length - j); i++)
			coef[i][j] = (coef[i+1][j-1]-coef[i][j-1])/(x[i+j]-x[i]);
	return coef; //Don't forget to free when calling this function
}

double newton_solve(double x, double *coefs, double *x_vals, int length){
	double val = coefs[length-1];
	for(int i = 2; i < length+1; i++)
		val = coefs[length-i] + (x-x_vals[length-i])*val;
	return val;
}

//double lagrange_solve(double *x, double *y, int length){
// e
//}
// .git
// src
// 	|-lib.c
// 	|-lin.c
// 	|-interpolate.c
// 	|-zero.c
// include

// 1 2 3 
// 4 5 6
// 7 8 9
//
// 1+4+7, 2+5+8, 3+6+9
//  
