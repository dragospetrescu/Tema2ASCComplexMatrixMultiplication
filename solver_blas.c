/*
 * Tema 2 ASC
 * 2018 Spring
 * Catalin Olaru / Vlad Spoiala
 */
#include "utils.h"
#include "cblas.h"

double *my_solver(int N, double *A)
{
	const enum CBLAS_ORDER Order = CblasRowMajor;
	const enum CBLAS_UPLO Uplo = CblasUpper;
	const enum CBLAS_TRANSPOSE Trans = CblasNoTrans;

	double *alpha = malloc(2 * sizeof(double));
	alpha[0] = 1.0;
	alpha[1] = 0.0;

	double *beta = malloc(2 * sizeof(double));
	beta[0] = 0.0;
	beta[1] = 0.0;

	int n = N;
	int k = N;
	double *result = calloc(2 * N * N, sizeof(double));

	int lda = N;
	int ldc = N;

	cblas_zsyrk(Order, Uplo, Trans, n, k, alpha, A, lda, beta, result, ldc);

	return result;
}
