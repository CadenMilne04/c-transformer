/*
 * attention.c
 */

#include "attention.h"
#include "constants.h"
#include "tensor.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

AttentionHead *create_attention_head() {
	AttentionHead *attention_head = malloc(sizeof(AttentionHead));
	if (!attention_head) {
		perror("failed to malloc attention head\n");
		exit(1);
	}
	attention_head->W_queries = create_matrix(D_MODEL, D_HEAD);
	attention_head->W_keys = create_matrix(D_MODEL, D_HEAD);
	attention_head->W_values = create_matrix(D_MODEL, D_HEAD);

	randomize_matrix(attention_head->W_queries, .1f);
	randomize_matrix(attention_head->W_keys, .1f);
	randomize_matrix(attention_head->W_values, .1f);

	return attention_head;
}

MultiHeadAttention *create_multihead_attention() {

	MultiHeadAttention *mha = malloc(sizeof(MultiHeadAttention));
	if (!mha) {
		perror("failed to malloc multi head attention \n");
		exit(1);
	}

	for (int i = 0; i < NUM_HEADS; i++) {
		mha->heads[i] = create_attention_head();
	}

	mha->W_output = create_matrix(D_MODEL, D_MODEL);

	return mha;
}

/* source: attention is all you need - section 3.2.1 */
Matrix *calculate_attention(Matrix *input_encoding, Matrix *W_queries, Matrix *W_keys,
                            Matrix *W_values) {
	int sequence_length = input_encoding->rows;

	Matrix *Q = create_matrix(sequence_length, D_HEAD);
	mat_mul(Q, input_encoding, W_queries);

	Matrix *K = create_matrix(sequence_length, D_HEAD);
	mat_mul(K, input_encoding, W_keys);

	Matrix *V = create_matrix(sequence_length, D_HEAD);
	mat_mul(V, input_encoding, W_values);

	Matrix *K_T = create_matrix(D_HEAD, sequence_length);
	mat_transpose(K_T, K);

	Matrix *scores = create_matrix(sequence_length, sequence_length);
	mat_mul(scores, Q, K_T);

	mat_div_scalar(scores, sqrt(D_HEAD));

	mat_rowwise_softmax(scores);

	Matrix *weighted_sum = create_matrix(sequence_length, D_HEAD);
	mat_mul(weighted_sum, scores, V);

	free_matrix(Q);
	free_matrix(K);
	free_matrix(V);
	free_matrix(K_T);
	free_matrix(scores);

	return weighted_sum;
}

void multihead_attention_forward(MultiHeadAttention *mha, Matrix *input_encoding) {
	int sequence_length = input_encoding->rows;
	Matrix *concatted_heads = create_matrix(sequence_length, D_MODEL);
	for (int i = 0; i < NUM_HEADS; i++) {
		Matrix *head_attention_output =
		    calculate_attention(input_encoding, mha->heads[i]->W_queries, mha->heads[i]->W_keys,
		                        mha->heads[i]->W_values);

		mat_copy_columns(concatted_heads, head_attention_output, i * D_HEAD);
		free_matrix(head_attention_output);
	}
}
