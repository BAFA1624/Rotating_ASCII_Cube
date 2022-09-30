#include "transform.h"

void rotate_x(point_t* const p, const double theta) {
    p->y = p->y * cos(theta) - (p->z * sin(theta));
    p->z = p->z * cos(theta) + p->y * sin(theta);
}

void rotate_y(point_t* const p, const double theta) {
    p->x = p->x * cos(theta) + p->z * sin(theta);
    p->z = p->z * cos(theta) - (p->x * sin(theta));
}

#include <stdio.h>
void rotate_z(point_t* const p, const double theta) {
    p->x = p->x * cos(theta) - (p->y * sin(theta));
    p->y = p->x * sin(theta) + p->y * cos(theta);
}

//void translate(point_t* const p, const vector_t* const v) {}

