/*
-------------------------------------
File:    expression_symbol.h
Project: grec2740_a09
file description
-------------------------------------
Author:  your name here
ID:      your ID here
Email:   your Laurier email here
Version  2023-03-29
-------------------------------------
 */
#ifndef EXPRESSION_SYMBOL_H
#define EXPRESSION_SYMBOL_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "common.h"
#include "queue.h"
#include "stack.h"
#include "hash.h"

/* Convert symbolic infix expression to postfix expression, output in queue format */
QUEUE infix_to_postfix_symbol(char *infixstr, HASHTABLE *ht);

/* evaluate symbolic infix expression */
int evaluate_infix_symbol(char *infixstr, HASHTABLE *ht);

int evaluate_postfix(QUEUE queue);

#endif

