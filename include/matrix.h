#ifndef MATRIX_H
#define MATRIX_H

#include <stdint.h>

typedef struct TENSOR
{
    int32_t rank;
    int32_t * size;
    void * data;
    // TODO: Some typeinfo goes here.
    //       Maybe data size too.
} tensor_t;

#endif // MATRIX_H
