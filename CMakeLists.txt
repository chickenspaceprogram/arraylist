#  This Source Code Form is subject to the terms of the Mozilla Public
#  License, v. 2.0. If a copy of the MPL was not distributed with this
#  file, You can obtain one at https://mozilla.org/MPL/2.0/.

cmake_minimum_required(VERSION 3.15)
project(arraylist C)

set(ARRAYLIST_HEADER_LIST "${arraylist_SOURCE_DIR}/include/arraylist/arraylist.h")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(arraylist
    arraylist.c
    ${ARRAYLIST_HEADER_LIST}
)

target_include_directories(arraylist PUBLIC "${PROJECT_SOURCE_DIR}/include")

add_executable(TEST-arraylist
    tests/TEST-arraylist.c
)

target_link_libraries(TEST-arraylist arraylist)

add_test(
    NAME arraylist
    COMMAND $<TARGET_FILE:TEST-arraylist>
)


source_group(
    TREE "${PROJECT_SOURCE_DIR}/include"
    PREFIX "Header Files"
    FILES ${ARRAYLIST_HEADER_LIST}
)
