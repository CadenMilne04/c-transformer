/*
 * test_matrix.c
 *
 * tests for the matrix module
 *
 * Caden Milne 2025
 */

#include "../src/tensor.h"
#include "test.h"

#define DEFAULT_ROWS 5
#define DEFAULT_COLS 5

void test_matrix() {
	TEST_MODULE("matrix")

	Matrix *m = create_matrix(DEFAULT_ROWS, DEFAULT_COLS);
	ASSERT_MSG(m->rows == 5 && m->cols == 5 && m->data != NULL, "create matrix");
	free_matrix(m);

	Matrix *a = create_matrix(2, 2);
	mat_set(a, 0, 0, 1);
	mat_set(a, 0, 1, 2);
	mat_set(a, 1, 0, 3);
	mat_set(a, 1, 1, 4);
	Matrix *b = create_matrix(2, 2);
	mat_set(b, 0, 0, 1);
	mat_set(b, 0, 1, 2);
	mat_set(b, 1, 0, 3);
	mat_set(b, 1, 1, 4);
	Matrix *out = create_matrix(2, 2);
	mat_mul(out, a, b);
	ASSERT_MSG(mat_get(out, 0, 0) == 7 && mat_get(out, 0, 1) == 10 && mat_get(out, 1, 0) == 15 &&
	               mat_get(out, 1, 1) == 22,
	           "matrix multiplication");
	free_matrix(a);
	free_matrix(b);
	free_matrix(out);
}
