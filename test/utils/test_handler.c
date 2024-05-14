#include "test_handler.h"

enum test_status {
    TEST_NOT_STARTED = -1,
    TEST_SUCCESS     =  0,
    TEST_FAILURE     =  1
};

typedef struct tests_counter_s {
    int              total_count;
    int              failure_count;
    enum test_status current_status;
} tests_counter_t;

static tests_counter_t __tests_counter;

void handler__init_testing() {
    __tests_counter.total_count    = 0;
    __tests_counter.failure_count  = 0;
    __tests_counter.current_status = TEST_NOT_STARTED;

    printf("== Running tests ==\n");
}

void handler_update_test_count() {
    ++__tests_counter.total_count;

    if (__tests_counter.current_status == TEST_FAILURE){
        ++__tests_counter.failure_count;
    } else {
        __tests_counter.current_status = TEST_SUCCESS;
    }
}

void handler_sum_up() {
    if (__tests_counter.failure_count) {
        printf(">> Failed %d tests of %d\n",
            __tests_counter.failure_count, 
            __tests_counter.total_count);
    } else {
        printf("=======================\n"
               " All %d tests passed \n"
               "=======================\n",
                __tests_counter.total_count);
    }
}

void __handler_assert_true(int condition, const char *condition_str) {
    if (!condition) {
        printf("FAILED: \'%s\' in test #%d\n", 
            condition_str, __tests_counter.total_count);
        __tests_counter.current_status = TEST_FAILURE;
    }
}
