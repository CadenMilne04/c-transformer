/*
 * hash_map.h
 *
 * My custom hash map implementation for use in my transformer in c project
 *
 * Caden Milne 2025
 *
 */

#ifndef HASH_MAP_H
#define HASH_MAP_H

#include <stddef.h>

#define DEFAULT_BUCKET_SIZE                                                                       \
	65000; // 30,000 common english words in most people's vocabulary (~500kb)

typedef struct HashMapEntry {
	char *key;
	int value;
	struct HashMapEntry *next;
} HashMapEntry;

typedef struct {
	HashMapEntry **buckets;
	size_t num_buckets;
	size_t size;
} HashMap;

HashMap *create_hashmap();

void hashmap_add(HashMap *map, const char *key);

int hashmap_get(HashMap *map, const char *key, int *out_value);

void hashmap_free(HashMap *map);

#endif
