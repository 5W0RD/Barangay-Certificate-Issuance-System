#include <stdio.h>
#include <stdbool.h>
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

    printf("Resident added successfully!\n");
}

void viewAllResidents(struct Resident residents[], int count) {
    if (count == 0) {
        printf("No residents available.\n");
        return;
    }

    printf("\n======= ALL RESIDENT RECORDS =======\n");
    for (int i = 0; i < count; i++) {
        printf("\nResident #%d\n", i + 1);
        printf("Name: %s\n", residents[i].name);
        printf("Age: %d\n", residents[i].age);
        printf("Sex: %s\n", residents[i].sex);
        printf("Birthdate: %d\n", residents[i].birthdate);
        printf("Civil Status: %s\n", residents[i].civil_status);
        printf("Contact Number: %d\n", residents[i].contact_number);
        printf("Purpose: %s\n", residents[i].purpose);
        printf("Purok: %d\n", residents[i].purok);
        printf("-----------------------------------\n");
    }
    printf("===================================\n");
}

void searchResident(struct Resident residents[], int count) {
    if (count == 0) {
        printf("No residents available.\n");
        return;
    }

    char searchName[50];
    printf("Enter your name: ");
    scanf(" %s", searchName);

    for (int i = 0; i < count; i++) {
        if (strcmp(residents[i].name, searchName) == 0) {
            printf("\n--- Resident Information ---\n");
            printf("Name: %s\n", residents[i].name);
            printf("Age: %d\n", residents[i].age);
            printf("Sex: %s\n", residents[i].sex);
            printf("Birthdate: %d\n", residents[i].birthdate);
            printf("Civil Status: %s\n", residents[i].civil_status);
            printf("Contact Number: %d\n", residents[i].contact_number);
            printf("Purpose: %s\n", residents[i].purpose);
            printf("Purok: %d\n", residents[i].purok);
            printf("----------------------------\n");
            return;
        }
    }

    printf("Resident '%s' not found.\n", searchName);
}

int main() {
    int choice, sub_choice;

    struct Resident residents[100];
    int residentCount = 0;

    while (true) {
        printf("\nWelcome to Barangay Villaflor\nSelect your option:\n1. Assistant\n2. Resident\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("1. Add Resident\n2. View All Residents\n3. Main Menu\n");
                scanf("%d", &sub_choice);

                switch (sub_choice) {
                    case 1:
                        fillUpForm(&residents[residentCount]);
                        residentCount++;
                        break;

                    case 2:
                        viewAllResidents(residents, residentCount);
                        break;

                    case 3:
                        printf("Returning to main menu...\n");
                        break;

                    default:
                        printf("Invalid option!\n");
                }
                break;

            case 2:
                printf("---- Resident Search ----\n");
                searchResident(residents, residentCount);
                break;

            default:
                printf("Invalid option!\n");
        }
    }

    return 0;
}
