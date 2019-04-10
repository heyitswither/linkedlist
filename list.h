#ifndef _LIST_H
#define _LIST_H

struct list {
    void *data;
    void *next;
};

#define EMPTY_LIST { NULL, NULL }

int list_size(struct list *head);
void *list_get(struct list *head, int index);
int list_set(struct list *head, int index, void *data);
int list_insert(struct list *head, void *data);
int list_append(struct list *head, void *data);
int list_remove(struct list *head, int index);
int list_clear(struct list *head);
int list_index(struct list *head, void *data);
void *list_pop(struct list *head, int index);
int list_reverse(struct list *head);

int list_free_all(struct list *head);
void *list_get_last(struct list *head);

#define _list_get_last(head, last) \
    for (last = &head; last->next != NULL; last = last->next)

#define list_for_each(head, pos) \
    for (pos = &head; pos != NULL; pos = pos->next)

#define list_sort(head) // TODO

#endif
