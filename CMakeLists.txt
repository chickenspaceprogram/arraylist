#  This Source Code Form is subject to the terms of the Mozilla Public
#  License, v. 2.0. If a copy of the MPL was not distributed with this
#  file, You can obtain one at https://mozilla.org/MPL/2.0/.

cmake_minimum_required(VERSION 3.15)
project(arraylist-tests C)

add_library(arraylist
    arraylist.c
    arraylist.h
)

add_executable(TEST-arraylist
    tests/TEST-arraylist.c
)

target_link_libraries(TEST-arraylist arraylist)

enable_testing()

add_test(
    NAME arraylist
    COMMAND $<TARGET_FILE:TEST-arraylist>
)

