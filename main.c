#include <stdio.h>
#include <stdlib.h>
#include "contact.h"


int main(void) {

    int count = 0;
    Contact contacts[MAX_CONTACTS];
    Contact* contacts = malloc(sizeof(Contact) * MAX_CONTACTS);
    if (!contacts) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    int userOp;
    do {
        displayMenu();
        printLine();
        scanf("%d", &userOp);
        getchar();
        switch (userOp) {
            case 1:
                add_contact(contacts, &count);
                break;
            case 2:
                list_contacts(contacts, count);
                break;
            case 3:
                save_contacts(contacts, count);
                break;
            case 4:
                load_contacts(contacts, &count);
                break;
            case 0:
                printf("Thank you for using the contacts book.\n");
                break;
            default:
                printf("Please enter a valid number.\n");
        }
    } while(userOp != 0);

    free(contacts);

    return 0;
}

void displayMenu(void) {
    printf("Welcome to the contact book\n");
    printf("\n");
    printf("1. Add contact\n");
    printf("2. List Contacts\n");
    printf("3. Save Contacts\n");
    printf("4. Load Contacts\n");
    printf("0. Exit\n");
}
