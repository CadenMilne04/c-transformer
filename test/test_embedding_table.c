/*
 * test_embedding_table.c
 */

#include "../src/constants.h"
#include "../src/embedding_table.h"
#include "../src/vocab.h"
#include "test.h"

void test_embedding_table() {
	TEST_MODULE("embedding table");

	Vocab *vocab = create_vocab();
	add_sentence_to_vocab(vocab, "The quick brown fox jumped over the lazy dog");
	Matrix *embedding_table = create_embedding_table(vocab);
	ASSERT_MSG(embedding_table->rows == 9 && embedding_table->cols == D_MODEL,
	           "Create embedding table");

	free_matrix(embedding_table);
}
