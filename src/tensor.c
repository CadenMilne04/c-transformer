/*
 * tensor.c
 *
 * This file will include all of linear algebra math required for the n.n.
 *
 * Caden Milne 2025
 */

#include "tensor.h"
#include <stdio.h>
#include <stdlib.h>

Matrix *create_matrix(int rows, int cols) {
	Matrix *new_matrix = (Matrix *)malloc(sizeof(Matrix));
	if (!new_matrix) {
		perror("failed to malloc matrix\n");
		return NULL;
	}
	new_matrix->rows = rows;
	new_matrix->cols = cols;
	new_matrix->data = (float *)malloc(rows * cols * sizeof(float));
	if (!new_matrix->data) {
		perror("failed to malloc matrix data\n");
		free(new_matrix);
		return NULL;
	}

	return new_matrix;
}

void free_matrix(Matrix *matrix) {
	free(matrix->data);
	free(matrix);
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
