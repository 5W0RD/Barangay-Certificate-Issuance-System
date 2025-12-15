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
    int contact_number;
    char purpose[300];
    int purok;
};

void fillUpForm(struct Resident *r) {
    printf("Fill up the questions\n");

    getchar(); 

    printf("Name: ");
    fgets(r->name, sizeof(r->name), stdin);
    r->name[strcspn(r->name, "\n")] = 0;

    printf("Age: ");
    scanf("%d", &r->age);
    getchar();

    printf("Sex: ");
    fgets(r->sex, sizeof(r->sex), stdin);
    r->sex[strcspn(r->sex, "\n")] = 0;

    printf("Birthdate (YYYYMMDD): ");
    scanf("%d", &r->birthdate);
    getchar();

    printf("Civil Status: ");
    fgets(r->civil_status, sizeof(r->civil_status), stdin);
    r->civil_status[strcspn(r->civil_status, "\n")] = 0;

    printf("Contact Number: ");
    scanf("%d", &r->contact_number);
    getchar();

    printf("Purpose of Certificate: ");
    fgets(r->purpose, sizeof(r->purpose), stdin);
    r->purpose[strcspn(r->purpose, "\n")] = 0;

    printf("Purok Number: ");
    scanf("%d", &r->purok);

    printf("\nResident added successfully!\n");
}

void certificateMenu() {
    int certChoice;
    char fullName[100];

    printf("\n--- Select Certificate ---\n\n");
    printf("1. Barangay Clearance\n");
    printf("2. Certification of Indigency\n");
    printf("3. Recommendation for Scholarship\n");
    printf("4. Certification of Low Income\n");
    printf("5. Certificate of Residency\n");

    printf("\nChoose your certificate: ");
    scanf("%d", &certChoice);
    getchar(); 

    printf("\nEnter your FULL NAME: ");
    fgets(fullName, sizeof(fullName), stdin);
    fullName[strcspn(fullName, "\n")] = 0; 

    printf("\nProcessing certificate for: %s\n", fullName);

    printf("\nPlease wait while we prepare your certificate...\n");

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
    printf("Enter your name: ");
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
            printf("Contact Number: %d\n", residents[i].contact_number);
            printf("Purpose: %s\n", residents[i].purpose);
            printf("Purok: %d\n", residents[i].purok);

            int confirm;
            printf("\nIs this you? (1 = Yes, 2 = No): ");
            scanf("%d", &confirm);

            if (confirm == 1) {
                certificateMenu();
                return 1;
            } else {
                return 0;
            }
        }
    }

    printf("Resident '%s' not found.\n", searchName);
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
        printf("Contact Number: %d\n", residents[i].contact_number);
        printf("Purpose: %s\n", residents[i].purpose);
        printf("Purok: %d\n", residents[i].purok);
    }
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

            case 2: {
                printf("---- Resident Search ----\n");
                int result = searchResident(residents, residentCount);

                if (result == 0) {
                    printf("\nRedirecting to Add Resident...\n");
                    fillUpForm(&residents[residentCount]);
                    residentCount++;
                }
                break;
            }

            default:
                printf("Invalid option!\n");
        }
    }

    return 0;
}

