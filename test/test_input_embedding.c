/*
 * test_input_embedding.c
 *
 * Tests for the input embedding module of our transformer
 *
 */
#include "../src/embedding_table.h"
#include "../src/input_embedding.h"
#include "../src/constants.h"
#include "../src/vocab.h"
#include "test.h"
#include <stdio.h>

void test_input_embedding() {
	TEST_MODULE("input embedding");

	Vocab *vocab = create_vocab();
	load_vocab_from_file(vocab, "test/test_sentences.txt");

	ASSERT_MSG(vocab->num_words == 10, "Load vocab from file");

	Matrix *embedding_table = create_embedding_table(vocab);
	ASSERT_MSG(embedding_table->rows == 10 && embedding_table->cols == D_MODEL,
	           "Create embedding table");
    free_matrix(embedding_table);
}
