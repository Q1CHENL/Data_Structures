#include <stddef.h>  // For size_t

/**
 * Represents a single list entry.
 **/
typedef struct ListBody {  // Use a typedef, so we don not have to write 'struct ListBody' every time.
    /**
     * Points to the next list element, or NULL if there is none.
     **/
    struct ListBody* next;
    int val;
} ListBody;

/**
 * The head of the list.
 **/
typedef struct ListHead {  // Use a typedef, so we don not have to write 'struct ListHead' every time.
    /**
     * Points to the first list element, or NULL if there is none.
     **/
    struct ListBody* next;
} ListHead;

/**
 * Adds a new 'ListBody' to the given list ('head') with 'val' as value.
 **/
void insert(int val, struct ListHead* head);

/**
 * Removes all occurrences of the given 'val' from the list ('head').
 **/
void remove_val(int val, struct ListHead* head);

/**
 * Removes this specific list entry from the list ('head').
 **/
void remove_entry(struct ListBody* entry, struct ListHead* head);

/**
 * Clears the list and removes all entries.
 * Do not free the 'head'.
 **/
void clear_head(struct ListHead* head);

/**
 * Clears the list and removes all entries.
 * Also frees the given 'entry' and sets it to NULL.
 **/
void clear_entry(struct ListBody** entry);

/**
 * Returns the number of elements in the list.
 **/
size_t size(struct ListHead* head);

/**
 * Returns the count of how many list entries have the same value as 'val'.
 **/
size_t count(int val, struct ListHead* head);

/**
 * Prints the list values, seperated by a ','.
 * Example output: 2,3,6,2,7,42,5
 * Hint: Do not forget the '\n' at the end when using printf(...) ;)
 **/
void print(struct ListHead* head);
