#include "s21_math.h"

long double s21_fmod(double x, double y) {
  long double result;
  if (y == 0) {
    result = S21_NAN;
  } else {
    long long int mod = 0;
    mod = x / y;
    result = (long double)x - mod * (long double)y;
  }

  return result;
}
