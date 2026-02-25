#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int id;
    char holder[50];
    float balance;
} Account;

void newAccount(Account *list, int *size);
void addDeposit(Account *list, int size);
void takeWithdrawal(Account *list, int size);
void listAccounts(Account *list, int size);

int main()
{
    Account list[MAX];
    int size = 0;
    int option;

    while (1)
    {
        printf("\n=== Banking Portal ===\n");
        printf("1. Open Account\n");
        printf("2. Deposit Funds\n");
        printf("3. Withdraw Funds\n");
        printf("4. View All Accounts\n");
        printf("5. Exit\n");
        printf("Select: ");
        scanf("%d", &option);

        switch (option)
        {
            case 1:
                newAccount(list, &size);
                break;
            case 2:
                addDeposit(list, size);
                break;
            case 3:
                takeWithdrawal(list, size);
                break;
            case 4:
                listAccounts(list, size);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}

void newAccount(Account *list, int *size)
{
    printf("Account ID: ");
    scanf("%d", &list[*size].id);
    getchar();

    printf("Account Holder: ");
    fgets(list[*size].holder, sizeof(list[*size].holder), stdin);
    list[*size].holder[strcspn(list[*size].holder, "\n")] = 0;

    printf("Initial Balance: ");
    scanf("%f", &list[*size].balance);

    (*size)++;
    printf("Account created.\n");
}

void addDeposit(Account *list, int size)
{
    int id;
    float amount;

    printf("Enter Account ID: ");
    scanf("%d", &id);

    for (int i = 0; i < size; i++)
    {
        if (list[i].id == id)
        {
            printf("Deposit Amount: ");
            scanf("%f", &amount);

            list[i].balance += amount;
            printf("Deposit successful. New Balance: %.2f\n", list[i].balance);
            return;
        }
    }

    printf("Account not found.\n");
}

void takeWithdrawal(Account *list, int size)
{
    int id;
    float amount;

    printf("Enter Account ID: ");
    scanf("%d", &id);

    for (int i = 0; i < size; i++)
    {
        if (list[i].id == id)
        {
            printf("Withdrawal Amount: ");
            scanf("%f", &amount);

            if (amount > list[i].balance)
            {
                printf("Insufficient balance.\n");
            }
            else
            {
                list[i].balance -= amount;
                printf("Withdrawal successful. Remaining Balance: %.2f\n", list[i].balance);
            }
            return;
        }
    }

    printf("Account not found.\n");
}

void listAccounts(Account *list, int size)
{
    if (size == 0)
    {
        printf("No accounts available.\n");
        return;
    }

    for (int i = 0; i < size; i++)
    {
        printf("\nID: %d\n", list[i].id);
        printf("Holder: %s\n", list[i].holder);
        printf("Balance: %.2f\n", list[i].balance);
    }
}