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

void test_rowwise_softmax() {
	Matrix *a = create_matrix(2, 3);
	mat_set(a, 0, 0, 1);
	mat_set(a, 0, 1, 2);
	mat_set(a, 0, 2, 3);
	mat_set(a, 1, 0, 0);
	mat_set(a, 1, 1, 1);
	mat_set(a, 1, 2, 2);

	mat_rowwise_softmax(a);

	// Check that each row sums to 1
	for (int i = 0; i < a->rows; i++) {
		float sum = 0;
		for (int j = 0; j < a->cols; j++) {
			sum += mat_get(a, i, j);
			ASSERT_MSG(mat_get(a, i, j) >= 0 && mat_get(a, i, j) <= 1,
			           "softmax values out in range");
		}
		ASSERT_MSG(fabsf(sum - 1.0f) < 1e-5, "softmax row sums to 1");
	}

	free_matrix(a);
}

void test_concat_matrix() {
	Matrix *a = create_matrix(2, 2);
	mat_set(a, 0, 0, 1);
	mat_set(a, 0, 1, 2);
	mat_set(a, 1, 0, 3);
	mat_set(a, 1, 1, 4);

	Matrix *b = create_matrix(2, 3);
	mat_set(b, 0, 0, 5);
	mat_set(b, 0, 1, 6);
	mat_set(b, 0, 2, 7);
	mat_set(b, 1, 0, 8);
	mat_set(b, 1, 1, 9);
	mat_set(b, 1, 2, 10);

	Matrix *out = create_matrix(2, 5); // 2 rows, 2+3=5 columns

	mat_concat_columns(out, a, b);

	float expected[2][5] = {{1, 2, 5, 6, 7}, {3, 4, 8, 9, 10}};

	int res = 1; 
	for (int i = 0; i < out->rows; i++) {
		for (int j = 0; j < out->cols; j++) {
			if (mat_get(out, i, j) != expected[i][j]) {
				res = 0;
			}
		}
	}

    ASSERT_MSG(res, "concat columns");

	free_matrix(a);
	free_matrix(b);
	free_matrix(out);
}

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

	a = create_matrix(2, 2);
	mat_set(a, 0, 0, 1);
	mat_set(a, 0, 1, 2);
	mat_set(a, 1, 0, 3);
	mat_set(a, 1, 1, 4);
	out = create_matrix(2, 2);
	mat_transpose(out, a);
	ASSERT_MSG(mat_get(out, 0, 0) == 1 && mat_get(out, 0, 1) == 3 && mat_get(out, 1, 0) == 2 &&
	               mat_get(out, 1, 1) == 4,
	           "matrix transpose");

	free_matrix(a);
	free_matrix(b);
	free_matrix(out);

	test_rowwise_softmax();

	test_concat_matrix();
}
