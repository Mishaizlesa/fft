#ifndef COMMON_H
#define COMMON_H

#ifdef USE_OPENMP
#include <omp.h>
#endif

#include <math.h>
#include <stdint.h>
#include <stdlib.h>

#define OWN_2PI 0x1.921fb54442d18p+2
// Complex float data type
typedef struct {
    float re;
    float im;
} cfloat32_t;

#endif // COMMON_H
