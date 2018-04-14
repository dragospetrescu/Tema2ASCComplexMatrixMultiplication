/*
 * Tema 2 ASC
 * 2018 Spring
 * Catalin Olaru / Vlad Spoiala
 */
#include "utils.h"


double *my_solver(int N, double *A)
{
	int l, c, i;
	double *result = calloc(2 * N * N, sizeof(double));

	for (l = 0; l < N; ++l) {
		for (c = l; c < N; ++c) {
			for (i = 0; i < N; ++i) {
				result[2 * (l * N + c)] +=
					A[2 * (l * N + i)] * A[2 * (c * N + i)]
						- A[2 * (l * N + i) + 1] * A[2 * (c * N + i) + 1];

				result[2 * (l * N + c) + 1] +=
					A[2 * (l * N + i)] * A[2 * (c * N + i) + 1]
						+ A[2 * (c * N + i)] * A[2 * (l * N + i) + 1];
			}
		}

	}

	return result;
}
