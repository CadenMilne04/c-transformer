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

	Matrix m = create_matrix(DEFAULT_ROWS, DEFAULT_COLS);
	ASSERT_MSG(m.rows == 5 && m.cols == 5 && m.data != NULL, "create matrix");
}
