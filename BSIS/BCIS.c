#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

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

void viewResident(struct Resident *r, bool filled) {
    if (!filled) {
        printf("No resident data available. Please add a resident first.\n");
        return;
    }

    printf("\n--- Resident Information ---\n");
    printf("Name: %s\n", r->name);
    printf("Age: %d\n", r->age);
    printf("Sex: %s\n", r->sex);
    printf("Birthdate: %d\n", r->birthdate);
    printf("Civil Status: %s\n", r->civil_status);
    printf("Contact Number: %d\n", r->contact_number);
    printf("Purpose: %s\n", r->purpose);
    printf("Purok: %d\n", r->purok);
    printf("----------------------------\n");
}

int main() {
    int choice;
    struct Resident r;
    bool residentAdded = false;
    while (true) {
        printf("\nWelcome to Barangay Villaflor\nSelect your option:\n1. Assistant\n2. Resident\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int sub_choice;
                printf("1. Add Resident\n2. View Resident\n3. Main Menu\n");
                scanf("%d", &sub_choice);

                switch (sub_choice) {
                    case 1:
                        fillUpForm(&r);
                        residentAdded = true;
                        break;
                    case 2:
                        viewResident(&r, residentAdded);
                        break;
                    case 3:
                        printf("Returning to main menu...\n");
                        break;
                    default:
                        printf("Invalid option!\n");
                        break;
                }
                break;
            }
            case 2:
                printf("You selected resident\n");
                break;
            default:
                printf("Invalid option!\n");
                break;
        }
    }

    return 0;
}


