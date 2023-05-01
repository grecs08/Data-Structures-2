/*
-------------------------------------
File:    factorial.c
Project: grec2740_a01
 Reads a positive integer n from the command line argument, computes and prints the factorials n!.
-------------------------------------
 Author:  Andrew Greco
 ID:      210422740
 Email:   grec2740@mylaurier.ca
Version  2023-01-17
-------------------------------------
 */

#include <stdio.h>
int main(int argc, char *args[]) {
	int n = 0, x, f = 1, is_overflow = 0;

	if (argc > 1) {
		sscanf(args[1], "%d", &n);

		if (n >= 1) {
			for (int i = 1; i <= n; ++i) {
				f *= i;

			}


	     } else {
			printf("%s:invalid\n", args[1]);
		}
	} else {
		printf("argument input:missing\n");
	}
	return 0;
}
