#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <windows.h>

struct Resident {
    char name[50];
    int age;
    char sex[20];
    int birthdate;
    char civil_status[50];
    char contact_number[20];   
    char purpose[300];
    int purok;
};

void clearInputBuffer() {
    while (getchar() != '\n');
}

void fillUpForm(struct Resident *r) {
    printf("\nFill up the questions\n");

    printf("Name: ");
    fgets(r->name, sizeof(r->name), stdin);
    r->name[strcspn(r->name, "\n")] = 0;

    printf("Age: ");
    scanf("%d", &r->age);
    clearInputBuffer();

    printf("Sex: ");
    fgets(r->sex, sizeof(r->sex), stdin);
    r->sex[strcspn(r->sex, "\n")] = 0;

    printf("Birthdate (YYYYMMDD): ");
    scanf("%d", &r->birthdate);
    clearInputBuffer();

    printf("Civil Status: ");
    fgets(r->civil_status, sizeof(r->civil_status), stdin);
    r->civil_status[strcspn(r->civil_status, "\n")] = 0;

    printf("Contact Number: ");
    fgets(r->contact_number, sizeof(r->contact_number), stdin);
    r->contact_number[strcspn(r->contact_number, "\n")] = 0;

    printf("Purpose of Certificate: ");
    fgets(r->purpose, sizeof(r->purpose), stdin);
    r->purpose[strcspn(r->purpose, "\n")] = 0;

    printf("Purok Number: ");
    scanf("%d", &r->purok);
    clearInputBuffer();

    printf("\nResident added successfully!\n");
}

void certificateMenu() {
    int certChoice;
    char fullName[100];

    printf("\n--- Select Certificate ---\n");
    printf("1. Barangay Clearance\n");
    printf("2. Certification of Indigency\n");
    printf("3. Recommendation for Scholarship\n");
    printf("4. Certification of Low Income\n");
    printf("5. Certificate of Residency\n");

    printf("\nChoose your certificate: ");
    scanf("%d", &certChoice);
    clearInputBuffer();

    printf("Enter your FULL NAME: ");
    fgets(fullName, sizeof(fullName), stdin);
    fullName[strcspn(fullName, "\n")] = 0;

    printf("\nProcessing certificate for: %s\n", fullName);
    printf("Please wait while we prepare your certificate...\n");

    for (int i = 20; i > 0; i--) {
        printf("Please wait... %d seconds remaining\r", i);
        fflush(stdout);
        Sleep(1000);
    }

    printf("\n\nYour certificate request is completed!\n");
}

int searchResident(struct Resident residents[], int count) {
    if (count == 0) {
        printf("No residents available.\n");
        return -1;
    }

    char searchName[50];

    printf("Enter your FULL NAME: ");
    fgets(searchName, sizeof(searchName), stdin);
    searchName[strcspn(searchName, "\n")] = 0;

    for (int i = 0; i < count; i++) {
        if (strcmp(residents[i].name, searchName) == 0) {
            printf("\n--- Resident Information ---\n");
            printf("Name: %s\n", residents[i].name);
            printf("Age: %d\n", residents[i].age);
            printf("Sex: %s\n", residents[i].sex);
            printf("Birthdate: %d\n", residents[i].birthdate);
            printf("Civil Status: %s\n", residents[i].civil_status);
            printf("Contact Number: %s\n", residents[i].contact_number);
            printf("Purpose: %s\n", residents[i].purpose);
            printf("Purok: %d\n", residents[i].purok);

            int confirm;
            printf("\nIs this you? (1 = Yes, 2 = No): ");
            scanf("%d", &confirm);
            clearInputBuffer();

            if (confirm == 1) {
                certificateMenu();
                return 1;
            } else {
                return 0;
            }
        }
    }

    printf("Resident not found.\n");
    return 0;
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
        printf("Contact Number: %s\n", residents[i].contact_number);
        printf("Purpose: %s\n", residents[i].purpose);
        printf("Purok: %d\n", residents[i].purok);
    }
}

int main() {
    int choice, sub_choice;
    struct Resident residents[100];
    int residentCount = 0;

    while (true) {
        printf("\nWelcome to Barangay Villaflor\n");
        printf("1. Assistant\n");
        printf("2. Resident\n");
        printf("Choose option: ");
        scanf("%d", &choice);
        clearInputBuffer();

        switch (choice) {
            case 1:
                printf("\n1. Add Resident\n");
                printf("2. View All Residents\n");
                printf("3. Main Menu\n");
                printf("Choose option: ");
                scanf("%d", &sub_choice);
                clearInputBuffer();

                if (sub_choice == 1) {
                    fillUpForm(&residents[residentCount]);
                    residentCount++;
                } else if (sub_choice == 2) {
                    viewAllResidents(residents, residentCount);
                } else if (sub_choice == 3) {
                    continue;
                } else {
                    printf("Invalid option!\n");
                }
                break;

            case 2:
                printf("\n---- Resident Search ----\n");
                int result = searchResident(residents, residentCount);
                if (result == 0) {
                    printf("\nRedirecting to Add Resident...\n");
                    fillUpForm(&residents[residentCount]);
                    residentCount++;
                }
                break;

            default:
                printf("Invalid option!\n");
        }
    }

    return 0;
}


