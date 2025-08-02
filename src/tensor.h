/*
 * tensor.h
 *
 * This file will include the function defs for the tensor math
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

Matrix *create_matrix(int rows, int cols);

void print_matrix(Matrix *matrix);

void free_matrix(Matrix *matrix);

#endif 
