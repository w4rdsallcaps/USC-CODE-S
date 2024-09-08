#include <stdio.h>

int main() {
	int x, y;
	printf("Enter the first value: ");
	scanf("%d", &x);
	printf("\nEnter the second value: ");
	scanf("%d", &y);
	printf("\nInitial value of x & y: %d %d \n", x, y);
	swap(&x, &y);
	printf("\nSwapped Value of x & y: %d %d", x, y);
	return 0;
}

void swap(int *x, int *y){
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
	return;
}
