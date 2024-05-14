#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

#include "test_handler.h"
#include "quadratic_equation.h"

#define TEST_CASES_PATH "test/test_cases.txt"

int run_all_tests() {
    FILE  *tests;
    char   buffer[BUFSIZ];
    double roots[2];
    double a, b, c;
    int    nroots;

    tests = fopen(TEST_CASES_PATH, "r");
    if (tests == NULL) {
        perror("fopen");
        return errno;
    }

    __handler__init_testing();

    while (fgets(buffer, sizeof(buffer), tests)) {
        if (sscanf(buffer, "%le %le %le | %d | %le %le", 
                   &a, &b, &c, &nroots, &roots[0], &roots[1])) {
            solution_t ans = solve_equation(a, b, c);
            ASSERT_EQUAL(nroots, ans.nroots, "%d");
            for (int i = 0; i < nroots; ++i)
                ASSERT_EQUAL(roots[i], ans.roots[i], "%le");
            __handler_update_test_count();
        }
    }

    __handler_sum_up();

    fclose(tests);
    return EXIT_SUCCESS;
}

int main() {
    int ret = run_all_tests();

    return ret;
}
