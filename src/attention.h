/*
 * attention.h
 *
 * Apparently, this is all you need...
 *
 * Caden Milne 2025
 */

#include "constants.h"
#include "tensor.h"

typedef struct {
	Matrix *W_queries; // [D_MODEL x D_MODEL]
	Matrix *W_keys;    // [D_MODEL x D_MODEL]
	Matrix *W_values;  // [D_MODEL x D_MODEL]
} AttentionHead;

typedef struct {
	AttentionHead *heads[NUM_HEADS];
	Matrix *W_output; // [D_MODEL x D_MODEL]
} MultiHeadAttention;

AttentionHead *create_attention_head();
MultiHeadAttention *create_multihead_attention();

/* input is a sequence of tokens by d_model */
void multihead_attention_forward(MultiHeadAttention *mha, Matrix *input_encoding);
