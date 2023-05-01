rem the following command uses 7z program to extract the code and readme.txt
7z.exe e *.zip *.h *.c *.txt -r
echo q1 > test_result.txt 
gcc mystring.c mystring_main.c -o q1.exe
q1.exe >> test_result.txt

echo q2 >> test_result.txt 
gcc mystring.c myword.c myword_main.c -o q2.exe
q2.exe >> test_result.txt

fc test_result.txt test_solution.txt > test_report.txt
fc word_report.txt word_solution.txt >> test_report.txt