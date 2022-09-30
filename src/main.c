#include <math.h>
#include <stdlib.h>

#include <stdio.h>

#include "transform.h"

int main(int argc, char* argv[]) {

    double angle;

    if (argc != 2) {
        angle = M_PI_2;
    }
    else {
        angle = atof(argv[1]) * 2 * M_PI / 360;
    }

    point_t p = { 1, 0, 0 };

    print_point(&p);
    putchar('\n');

    rotate_z(&p, angle);

    print_point(&p);
    putchar('\n');

    return 0;
}
