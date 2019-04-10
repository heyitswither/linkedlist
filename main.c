#include <stdio.h>
#include "list.h"

int main(void) {
    // create empty list
    struct list list = EMPTY_LIST;
    struct list *curr;

    printf("list created: %p\n", &list);
    // set index 0 to known value
    printf("set list[0] = 0xff\n");
    list_set(&list, 0, (void *) 0xff);
    // verify value
    printf("get list[0] = %p\n", list_get(&list, 0));

    // append [0x0, 0xa) to list
    printf("populate list with [0x0, 0xa)\n");
    for (u_int64_t i = 0; i < 0xa; i++) {
        printf("%p ", (void *) i);
        list_append(&list, (void *) i);
    }

    printf("\n");

    // remove index 0 (0xff)
    list_remove(&list, 0);

    printf("list size: %d\n", list_size(&list));
    printf("list_get_last: %p\n", list_get_last(&list));

    // print all values
    printf("print all values\n");
    list_for_each(list, curr)
        printf("%p ", curr->data);

    printf("\n");

    printf("insert 0xbad at 1\n");

    list_insert(&list, (void *) 0xbad);

    printf("get list[1] = %p\n", list_get(&list, 1));

    printf("index of 0xbad: %d\n", list_index(&list, (void *) 0xbad));

    printf("pop: %p\n", list_pop(&list, -1));

    list_for_each(list, curr)
        printf("%p ", curr->data);

    printf("\n");

    list_clear(&list);

    printf("cleared list.data: %p, list.next: %p\n", list.data, list.next);

    //TODO: free_all

    return 0;
}
