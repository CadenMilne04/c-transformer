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
	Matrix *W_queries; // [D_MODEL x D_HEAD]
	Matrix *W_keys;    // [D_MODEL x D_HEAD]
	Matrix *W_values;  // [D_MODEL x D_HEAD]
} AttentionHead;

typedef struct {
	AttentionHead *heads[NUM_HEADS];
	Matrix *W_output; // [D_MODEL x D_MODEL]
} MultiHeadAttention;

AttentionHead *create_attention_head();
MultiHeadAttention *create_multihead_attention();

Matrix *calculate_attention(Matrix *input_encoding, Matrix *W_queries, Matrix *W_keys,
                            Matrix *W_values);
void multihead_attention_forward(MultiHeadAttention *mha, Matrix *input_encoding);
