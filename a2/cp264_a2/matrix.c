/*
-------------------------------------
File:    matrix.c
Project: grec2740_a02
file description
-------------------------------------
 Author:  Andrew Greco
 ID:      210422740
 Email:   grec2740@mylaurier.ca
Version  2023-01-25
-------------------------------------
 */

#include<stdio.h>
#include "matrix.h"

float vsum(float *v, int n) {
	float sum = 0;
	for (int i = 0; i < n; i++) {
		sum += v[i];
	}
	return sum;
}

float msum(float *m, int n) {
	float sum = 0;
	for (int i = 0; i < n * n; i++) {
		sum += m[i];
	}
	return sum;
}

void multiply_vector(float *m, float *vin, float *vout, int n) {
	int i, j;
	for (i = 0; i < n; i++) {
		vout[i] = 0;
		for (j = 0; j < n; j++) {
			vout[i] += m[i * n + j] * vin[j];
		}
	}
}


void transpose_matrix(float *m1, float *m2, int n) {
for (int i = 0; i < n; i++) {
	for (int j = 0; j < n; j++) {
		m2[j * n + i] = m1[i * n + j];
	}
}
}

void multiply_matrix(float *m1, float *m2, float *m3, int n) {
int i, j, k;
for (i = 0; i < n; i++) {
	for (j = 0; j < n; j++) {
		m3[i * n + j] = 0;
		for (k = 0; k < n; k++) {
			m3[i * n + j] += m1[i * n + k] * m2[k * n + j];
		}
	}
}
}
