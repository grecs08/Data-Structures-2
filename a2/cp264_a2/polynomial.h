/*
-------------------------------------
File:    polynomial.h
Project: grec2740_a02
file description
-------------------------------------
 Author:  Andrew Greco
 ID:      210422740
 Email:   grec2740@mylaurier.ca
Version  2023-01-25
-------------------------------------
 */
#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include<stdio.h>
#include<math.h>

#define EPSILON 1e-6

float horner(float p[], int n, float x) {
	float result = p[0];
	for (int i = 1; i < n; i++)
		result = result * x + p[i];
	return result;

}

// compute the derivative of polynomial p[], and output to d[]
void derivative(float p[], int n, float d[]) {
	for (int i = 0; i < n - 1; i++) {
		d[i] = (n - i - 1) * p[i];
	}
}

// Use Newton's method to find and return a root of polynomial of p[]
float newton(float p[], int n, float x0) {
	float x1;
	float fx0 = horner(p, n, x0);
	float dfx0;
	float dp[n];
	derivative(p, n, dp);
	while (fabs(fx0) > EPSILON) {
		dfx0 = horner(dp, n - 1, x0);
		x1 = x0 - fx0 / dfx0;
		if (fabs(x1 - x0) < EPSILON) {
			return x1;
		}
		x0 = x1;
		fx0 = horner(p, n, x0);
	}
	return x0;
}

#endif
