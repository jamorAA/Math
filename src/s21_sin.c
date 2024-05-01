#include "s21_math.h"

long double s21_sin(double x) {
  long double result = 0;
  if (x == S21_INF || x == S21_NINF) {
    result = S21_NAN;
  } else {
    while (x > S21_PI) {
      x = x - 2 * S21_PI;
    }
    while (x < -S21_PI) {
      x = x + 2 * S21_PI;
    }
    result = x;

    long double temp = x;
    for (int i = 1; s21_fabs(temp) > S21_EPS; i++) {
      temp = temp * (-1) * s21_pow(x, 2) / (2 * i * (2 * i + 1));
      result += temp;
    }
  }
  return result;
}
