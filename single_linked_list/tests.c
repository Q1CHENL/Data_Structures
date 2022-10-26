#include "list.h"
#include <stdio.h>  // For printf()
#include <stdlib.h>  // For EXIT_SUCCESS

int main() {
    struct ListHead head;
    head.next = NULL;
    insert(1, &head);
    insert(2, &head);
    insert(3, &head);
    insert(4, &head);
    insert(5, &head);
    print(&head);
    printf("\n");
    remove_val(1, &head);
    remove_val(4, &head);
    insert(3, &head);
    print(&head);
    printf("\nnumber of entities that val==3: %zu\n", count(3, &head));
    printf("\n");
    ListBody *body = head.next;
    remove_entry(body, &head);
    print(&head);
    //do not name size, cuz compiler would think that I am calling a integer
    int count = size(&head);
    printf("\nlist count after all operations: %d\n", count);
    clear_head(&head);
    int clear_count = size(&head);
    printf("\nlist count after all clear: %d\n", clear_count);
    //remove_entry(head.next,  &head);
    //print(&head);
    // Do magic ╰( ͡° ͜ʖ ͡° )つ──☆*:・ﾟ and implement your test cases here.

    printf("SUCCESS!\n");
    return EXIT_SUCCESS;  // Same as "return 0;"
}
