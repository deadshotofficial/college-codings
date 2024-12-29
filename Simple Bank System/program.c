#include <stdio.h>
#include <string.h>

#define MAX_CUSTOMERS 20

struct Customer {
    char accountNumber[20];
    char name[50];
    float balance;
};

void readCustomerDetails(struct Customer customers[], int *customerCount) {
    int i;
    printf("Enter details for customers:\n");
    for(i = 0; i < MAX_CUSTOMERS; i++) {
        printf("Enter details for customer %d:\n", i + 1);
        printf("Account Number: ");
        scanf("%s", customers[i].accountNumber);
        printf("Name: ");
        getchar();
        fgets(customers[i].name, sizeof(customers[i].name), stdin);
        customers[i].name[strcspn(customers[i].name, "\n")] = 0;
        printf("Balance: ");
        scanf("%f", &customers[i].balance);

        (*customerCount)++;

        char choice;
        printf("Do you want to add another customer? (y/n): ");
        getchar();
        choice = getchar();
        if(choice == 'n' || choice == 'N') {
            break;
        }
    }
}

void printAllCustomers(struct Customer customers[], int customerCount) {
    printf("\nCustomer Details:\n");
    for(int i = 0; i < customerCount; i++) {
        printf("Account Number: %s, Name: %s, Balance: %.2f\n", customers[i].accountNumber, customers[i].name, customers[i].balance);
    }
}

void withdrawMoney(struct Customer customers[], int customerCount) {
    char accountNumber[20];
    float amount;
    printf("Enter Account Number to withdraw from: ");
    scanf("%s", accountNumber);
    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);

    for(int i = 0; i < customerCount; i++) {
        if(strcmp(customers[i].accountNumber, accountNumber) == 0) {
            if(customers[i].balance >= amount) {
                customers[i].balance -= amount;
                printf("Withdrawal successful! New balance: %.2f\n", customers[i].balance);
                return;
            } else {
                printf("Insufficient funds!\n");
                return;
            }
        }
    }
    printf("Account not found.\n");
}

void depositMoney(struct Customer customers[], int customerCount) {
    char accountNumber[20];
    float amount;
    printf("Enter Account Number to deposit into: ");
    scanf("%s", accountNumber);
    printf("Enter amount to deposit: ");
    scanf("%f", &amount);

    for(int i = 0; i < customerCount; i++) {
        if(strcmp(customers[i].accountNumber, accountNumber) == 0) {
            customers[i].balance += amount;
            printf("Deposit successful! New balance: %.2f\n", customers[i].balance);
            return;
        }
    }
    printf("Account not found.\n");
}

void searchCustomer(struct Customer customers[], int customerCount) {
    char accountNumber[20];
    printf("Enter Account Number to search: ");
    scanf("%s", accountNumber);

    for(int i = 0; i < customerCount; i++) {
        if(strcmp(customers[i].accountNumber, accountNumber) == 0) {
            printf("Account found! Account Number: %s, Name: %s, Balance: %.2f\n", customers[i].accountNumber, customers[i].name, customers[i].balance);
            return;
        }
    }
    printf("Account not found.\n");
}

int main() {
    struct Customer customers[MAX_CUSTOMERS];
    int customerCount = 0;
    int choice;

    readCustomerDetails(customers, &customerCount);

    while(1) {
        printf("\nMenu:\n");
        printf("1. Print Account Number, Name and Balance of each customer\n");
        printf("2. Withdraw Money\n");
        printf("3. Deposit Money\n");
        printf("4. Search Customer\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printAllCustomers(customers, customerCount);
                break;
            case 2:
                withdrawMoney(customers, customerCount);
                break;
            case 3:
                depositMoney(customers, customerCount);
                break;
            case 4:
                searchCustomer(customers, customerCount);
                break;
            case 5:
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
