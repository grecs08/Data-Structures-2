/*
-------------------------------------
File:    mysort.h
Project: grec2740_a04
file description
-------------------------------------
Author:  your name here
ID:      your ID here
Email:   your Laurier email here
Version  2023-02-09
-------------------------------------
 */

#ifndef MYSORT_H
#define MYSORT_H

typedef enum {
	false, true
} BOOLEAN;
BOOLEAN is_sorted(float *a, int left, int right);
void select_sort(float *a, int left, int right);
void quick_sort(float *a, int left, int right);

#endif
