#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

char login();
typedef struct Bank
{

    char u_pass[25];
    char name[25];
    char ph_no[20];
    int Deposit, Acc;
} bank;
bank a, crt, check, my, lo; //to create many structure variables
char temp[20];
void create()
{
    FILE *a;
    a = fopen("record.txt", "a+");
Account:
    system("cls");
    printf("\n\n\n");
    printf("=================================== Create Bank Account ==================================\n\n");
    printf("\n\t\t\tEnter the account number:");
    scanf("%d", &check.Acc);
    while (fscanf(a, "%s %s %d %s %d\n", &crt.u_pass, &crt.name, &crt.Acc, &crt.ph_no, &crt.Deposit) != EOF)
    {
        if (check.Acc == crt.Acc)
        {
            printf("\n==================================================================================\n");
            printf("\t\t\tAccount no. already in use!\n");
            printf("\t\t\tPress any key...\n");
            printf("\n==================================================================================\n");
            getch();
            goto Account;
        }
    }
    crt.Acc = check.Acc;

    printf("\n\t\t\tPassword : ");
    scanf("%s", crt.u_pass);
    printf("\n\t\t\tName :");
    scanf("%s", crt.name);
    printf("\n\t\t\tPhone number : ");
    scanf("%s", &crt.ph_no);
    printf("\n\t\t\tAmt to Deposit : ");
    scanf("%d", &crt.Deposit);
    fprintf(a, "%s %s %d %s %d\n", crt.u_pass, crt.name, crt.Acc, crt.ph_no, crt.Deposit);
    fclose(a);
    printf("\n================================== Account Created ==================================\n");
}

void My_acc(void)
{
    system("cls");
    printf("\n================================== My Account ==================================\n");
    // printf("%s", login());
    int acc = login();
    printf("%s", acc);
}

int main()
{
    int num;
    do
    {
        // system("cls");
        printf("\n\n\n");
        printf("\n====================================== Bank Management ======================================\n\n\n");
        printf("\t\t\t\t\t[1] : Create\n");
        printf("\n");
        printf("\t\t\t\t\t[2] : My Account\n");
        printf("\n");
        printf("\t\t\t\t\t[3] : Exit\n\n");
        printf("=============================================================================================\n\n");
        printf("\t\t\tEnter Your Choice : ");
        scanf("%d", &num);
        switch (num)
        {
        case 1:
            create();
            break;
        case 2:
            My_acc();
            break;
        }
        getch();
    } while (num != 3);
    getch();
    return 0;
}

int login()
{
    FILE *l;
    int a = 0, i = 0;

    char acc[20];
    char uname[10], c = ' ';
    char pword[10], code[10];
    l = fopen("record.txt", "r");
    // do
    // {
    while (fscanf(l, "%s %s %d %s %d\n", &lo.u_pass, &lo.name, &lo.Acc, &lo.ph_no, &lo.Deposit) != EOF)
    {
        printf("\n\t\t\tEnter Account number : ");
        scanf("%s", &acc);
        printf("\n\t\t\tEnter Password : ");
        while (i < 10)
        {
            pword[i] = getch();
            c = pword[i];
            if (c == 13)
                break;
            else
                printf("*");
            i++;
        }
        pword[i] = '\0';
        i = 0;
        itoa(lo.Acc, temp, 10);
        if (strcmp(acc, temp) == 0 && strcmp(pword, lo.u_pass) == 0)
        {
            printf("\n\n\n       WELCOME TO OUR SYSTEM !!!! LOGIN IS SUCCESSFUL");
            printf("\n\n\n\t\t\tPress any key to continue...");
            break;
        }
        else
        {
            printf("\n        SORRY !!!!  LOGIN IS UNSUCESSFUL");
            a++;
            getch(); //holds the screen
        }
    }
    // while (a <= 2)
    //     ;
    // if (a > 2)
    // {
    //     printf("\nSorry you have entered the wrong username and password for four times!!!");
    //     getch();
    // }
    // system("cls");
    // fclose(l);
    return temp;
}
