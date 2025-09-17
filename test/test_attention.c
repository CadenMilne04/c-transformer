/*
 * test_attention.c
 */

#include "../src/attention.h"
#include "test.h"

void test_calculate_attention() {
	// Input: 2 tokens, D_MODEL = constant
	Matrix *input = create_matrix(2, D_MODEL);
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < D_MODEL; j++) {
			mat_set(input, i, j, i + j + 1); // arbitrary values
		}
	}

	// W matrices: D_MODEL × D_HEAD
	Matrix *W_q = create_matrix(D_MODEL, D_HEAD);
	Matrix *W_k = create_matrix(D_MODEL, D_HEAD);
	Matrix *W_v = create_matrix(D_MODEL, D_HEAD);

	// Fill W matrices with simple values
	for (int i = 0; i < D_MODEL; i++) {
		for (int j = 0; j < D_HEAD; j++) {
			mat_set(W_q, i, j, 1.0f);
			mat_set(W_k, i, j, 1.0f);
			mat_set(W_v, i, j, 1.0f);
		}
	}

	// Run attention
	Matrix *out = calculate_attention(input, W_q, W_k, W_v);

	// Check output shape: [sequence_length x D_HEAD]
	int res = (out->rows == 2 && out->cols == D_HEAD);

	// Optional: check that values are non-negative
	for (int i = 0; i < out->rows; i++) {
		for (int j = 0; j < out->cols; j++) {
			if (mat_get(out, i, j) < 0)
				res = 0;
		}
	}

	ASSERT_MSG(res, "calculate_attention basic test failed");

	// Clean up
	free_matrix(input);
	free_matrix(W_q);
	free_matrix(W_k);
	free_matrix(W_v);
	free_matrix(out);
}

void test_attention() {
	TEST_MODULE("attention");

	AttentionHead *ah = create_attention_head();
	ASSERT_MSG(ah->W_queries->data[0] >= -.1, "Data inside query weight should be random");
	ASSERT_MSG(ah->W_queries->rows == D_MODEL && ah->W_queries->cols == D_HEAD, "create head");

	MultiHeadAttention *mah = create_multihead_attention();
	ASSERT_MSG(mah->heads[1]->W_queries->rows == D_MODEL, "creating multihead attention");

	test_calculate_attention();
}
