/*
-------------------------------------
File:    bigint.h
Project: grec2740_a05
file description
-------------------------------------
Author:  your name here
ID:      your ID here
Email:   your Laurier email here
Version  2023-02-17
-------------------------------------
 */
#ifndef BIGINT_H
#define BIGINT_H
#include "dllist.h"

typedef DLLIST BIGINT;
BIGINT bigint(char *digitstr);
BIGINT add(BIGINT oprand1, BIGINT oprand2);
BIGINT Fibonacci(int n);

#endif
