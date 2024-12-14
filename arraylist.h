/*
  This Source Code Form is subject to the terms of the Mozilla Public
  License, v. 2.0. If a copy of the MPL was not distributed with this
  file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/

#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <stddef.h>

typedef struct array_list ArrayList;

// apologies for the function pointers, OOP was natural here
struct array_list {
    // fields
    void *data_arr;
    size_t num_elements;
    const size_t element_size;
    size_t space;

    // methods
    int (*push)(ArrayList *list, void *obj); // pushes an object onto the stack, returns success/failure code
    int (*pop)(ArrayList *list, void *buf); // copies the top object into `buf`, then pops it off the stack
    int (*peek)(ArrayList *list, void *buf); // copies the top object into `buf`
    void (*free)(ArrayList *list); // frees the stack
    void *(*getArray)(ArrayList *list); // returns a pointer to data_arr
};

ArrayList newArrayList(size_t element_size);

#endif