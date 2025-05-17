#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"

void printLine(void) {
    printf("===================================\n");
}

void add_contact(Contact **contacts, int *count, int *capacity) {
    printLine();

    // Resize if needed

    resize(contacts, count, capacity);

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

    (*contacts)[*count] = newContact;
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

void load_contacts(Contact **contacts, int *count, int *capacity) {
    printLine();

    // Open the file in read mode and return an error if you get fp as 0 (ie NULL)

    FILE *fp = fopen("contacts.txt", "r");
    if (!fp) {
        perror("Failed to open file");
        return;
    }

    // Reset everything so you have a fresh contacts list to load into

    free(*contacts);
    *contacts = malloc(INITIAL_CAPACITY * sizeof **contacts);
    if (!*contacts) {
        perror("malloc");
        return;
    }
    (*count) = 0;
    (*capacity) = INITIAL_CAPACITY;

    // Checks if count is less than max contacts
    // Then uses scanf to read from the file into the addresses of the contacts
    // That scanset says "ignore whitespaces, then take the first 49 characters
    // and stop at , then take the next 19 characters and stop at newline
    // Then jump to the next line"

    Contact nextContact;

    while (fscanf(fp, " %49[^,],%19[^\n]\n",
        nextContact.name,
        nextContact.phone) == 2) {

        // Resize if needed

        resize(contacts, count, capacity);

        (*contacts)[*count] = nextContact;

        (*count)++;
    }

    // Close the file and throw an error if there was some issue (eg no more disk)

    if (fclose(fp) != 0) {
        perror("Failed to close file");
        return;
    }
    printLine();
}

void resize(Contact **contacts, int* count, int* capacity) {
        if (*count >= *capacity) {
        int newCapacity = (*capacity) * 2;
        Contact *tmp = realloc(*contacts,newCapacity * sizeof(*tmp));
        if (!tmp) {
            perror("Memory reallocation failed\n");
            exit(1);
        }
        *contacts = tmp; 
        *capacity = newCapacity;
    }
}
