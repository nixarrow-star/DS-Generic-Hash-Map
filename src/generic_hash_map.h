#ifndef GENERIC_HASH_MAP_H
#define GENERIC_HASH_MAP_H
#include <stddef.h>
#include <stdlib.h>
#include "util/generic_link_list.h"

struct hashmap_node
{
    struct link_list *list;
};

struct hashmap
{
    size_t (*hash_function)(void *);
    struct link_list *list;
};

struct hashmap *hashmap_init(size_t (*hash_function)(void *), size_t nb);
size_t test_hash_function(struct hashmap *hashmap, void *data);
struct hashmap *hashmap_insert(struct hashmap *hashmap, void *data, void (*destroy_data)(void *));
void *hashmap_find(struct hashmap *hashmap, void *data, int (*comparasion_function)(void *, void *));
struct hashmap *hashmap_pop(struct hashmap *hashmap, struct link_list_node *node);
void hashmap_destroy(struct hashmap *hashmap);


#endif /* GENERIC_HASH_MAP_H */