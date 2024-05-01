#include "s21_math.h"
long double s21_cos(double x) {
  long double result = 0;
  while (x > S21_PI) {
    x = x - 2 * S21_PI;
  }
  while (x < -S21_PI) {
    x = x + 2 * S21_PI;
  }
  result = s21_sin((S21_PI / 2.) - x);
  return result;
}
