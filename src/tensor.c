/*
 * tensor.c
 *
 * This file will include all of linear algebra math required for the n.n.
 *
 * Caden Milne 2025
 */

#include "tensor.h"
#include <float.h>
#include <stdio.h>
#include <stdlib.h>

Matrix *create_matrix(int rows, int cols) {
	Matrix *new_matrix = (Matrix *)malloc(sizeof(Matrix));
	if (!new_matrix) {
		perror("failed to malloc matrix\n");
		exit(1);
	}
	new_matrix->rows = rows;
	new_matrix->cols = cols;
	new_matrix->data = (float *)malloc(rows * cols * sizeof(float));
	if (!new_matrix->data) {
		perror("failed to malloc matrix data\n");
		free(new_matrix);
		exit(1);
	}

	return new_matrix;
}

void free_matrix(Matrix *matrix) {
	free(matrix->data);
	free(matrix);
}

void randomize_matrix(Matrix *mat, float scale) {
	for (int i = 0; i < mat->rows; i++) {
		for (int j = 0; j < mat->cols; j++) {
			mat->data[i * mat->cols + j] = ((float)rand() / RAND_MAX) * 2 * scale - scale;
		}
	}
}

void print_matrix(Matrix *matrix) {
	printf("{");
	for (int i = 0; i < matrix->rows; i++) {
		printf("[");
		for (int j = 0; j < matrix->cols; j++) {
			if (j == matrix->cols - 1) {
				printf("%f", matrix->data[i * matrix->cols + j]);
			} else {
				printf("%f, ", matrix->data[i * matrix->cols + j]);
			}
		}
		if (i == matrix->rows - 1) {
			printf("]");
		} else {
			printf("],\n");
		}
	}
	printf("}\n");
}

void mat_mul(Matrix *out, Matrix *a, Matrix *b) {
	if (a->cols != b->rows) {
		fprintf(stderr, "Error: Multiplying incompatible matrices (%d x %d) * (%d x %d)\n",
		        a->rows, a->cols, b->rows, b->cols);
		exit(EXIT_FAILURE);
	}

	for (int i = 0; i < a->rows; i++) {
		for (int j = 0; j < a->cols; j++) {
			int sum = 0;
			for (int k = 0; k < b->rows; k++) {
				sum += mat_get(a, i, k) * mat_get(b, k, j);
			}
			mat_set(out, i, j, sum);
		}
	}
}

/* swaps the rows and the columns */
void mat_transpose(Matrix *out, Matrix *a) {
	for (int i = 0; i < a->rows; i++) {
		for (int j = 0; j < a->cols; j++) {
			mat_set(out, j, i, mat_get(a, i, j));
		}
	}
}

void mat_rowwise_softmax(Matrix *a) {
	/* use the re-centering around 0 trick to prevent overflow */
	for (int i = 0; i < a->rows; i++) {
		float row_max = -FLT_MAX;
		for (int j = 0; j < a->cols; j++) {
			row_max = mat_get(a, i, j) > row_max ? mat_get(a, i, j) : row_max;
		}
		float row_total = 0;
		for (int j = 0; j < a->cols; j++) {
			row_total += expf(mat_get(a, i, j) - row_max);
		}
		for (int j = 0; j < a->cols; j++) {
			float softmax_val = expf(mat_get(a, i, j) - row_max) / row_total;
			mat_set(a, i, j, softmax_val);
		}
	}
}

void mat_concat_columns(Matrix *out, Matrix *a, Matrix *b) {
	for (int i = 0; i < a->rows; i++) {
		for (int j = 0; j < b->cols; j++) {
			mat_set(out, i, j, mat_get(a, i, j));
		}
	}
	for (int i = 0; i < b->cols; i++) {
		for (int j = 0; j < b->rows; j++) {
			mat_set(out, j, a->cols + i, mat_get(b, j, i));
		}
	}
}
