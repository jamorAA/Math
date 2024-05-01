#include <math.h>

#include "s21_math.h"
long double s21_pow(double base, double power) {
  long double result = 1;

  if (base == -S21_INF && power == S21_INF) {
    result = S21_INF;
  } else if ((base < 0) && (base > -1) && (power == S21_INF)) {
    result = 0;
  } else if ((base == S21_INF && power == -S21_INF)) {
    result = 0;
  } else if ((base < 0) && (base > -1) && (power == -S21_INF)) {
    result = S21_INF;
  } else if ((base == 1 || base == -1) &&
             (power == S21_INF || power == -S21_INF)) {
    result = 1;
  } else if ((base == -S21_INF && power == -S21_INF)) {
    result = 0;
  } else if ((base == S21_INF && power == S21_INF)) {
    result = S21_INF;
  } else if ((base < 0) && (base - (int)base != 0) &&
             (power - (int)power != 0)) {
    result = S21_NAN;
  } else if ((base < 0) && ((int)power % 2 != 0) && (power - (int)power == 0)) {
    base = -base;
    result = s21_exp(power * s21_log(base));
    result = -result;
  } else if (power == 0) {
    result = 1;
  } else if ((base < 0) && ((int)power % 2 == 0)) {
    base = -base;
    result = s21_exp(power * s21_log(base));
  } else
    result = s21_exp(power * s21_log(base));

  return result;
}
