#include<stdio.h>
#include<stdlib.h>

struct customer
{
    int account_no;
    int account_pin;
    char name[80];
//    char pin[80];
    int balance;
};

void atmdata(struct customer[], int);
int search(struct customer[], int, int);
int searchp(struct customer list[80], int s, int pin);
void deposit(struct customer[], int, int, int);
void withdraw(struct customer[], int, int, int);

int main()
{
    struct customer data[20];
    int n, choice, account_no, amount, index, account_pin, indexp;



    do
    {

        printf("\n********Emran, Sumaia, Shuaib Bank ATM Service***********\n");
        printf("\n" );
        printf("Press 1 to search your account .\n");
        printf("Press 2 to deposit amount.\n");
        printf("Press 3 to withdraw amount.\n");
        printf("Press 4 to create account.\n");
        printf("Press 0 to exit\n");
        printf("\nEnter choice(0-4) : ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter account number to search : ");
                scanf("%d", &account_no);
                printf("Enter your pin : ");
                fflush(stdin);
                scanf("%d",&account_pin);

//                printf("\nEnter your pin : ");
//                fflush(stdin);
//                scanf("%s",list[i].pin);

                index = search(data, n, account_no);
                indexp = searchp(data, n, account_pin);
                if (index ==  - 1 && indexp == -1)
                {
                    printf("Record not found : ");
                }
                else
                {   //searchp(data, n, account_pin);
                    printf("A/c Number: %d\nName: %s\nBalance: %d\n",
                        data[index].account_no, data[index].name,
                        data[index].balance, data[index].account_pin);
                //    searchp(data, n, account_pin);
                }
                break;
            case 2:
                printf("Enter account number : ");
                scanf("%d", &account_no);
                printf("Enter account pin : ");
                fflush(stdin);
                scanf("%d",&account_pin );
                printf("Enter amount to deposit : ");
                scanf("%d", &amount);
                deposit(data, n, account_no, amount);
                break;
            case 3:
                printf("Enter account number : ");
                scanf("%d", &account_no);
                printf("Enter account pin : ");
                fflush(stdin);
                scanf("%d",&account_pin );
                printf("Enter amount to withdraw : ");
                scanf("%d", &amount);
                withdraw(data, n, account_no, amount);
            case 4:
                printf("Number of account you want to  create? : ");
                scanf("%d", &n);
                atmdata(data, n);
        }
    }
    while (choice != 0);
    printf("\n\n THANKS FOR USING Emran, Sumaia, Shuaib Bank ATM Service  \n\n");
    return 0;
}

void atmdata(struct customer list[80], int s)
{
    int i;
    for (i = 0; i < s; i++)
    {
        printf("\nEnter data for Record #%d", i + 1);

        printf("\nEnter account_no : ");
        scanf("%d", &list[i].account_no);
        fflush(stdin);
        printf("Enter name : ");
        fflush(stdin);
        scanf("%s",list[i].name);
        printf("\nEnter your pin : ");
        fflush(stdin);
        scanf("%d", &list[i].account_pin);

        list[i].balance = 0;
    }
}


int search(struct customer list[80], int s, int number)
{
    int i;

    for (i = 0; i < s; i++)
    {
        if (list[i].account_no == number)
        {
            return i;
        }
    }


    return  - 1;
}

int searchp(struct customer list[80], int s, int pin)
{
    int i;

    for (i = 0; i < s; i++)
    {
        if (list[i].account_pin == pin)
        {
            return i;
        }
    }
    return  - 1;
}

void deposit(struct customer list[], int s, int number, int chk)
{
    int i = search(list, s, number);
    if (i ==  - 1)
    {
        printf("Record not found");
    }
    else
    {
        list[i].balance += chk;
    }
}

void withdraw(struct customer list[], int s, int number, int chk)
{
    int i = search(list, s, number);
    if (i ==  - 1)
    {
        printf("Record not found\n");
    }
    else if (list[i].balance < chk)
    {
        printf("Insufficient balance\n");
    }
    else
    {
        list[i].balance -= chk;
    }
}

