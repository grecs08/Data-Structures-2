/*
-------------------------------------
File:    stack.h
Project: grec2740_a06
file description
-------------------------------------
Author:  your name here
ID:      your ID here
Email:   your Laurier email here
Version  2023-03-01
-------------------------------------
 */
#ifndef STACK_H
#define STACK_H

#include "common.h"

typedef struct stack {
	int height;
	NODE *top;
} STACK;

void push(STACK *sp, NODE *np);
NODE *pop(STACK *sp);
void clean_stack(STACK *sp);

#endif
