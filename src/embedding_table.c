/*
 * embedding_table.c
 */

#include "embedding_table.h"
#include "constants.h"
#include <stdio.h>
#include <stdlib.h>

Matrix *create_embedding_table(Vocab *vocab) {
	Matrix *embedding_table = create_matrix(vocab->num_words, D_MODEL);
	if (!embedding_table) {
		perror("failed to create embedding table\n");
		exit(1);
	}

	/* initialize the embedding table to small random floats for each word*/
	for (int i = 0; i < embedding_table->rows; i++) {
		for (int j = 0; j < embedding_table->cols; j++) {
			float random_float = ((float)rand() / RAND_MAX) * 0.2f - 0.1f; // range [-0.1, 0.1]
			embedding_table->data[i * D_MODEL + j] = random_float;
		}
	}

	return embedding_table;
}
