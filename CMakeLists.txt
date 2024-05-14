cmake_minimum_required(VERSION 3.10)

set(PROJECT_NAME "quadratic_equation")
set(BINARY_NAME "quadratic_equation")

project("${PROJECT_NAME}" VERSION 1.0)

add_subdirectory(src/utils)

add_subdirectory(src/quadratic_equation)

add_subdirectory(test/utils)

add_subdirectory(test)

install(TARGETS ${BINARY_NAME}
        LIBRARY
        CONFIGURATIONS Release)

if(NOT TARGET check)
    add_custom_target(check
        COMMAND cd ${CMAKE_CURRENT_SOURCE_DIR} && ${CMAKE_CURRENT_BINARY_DIR}/test/test)
endif()
        
#add_executable(main main.c)

#target_include_directories(main PRIVATE
#    ${CMAKE_CURRENT_SOURCE_DIR})

#target_link_libraries(main PRIVATE
#    quadratic_equation)
