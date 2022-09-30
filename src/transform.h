#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "vector.h"
#include "point.h"

#ifndef M_PI
#    define M_PI 3.14159265358979323846
#endif
#ifndef M_PI_2
#    define M_PI_2 (M_PI / 2)
#endif
#ifndef M_2_PI
#    define M_2_PI (2 / M_PI)
#endif

void rotate_x(point_t* const p, const double theta); // Rotate around the x-axis
void rotate_y(point_t* const p, const double theta); // Rotate around the y-axis
void rotate_z(point_t* const p, const double theta); // Rotate around the z-axis
// Apply general rotation
void rotate(point_t* const p, const double Rx, const double Ry, const double Rz);

//void translate(point_t* const p, const vector_t* const v);

#endif // TRANSFORM_H
