// file: lecture_06/example.h
//

// make sure definitions are only made once
//
#ifndef ISIP_EXAMPLE
#define ISIP_EXAMPLE

// system include files
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// define my favorite number
//
#define JOES_NUMBER (float)2.727273e+01
#define MAX_LINE (long) 9999999

// Function definitions
//
bool ece1111_allocate(float** array, long num_channels, long N);

bool ece_1111_compute_sin(float* array, long N, float freq, float fsamp,float amp, float phase);

bool ece1111_deallocate(float** array, long num_channels, long N);
// end of include file
//
#endif
