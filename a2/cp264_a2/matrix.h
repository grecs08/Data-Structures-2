/*
-------------------------------------
File:    matrix.h
Project: grec2740_a02
file description
-------------------------------------
 Author:  Andrew Greco
 ID:      210422740
 Email:   grec2740@mylaurier.ca
Version  2023-01-25
-------------------------------------
 */
#ifndef MATRIX_H_
#define MATRIX_H_

float vsum(float *v, int n);
float msum(float *m, int n);
void multiply_vector(float *m, float *v1, float *v2, int n);
void transpose_matrix(float *m1, float *m2, int n);
void multiply_matrix(float *m1, float *m2, float *m3, int n);

#endif /* MATRIX_H_ */
