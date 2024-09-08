#include <stdio.h>

int main() {
  int i, sum, count;
  printf("Enter the number of quizzes: ");
  scanf("%d", &count);
  while (count <= 0 && count >= 0){
          printf( "\nInvalid option. Please enter a proper integer\nEnter the number of quizzes:  ");
        }
  sum = 0;
  for (i = 0; i < count; i++) {
    int quiz_grade;
    printf("Enter the quiz grade for quiz %d: ", i + 1);
    scanf("%d", &quiz_grade);
    sum += quiz_grade;
  }
  float average = sum / (float)count;
  printf("The average quiz grade is %.2f\n", average);

  return 0;
}
 
