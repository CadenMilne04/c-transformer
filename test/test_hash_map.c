/*
 * test_hash_map.c
 *
 * Tests for my custom hashmap implementation in c
 *
 * Caden Milne 2025
 */

#include "../src/utils/hash_map.h"
#include "test.h"

void test_hash_map() {
    TEST_MODULE("hashmap");

	HashMap *map = create_hashmap();
	ASSERT_MSG(map->size == 0, "Create hashmap");

	const char *test_key = "test";
	hashmap_add(map, test_key);
	ASSERT_MSG(map->size == 1, "Hashmap add");

	int value;
	ASSERT_MSG(hashmap_get(map, test_key, &value) == 1 && value == 0, "Hashmap get");

	ASSERT_MSG(hashmap_get(map, "not in", &value) == 0, "Hashmap get not in");

	hashmap_add(map, "test_1");
	hashmap_add(map, "test_2");
	hashmap_add(map, "test_3");
	ASSERT_MSG(map->size == 4, "Hashmap add a bunch");
}
