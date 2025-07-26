/*
 * test.h
 *
 * test interface
 *
 * Caden Milne 2025
 */

#include <stdio.h>
#include <stdlib.h>

extern int tests_run;
extern int tests_passed;
extern int tests_failed;

#define TEST_MODULE(name) printf("\n[Module: %s]\n", name);

#define ASSERT_MSG(cond, msg)                                                                      \
	do {                                                                                           \
		tests_run++;                                                                               \
		if (!(cond)) {                                                                             \
			tests_failed++;                                                                        \
			fprintf(stderr, "[FAIL] %s:%d: %s\n", __FILE__, __LINE__, msg);                        \
		} else {                                                                                   \
			tests_passed++;                                                                        \
			fprintf(stdout, "[PASS] %s:%d: %s\n", __FILE__, __LINE__, msg);                        \
		}                                                                                          \
	} while (0)

void print_test_summary(void);
