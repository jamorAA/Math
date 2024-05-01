#include "s21_math.h"

long double s21_exp(double x) {
  long double result = 1;
  long double temp = 1;
  long double i = 1;
  int flag = 0;
  if (x < 0) {
    x *= -1;
    flag = 1;
  }
  while (s21_fabs(result) > S21_EPS) {
    result = result * (x / i);
    i = i + 1;
    temp = temp + result;
    if (temp > S21_MAX_double) {
      temp = S21_INF;
      break;
    }
  }
  if (flag == 1) {
    if (temp > S21_MAX_double)
      temp = 0;
    else
      temp = 1. / temp;
  }
  return temp > S21_MAX_double ? S21_INF : temp;
}
