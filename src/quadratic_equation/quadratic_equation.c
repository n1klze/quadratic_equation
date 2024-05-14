#include "quadratic_equation.h"

#include <errno.h>
#include <math.h>

#include "utils.h"

//bx + c = 0
solution_t solve_linear(double b, double c) {
    solution_t result;

    if (doublecmp(b, 0) == 0) {
        result.nroots = (doublecmp(c, 0) == 0) ? INF_ROOTS : NO_ROOTS;
        return result;
    }

    result.nroots = SINGLE_ROOT;
    result.roots[0] = -c / b;

    return result;
}


// ax^2 + bx + c = 0
solution_t solve_equation(double a, double b, double c) {
    solution_t result;

    if (!isfinite(a) || !isfinite(b) || !isfinite(c)) {
        errno = EINVAL;
    }

    if (doublecmp(a, 0) == 0) 
        return solve_linear(b, c);

    double discriminant = b * b - 4 * a * c;
    int discriminant_sign = doublecmp(discriminant, 0);

    if (discriminant_sign < 0) {
        result.nroots = NO_ROOTS;
    } else if (discriminant_sign == 0) {
        result.roots[0] = -b / (2 * a);
        result.nroots = SINGLE_ROOT;
    } else {
        double d_sqrt = sqrt(discriminant);
        result.roots[0] = (-b - d_sqrt) / (2 * a);
        result.roots[1] = (-b + d_sqrt) / (2 * a);
        result.nroots = TWO_ROOTS;
    }

    return result;
}
