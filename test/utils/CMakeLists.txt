add_library(testutils test_handler.c)

target_include_directories(testutils PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR})
