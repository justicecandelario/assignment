#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

/*
This program implements a simple 'List' structure and some related functions
which can be used to manipulate it.  The List represents a variable sized array
that you can add elements to, or remove elements from.
First fill in the 'List' structure
You should implement the functions in this order:
1. makeList
2. resizeList
3. pushList
4. popList
5. getList
6. setList
7. sumList
8. freeList
Roughly, each comment can be converted to one or two lines of code that you
need.
Note that the test is not exhaustive and only tests basic functionality.
*/

typedef struct List {
    // (start) int*: The pointer to an integer array
    int *start;
    // (len) int: Length of the list, i.e. the number of valid elements
    int len;
    // (maxlen) int: The maximum number of elements that can currently be stored
    int maxlen;
} List;

List* makeList() {
    // Create a pointer to a new List structure using malloc
    List *list_return = malloc(sizeof(List));
    // Check for out of memory error
    // Initialize length and maxlength
    // Set the len
    list_return -> len = 0; 
    // Set the maxlen (start at 2)
    list_return -> maxlen = 2; 
    // Create a pointer to a new integer array of size maxlen (using malloc)
    // Set the start equal to that pointer
    list_return -> start = malloc(sizeof(int)*(list_return->maxlen)); 
    // Check for out of memory error
    // Return the list pointer
    return list_return; 
}

/* Resize the list to a new maximum length */
void resizeList(List *list, int size) {
    // Assert that the size is greater than the current length
    // Reallocate the array with more space
    // Change the maxlen to the new maximum length
    if (size > list->) {
        realloc(list->start, size);
        list->
    }
}

/* Add 'value' to the end of the list */
void pushList(List *list, int value) {
    // If not enough space, resize the list to two times its current size
    if (list->len == list->maxlen) {
        resizeList(list, list->maxlen*2);
    }
    // Add the value to the end of the list
    *(list->start + list->len) = value; 
    // Increment the len by 1
    list -> len++; 
}

/* Remove and return the last element of the list */
int popList(List *list) {
    // Assert the list has len greater than 0
    if (list->len <= 0){
        return 0; 
    }
    // Decrement the length by 1
    list->len--;
    // Get the last value in the list
    int last_value = *(list->start + list->len);
    // If the list size is now less than half its current maximum length,
    if (list -> len < (list ->maxlen/2)) {
        resizeList(list, list->maxlen/2));
    }
    // resize the list to half its current maximum length
    // Return the last value
    return last_value; 
}

int getList(List *list, int index) {
    // Assert index is greater than 0 and less than the list len
    if (index > 0 && index < list->len){
        return *(list->start + index); 
    }
    // Get the element at position 'index' in the list
}

void setList(List *list, int index, int value) {
    // Assert index is greater than 0 and less than the list len
    if (index > 0)
    // Set the element at position 'index' to 'value'
}

int sumList(List *list) {
    // Return the sum of all valid elements
    int sum = 0;
    for (int i = 0; i < list->; i+=) {
        sum += list -> start[i];
    }
    return sum; 
    
}

void freeList(List *list) {
    // Free the array space
    free(list->start);
    free(list); 
    // Free the list space
}

int main() {
    List *list = makeList();
    pushList(list, 1);
    pushList(list, 2);
    pushList(list, 3);
    assert(sumList(list) == 6);
    popList(list);
    popList(list);
    popList(list);
    for (int n = 0; n < 100; n++) {
        pushList(list, n);
        assert(getList(list, n) == n);
    }
    for (int n = 99; n >= 0; n--) {
        int m = popList(list);
        assert(m == n);
    }
    freeList(list);
}
