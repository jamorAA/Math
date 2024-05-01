#include "s21_math.h"

long double s21_floor(double x) {
  long double result;
  result = (x == (long long int)x) ? x
           : (x < 0)               ? (long long int)x - 1
                                   : (long long int)x;
  return result;
}
