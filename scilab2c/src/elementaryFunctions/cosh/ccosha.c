/*
**  -*- C -*-
**
** ccosha.c
** Made by  Bruno JOFRET <bruno.jofret@inria.fr>
**
** Started on  Thu Dec  7 14:54:24 2006 jofret
** Last update Fri Jan 19 14:55:22 2007 jofret
**
** Copyright INRIA 2006
*/


#ifndef STDC99
#include "floatComplex.h"
#else
#include <complex.h>
typedef float complex floatComplex;
#endif

floatComplex ccoshs(floatComplex);

void ccosha(floatComplex* x, int strideX, floatComplex* y, int strideY, int size) {
  int i = 0;
  for (i = 0; i < size; ++i) {
    y[i] = ccoshs(x[i]);
  }
}
