JobID: cp264-a4
Name: type your name
ID: type your student ID

Statement: I claim that the enclosed submission is my individual work.

Fill in the self-evaluation in the following evaluation grid.
Symbols:  A - Assignment, Q - Question, T - Task
Field format: [self-evaluation/total marks/marker's evaluation]

For example, you put your self-evaluation, say 2, like [2/2/*]. 
If markers give different evaluation value, say 1, it will show 
[2/2/1] in the marking report. 

Grade_Item_ID [self-evaluation/total/marker-evaluation] Description


Q1 Sorting algorithms
Q1.1 [1/1/*] BOOLEAN type                            
Q1.2 [3/3/*] is_sort()                               
Q1.3 [4/4/*] select_sort()                           
Q1.4 [4/4/*] quick_sort()                            

Q2 Record data processing
Q2.1 [1/1/*] RECORD type                             
Q2.2 [1/1/*] STATS type                              
Q2.3 [2/2/*] letter_grade()                          
Q2.4 [3/4/*] import_data()                           
Q2.5 [4/6/*] process_data(),mean,stddev,median       
Q2.6 [2/4/*] report_data()                           

Total: [25/30/*]

Copy and paste the console output of your public test in the following. 
This will help markers to evaluate your program if it fails the marking tests.  

Q1 output:

C:\cp264\workspace\grec2740_a04\src>gcc mysort.c mysort_main.c -o mysort

C:\cp264\workspace\grec2740_a04\src>mysort
Algorithm correctness testing:
a[]:3.0, 1.0, 4.0, 5.0, 2.0, 7.0, 6.0, 9.0, 8.0
is_sorted(a):0
selection sort:1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0
is_sorted(b):1
quick sort:1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0
is_sorted(b):1

C:\cp264\workspace\grec2740_a04\src>mysort time
Algorithm runtime testing:
time_span(selection_sort(10000 numbers) for 10 times)(ms):855.9
time_span(quick_sort(10000 numbers) for 1000 times)(ms):967.0
time_span(selection_sort(10000 numbers))/time_span(quick_sort(10000 numbers)):88.5

Q2 output:

C:\cp264\workspace\grec2740_a04\src>myrecord
stats:value
count:20
mean:77.9
stddev:13.5
median:80.6

name:score,grade
:0.0,F
        :45.1,F
:286970671698114310000000000000000.0,X
e:74.4,B
Sun:67.7,C
Chabot:80.4,A
Giblett:59.1,D
Suglio:85.7,A
Smith:60.1,C
Bodnar:93.6,S
Allison:67.7,C
Koreck:77.4,B
Parr:92.5,S
Lamont:98.1,S
Peters:82.3,A
Wang:98.1,S
Eccles:77.8,B
Pereira:80.3,A
He:85.7,A
Ali:88.0,A

