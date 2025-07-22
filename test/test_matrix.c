/*
 * test_matrix.c
 *
 * tests for the matrix module
 *
 * Caden Milne 2025
 */

#include "../src/tensor.h"
#include "test.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_ROWS 5
#define DEFAULT_COLS 5

int test_matrix() {
	Matrix m = create_matrix(DEFAULT_ROWS, DEFAULT_COLS);
	assert(m.rows == 5 && m.cols == 5 && m.data != NULL);

	printf("All matrix tests passed!\n");
	return TEST_SUCCESS;
}
