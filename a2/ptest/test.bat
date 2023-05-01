rem the following command uses 7z program to extract the code and readme.txt
7z.exe e *.zip *.h *.c *.txt -r

rem q1 test
echo q1 > test_result.txt
gcc fibonacci.h fibonacci_main.c -o fibonacci.exe
fibonacci.exe 40 >> test_result.txt

rem q2 test
echo q2 >> test_result.txt
gcc polynomial.h polynomial_main.c -o polynomial
polynomial >> test_result.txt

rem q3 test
echo q3 >> test_result.txt
gcc matrix.c matrix_main.c -o matrix
matrix >> test_result.txt

rem compare test results with solution results
fc test_result.txt test_solution.txt > test_report.txt
