/**
 * SO, 2016
 * Lab #7
 *
 * Task #4, lin
 *
 * Implementing 'cp' with mmap
 */
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <math.h>

#include "utils.h"

#define DIE(assertion, call_description)				\
	do {								\
		if (assertion) {					\
			fprintf(stderr, "(%s, %d): ",			\
					__FILE__, __LINE__);		\
			perror(call_description);			\
			exit(-1);					\
		}							\
	} while (0)


int main(int argc, char *argv[])
{
	int fdref, fdout, rc;
	double *ref, *out;
	struct stat statbuf_ref, statbuf_out;

	DIE(argc != 3, "Usage: ./checker <from_file> <to_file>");

	/* TODO - open the input file */
	fdref = open(argv[1], O_RDONLY);
	DIE(fdref == -1, "open fdref");

	/* TODO - open/create the output file */
	fdout = open(argv[2], O_RDONLY);
	DIE(fdout == -1, "open fdout");

	rc = fstat(fdref, &statbuf_ref);
	DIE(rc == -1, "fstat");

	rc = fstat(fdout, &statbuf_out);
	DIE(rc == -1, "fstat");

	/* TODO - mmap the input and output file */
	ref = mmap(0, statbuf_ref.st_size, PROT_READ, MAP_SHARED, fdref, 0);
	DIE(ref == MAP_FAILED, "mmap ref");

	out = mmap(0, statbuf_out.st_size, PROT_READ, MAP_SHARED, fdout, 0);
	DIE(out == MAP_FAILED, "mmap out");

//	fprintf(stderr, "%d", (int)statbuf_ref.st_size);
	int N = (int)sqrt((int)statbuf_ref.st_size / 16.0);

	DIE(statbuf_ref.st_size != statbuf_out.st_size , "Fisiere neegale ca marime");

	int i, j;
	for (i = 0; i < N; ++i) {
		for (j = 0; j < N; ++j) {

			if(fabs(ref[2 * (i * N + j)] - out[2 * (i * N + j)]) > 0.001) {
				fprintf (stderr, "DIFERENTA REAL DE %lf la linia %d si coloana %d. Expected %lf found %lf\n", ref[2 * (i * N + j)] - out[2 * (i * N + j)], i, j, ref[2 * (i * N + j)], out[2 * (i * N + j)]);
				printf("Failed\n");
				exit (-1);
			}

			if(fabs(ref[2 * (i * N + j) + 1] - out[2 * (i * N + j) + 1]) > 0.001) {
				fprintf (stderr, "DIFERENTA IMAG DE %lf la linia %d si coloana %d. Expected %lf found %lf\n", ref[2 * (i * N + j) + 1] - out[2 * (i * N + j) + 1], i, j, ref[2 * (i * N + j) + 1], out[2 * (i * N + j) + 1]);
				printf("Failed\n");
				exit (-1);
			}

		}
	}
	printf("Success\n");

	/* TODO - clean up */
	rc = munmap(ref, statbuf_ref.st_size);
	DIE(rc == -1, "munmap source");

	rc = munmap(out, statbuf_out.st_size);
	DIE(rc == -1, "munmap dest");

	rc = close(fdref);
	DIE(rc == -1, "close source");

	rc = close(fdout);
	DIE(rc == -1, "close dest");

	return 0;
}
