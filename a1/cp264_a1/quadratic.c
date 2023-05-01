/*
-------------------------------------
File:    quadratic.c
Project: grec2740_a01
file description
-------------------------------------
 Author:  Andrew Greco
 ID:      210422740
 Email:   grec2740@mylaurier.ca
Version  2023-01-18
-------------------------------------
 */

#include <stdio.h>
#include <math.h>

#define EPSILON 1e-6 // or #define EPSILON 0.000001

int main(int argc, char* argv[]) {
	float a, b, c, d, x1, x2;

	if (argc < 2) {
		printf("argument input:missing\n");
	} else {
		int n = sscanf(argv[1], "%f,%f,%f", &a, &b, &c);
		if (n != 3) {
			printf("input:invalid\n");
		} else {

			printf("(%f)x^2+(%f)x+(%f)=0 ", a, b, c);

			if (fabs(a) < EPSILON) {
				printf("is not a quadratic equation\n");
			} else {

				// calculate d
				d = b * b - 4 * a * c;

				// handle case where d = 0 (two equal real roots)
				if (d == 0) {
					printf("has two equal real roots: %f\n",
							-b / (2 * a));

					// handle case where d < 0 (two complex roots)
				} else if (d < 0) {
					x1 = -b/(2*a);
					x2 = sqrt(-d)/(2*a);
					printf("has two complex roots: %f + %fi, %f - %fi\n", x1,
							x2, x1, x2);

					// handle case where d > 0 (two distinct real roots)
				} else {
					printf(
							"has two distinct real roots: %f, %f\n",
							(-b + sqrt(d)) / (2 * a), (-b - sqrt(d)) / (2 * a));
				}
				}
			}
		}
		return 0;
	}
