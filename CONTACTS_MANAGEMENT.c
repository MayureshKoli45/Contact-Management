#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

void Add_Contact()
{
    FILE *contacts;
    char name[50], phone_number[20];
    fflush(stdin);
    printf("To add a contact please\n");
    printf("Enter the name :-\n");
    gets(name);
    printf("Enter the phone number :-\n");
    gets(phone_number);
    printf("The phone number is successfully registered\n");
    contacts = fopen("contacts.txt", "a");
    fprintf(contacts, "\n%s\t--->\t%s\n", name, phone_number);
    fclose(contacts);
}

int main()
{
    FILE *list;
    char input, cont, b;
    while (1)
    {
        fflush(stdin);
        printf("---------------------------------------------------------\t\t\n");
        printf("|\t\t*****\t  CONTACTS\t*****\t\t|\n");
        printf("|\t\t ***\t MANAGEMENT\t ***\t\t|\n");
        printf("---------------------------------------------------------\t\t\n");
        printf("{\t--> Press '1' to add a contact\t\t\t}\n");
        printf("{\t--> Press '2' to list down all contacts\t\t}\n");
        printf("{\t--> Press '0' to quit\t\t\t\t}\n");
        printf("---------------------------------------------------------\t\t\n");

        scanf("%c", &input);

        if (input == '1')
        {
            system("cls");
            fflush(stdin);
            Add_Contact();
        }

        else if (input == '2')
        {
            system("cls");
            fflush(stdin);
            list = fopen("contacts.txt", "r");
            cont = fgetc(list);
            while (cont != EOF)
            {
                printf("%c", cont);
                cont = fgetc(list);
            }
            printf("\n\t\t***\tpress b to back\t ***\t\t\n");
            scanf("%c", &b);
            fclose(list);
            system("cls");
        }

        else
        {
            fflush(stdin);
            printf("Quitting\n");
            break;
        }
    }

    return 0;
}