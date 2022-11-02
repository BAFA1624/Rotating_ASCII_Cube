#ifndef VECTOR_H
#define VECTOR_H

typedef union VECTOR
{
    struct
    {
        double x;
        double y;
        double z;
    };
    struct
    {
        double a;
        double b;
        double c;
    };
    struct
    {
        double i;
        double j;
        double k;
    };
} vector_t;

typedef union VECTOR_F
{
    struct
    {
        float x;
        float y;
        float z;
    };
    struct
    {
        float a;
        float b;
        float c;
    };
    struct
    {
        float i;
        float j;
        float k;
    };
} vector_f_t;

#endif
