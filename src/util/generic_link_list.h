#ifndef GENERIC_LINK_LIST_H
#define GENERIC_LINK_LIST_H
#include <stddef.h>
#include <stdlib.h>

struct link_list_node
{
    void *data;
    void (*destroy_data)(void *);
    struct link_list_node *next;
};

struct link_list
{
    size_t size;
    struct link_list_node *first_node;
};

struct link_list *list_init();
struct link_list *list_insert_front(struct link_list *list, void *data, void (*destroy_data)(void *));
struct link_list *list_insert_back(struct link_list *list, void *data, void (*destroy_data)(void *));
struct link_list *list_insert_at(struct link_list *list, void *data, void (*destroy_data)(void *), size_t index);
void *list_get_at(struct link_list *list, size_t index);
void *list_pop_at(struct link_list *list, size_t index);
void list_destroy(struct link_list *list);

#endif /* GENERIC_LINK_LIST_H */