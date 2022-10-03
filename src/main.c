#include <math.h>
#include <stdlib.h>
#include <stdint.h>

#include <stdio.h>

#include "transform.h"

typedef struct DATA_STORE {
    double* xdata;
    double* zdata;
    uint32_t n_vals;
} data_t;

void delete_data(data_t* const data) {
    free(data->xdata);
    free(data->zdata);
    data->n_vals = 0;
}

void write_data(
        const char* const filename,
        const data_t* const data
        ) {
    FILE* fp = fopen(filename, "w");

    fprintf(fp, "x,z\n");
    for (uint32_t i = 0; i < data->n_vals; ++i) {
        fprintf(fp, "%.10lf, %.10lf\n", data->xdata[i], data->zdata[i]);
    }

    fclose(fp);
}

data_t gen_data(
        point_t* const start_point,
        const double r_start, const double r_end,
        const uint32_t n_vals,
        void (*f)(point_t* const, const double)
        ) {
    data_t storage;

    storage.xdata = (double*)malloc(n_vals * sizeof(double));
    storage.zdata = (double*)malloc(n_vals * sizeof(double));
    storage.n_vals = n_vals;

    const double interval = (r_end - r_start) / n_vals;
    for (uint32_t i = 0; i < n_vals; ++i) {
        storage.xdata[i] = start_point->x;
        storage.zdata[i] = start_point->z;

        f(start_point, interval);
    }

    return storage;
}

int main() {

    // Clear screen
    printf("\x1b[2j");

    point_t p = { 0, 1, 1 };

    print_point(&p);

    p = rotate_x(&p, M_PI_2);

    print_point(&p);

    return 0;
}
