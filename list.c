#include "list.h"
#include <stdio.h>
#include <stdlib.h>

void insert(int val, struct ListHead* head) {
    if(head == NULL) return;
    //have to be freed in remove operations
    ListBody *new_body = malloc(sizeof (ListBody));

    //check if malloc successful done
    if(!new_body) {
        printf("malloc failed!");
        exit(EXIT_FAILURE);
    }
    new_body->next = NULL;
    new_body->val = val;

    if(!(head->next)){
        head->next = new_body;
        return;
    }
    ListBody *itr = head->next;
    while(itr->next){
        itr = itr->next;
    }
    itr->next = new_body;
}

void remove_val(int val, struct ListHead* head) {
    if(head == NULL || head->next == NULL) return;
    ListBody *itr = head->next;
    while(itr->val == val){
        head->next = itr->next;
        free(itr);
        itr = head->next;
    }
    while (itr->next != NULL) {
        if (itr->next->val == val) {
            ListBody *tmp = itr->next;
            itr->next = itr->next->next;
            free(tmp);
            // head, 1, 2, 3, 4, 5
        } else {
            itr = itr->next;
        }
    }
}

void remove_entry(struct ListBody* entry, struct ListHead* head) {
    if (entry == NULL || head == NULL) return;
    ListBody *itr = head->next;
    if (itr == NULL) return;
    if (itr == entry) {
        head->next = itr->next;
        free(itr);
        return;
    }
    while (itr != NULL) {
        if (itr->next == entry) {
            ListBody *tmp = itr->next;
            itr->next = itr->next->next;
            free(tmp);
            return;
        }
        itr = itr->next;
    }
}

void clear_head(struct ListHead* head) {
    ListBody *itr = head->next;
    while (itr != NULL) {
        ListBody *tmp = itr->next;
        free(itr);
        itr = tmp;
    }
    head->next = NULL;
}

void clear_entry(struct ListBody** entry){
/*    //pointer size is 8 (64bit)
    int count = sizeof **entry / sizeof (ListBody);
    for (int i = 0; i < count; ++i) {
        free(entry[i]);
    }*/
}


size_t size(struct ListHead* head){
    if(head == NULL || head->next == NULL) return 0;
    int count = 0;
    ListBody *itr =  head->next;
    while(itr != NULL){
        count++;
        itr = itr->next;
    }
    return count;
}

void print(struct ListHead* head){
    if(head == NULL || head->next == NULL) return;
    printf("%d,", head->next->val);
    ListBody *itr =  head->next->next;
    while(itr != NULL){
        printf("%d,", itr->val);
        itr = itr->next;
    }
}

size_t count(int val, struct ListHead* head) {
    if (head == NULL || head->next == NULL) return 0;
    ListBody *itr = head->next;
    size_t count = 0;
    while (itr != NULL) {
        if (itr->val == val) {
            count++;
        }
        itr = itr->next;
    }
    return count;
}




// Do magic ╰( ͡° ͜ʖ ͡° )つ──☆*:・ﾟ and implement your list here.
