#ifndef QUADRATIC_EQUATION_H
#define QUADRATIC_EQUATION_H

enum RootsNumber {
    INF_ROOTS   = -1,
    NO_ROOTS    =  0,
    SINGLE_ROOT =  1,
    TWO_ROOTS   =  2
};

typedef struct solution_s {
    enum RootsNumber nroots;
    double roots[2];
} solution_t;

solution_t solve_equation(double a, double b, double c);

#endif //QUADRATIC_EQUATION_H
