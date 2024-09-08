#include <stdio.h>
#include <stdlib.h>

struct Expense {
    char name[50];
    int amount;
    char date[20];
};
void saveExpensesToFile(struct Expense *expenses_list, int num_expenses, int income, int expenses, int remaining_balance) {
    FILE *file = fopen("budget_summary.txt", "a");  
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }
    fprintf(file, "\n\nBudget Summary (Run):\n");
    fprintf(file, "Income: %d\n", income);
    fprintf(file, "Expenses:\n");
    for (int i = 0; i < num_expenses; i++) {
        fprintf(file, "%s: %d (Date: %s)\n", expenses_list[i].name, expenses_list[i].amount, expenses_list[i].date);
    }
    fprintf(file, "Total Expenses: %d\n", expenses);
    fprintf(file, "Remaining Balance: %d\n", remaining_balance);
    fclose(file);
}
int main() {
    int income;
    int expenses = 0;
    printf("Enter your income: ");
    scanf("%d", &income);

    int max_expenses = 5;
    struct Expense *expenses_list = (struct Expense *)malloc(max_expenses * sizeof(struct Expense));

    if (expenses_list == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    int num_expenses = 0;
    char addMoreExpenses;
    do {
        printf("Enter the name of the expense: ");
        getchar();
        fgets(expenses_list[num_expenses].name, sizeof(expenses_list[num_expenses].name), stdin);
        printf("Enter the amount for %s: ", expenses_list[num_expenses].name);
        scanf("%d", &expenses_list[num_expenses].amount);
        printf("Enter the date for %s (e.g., DD/MM/YYYY): ", expenses_list[num_expenses].name);
        scanf("%s", expenses_list[num_expenses].date);
        expenses += expenses_list[num_expenses].amount;
        num_expenses++;

        printf("Do you want to add more expenses? (y/n): ");
        scanf(" %c", &addMoreExpenses);

        if (addMoreExpenses == 'y') {
            if (num_expenses == max_expenses) {
                max_expenses *= 2;
                expenses_list = (struct Expense *)realloc(expenses_list, max_expenses * sizeof(struct Expense));

                if (expenses_list == NULL) {
                    printf("Memory reallocation failed.\n");
                    return 1;
                }
            }
        }
    } while (addMoreExpenses == 'y');
    
    int remaining_balance = income - expenses;

    printf("\nBudget Summary:\n");
    printf("Income: %d\n", income);
    printf("Expenses:\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("%s: %d (Date: %s)\n", expenses_list[i].name, expenses_list[i].amount, expenses_list[i].date);
    }
    printf("Total Expenses: %d\n", expenses);
    printf("Remaining Balance: %d\n", remaining_balance);

    if (remaining_balance > 0) {
        printf("You have a surplus! Consider saving or investing.\n");
    } else if (remaining_balance == 0) {
        printf("You've balanced your budget. Good job!\n");
    } else {
        printf("Warning: Your expenses exceed your income. Review your budget.\n");
    }
    saveExpensesToFile(expenses_list, num_expenses, income, expenses, remaining_balance);
    free(expenses_list);
    return 0;
}
