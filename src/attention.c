/*
 * attention.c
 */

#include "attention.h"
#include "constants.h"
#include "tensor.h"
#include <stdio.h>
#include <stdlib.h>

AttentionHead *create_attention_head() {
	AttentionHead *attention_head = malloc(sizeof(AttentionHead));
	if (!attention_head) {
		perror("failed to malloc attention head\n");
		exit(1);
	}
	attention_head->W_queries = create_matrix(D_MODEL, D_MODEL);
	attention_head->W_keys = create_matrix(D_MODEL, D_MODEL);
	attention_head->W_values = create_matrix(D_MODEL, D_MODEL);

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
void multihead_attention_forward(MultiHeadAttention *mha, Matrix *input_encoding) {
	/* for each head */
	for (int i = 0; i < NUM_HEADS; i++) {
		/* 1. compute q,k,v */
        /* TODO: after implementing matmul */
		/* 2. compute attention */
	}
	/* then, concat outputs from all heads */
	/* then, apply that final output projection */
}
