/*
-------------------------------------
File:    mystring.c
Project: grec2740_a03
file description
-------------------------------------
 Author:  Andrew Greco
 ID:      210422740
 Email:   grec2740@mylaurier.ca
Version  2023-02-01
-------------------------------------
 */

#include "mystring.h"
#define NULL 0

int str_length(char *s) {
	int length = 0;
	while (*s) {
		length++;
		s++;
	}
	return length;
}

int word_count(char *s) {
	int count = 0;
	int word = 0;
	while (*s) {
		if (*s == ' ') {
			if (word) {
				count++;
				word = 0;
			}
		} else {
			word = 1;
		}
		s++;
	}
	if (word) {
		count++;
	}
	return count;
}

void lower_case(char *s) {
	while (*s) {
		if (*s >= 'A' && *s <= 'Z') {
			*s = *s + ('a' - 'A');
		}
		s++;
	}
}

void str_trim(char *s) {
	int i = 0, j = str_length(s) - 1;
	while (s[i] == ' ') {
		i++;
	}
	while (s[j] == ' ') {
		j--;
	}
	int k = 0;
	int space = 0;
	for (int m = i; m <= j; m++) {
		if (s[m] == ' ' && !space) {
			space = 1;
			s[k++] = s[m];
		} else if (s[m] != ' ') {
			space = 0;
			s[k++] = s[m];
		}
	}
	s[k] = '\0';
}
