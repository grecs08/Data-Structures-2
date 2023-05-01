rem the following command uses 7z program to extract the code and readme.txt
7z.exe e *.zip *.c *.h *.txt -r

echo q1 > test_result.txt
gcc caseflip.c -o caseflip.exe
caseflip.exe < caseflip_ptest.txt >> test_result.txt

echo q2 >> test_result.txt
gcc factorial.c -o factorial.exe
factorial.exe 5 >> test_result.txt
factorial.exe 12 >> test_result.txt
factorial.exe 13 >> test_result.txt
factorial.exe -5 >> test_result.txt

echo q3 >> test_result.txt
gcc quadratic.c -o quadratic.exe
quadratic.exe 0,1,2 >> test_result.txt
quadratic.exe 1,-4,4 >> test_result.txt
quadratic.exe 1,2,2 >> test_result.txt
quadratic.exe 1,-1,-6 >> test_result.txt
quadratic.exe  >> test_result.txt
quadratic.exe a,b,c >> test_result.txt

fc test_result.txt test_solution.txt > test_report.txt
