#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"

void printLine(void) {
    printf("===================================\n");
}

void add_contact(Contact contacts[], int* count) {
    printLine();

    Contact newContact; 

    // Get name

    printf("Enter contact name: \n");
    fgets(newContact.name, sizeof(newContact.name), stdin);
    newContact.name[strcspn(newContact.name,"\n")] = 0;

    // Get phone

    printf("Enter contact phone number: \n");
    fgets(newContact.phone, sizeof(newContact.phone), stdin);
    newContact.phone[strcspn(newContact.phone,"\n")] = 0;


    // Add to contacts and increment size

    contacts[*count] = newContact;
    (*count)++;

    printLine();
}

void list_contacts(const Contact contacts[], int count) {
    printLine();
    for (int i = 0; i<count; i++) {
        //Prints each contact like "(i+1). {name} - {phone}"
        printf("%d. %s - %s\n", i+1, contacts[i].name, contacts[i].phone);
    }
    printLine();
}

void save_contacts(const Contact contacts[], int count) {
    printLine();

    // Open the file in write mode and return an error if you get fp as 0 (ie NULL)

    FILE *fp = fopen("contacts.txt", "w");
    if (!fp) {
        perror("Failed to open file");
        return;
    }
    
    // Writes each contact to the file on a newline

    for (int i=0; i<count; i++) {
        fprintf(fp, "%s,%s\n", contacts[i].name, contacts[i].phone);
    }

    // Close the file and throw an error if there was some issue (eg no more disk)

    if (fclose(fp) != 0) {
        perror("Failed to close file");
        return;
    }
}

void load_contacts(Contact contacts[], int* count) {
    printLine();

    // Open the file in read mode and return an error if you get fp as 0 (ie NULL)

    FILE *fp = fopen("contacts.txt", "r");
    if (!fp) {
        perror("Failed to open file");
        return;
    }

    (*count) = 0;

    // Checks if count is less than max contacts
    // Then uses scanf to read from the file into the addresses of the contacts
    // That scanset says "ignore whitespaces, then take the first 49 characters
    // and stop at , then take the next 19 characters and stop at newline
    // Then jump to the next line"

    while (*count < MAX_CONTACTS && fscanf(fp, " %49[^,],%19[^\n]\n",
        contacts[*count].name,
        contacts[*count].phone) == 2) {
        (*count)++;
    }

    // Close the file and throw an error if there was some issue (eg no more disk)

    if (fclose(fp) != 0) {
        perror("Failed to close file");
        return;
    }
    printLine();
}
