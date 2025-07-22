/*
 * tensor.c
 *
 * This file will include all of linear algebra math required for the n.n.
 *
 * Caden Milne 2025
 */

#include "tensor.h"
#include <stdlib.h>

Matrix create_matrix(int rows, int cols) {
	Matrix new_matrix;
	new_matrix.rows = rows;
	new_matrix.cols = cols;
	new_matrix.data = (float *)malloc(rows * cols * sizeof(float));

	return new_matrix;
}
