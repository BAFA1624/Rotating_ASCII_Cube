#include "transform.h"

point_t
rotate_x( const point_t * const p, const double theta ) {
    const double s = sin( theta );
    const double c = cos( theta );
    point_t result = { p->x, p->y * c - ( p->z * s ), p->z * c + p->y * s };
    return result;
}
void
i_rotate_x( point_t * const p, const double theta ) {
    const double s     = sin( theta );
    const double c     = cos( theta );
    const double y_tmp = p->y;
    const double z_tmp = p->z;
    p->y               = y_tmp * c - ( z_tmp * s );
    p->z               = z_tmp * c + y_tmp * s;
}

point_t
rotate_y( const point_t * const p, const double theta ) {
    const double s = sin( theta );
    const double c = cos( theta );
    point_t result = { p->x * c + p->z * s, p->y, p->z * c - p->x * s };
    return result;
}
void
i_rotate_y( point_t * const p, const double theta ) {
    const double s     = sin( theta );
    const double c     = cos( theta );
    const double x_tmp = p->x;
    const double z_tmp = p->z;
    p->x               = x_tmp * c + z_tmp * s;
    p->z               = z_tmp * c - ( x_tmp * s );
}

point_t
rotate_z( const point_t * const p, const double theta ) {
    const double s = sin( theta );
    const double c = cos( theta );
    point_t result = { p->x * c - p->y * s, p->x * s + p->y * c, p->z };
    return result;
}
void
i_rotate_z( point_t * const p, const double theta ) {
    const double s     = sin( theta );
    const double c     = cos( theta );
    const double x_tmp = p->x;
    const double y_tmp = p->y;
    p->x               = x_tmp * c - y_tmp * s;
    p->y               = x_tmp * s + y_tmp * c;
}

point_f_t
rotate_f_x( const point_f_t * const p, const float theta ) {
    const float s    = sinf( theta );
    const float c    = cosf( theta );
    point_f_t result = { p->x, p->y * c - ( p->z * s ), p->z * c + p->y * s };
    return result;
}
void
i_rotate_f_x( point_f_t * const p, const float theta ) {
    const float s     = sinf( theta );
    const float c     = cosf( theta );
    const float y_tmp = p->y;
    const float z_tmp = p->z;
    p->y              = y_tmp * c - ( z_tmp * s );
    p->z              = z_tmp * c + y_tmp * s;
}

point_f_t
rotate_f_y( const point_f_t * const p, const float theta ) {
    const float s    = sinf( theta );
    const float c    = cosf( theta );
    point_f_t result = { p->x * c + p->z * s, p->y, p->z * c - p->x * s };
    return result;
}
void
i_rotate_f_y( point_f_t * const p, const float theta ) {
    const float s     = sinf( theta );
    const float c     = cosf( theta );
    const float x_tmp = p->x;
    const float z_tmp = p->z;
    p->x              = x_tmp * c + z_tmp * s;
    p->z              = z_tmp * c - ( x_tmp * s );
}

point_f_t
rotate_f_z( const point_f_t * const p, const float theta ) {
    const float s    = sinf( theta );
    const float c    = cosf( theta );
    point_f_t result = { p->x * c - p->y * s, p->x * s + p->y * c, p->z };
    return result;
}
void
i_rotate_f_z( point_f_t * const p, const float theta ) {
    const float s     = sinf( theta );
    const float c     = cosf( theta );
    const float x_tmp = p->x;
    const float y_tmp = p->y;
    p->x              = x_tmp * c - y_tmp * s;
    p->y              = x_tmp * s + y_tmp * c;
}

point_t
rotate( const point_t * const p, const double Rx, const double Ry,
        const double Rz ) {
    const double sx = sin( Rx );
    const double cx = cos( Rx );
    const double sy = sin( Ry );
    const double cy = cos( Ry );
    const double sz = sin( Rz );
    const double cz = cos( Rz );

    point_t result = { ( p->x * cy * cz ) - ( p->y * cy * sz ) + ( p->z * sy ),
                       ( p->x * ( sx * sy * cz + cx * sz ) )
                           + ( p->y * ( cx * cz - sx * sy * sz ) )
                           - ( p->z * sx * cy ),
                       ( p->x * ( sx * sz - cx * sy * cz ) )
                           + ( p->y * ( cx * sy * sz + sx * cz ) )
                           + ( p->z * cx * cy ) };
    return result;
}
point_f_t
rotate_f( const point_f_t * const p, const float Rx, const float Ry,
          const float Rz ) {
    const float sx = sinf( Rx );
    const float cx = cosf( Rx );
    const float sy = sinf( Ry );
    const float cy = cosf( Ry );
    const float sz = sinf( Rz );
    const float cz = cosf( Rz );

    point_f_t result = {
        ( p->x * cy * cz ) - ( p->y * cy * sz ) + ( p->z * sy ),
        ( p->x * ( sx * sy * cz + cx * sz ) )
            + ( p->y * ( cx * cz - sx * sy * sz ) ) - ( p->z * sx * cy ),
        ( p->x * ( sx * sz - cx * sy * cz ) )
            + ( p->y * ( cx * sy * sz + sx * cz ) ) + ( p->z * cx * cy )
    };
    return result;
}

// void translate(point_t* const p, const vector_t* const v) {}

// TODO: Remove this func
//       Added to brute-force suppress -lm unused warning
double
dummy_func( double x, double y ) {
    return pow( x, y );
}

