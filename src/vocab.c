/*
 * vocab.c
 */

#include "vocab.h"
#include "utils/hash_map.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Vocab *create_vocab() {
	HashMap *map = create_hashmap();
	Vocab *vocab = malloc(sizeof(Vocab));
	if (!vocab) {
		perror("Failed to malloc new vocab\n");
		exit(1);
	}
	vocab->map = map;
	vocab->num_words = 0;

	return vocab;
}

void vocab_free(Vocab *vocab) {
	hashmap_free(vocab->map);
	free(vocab);
}

void add_sentence_to_vocab(Vocab *vocab, const char *sentence) {
	char *buf = strdup(sentence);
	char *word = strtok(buf, " ");
	while (word != NULL) {
		hashmap_add(vocab->map, word);
		word = strtok(NULL, " ");
	}
	vocab->num_words = vocab->map->size;
	free(buf);
}
