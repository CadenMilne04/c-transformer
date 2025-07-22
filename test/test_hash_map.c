/*
 * test_hash_map.c
 *
 * Tests for my custom hashmap implementation in c
 *
 * Caden Milne 2025
 */

#include "../src/utils/hash_map.h"
#include "test.h"
#include <assert.h>
#include <stdio.h>

int test_hash_map() {
	HashMap *map = create_hashmap();
	assert(map->size == 0);

	const char *test_key = "test";
	hashmap_add(map, test_key);
	assert(map->size == 1);

	int value;
	assert(hashmap_get(map, test_key, &value) == 1 && value == 0);

	assert(hashmap_get(map, "not in", &value) == 0);

	hashmap_add(map, "test_1");
	hashmap_add(map, "test_2");
	hashmap_add(map, "test_3");
    assert(map->size == 4);

	printf("All hashmap tests passed!\n");
	return TEST_SUCCESS;
}
