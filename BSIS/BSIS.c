#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct Resident {
    char name[50];
    int age;
    char sex[20];
    int birthdate;
    char civil_status[50];
    int contact_number;
    char purpose[300];
    int purok; 
};

void fillUpForm(struct Resident *r) {

        printf("Fill up the questions\n");

        printf("Name: ");
        scanf(" %s", r->name);

        printf("Age: ");
        scanf("%d", &r->age);

        printf("Sex: ");
        scanf(" %s", r->sex);

        printf("Birthdate (YYYYMMDD): ");
        scanf("%d", &r->birthdate);

        printf("Civil Status: ");
        scanf(" %s", r->civil_status);

        printf("Contact Number: ");
        scanf("%d", &r->contact_number);

        printf("Purpose of Certificate: ");
        scanf(" %s", r->purpose);

        printf("Purok: ");
        scanf("%d", &r->purok);

        printf("Residence added successfully!\n");
}

int main() {

    int choice;
    
    while (true) {
    printf("welcome to barangay villaflor\nselect your option:\n1. assistant\n2. resident\n");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        printf("1. add residence\n2. view residence\n3. main menu\n");
        int sub_choice;
        scanf("%d", &sub_choice);
        switch (sub_choice)
        {
        case 1:
            fillUpForm(NULL);
            break;
        case 2:
            printf("Resident 1\n");
            break;
        case 3:
            printf("returning to main menu\n");
            exit(0);
        }
        break;
    case 2:
        printf("you selected resident\n");
        break;
    }
    }
    return 0;}