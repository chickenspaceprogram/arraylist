/*
  This Source Code Form is subject to the terms of the Mozilla Public
  License, v. 2.0. If a copy of the MPL was not distributed with this
  file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/

#include <assert.h>
#include <string.h>
#include <stddef.h>
#include <arraylist/arraylist.h>


int main(void) {
    CSPArrayList list = CSP_array_list_new(sizeof(char));
    char str[] = "hello world this is a test of an arraylist";
    char temp;
    size_t len = strlen(str);
    for (size_t = 0; i < len; ++i) {
        assert(CSP_array_list_push(&list, &(str[i])) != -1);
    }

    assert(CSP_array_list_get_size(&list) == len);

    char *arr = CSP_array_list_get_array(&list);
    for (size_t i = 0; i < len; ++i) {
        assert(arr[i] == str[i]);
    }

    for (int i = len - 1; i >= 0; --i) {
        assert(CSP_array_list_pop(&list, &temp) != -1);
        assert(temp == str[i]);
    }
    CSP_array_list_free(&list);
}
