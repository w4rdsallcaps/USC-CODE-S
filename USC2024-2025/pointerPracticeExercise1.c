#include <stdio.h>

void exercise1();
void exercise2();
void exercise3();
void exercise4();
void exercise5();

int excercise3Func1(int *a, int *b);

int inputInt(int *target);

int main(){
    void (*funcs[5])() = {exercise1, exercise2, exercise3, exercise4, exercise5};

    /*
        COMMENT:
            Looping through a array of functions
            Fun fact void can hold any type
    */

    for (int i = 0; i < sizeof(funcs)/sizeof(funcs[0]); i++){
        printf("================Exercise %d===================\n", i + 1);
        funcs[i]();
        printf("\n\n");
    }

    return 0;
}

void exercise1(){
    int numbers[5] = {3, 5, 7, 8, 90};
    int *ptr;

    ptr = numbers;

    /*
        COMMENT:
            Array manipulation using pointers
    */
    for (int i = 0; i < sizeof(numbers)/sizeof(int); i++){
        *(ptr + i) *= 10;
    }

    /*
        COMMENT:
            Pointer reset + Array display using pointers
    */

    ptr = numbers;

    for (int j = 0; j < sizeof(numbers)/ sizeof(int); j++){
        printf("%d ", *(ptr + j));
    }
    
}

void exercise2(){
    char str[13] = "Hello World";
    char *ptr;

    ptr = str;

    /*
        COMMENT:
            Array display using pointers + early exit for null element in array
    */
    for (int i = 0; i < sizeof(str); i++){
        if (*(ptr + i) == '\0' || *(ptr + i) == '\n'){
            break;
        }

        printf("%c", *(ptr + i));
    }
}

void exercise3(){
    int num1, num2;

    /*
        COMMENT:
            inputInt is a custom input but needs a lot of fixing
        NOTE:
            i have not fixed it i have been procrastinating on it
    */

    do {
        printf("Input the first number: ");
    } while(!inputInt(&num1));
    
    do {
        printf("Input the second number: ");
    } while(!inputInt(&num2));
    

    printf("The sum of %d and %d is %d", num1, num2, excercise3Func1(&num1, &num2));
}

void exercise4(){
    int array[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int *ptr;

    ptr = array;

    /*
        COMMENT:
            Array display using pointers
            i = row, j = col, 3 = size of array

            for 2dimensional array + ptr 
            According to the ppt array[i][j] = *(ptr_adress + (row * col) + sizeof(type))
    */

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            printf("%d\t", *(ptr + (j + i * 3)));
        }
        printf("\n");
    }
}

void exercise5(){
    int array[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int *ptr;

    ptr = array;

    /*
        COMMENT:
            Array manipulation using pointers
            i = row, j = col, 3 = size of array

            for 2dimensional array + ptr 
            According to the ppt array[i][j] = *(ptr_adress + (row * col) + sizeof(type))
    */


    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            *(ptr + (j + i * 3)) += 100;
        }
    }

    /*
        COMMENT:
            Array display using pointers
            i = row, j = col, 3 = size of array

            for 2dimensional array + ptr 
            According to the ppt array[i][j] = *(ptr_adress + (row * col) + sizeof(type))
    */

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            printf("%d\t", *(ptr + (j + i * 3)));
        }
        printf("\n");
    }
}

int excercise3Func1(int *a, int *b){
    return *a + *b;
}

int inputInt(int* target){
    /*
        IMPORTANT:
            Still havent cleared buffer this might need refactoring
    */
    char buffer[999];
    char tempVar;
    int correct = 1;
    int value;

    if (fgets(buffer, sizeof(buffer), stdin) != 0){
        if (buffer[0] == '\0' || buffer[0] == '\n') {return 0;}
        for (int i = 0; i < sizeof(buffer); i++){
            tempVar = buffer[i];

            if (tempVar == '\0' || tempVar == '\n'){
                break;
            }

            if (i == 0 && tempVar == '-'){
                continue;
            }

            if ((tempVar > '9' || tempVar < '0') && correct == 1){
                fprintf(stderr, "Error: Char %c\n", buffer[i]);
                correct = 0;
            }
        }

        if (correct == 0) {return 0;}

        sscanf(buffer, "%d", &value);
        *target = value;

        return 1;
    }
    return 0;
}