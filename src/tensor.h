/*
 * tensor.h
 *
 * This file will include the function defs for the tensor math
 * What the hell is a tensor anyways? ChatGPT said it's basically an N dim Matrix
 *
 * Caden Milne 2025
 */

#ifndef TENSOR_H
#define TENSOR_H

#include <math.h>

typedef struct {
	int rows;
	int cols;
	float *data;
} Matrix;

static inline float mat_get(Matrix *m, int row, int col) { return m->data[row * m->cols + col]; }

static inline void mat_set(Matrix *m, int row, int col, float value) {
	m->data[row * m->cols + col] = value;
}

Matrix *create_matrix(int rows, int cols);

void print_matrix(Matrix *matrix);

void randomize_matrix(Matrix *mat, float scale);

void free_matrix(Matrix *matrix);

void mat_mul(Matrix *out, Matrix *a, Matrix *b);

void mat_div_scalar(Matrix *a, float scalar);

void mat_transpose(Matrix *out, Matrix *a);

void mat_rowwise_softmax(Matrix *a);

void mat_concat_columns(Matrix *out, Matrix *a, Matrix *b);

void mat_copy_columns(Matrix *out, Matrix *src, int offset_col);

#endif
