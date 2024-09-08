#include <stdio.h>


enum Grade_type { Excellent, Very_Good, Good, Fair, Poor, Very_Poor, Grade_Undefined };

int main() {
  float physics, chemistry, biology, mathematics, computer;
  printf("Enter your physics grade: ");
  scanf("%f", &physics);
  printf("Enter your chemistry grade: ");
  scanf("%f", &chemistry);
  printf("Enter your biology grade: ");
  scanf("%f", &biology);
  printf("Enter your mathematics grade: ");
  scanf("%f", &mathematics);
  printf("Enter your computer grade: ");
  scanf("%f", &computer);

  float average_grade = calculate_grade(physics, chemistry, biology, mathematics, computer);
  Grade_type grade_type = determine_grade_type(average_grade);

  switch (grade_type) {
    case Excellent:
      printf("Your grade is Excellent.\n");
      break;
    case Very_Good:
      printf("Your grade is Very Good.\n");
      break;
    case Good:
      printf("Your grade is Good.\n");
      break;
    case Fair:
      printf("Your grade is Fair.\n");
      break;
    case Poor:
      printf("Your grade is Poor.\n");
      break;
    case Very_Poor:
      printf("Your grade is Very Poor.\n");
      break;
    case Grade_Undefined:
      printf("Your grade is undefined.\n");
      break;
  }
  return 0;
}

float calculate_grade(float physics, float chemistry, float biology, float mathematics, float computer) {
  float average_grade = (physics + chemistry + biology + mathematics + computer) / 5;
  return average_grade;
}

Grade_type determine_grade_type(float average_grade) {
  if (average_grade >= 90) {
    return Excellent;
  } else if (average_grade >= 80) {
    return Very_Good;
  } else if (average_grade >= 70) {
    return Good;
  } else if (average_grade >= 60) {
    return Fair;
  } else if (average_grade >= 50) {
    return Poor;
  } else {
    return Very_Poor;
  }
}
