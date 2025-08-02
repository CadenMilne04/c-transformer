/*
 * test_positional_encoding.c
 */

#include "../src/constants.h"
#include "../src/positional_encoding.h"
#include "../src/tensor.h"
#include "test.h"

void test_positional_encoding() {
	TEST_MODULE("positional encoding");

    Matrix *pe_matrix = create_matrix(MAX_SEQ_LEN, D_MODEL);

    create_positional_encodings(pe_matrix);

	ASSERT_MSG(pe_matrix->data[0] == 0, "positional encoding matrix pe[0][0] should be 0");
	ASSERT_MSG(pe_matrix->data[1] == 1, "positional encoding matrix pe[0][1] should be 1");
    
    free_matrix(pe_matrix);
}
