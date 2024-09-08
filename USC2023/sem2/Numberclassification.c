#include <stdio.h>

int main() {
  int i;
  int numbers[10];
  int positiveCount = 0;
  int negativeCount = 0;
  int zeroCount = 0;

  for (i = 0; i < 10; i++) {
    printf("Enter the %dth integer: ", i + 1);
    scanf("%d", &numbers[i]);

    if (numbers[i] > 0) {
      positiveCount++;
    } else if (numbers[i] < 0) {
      negativeCount++;
    } else {
      zeroCount++;
    }
  }

  printf("There are %d positive numbers, %d negative numbers, and %d numbers equal to 0.\n", positiveCount, negativeCount, zeroCount);

  return 0;
}