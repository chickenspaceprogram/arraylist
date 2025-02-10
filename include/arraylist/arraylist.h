// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at https://mozilla.org/MPL/2.0/.

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>

typedef struct chicken_space_program_array_list CSPArrayList;

struct chicken_space_program_array_list {
    // fields
    void *data_arr;
    size_t num_elements;
    const size_t element_size;
    size_t space;
};

// vim has autocomplete, you can type this, stop complaining

CSPArrayList CSP_array_list_new(size_t element_size);
int CSP_array_list_push(CSPArrayList *list, void *obj);
int CSP_array_list_pop(CSPArrayList *list, void *buf);
int CSP_array_list_peek(CSPArrayList *list, void *buf);
void CSP_array_list_free(CSPArrayList *list);
void *CSP_array_list_get_array(CSPArrayList *list);
size_t CSP_array_list_get_size(CSPArrayList *list);

#ifdef __cplusplus
}
#endif

