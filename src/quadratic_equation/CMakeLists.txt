add_library(quadratic_equation quadratic_equation.c)

target_include_directories(quadratic_equation PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(quadratic_equation  PRIVATE 
                    m
                    utils)