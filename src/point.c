#include <stdio.h>
#include "point.h"

double distance(const point_t* const a, const point_t* const b) {
    return sqrt(pow(a->x - b->x, 2) + pow(a->y - b->y, 2) + pow(a->z - b->z, 2));
}
float distance_f(const point_f_t* const a, const point_f_t* const b) {
    return sqrtf(powf(a->x - b->x, 2) + powf(a->y - b->y, 2) + powf(a->z - b->z, 2));
}

void print_point(const point_t* const p) {
    printf("{ %lf, %lf, %lf }", p->x, p->y, p->z);
}
void print_point_f(const point_f_t* const p) {
    printf("{ %f, %f, %f }", p->x, p->y, p->z);
}

