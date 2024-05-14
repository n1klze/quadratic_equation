#ifndef TEST_HANDLER_H
#define TEST_HANDLER_H

#include <stdio.h>

void __handler__init_testing();
void __handler_update_test_count();
void __handler_sum_up();
void __handler_assert_true(int condition, const char *condition_str);

#define ASSERT_TRUE(condition) \
    __handler_assert_true(condition, #condition);

#define ASSERT_EQUAL(expected, actual, qualifier) do \
{                                                    \
    ASSERT_TRUE(expected == actual);                 \
    if (expected != actual)                          \
        printf("\texpected: " qualifier              \
               ", actual: " qualifier                \
               "\n",                                 \
               expected, actual);                    \
} while (0)

#endif  //TEST_HANDLER_H
