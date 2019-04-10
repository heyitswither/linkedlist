#include <stdio.h>
#include "list.h"

int main(void) {
    struct list list = EMPTY_LIST;
    struct list *curr;

    list_set(&list, 0, 0);

    for (u_int64_t i = 0; i < 0xa; i++) {
        printf("%p ", (void *) i);
        list_append(&list, (void *) i);
    }

    printf("\n");

    list_remove(&list, 0);

    printf("%d, ", list_size(&list));
    printf("%p\n", list_get_last(&list));

    list_for_each(list, curr)
        printf("%p ", curr->data);

    printf("\n");

    list_clear(&list);

    return 0;
}
