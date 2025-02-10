#include <stdio.h>
#include <string.h>

#define maxLength 100
#define amountOfUsers 3
struct userCred {
    char username[maxLength];
    char password[maxLength];
    int balance;
    int debt;
};

void main(){
    int i = 0;
    struct userCred userCreds[amountOfUsers] = {
        {"kineth","asdfg","1000"},
        {"dale","qwerty","2000"},
        {"john","zxcvbnm","3000"}
    };

    char inputedUsername[maxLength];
    char inputedPassword[maxLength];

    do{
        printf("Username: ");
        scanf("%99s",inputedUsername);
        printf("Password: ");
        scanf("%99s",inputedPassword);
        
    } while ( i != 0);
    
           
}
    
