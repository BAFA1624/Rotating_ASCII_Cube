#include "point.h"

#include <stdio.h>

double
distance( const point_t * const a, const point_t * const b ) {
    return sqrt( pow( a->x - b->x, 2 ) + pow( a->y - b->y, 2 )
                 + pow( a->z - b->z, 2 ) );
}
float
distance_f( const point_f_t * const a, const point_f_t * const b ) {
    return sqrtf( powf( a->x - b->x, 2 ) + powf( a->y - b->y, 2 )
                  + powf( a->z - b->z, 2 ) );
}

void
print_point( const point_t * const p ) {
    printf( "{ %lf, %lf, %lf }\n", p->x, p->y, p->z );
}
void
print_point_f( const point_f_t * const p ) {
    printf( "{ %f, %f, %f }\n", p->x, p->y, p->z );
}

void
set_point( point_t * const p, const double x, const double y, const double z ) {
    p->x = x;
    p->y = y;
    p->z = z;
}
void
set_point_f( point_f_t * const p, const float x, const float y,
             const float z ) {
    p->x = x;
    p->y = y;
    p->z = z;
}

void
translate_point( point_t * const p, const double dx, const double dy,
                 const double dz ) {
    p->x += dx;
    p->y += dy;
    p->z += dz;
}
void
translate_point_f( point_f_t * const p, const float dx, const float dy,
                   const float dz ) {
    p->x += dx;
    p->y += dy;
    p->z += dz;
}

