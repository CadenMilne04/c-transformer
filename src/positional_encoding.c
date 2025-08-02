/*
 * positional_encoding.c
 *
 * Caden Milne 2025
 */

#include "constants.h"
#include "tensor.h"

#define PE_DENOMINATOR 10000.0f

/* source: Section 3.5 attention is all you need google */
void create_positional_encodings(Matrix *pe) {
	int rows = pe->rows; // max_seq_len
	int cols = pe->cols; // d_model

	for (int pos = 0; pos < rows; pos++) {
		for (int i = 0; i < cols; i++) {
			int index_pair = i / 2;
			float exponent = (2.0f * index_pair) / D_MODEL;

			float angle_rate = pos / powf(PE_DENOMINATOR, exponent);

			if (i % 2 == 0) {
				pe->data[pos * D_MODEL + i] = sinf(angle_rate);
			} else {
				pe->data[pos * D_MODEL + i] = cosf(angle_rate);
			}
		}
	}
}
