/*
 ============================================================================
 Project: cp264-a1q1
 File:    caseflip.c
 Author:  Andrew Greco
 Version: 2023-01-17
 ============================================================================
 */

#include <stdio.h>
int main() {
	setvbuf(stdout, NULL, _IONBF, 0);

	char c = 0, temp;
	do {
		printf("Please enter a character\n");
		scanf("%c", &c);

		do {
			scanf("%c", &temp);
			if (temp == '\n')
				break;
		} while (1);

		if (c >= 'a' && c <= 'z') {
			printf("%c:%c\n", c, c - 32);
		} else if (c >= 'A' && c <= 'Z') {
			printf("%c:%c\n", c, c + 32);
		} else if (c == 42) {
			printf("%c:quit\n", c);
			break;
		} else {
			printf("%c:invalid\n", c);
		}

	} while (1);

	return 0;
}

