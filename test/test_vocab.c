/*
 * test_vocab.c
 */

#include "../src/vocab.h"
#include "test.h"
#include <string.h>

void test_vocab() {
	TEST_MODULE("vocab");

	Vocab *vocab = create_vocab();
	ASSERT_MSG(vocab->num_words == 0, "Create empty vocab");

	char *test_sentence = "The quick brown fox jumped over the lazy dog";
	int num_words = 0;
	char *word = strtok(strdup(test_sentence), " ");
	while (word != NULL) {
		num_words++;
		word = strtok(NULL, " ");
	}

	add_sentence_to_vocab(vocab, strdup(test_sentence));
	ASSERT_MSG(vocab->num_words == num_words, "Add sentence to vocab");

	add_sentence_to_vocab(vocab, strdup(test_sentence));
	ASSERT_MSG(vocab->num_words == num_words, "Add duplicate sentence to vocab");
}
