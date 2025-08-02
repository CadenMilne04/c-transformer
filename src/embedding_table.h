/*
 * embedding_table.h
 */

#include "tensor.h"
#include "vocab.h"

/* embedding tables are two dimensional */
Matrix *create_embedding_table(Vocab *vocab);
