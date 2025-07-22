/*
 * hash_map.c
 *
 * my hash map implementation in c
 *
 * Caden Milne 2025
 */

#include "hash_map.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_HASHMAP_SEED_VALUE 1337
#define HASHMAP_SMALL_FIXED_NUMBER 5 // shift left 5 == multiply by 32 :P

HashMapEntry *__create_hashmap_entry(const char *key, int value) {
	HashMapEntry *new_entry = malloc(sizeof(HashMapEntry));
	if (!new_entry) {
		perror("Failed to malloc new HashMap entry\n");
		exit(1);
	}

	new_entry->key = strdup(key);
	new_entry->value = value;
	new_entry->next = NULL;

	return new_entry;
}

HashMap *create_hashmap() {
	HashMap *map = malloc(sizeof(HashMap));
	if (!map)
		return NULL;

	map->num_buckets = DEFAULT_BUCKET_SIZE;
	map->size = 0;

	map->buckets = calloc(map->num_buckets, sizeof(HashMapEntry *));
	if (!map->buckets) {
		free(map);
		return NULL;
	}

	return map;
}

/* source: djb2 */
unsigned long __hash_function(const char *key) {
	unsigned long hash_value = INITIAL_HASHMAP_SEED_VALUE;
	int key_length = strlen(key);

	int i;
	for (i = 0; i < key_length; i++) {
		hash_value =
		    ((hash_value << HASHMAP_SMALL_FIXED_NUMBER) + hash_value) + key[i];
	}

	return hash_value;
}

/* TODO (c. milne): Implement automatic resizing/hashing at 75% capacity */
void hashmap_add(HashMap *map, const char *key) {
	int hashed_index = __hash_function(key) % map->num_buckets;
	if (map->buckets[hashed_index] == NULL) {
		map->buckets[hashed_index] = __create_hashmap_entry(key, map->size);
		map->size += 1;
		return;
	}

	HashMapEntry *current_entry = map->buckets[hashed_index];
	while (current_entry != NULL) {
		if (strcmp(current_entry->key, key) == 0)
			return;
		current_entry = current_entry->next;
	}

	HashMapEntry *new_entry = __create_hashmap_entry(key, map->size);
	new_entry->next = map->buckets[hashed_index];

	map->buckets[hashed_index] = new_entry;
	map->size += 1;
}

int hashmap_get(HashMap *map, const char *key, int *out_value){
	int hashed_index = __hash_function(key) % map->num_buckets;
	if (map->buckets[hashed_index] == NULL) {
		return 0;
	}

	HashMapEntry *current_entry = map->buckets[hashed_index];
	while (current_entry != NULL) {
		if (strcmp(current_entry->key, key) == 0){
            *out_value = current_entry->value;
			return 1;
        }
	}

    return 0;
}

void hashmap_free(HashMap *map);
