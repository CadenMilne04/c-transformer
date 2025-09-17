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

/* input is a sequence of tokens by d_model */
/* section 3.2.1 */
void multihead_attention_forward(MultiHeadAttention *mha, Matrix *input_encoding) {
	/* for each head */
	int sequence_length = input_encoding->rows;
    Matrix *concatted_outputs = create_matrix(sequence_length, D_MODEL);
	for (int i = 0; i < NUM_HEADS; i++) {
		/* 1. compute q,k,v */
		Matrix *Q = create_matrix(sequence_length, D_HEAD);
		mat_mul(Q, mha->heads[i]->W_queries, input_encoding);

		Matrix *K = create_matrix(sequence_length, D_HEAD);
		mat_mul(K, mha->heads[i]->W_keys, input_encoding);

		Matrix *V = create_matrix(sequence_length, D_HEAD);
		mat_mul(V, mha->heads[i]->W_values, input_encoding);

		/* 2. compute attention */
		Matrix *attention = create_matrix(sequence_length, D_MODEL);
		// (QK^T)/sqrt(d_k)
		Matrix *K_transpose = create_matrix(D_HEAD, sequence_length);
		mat_transpose(K_transpose, K);
		Matrix *Q_K_transpose = create_matrix(sequence_length, sequence_length);
		mat_mul(Q_K_transpose, Q, K_transpose);
		double sqrt_d_head = sqrt(D_HEAD);

		// scalar division
		for (int i = 0; i < Q_K_transpose->rows; i++) {
			for (int j = 0; j < Q_K_transpose->cols; j++) {
				mat_set(Q_K_transpose, i, j, mat_get(Q_K_transpose, i, j) / sqrt_d_head);
			}
		}

        mat_rowwise_softmax(Q_K_transpose);
        Matrix *head_output = create_matrix(sequence_length, D_HEAD);
        mat_mul(head_output, Q_K_transpose, V);
	}
	/* then, concat outputs from all heads */
	/* then, apply that final output projection */
}
