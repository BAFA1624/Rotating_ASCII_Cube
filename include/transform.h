#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "point.h"
#include "vector.h"

#include <math.h>

#ifndef M_PI
    #define M_PI 3.14159265358979323846
#endif
#ifndef M_PI_2
    #define M_PI_2 ( M_PI / 2 )
#endif
#ifndef M_2_PI
    #define M_2_PI ( 2 / M_PI )
#endif

point_t
rotate_x( const point_t * const p,
          const double theta ); // Rotate around the x-axis
point_t
rotate_y( const point_t * const p,
          const double theta ); // Rotate around the y-axis
point_t
rotate_z( const point_t * const p,
          const double theta ); // Rotate around the z-axis
void
i_rotate_x( point_t * const p, const double theta ); // Rotate around the x-axis
void
i_rotate_y( point_t * const p, const double theta ); // Rotate around the y-axis
void
i_rotate_z( point_t * const p, const double theta ); // Rotate around the z-axis

point_f_t
rotate_f_x( const point_f_t * const p,
            const float theta ); // Rotate around the x-axis
point_f_t
rotate_f_y( const point_f_t * const p,
            const float theta ); // Rotate around the y-axis
point_f_t
rotate_f_z( const point_f_t * const p,
            const float theta ); // Rotate around the z-axis
void
i_rotate_f_x( point_f_t * const p,
              const float theta ); // Rotate around the x-axis
void
i_rotate_f_y( point_f_t * const p,
              const float theta ); // Rotate around the y-axis
void
i_rotate_f_z( point_f_t * const p,
              const float theta ); // Rotate around the z-axis

// Apply general rotation
point_t
rotate( const point_t * const p, const double Rx, const double Ry,
        const double Rz );
point_f_t
rotate_f( const point_f_t * const p, const float Rx, const float Ry,
          const float Rz );

// void translate(point_t* const p, const vector_t* const v);

#endif // TRANSFORM_H
