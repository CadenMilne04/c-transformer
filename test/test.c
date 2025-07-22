/*
 * test.c
 *
 * Driver for the tests
 *
 * Caden Milne 2025
 */

#include "test.h"
#include "test_matrix.c"
#include "test_hash_map.c"
#include "test_input_embedding.c"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define EXIT_SUCCESS 0

int main(int argc, char *argv[]) {
	assert(test_matrix() == TEST_SUCCESS);
	assert(test_hash_map() == TEST_SUCCESS);
	assert(test_input_embedding() == TEST_SUCCESS);

	printf("All tests passed!\n");
	return EXIT_SUCCESS;
}
