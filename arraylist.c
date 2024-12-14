/*
  This Source Code Form is subject to the terms of the Mozilla Public
  License, v. 2.0. If a copy of the MPL was not distributed with this
  file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/

#include <stdlib.h>
#include <string.h>
#include "arraylist.h"

#define MIN_STACK_SIZE 16
#define STACK_REDUCE_TRIGGER 4 // stack will realloc() when num_elements < space / STACK_REDUCE_TRIGGER && space > MIN_STACK_SIZE
#define STACK_REDUCE_MULTIPLIER 2 // stack will be reduced to a size of space / STACK_REDUCE_MULTIPLIER when necessary
#define STACK_GROW_MULTIPLIER 2 // stack will grow to a size of space * STACK_GROW_MULTIPLIER when necessary

/* Public */
int push(ArrayList *list, void *obj);
int pop(ArrayList *list, void *buf);
int peek(ArrayList *list, void *buf);
void freeArrayList(ArrayList *list);
void *getArray(ArrayList *list);
size_t getSize(ArrayList *list);

/* Private */
int reallocArrayList(ArrayList *list, size_t new_size); // new_size is a number of elements, not a size in bytes!



/* Constructor */
ArrayList newArrayList(size_t element_size) {
    ArrayList new = {
        .data_arr = NULL,
        .num_elements = 0,
        .element_size = element_size,
        .space = MIN_STACK_SIZE, // number of elements, not number of bytes
        .push = &push,
        .pop =  &pop,
        .peek = &peek,
        .free = &freeArrayList,
        .getArray = &getArray,
	.getSize = &getSize
    };
    new.data_arr = malloc(new.element_size * new.space); // user must check this for NULL
    return new;
}

/* Public */

int push(ArrayList *list, void *obj) {
    if (list->num_elements >= list->space) {
        if (reallocArrayList(list, list->space * STACK_GROW_MULTIPLIER) == -1) {
            return -1;
        }
    }

    memcpy((char *)list->data_arr + list->num_elements * list->element_size, obj, list->element_size);
    ++(list->num_elements);
    return 0;
}

int pop(ArrayList *list, void *buf) {

    if (list->peek(list, buf) == -1) {
        return -1;
    }
    
    --(list->num_elements);
    if ((list->num_elements < list->space / STACK_REDUCE_TRIGGER) && list->space > MIN_STACK_SIZE) {
        return reallocArrayList(list, list->space / STACK_REDUCE_MULTIPLIER);
    }
    return 0;
}

int peek(ArrayList *list, void *buf) {
    if (list->num_elements == 0) {
        return -1;
    }
    memcpy(buf, (char *)list->data_arr + (list->num_elements - 1) * list->element_size, list->element_size);
    return 0;
}

void freeArrayList(ArrayList *list) {
    free(list->data_arr);
    list->data_arr = NULL;
    list->space = 0;
    list->num_elements = 0;
}

inline void *getArray(ArrayList *list) {
    return list->data_arr;
}

size_t getSize(ArrayList *list) {
    return list->num_elements;
}

/* Private */
int reallocArrayList(ArrayList *list, size_t new_size) {

    if (list->num_elements > list->space) {
        return -1;
    }

    void *new_ptr = realloc(list->data_arr, new_size * list->element_size);

    // checking for memory allocation issues
    if (new_ptr == NULL) {
        list->free(list);
        return -1;
    }

    list->data_arr = new_ptr;
    list->space = new_size;
    return 0;
}
