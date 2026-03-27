#include "generic_hash_map.h"

struct hashmap *hashmap_init(size_t (*hash_function)(void *), size_t nb)
{
    struct hashmap *hash = calloc(1,sizeof(struct hashmap));
    hash->hash_function = hash_function;
    hash->list = calloc(nb, sizeof(struct hashmap_node));
    for(size_t i = 0; i < nb; i++)
    {
        hash->list[i].list = list_init();
    }
    hash->size = nb;

    return hash;
}

size_t test_hash_function(struct hashmap *hashmap, void *data)
{
    return hashmap->hash_function(data);
}

struct hashmap *hashmap_insert(struct hashmap *hashmap, void *data, void (*destroy_data)(void *))
{
    size_t index = hashmap->hash_function(data);
    hashmap->list[index].list = list_insert_front(hashmap->list[index].list, data, destroy_data);

    return hashmap;
}

struct link_list_node *hashmap_find(struct hashmap *hashmap, void *data, int (*comparasion_function)(void *, void *))
{
    size_t index = hashmap->hash_function(data);
    struct link_list_node *cur_list_node = hashmap->list[index].list->first_node;
    while (cur_list_node != NULL)
    {
        if(comparasion_function(data, cur_list_node->data))
        {
            return cur_list_node;
        }
        cur_list_node = cur_list_node->next;
    }
    return NULL;
}

void hashmap_destroy(struct hashmap *hashmap)
{
    size_t size = hashmap->size;
    for(size_t i = 0; i < size; i++)
    {
        list_destroy(hashmap->list[i].list);
    }
    free(hashmap->list);
    free(hashmap);
}