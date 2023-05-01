/*
-------------------------------------
File:    bigint.c
Project: grec2740_a05
file description
-------------------------------------
Author:  your name here
ID:      your ID here
Email:   your Laurier email here
Version  2023-02-17
-------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>
#include "bigint.h"

BIGINT bigint(char *p) {
	BIGINT bn = { 0 };
	if (p == NULL)
		return bn;
	else if (!(*p >= '0' && *p <= '9')) { // not begin with digits
		return bn;
	} else if (*p == '0' && *(p + 1) == '\0') { // just "0"
		insert_end(&bn, new_node(*p - '0'));
		return bn;
	} else {
		while (*p) {
			if (*p >= '0' && *p <= '9') {
				insert_end(&bn, new_node(*p - '0'));
			} else {
				clean(&bn);
				break;
			}
			p++;
		}
		return bn;
	}
}

BIGINT add(BIGINT op1, BIGINT op2) {
	BIGINT result = { 0 };
	int carry = 0;
	NODE *p1 = op1.end;
	NODE *p2 = op2.end;

	while (p1 != NULL || p2 != NULL || carry) {
		int digit1 = p1 != NULL ? p1->data : 0;
		int digit2 = p2 != NULL ? p2->data : 0;
		int sum = digit1 + digit2 + carry;
		carry = sum / 10;
		int digit = sum % 10;
		insert_start(&result, new_node(digit));
		if (p1 != NULL)
			p1 = p1->prev;
		if (p2 != NULL)
			p2 = p2->prev;
	}

	return result;
}

BIGINT Fibonacci(int n) {
	BIGINT prev = bigint("0");
	BIGINT curr = bigint("1");
	BIGINT next = { 0 };

	if (n == 0) {
		return prev;
	} else if (n == 1) {
		return curr;
	} else {
		for (int i = 2; i <= n; i++) {
			next = add(prev, curr);
			prev = curr;
			curr = next;
		}
		return next;
	}
}
