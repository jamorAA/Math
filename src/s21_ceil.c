#include "s21_math.h"

long double s21_ceil(double x) {
  long double result;
  if (x == (long long int)x) {
    result = x;
  } else {
    result = (x < 0) ? (long long int)x : (long long int)x + 1;
  }
  return result;
}