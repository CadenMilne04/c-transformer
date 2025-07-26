/*
 * vocab.h
 */

#ifndef VOCAB_H
#define VOCAB_H

#include "utils/hash_map.h"

typedef struct {
	HashMap *map; // for now the data structure can be a map :D
	size_t num_words;
} Vocab;

Vocab *create_vocab();
void free_vocab(Vocab *vocab);

void add_sentence_to_vocab(Vocab *vocab, const char *sentence);

#endif
