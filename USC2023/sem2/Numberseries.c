#include <stdio.h>

int main() {
	int n, row, i, total = 0;
	printf("Input the value for the nth term: ");
	scanf("%d", &n);
	for (row = 1; row <= n; row++){
		int sum = 1;
		printf("1");
		for (i = 2; i <= row; i++) { 
			printf("+%d", i);
			sum = sum + i;
		}
		total = total + sum;
		printf("=%d\n", sum);
	}
	printf("The sum of the above series is: %d", total);
	return 0;
}