/*
 * test_attention.c
 */

#include "../src/attention.h"
#include "test.h"

void test_attention() {
	TEST_MODULE("attention");

	AttentionHead *ah = create_attention_head();
	ASSERT_MSG(ah->W_queries->data[0] >= -.1, "Data inside query weight should be random");
	ASSERT_MSG(ah->W_queries->rows == D_MODEL && ah->W_queries->cols == D_MODEL, "create head");

	MultiHeadAttention *mah = create_multihead_attention();
	ASSERT_MSG(mah->heads[1]->W_queries->rows == D_MODEL, "creating multihead attention");
}
