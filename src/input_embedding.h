/*
 * input_embedding.h
 *
 * Header for input_embedding module
 *
 * Caden Milne 2025
 *
 */

#include "./utils/hash_map.h"
#include "vocab.h"

/* See README for training input file specification */
void load_vocab_from_file(Vocab *vocab, const char *file_path);
