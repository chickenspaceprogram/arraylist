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
    ArrayList list = newArrayList(sizeof(char));
    char str[] = "hello world this is a test of an arraylist";
    char temp;
    size_t len = strlen(str);
    for (int i = 0; i < len; ++i) {
        assert(list.push(&list, &(str[i])) != -1);
    }

    assert(list.getSize(&list) == len);

    char *arr = list.getArray(&list);
    for (int i = 0; i < len; ++i) {
        assert(arr[i] == str[i]);
    }

    for (int i = len - 1; i >= 0; --i) {
        assert(list.pop(&list, &temp) != -1);
        assert(temp == str[i]);
    }
    list.free(&list);
}
