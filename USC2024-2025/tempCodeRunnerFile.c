#include <stdio.h>
#include <stdbool.h>

bool isLetter(char letter);
bool isVowel(char vowel);

int main() {
    int ends = 0;
    
    do{
    
    char user_input;
    bool letter = true, vowel = true;
    
    do{
        //ask for letter and checks if input is char
        printf("Input a Letter: ");
        scanf("%c", &user_input);
        letter = isLetter(user_input);  //call function and assign returned value to letter
        if (letter != true){    
            printf("INVALID INPUT!\n");
            while(getchar() != '\n');
        } else {
            
        }

    }while(letter != true);
    
    vowel = isVowel(user_input);    //checks if user_input is a vowel or cosonant
    
    //displays vowel or consonant depend on value of vowel
    if(vowel == true){
        printf("VOWEL!\n");
        while(getchar() != '\n');
    } else {
        printf("CONSONANT!\n");
        while(getchar() != '\n');
    }
    
    }while(ends != 1);
    printf("Bye!");

    return 0;
}

//function checks if input is char
bool isLetter(char letter){
    bool final_answer;
    
    if((letter >= 'a'&& letter <= 'z') || (letter >= 'A'&& letter <= 'Z')){ 
            final_answer = true;
        } else {
            final_answer = false;
        }
    return final_answer;
}

//checks if user_input is vowel, if not it is consonant
bool isVowel(char vowel){
    bool final_verdict;
    
    if((vowel == 'a'|| vowel == 'e'|| vowel == 'u'|| vowel == 'i'|| vowel == 'o') ||(vowel == 'A' || vowel == 'E' || vowel == 'U' || vowel == 'I' || vowel == 'O')){
        final_verdict = true;
    } else {
        final_verdict = false;
    }
    
    return final_verdict;
}
