/*
 * input_embedding.c
 *
 * Take in a file with a newline seperated list of sentences as training data,
 * return a vocab map
 *
 * Caden Milne 2025
 *
 */

#include "input_embedding.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 1024

void load_vocab_from_file(Vocab *vocab, const char *file_path) {
	char buf[BUF_SIZE];
	FILE *file = fopen(file_path, "r");
	if (!file) {
		fprintf(stderr, "Failed to open file: %s\n", file_path);
		exit(1);
	}

	while (fgets(buf, sizeof(buf), file)) {
		char *sentence = strtok(buf, "\n");
		while (sentence != NULL) {
			add_sentence_to_vocab(vocab, sentence);

			sentence = strtok(NULL, "\n");
		}
	}
}
