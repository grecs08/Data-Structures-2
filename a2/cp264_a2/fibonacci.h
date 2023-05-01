/*
-------------------------------------
File:    fibonacci.h
Project: grec2740_a02
file description
-------------------------------------
Author:  Andrew Greco
ID:      210422740
Email:   grec2740@mylaurier,ca
Version  2023-01-25
-------------------------------------
 */

#ifndef FIBONACCI_H
#define FIBONACCI_H

extern int *la;  // global pointer variable to hold lowest variable address

int recursive_fibonacci(int n) {
  if (&n < la) la = &n;
 if (n==0) return 0;
 if (n==1 || n == 2) return 1;
 return recursive_fibonacci(n-1) + recursive_fibonacci(n-2);
}

int iterative_fibonacci(int n)
{
  if (&n < la) la = &n;   
  int i, a=0, b=1, c;
  if (n == 0) return 0;
  for (i = 2; i <= n; i++) {
	  c = a + b;
	  a = b;
	  b = c;
  }
  return b;
}

#endif