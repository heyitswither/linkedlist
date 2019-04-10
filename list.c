#include <stdlib.h>
#include "list.h"

// return number of elements in list
int list_size(struct list *head) {
    int i = 0;
    struct list *curr;
    if (head == NULL) return 0;
    list_for_each(*head, curr)
        i++;
    return i;
}

// get value at index
// return value, NULL if error
void *list_get(struct list *head, int index) {
    int i = 0;
    struct list *curr;
    if (head == NULL) return NULL;
    list_for_each(*head, curr) {
        if (i == index)
            return curr->data;
        i++;
    }
    return NULL;
}

// set value at index
// return status
int list_set(struct list *head, int index, void *data) {
    int i = 0;
    struct list *curr;
    if (head == NULL) return 0;
    list_for_each(*head, curr) {
        if (i == index) {
            curr->data = data;
            return 1;
        }
        i++;
    }
    return 0;
}

// insert value after head
// return status
int list_insert(struct list *head, void *data) {
    struct list *new = malloc(sizeof(struct list));
    if (new == NULL) return 0;
    if (head == NULL) return 0;
    new->data = data;
    new->next = head->next;
    head->next = new;
    return 1;
}

// insert value at end
// return status
int list_append(struct list *head, void *data) {
    struct list *curr;
    if (head == NULL) return 0;
    _list_get_last(*head, curr);
    return list_insert(curr, data);
}

// remove element
// return status
int list_remove(struct list *head, int index) {
    int i = 0;
    struct list *curr, *prev = NULL;
    if (head == NULL) return 0;
    if (index == 0) {
        if (head->next == NULL) {
            // first and only element
            head->data = NULL;
            return 1;
        }
        // first element with one after, move next data into current
        head->data = ((struct list *) head->next)->data;
        head->next = ((struct list *) head->next)->next;
        return 1;
    }
    prev = head;
    list_for_each(*head, curr) {
        if (i == index) break;
        i++;
        prev = curr;
    }
    if (prev == NULL) return 0;
    prev->next = curr->next;
    free(curr);
    return 1;
}

// clear list, remove all but head
// return status
int list_clear(struct list *head) {
    int size;
    if (head == NULL) return 0;
    size = list_size(head);
    for (int i = size - 1; i >= 0; i--) {
        list_remove(head, i);
    }
    return 1;
}

// return index of element or -1 if not found
int list_index(struct list *head, void *data) {
    int i = 0;
    struct list *curr;
    if (head == NULL) return -1;
    list_for_each(*head, curr) {
        if (curr->data == data) return i;
        i++;
    }
    return -1;
}

// return item at index and remove, default last item
void *list_pop(struct list *head, int index) {
    void *tmp;
    if (head == NULL) return NULL;
    if (index == -1) {
        index = list_size(head) - 1;
    }
    tmp = list_get(head, index);
    list_remove(head, index);
    return tmp;
}

// reverse list
// return status
int list_reverse(struct list *head) {
    // TODO
    return 0;
}

// free all elements in list
// return status
int list_free_all(struct list *head) {
    int size;
    if (head == NULL) return 0;
    size = list_size(head);
    for (int i = size - 1; i >= 0; i--) {
        free(list_get(head, i));
        list_remove(head, i);
    }
    return 1;
}

void *list_get_last(struct list *head) {
    struct list *curr;
    if (head == NULL) return &(struct list) EMPTY_LIST;
    _list_get_last(*head, curr);
    return curr->data;
}
