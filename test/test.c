/*
 * test.c
 *
 * Driver for the tests
 *
 * Caden Milne 2025
 */

#include "test.h"
#include "test_attention.c"
#include "test_embedding_table.c"
#include "test_hash_map.c"
#include "test_input_embedding.c"
#include "test_matrix.c"
#include "test_positional_encoding.c"
#include "test_vocab.c"

int tests_run = 0;
int tests_passed = 0;
int tests_failed = 0;

void print_test_summary(void) {
	printf("\nTest summary:\n");
	printf("\tRun:    %d\n", tests_run);
	printf("\tPassed: %d\n", tests_passed);
	printf("\tFailed: %d\n", tests_failed);
	if (tests_failed > 0) {
		exit(1);
	}
}

int main(int argc, char *argv[]) {
	test_matrix();
	test_hash_map();
	test_vocab();
	test_embedding_table();
	test_input_embedding();
	test_positional_encoding();
	test_attention();

	print_test_summary();
}
