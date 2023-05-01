JobID: cp264-a2
Name: Andrew Greco
ID: 210422740

Statement: I claim that the enclosed submission is my individual work.

Fill in the self-evaluation in the following evaluation grid.
Symbols:  A - Assignment, Q - Question, T - Task
Field format: [self-evaluation/total marks/marker's evaluation]

For example, you put your self-evaluation, say 2, like [2/2/*]. 
If markers give different evaluation value, say 1, it will show 
[2/2/1] in the marking report. 

Grade_Item_ID [self-evaluation/total/marker-evaluation] Description


Q1 Computing Fibonacci numbers
Q1.1 [3/3/*] recursive_fibonacci()                   
Q1.2 [5/5/*] iterative_fibonacci()                   

Q2 Array & polynomial
Q2.1 [4/4/*] horner()                                
Q2.2 [4/4/*] derivative()                            
Q2.3 [4/4/*] newton()                                

Q3 Vector, Matrix
Q3.1 [2/2/*] vsum(), msum()                          
Q3.2 [2/2/*] transpose_matrix()                      
Q3.3 [3/3/*] multiply_matrix()                       
Q3.4 [3/3/*] multiply_vector()                       

Total: [30/30/*]

Copy and paste the console output of your public test in the following. 
This will help markers to evaluate your program if it fails the marking tests.  

Q1 output:

C:\cp264\workspace\grec2740_a02\src> gcc fibonacci.h fibonacci_main.c -o fibonacci

C:\cp264\workspace\grec2740_a02\src> fibonacci 40
iterative_fibonacci(40):102334155
recursive_fibonacci(40):102334155

C:\cp264\workspace\grec2740_a02\src> fibonacci
**Iterative algorithm measurement**
iterative_fibonacci(40):102334155
high address:6422260
low address:6422208
iterative_fibonacci(40) memory span:52
time_span(iterative_fibonacci(40) for 500000 times):47.0 (ms)

**Recursive algorithm measurement**
recursive_fibonacci(40):102334155
high address:6422260
low address:6420992
recursive_fibonacci(40) memory span:1268
time_span(recursive_fibonacci(40) for 10 times) in (ms):4898.0

**Comparison of recursive and iterative algorithms**
memory_span(recursive_fibonacci(40))/memory_span(iterative_fibonacci(40)):24.4
time_span(recursive_fibonacci(40))/time_span(iterative_fibonacci(40)):5210638.3

Q2 output:

C:\cp264\workspace\grec2740_a02\src> polynomial
p(0.00)=1.00*0.00^3+2.00*0.00^2+3.00*0.00^1+4.00*0.00^0=4.00
p(1.00)=1.00*1.00^3+2.00*1.00^2+3.00*1.00^1+4.00*1.00^0=10.00
p(10.00)=1.00*10.00^3+2.00*10.00^2+3.00*10.00^1+4.00*10.00^0=1234.00
d(0.00)=3.00*0.00^2+4.00*0.00^1+3.00*0.00^0=3.00
d(1.00)=3.00*1.00^2+4.00*1.00^1+3.00*1.00^0=10.00
d(10.00)=3.00*10.00^2+4.00*10.00^1+3.00*10.00^0=343.00
root=-1.65
p(-1.65)=-0.00

Q3 output:

C:\cp264\workspace\grec2740_a02\src> gcc matrix.c matrix_main.c -o matrix

C:\cp264\workspace\grec2740_a02\src> matrix

m1:
1.00  2.00  -1.00
-2.00 0.00  1.00
1.00  -1.00 0.00
msum(m1):1.00

m2=m1':
1.00  -2.00 1.00
2.00  0.00  -1.00
-1.00 1.00  0.00
msum(m2):1.00

m3=m1*m2':
6.00  -3.00 -1.00
-3.00 5.00  -2.00
-1.00 -2.00 2.00
msum(m3):1.00

v1:
1.00  1.00  1.00
vsum(v1):3.00

v2=m1*v1':
2.00  -1.00 0.00
vsum(v2):1.00

