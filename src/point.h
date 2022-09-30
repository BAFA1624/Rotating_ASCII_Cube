#ifndef POINT_H
#define POINT_H

#include <math.h>

typedef struct POINT_T {
    double x;
    double y;
    double z;
} point_t;

typedef struct POINT_F_T {
    float x;
    float y;
    float z;
} point_f_t;

double distance(const point_t* const a, const point_t* const b);
float distance_f(const point_f_t* const a, const point_f_t* const b);

void print_point(const point_t* const p);
void print_point_f(const point_f_t* const p);

#endif
