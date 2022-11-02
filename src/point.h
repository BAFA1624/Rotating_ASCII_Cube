#ifndef POINT_H
#define POINT_H

#include <math.h>

typedef struct POINT_T
{
    double x;
    double y;
    double z;
} point_t;

typedef struct POINT_F_T
{
    float x;
    float y;
    float z;
} point_f_t;

double
distance( const point_t * const a, const point_t * const b );
float
distance_f( const point_f_t * const a, const point_f_t * const b );

void
print_point( const point_t * const p );
void
print_point_f( const point_f_t * const p );

void
set_point( point_t * const p, const double x, const double y, const double z );
void
set_point_f( point_f_t * const p, const float x, const float y, const float z );

void
translate_point( point_t * const p, const double dx, const double dy,
                 const double dz );

void
translate_point_f( point_f_t * const p, const float dx, const float dy,
                   const float dz );

#endif
