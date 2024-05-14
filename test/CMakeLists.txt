add_executable(test test.c)

target_include_directories(test PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(test PRIVATE
                      quadratic_equation
                      testutils)
