#include <check.h>
#include <locale.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "s21_math.h"

#define BUFF_SIZE 512

START_TEST(abs_1) {
  for (int i = -3; i < 4; i++) {
    ck_assert_int_eq(s21_abs(i), s21_abs(i));
  }
}
END_TEST

START_TEST(acos_1) {
  ck_assert_float_eq(s21_acos(1), acos(1));
  ck_assert_int_eq(s21_acos(S21_NAN), acos(S21_NAN));
  ck_assert_float_eq(s21_acos(0.5), acos(0.5));
  ck_assert_float_eq(s21_acos(-1), acos(-1));
  ck_assert_int_eq(s21_acos(2), acos(2));
  ck_assert_int_eq(s21_acos(-1.2), acos(-1.2));
  ck_assert_int_eq(s21_acos(1.2234), acos(1.2234));
  ck_assert_float_eq(s21_acos(-0.), acos(-0.));
  ck_assert_float_eq(s21_acos(-0.0000000000), acos(-0.0000000000));
}

END_TEST

START_TEST(asin_1) {
  ck_assert_int_eq(s21_asin(-1.2), asin(-1.2));
  ck_assert_int_eq(s21_asin(1.2), asin(1.2));
  ck_assert_int_eq(s21_asin(-1), asin(-1));
  ck_assert_int_eq(s21_asin(1), asin(1));
  ck_assert_float_eq(s21_asin(0.5), asin(0.5));
  ck_assert_float_eq(s21_asin(-0.5), asin(-0.5));
  ck_assert_int_eq(s21_asin(S21_INF), asin(S21_INF));
  ck_assert_int_eq(s21_asin(S21_NAN), asin(S21_NAN));
}
END_TEST

START_TEST(atan_1) {
  ck_assert_float_eq(s21_atan(1.57079632677), atan(1.57079632677));
  ck_assert_int_eq(s21_atan(0), atan(0));
  ck_assert_float_eq(s21_atan(-0.0000000000), atan(-0.0000000000));
  ck_assert_float_eq(s21_atan(-0.0000000007), atan(-0.0000000007));
  ck_assert_float_eq(s21_atan(0.0000000007), atan(0.0000000007));
  ck_assert_int_eq(s21_atan(S21_NAN), atan(S21_NAN));
  ck_assert_int_eq(s21_atan(S21_INF), atan(S21_INF));
  ck_assert_int_eq(s21_atan(S21_NINF), atan(S21_NINF));
  ck_assert_float_eq(s21_atan(-1.0000000000), atan(-1.0000000000));
  ck_assert_float_eq(s21_atan(1.0000000000), atan(1.0000000000));
}
END_TEST

START_TEST(ceil_1) {
  for (double i = -10.3; i < 10; i += 0.157) {
    ck_assert_float_eq(s21_ceil(i), ceil(i));
  }
  ck_assert_ldouble_eq(s21_ceil(-92233720368), ceil(-92233720368));
}
END_TEST

START_TEST(cos_1) {
  float res = 0;
  for (double i = -S21_PI - 1; i <= S21_PI + 1; i += 0.001) {
    ck_assert_float_eq(s21_cos(i), cos(i));
  }
  ck_assert_float_eq(s21_cos(2), cos(2));
  ck_assert_float_eq(s21_cos(1), cos(1));
  res = s21_fabs(s21_cos(S21_PI) - cos(S21_PI));
  ck_assert_float_le(res, 0.0000000000000001);
}
END_TEST

START_TEST(exp_1) {
  for (double i = -0.000000000000001; i <= 0.000000000000001;
       i += 0.00000000000000001)
    ck_assert_float_eq(s21_exp(i), exp(i));
  ck_assert_float_eq(s21_exp(1.7976931348623156e308),
                     exp(1.7976931348623156e308));
  ck_assert_float_eq(s21_exp(0.0000000000000000008),
                     exp(0.0000000000000000008));
  ck_assert_float_eq(s21_exp(S21_EPS - 0.0000000000000000001),
                     exp(S21_EPS - 0.0000000000000000001));
}
END_TEST

START_TEST(fabs_1) {
  for (double i = -1; i < 2; i += 0.01) {
    ck_assert_ldouble_eq(s21_fabs(i), fabs(i));
  }

  ck_assert_ldouble_eq(s21_fabs(-612367.54783), fabs(-612367.54783));
}
END_TEST

START_TEST(floor_1) {
  for (double i = -10.3; i < 10; i += 0.157) {
    ck_assert_ldouble_eq(s21_floor(i), floor(i));
    ck_assert_ldouble_eq(s21_floor(-92233720368), floor(-92233720368));
  }
}
END_TEST
START_TEST(fmod_1) {
  for (double i = -10.; i < 10; i += 1.157457) {
    ck_assert_double_eq(s21_fmod(i * i / i, i), fmod(i * i / i, i));
  }
  ck_assert_int_eq(s21_fmod(10, 0), fmod(10, 0));
}
END_TEST
START_TEST(log_1) {
  for (double i = 0; i < 0.000000000000002; i += 0.000000000000001) {
    ck_assert_float_eq(s21_log(i), log(i));
  }
  ck_assert_int_eq(s21_log(-1), log(-1));
  ck_assert_float_eq(s21_log(12), log(12));
}
END_TEST

START_TEST(pow_1) {
  for (double i = -10; i < 10; i += 1.157457) {
    ck_assert_float_eq(s21_pow(exp(fabs(i)), i), pow(exp(fabs(i)), i));
  }
  ck_assert_float_eq(s21_pow(S21_NINF, S21_INF), pow(S21_NINF, S21_INF));

  ck_assert_float_eq(s21_pow(S21_NINF, S21_NINF), pow(S21_NINF, S21_NINF));
  ck_assert_float_eq(s21_pow(S21_INF, S21_NINF), pow(S21_INF, S21_NINF));
  ck_assert_float_eq(s21_pow(S21_INF, S21_INF), pow(S21_INF, S21_INF));

  ck_assert_float_eq(s21_pow(-0.2, S21_INF), pow(-0.2, S21_INF));
  ck_assert_float_eq(s21_pow(-0.2, S21_NINF), pow(-0.2, S21_NINF));

  ck_assert_float_eq(s21_pow(-1, S21_NINF), pow(-1, S21_NINF));
  ck_assert_float_eq(s21_pow(1, S21_NINF), pow(1, S21_NINF));
  ck_assert_float_eq(s21_pow(-1, S21_INF), pow(-1, S21_INF));
  ck_assert_float_eq(s21_pow(1, S21_INF), pow(1, S21_INF));
  ck_assert_int_eq(s21_pow(-0.0001, 2.1), pow(-0.0001, 2.1));
  ck_assert_int_eq(s21_pow(-0.00000001, 200000000),
                   pow(-0.00000001, 200000000));
}
END_TEST
START_TEST(sin_1) {
  for (double i = -S21_PI - 1; i <= S21_PI + 1; i += 0.01) {
    ck_assert_float_eq_tol(s21_sin(i), sin(i), 1e-10);
  }
  ck_assert_int_eq(s21_sin(S21_INF), sin(S21_INF));
  ck_assert_int_eq(s21_sin(S21_NINF), sin(S21_NINF));
  ck_assert_double_eq(s21_sin(0.0000000000000001), sin(0.0000000000000001));
  ck_assert_double_eq(s21_sin(1), sin(1));
  ck_assert_int_eq(s21_sin(S21_NAN), sin(S21_NAN));
}
END_TEST

START_TEST(sqrt_1) {
  for (double i = .003; i < 10; i += 0.157) {
    ck_assert_float_eq(s21_sqrt(i), sqrt(i));
  }
  ck_assert_float_eq(s21_sqrt(0), sqrt(0));
  ck_assert_int_eq(s21_sqrt(-1), sqrt(-1));
}

START_TEST(tan_1) {
  ck_assert_int_eq(s21_tan(S21_NAN), tan(S21_NAN));
  for (double i = -S21_PI; i <= S21_PI; i += 0.01) {
    ck_assert_float_eq_tol(s21_tan(i), tan(i), 0.0000001);
  }

  double value1 = 0.23;
  ck_assert_int_eq(s21_tan(value1), tan(value1));
  double value2 = 1234567;
  ck_assert_int_eq(s21_tan(value2), tan(value2));
  double value3 = -1234567;
  ck_assert_int_eq(s21_tan(value3), tan(value3));
  for (double i = -100; i < 100; i += 1) {
    ck_assert_int_eq(s21_tan(i), tan(i));
  }
  for (double i = -1; i < 1; i += 0.02) {
    ck_assert_float_eq_tol(s21_tan(i), tan(i), 0.0000001);
  }
}

END_TEST

Suite *suite_math_create(void) {
  Suite *s = suite_create("suite_math");
  TCase *tc = tcase_create("math_tc");
  tcase_add_test(tc, abs_1);
  tcase_add_test(tc, acos_1);
  tcase_add_test(tc, asin_1);
  tcase_add_test(tc, atan_1);
  tcase_add_test(tc, ceil_1);
  tcase_add_test(tc, cos_1);
  tcase_add_test(tc, exp_1);
  tcase_add_test(tc, fabs_1);
  tcase_add_test(tc, floor_1);
  tcase_add_test(tc, fmod_1);
  tcase_add_test(tc, log_1);
  tcase_add_test(tc, pow_1);
  tcase_add_test(tc, sin_1);
  tcase_add_test(tc, sqrt_1);
  tcase_add_test(tc, tan_1);
  suite_add_tcase(s, tc);
  return s;
}

int main(void) {
  setlocale(LC_ALL, "US");
  int nf;
  Suite *s1;
  SRunner *sr;
  s1 = suite_math_create();
  sr = srunner_create(s1);

  srunner_run_all(sr, CK_NORMAL);

  nf = srunner_ntests_failed(sr);
  srunner_free(sr);
  return nf == 0 ? 0 : 1;
}