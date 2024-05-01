#include "s21_math.h"
long double s21_tan(double x) {
  long double result = 1;
  result = (long double)(double)s21_sin(x) / (double)s21_cos(x);

  return result;
}
