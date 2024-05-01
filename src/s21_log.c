#include "s21_math.h"

long double s21_log(double x) {
  int ex_pow = 0;
  long double result = 0;
  long double compare = 0;
  if (x < 0) {
    result = S21_NAN;
  } else if (x == 0) {
    result = S21_NINF;
  } else {
    for (; x >= S21_E; x /= S21_E, ex_pow++) continue;
    for (int i = 0; i < 100; i++) {
      compare = result;
      result = compare + 2 * (x - s21_exp(compare)) / (x + s21_exp(compare));
    }
  }
  return result + ex_pow;
}
