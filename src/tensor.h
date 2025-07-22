/*
 * tensor.h
 *
 * This file will include the function defs for the tensor math
 *
 * Caden Milne 2025
 */

#include <math.h>
typedef struct {
    int rows;
    int cols;
    float *data;
} Matrix;

Matrix create_matrix(int rows, int cols);

// | Operation                     | Purpose                                     | Notes                                   |
// | ----------------------------- | ------------------------------------------- | --------------------------------------- |
// | **Create tensor**             | Allocate and initialize tensor data         | Allocate memory, store shape info       |
// | **Free tensor**               | Release allocated memory                    | Avoid memory leaks                      |
// | **Fill tensor**               | Set all elements to a constant (e.g. zeros) | Useful for initialization               |
// | **Print tensor**              | For debugging: display values               | Helpful for verifying correctness       |
// | **Matrix multiply**           | Core for linear layers and attention        | Multiply 2D tensors                     |
// | **Element-wise add**          | Add bias or residual connections            | Add two tensors element-wise            |
// | **Element-wise multiply**     | For scaling tensors                         | Used in some attention steps            |
// | **Transpose**                 | Swap rows and columns                       | Needed in attention computations        |
// | **Apply activation function** | Apply ReLU, softmax, or other activations   | Softmax is essential in attention       |
// | **Copy tensor**               | Duplicate tensor data                       | Useful when you don’t want to overwrite |
//
