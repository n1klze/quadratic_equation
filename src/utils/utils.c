#include "utils.h"

#include <math.h>

#define EPS 1e-9

int doublecmp(double a, double b) {
    if (fabs(a - b) < EPS) 
        return 0;
    if (a > b) {
        return 1;
    } else {
        return -1;
    }
}
