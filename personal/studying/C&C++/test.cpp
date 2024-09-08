#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int CFP();
int CFPmed();
int CFPhard();
int PHYSICS();

int main() {
    int score;
    char subject;
    
    printf("Welcome to SHS Reviewer!\n Enter letter c to review CFP, letter p for Physics, and letter q to quit\n Physics \n CFP\n");
    subject = getch();
    
    if (subject == 'c') 
	{
        system("cls");
        score = CFP();
		if (score>1)
        	{
        		system("cls");
				CFPmed();
			}
		else
			{
				system("cls");
				CFP();
				
			}
			score = CFPmed();
			if (score>2)
			{
				system("cls");
				CFPhard();
			}
			else
			{
				system("cls");
				CFPmed();
			}
    }
	else if (subject == 'p') 
	{
        system("cls");
        score = PHYSICS();
    } 
	else if (subject == 'q')
	{
        return 0;
    }
    else
    {
    	system("cls");
	}
     
    return 0;
}

int CFP() {
    int score = 0;
    char answer;
//1
	printf("EASY DIFFICULTY\n");
	printf("Q1 \na\tb\tc\nAnswer: ");
	if(getchar()=='a')
	{
		++score;
		system("cls");
		
	}
	else
	{
		printf("The correct answer is a because...");
		getch();
		system("cls");
	}
//2
	
	printf("EASY DIFFICULTY\n");
	printf("Q2 \na\tb\tc\nAnswer: ");
	if(getchar()=='b')
	{
		system("cls");
		++score;
	}
	else
	{
		printf("The correct answer is b because...");
		getch();
		system("cls");
	}
//3
	printf("EASY DIFFICULTY\n");
	printf("Q3 \na\tb\tc\nAnswer: ");
	if(getchar()=='c')
	{	
		system("cls");
		++score;
	}
	else
	{
		printf("The correct answer is a because...");
		getch();
		system("cls");
	}
    
    printf("Your score is %d\n", score);
    printf("Explanations");
	getch();
	system("cls");   
    return score;
	
}

int CFPmed(){
	int score = 0;
	char answer;
//1
	printf("MEDIUM DIFFICULTY");
	printf("\nQ1 \na\tb\tc");
	scanf("%c",&answer);
	if(answer=='a')
	{
		system("cls");
		++score;
	}
	else
	{
		system("cls");
	}
//2
	printf("MEDIUM DIFFICULTY");
	printf("\nQ2 \na\tb\tc");
	scanf("%c",&answer);
	if(answer=='b')
	{
		system("cls");
		++score;
	}
	else
	{
		system("cls");
	}
//3
	printf("MEDIUM DIFFICULTY");
	printf("\nQ3 \na\tb\tc");
	scanf("%c",&answer);
	if(answer=='c')
	{	system("cls");
		++score;
	}
	else
	{
		system("cls");
	}
    
    printf("Your score is %d\n", score);
	getch();
	system("cls");       
    return score;
}

int CFPhard(){

	int score = 0;
	char answer;
//1
	printf("HARD DIFFICULTY");
	printf("Q1 \na\tb\tc");
	scanf("%c",&answer);
	if(answer=='a')
	{
		system("cls");
		++score;
	}
	else
	{
		system("cls");
	}
//2
	printf("HARD DIFFICULTY");
	printf("Q1 \na\tb\tc");
	scanf("%c",&answer);
	if(answer=='b')
	{
		system("cls");
		++score;
	}
	else
	{
		system("cls");
	}
//3
	printf("HARD DIFFICULTY");
	printf("Q2 \na\tb\tc");
	scanf("%c",&answer);
	if(answer=='b')
	{
		system("cls");
		++score;
	}
	else
	{
		system("cls");
	}
    
    printf("Your score is %d\n", score);
	getch();
	system("cls");    
    return score;
}

int PHYSICS() {
    int score = 0;    
//1
	printf("Starting Easy Difficulty......");
	system("cls");
	printf("Q1 \na\tb\tc");
	if(getch()=='a')
	{
		system("cls");
		++score;
	}
	else
	{
		system("cls");
	}
//2
	printf("Q2 \na\tb\tc");
	if(getch()=='b')
	{
		system("cls");
		++score;
	}
	else
	{
		system("cls");
	}
    printf("Your score is %d\n", score);
    system("cls");
    if (score > 5) {
        printf("Proceeding to Medium Difficulty......\n");
        system("cls");
        
    } else 
	{
        printf("Returning to main menu...\n");
        system("cls");
        main();
    }
    
    return score;
}