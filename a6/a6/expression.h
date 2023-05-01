/*
-------------------------------------
File:    expression.h
Project: grec2740_a06
file description
-------------------------------------
Author:  your name here
ID:      your ID here
Email:   your Laurier email here
Version  2023-03-01
-------------------------------------
 */
#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "common.h"
#include "queue.h"

QUEUE infix_to_postfix(char *infixstr);
int evaluate_postfix(QUEUE queue);
int evaluate_infix(char *infixstr);

#endif
