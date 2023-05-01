/*
-------------------------------------
File:    mysort.c
Project: grec2740_a04
file description
-------------------------------------
Author:  your name here
ID:      your ID here
Email:   your Laurier email here
Version  2023-02-09
-------------------------------------
 */

#include "mysort.h"

BOOLEAN is_sorted(float *a, int left, int right) {
	for (int i = left; i < right; i++) {
		if (a[i] > a[i + 1])
			return false;
	}
	return true;
}

void select_sort(float *a, int left, int right) {
	int min_index;
	float temp;

	for (int i = left; i < right; i++) {
		min_index = i;
		for (int j = i + 1; j <= right; j++) {
			if (a[j] < a[min_index])
				min_index = j;
		}
		temp = a[i];
		a[i] = a[min_index];
		a[min_index] = temp;
	}
}

void quick_sort(float *a, int left, int right) {
	int i = left;
	int j = right;
	float pivot = a[(left + right) / 2];
	float temp;

	while (i <= j) {
		while (a[i] < pivot)
			i++;
		while (a[j] > pivot)
			j--;
		if (i <= j) {
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			i++;
			j--;
		}
	}

	if (left < j)
		quick_sort(a, left, j);
	if (i < right)
		quick_sort(a, i, right);
}
