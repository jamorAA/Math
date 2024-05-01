CC=gcc
FLAGS=-Wall -Werror -Wextra -std=c11
FLAG_COV = --coverage
LIBS=-lcheck
TEST_LIBS = -lcheck -lm -lpthread
TEST_FUNC = s21_abs.c s21_acos.c s21_asin.c s21_atan.c s21_ceil.c s21_cos.c s21_log.c s21_exp.c s21_fabs.c s21_floor.c s21_fmod.c s21_pow.c s21_sin.c s21_sqrt.c s21_tan.c
all: gcov_report

s21_math.a:
	$(CC) $(FLAGS) -c $(TEST_FUNC)
	ar rc s21_math.a *.o
	ranlib s21_math.a

test: s21_math.a
	$(CC) $(FLAGS) -c unit_test.c -o unit_test.o 
	$(CC) unit_test.o s21_math.a $(TEST_LIBS) -o s21_math
	./s21_math

gcov_report: test
	$(CC) $(FLAGS) $(FLAG_COV) unit_test.c s21_*.c s21_math.a $(TEST_LIBS) -o gcov_test
	rm -rf u*.gcno
	rm -rf u*.gcda
	rm -rf u*.gcov
	chmod +x *
	./gcov_test
	gcov s21_*.gcda
	rm -rf u*.gcda
	gcovr -b
	gcovr
	gcovr --html-details -o report.html

clean:
	rm -rf s21_math
	rm -rf *.o
	rm -rf *.a
	rm -rf *.gcno
	rm -rf *.gcda
	rm -rf *.gcov
	rm -rf *.info
	rm -rf *.html
	rm -rf *.css
	rm -rf test
	rm -rf gcov_test
style:
	clang-format -style=google -n *.c
	clang-format -style=google -n *.h
	
rebuild: clean all
