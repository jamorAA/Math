#include "s21_math.h"

long double s21_sqrt(double x) {
  long double left = 0;
  long double right = x;
  long double mid;
  if (x > 0 && x < 1) {
    right = 1;
  }
  mid = (left + right) / 2.;
  while ((mid - left) > S21_EPS) {
    if (mid * mid > x) {
      right = mid;
    } else {
      left = mid;
    }
    mid = (left + right) / 2.;
  }

  return (x < 0) ? S21_NAN : mid;
}
