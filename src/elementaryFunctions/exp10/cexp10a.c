/*
**  -*- C -*-
**
** cexp10a.c
** Made by  Bruno JOFRET <bruno.jofret@inria.fr>
**
** Started on  Thu Dec  7 14:54:24 2006 jofret
** Last update Mon Oct 22 09:54:11 2007 bruno
**
** Copyright INRIA 2006
*/

#include "exp10.h"

void cexp10a(floatComplex* x, int size, floatComplex* y) {
  int i = 0;
  for (i = 0; i < size; ++i) {
    y[i] = cexp10s(x[i]);
  }
}