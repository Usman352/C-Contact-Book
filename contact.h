#ifndef CONTACT_H
#define CONTACT_H

#define MAX_CONTACTS 100
#define NAME_LENGTH 50
#define PHONE_LENGTH 20

typedef struct {
    char name[NAME_LENGTH];
    char phone[PHONE_LENGTH];    
} Contact; 

void displayMenu(void);
void printLine(void);

void add_contact(Contact contacts[], int* count);
void list_contacts(const Contact contacts[], int count);
void save_contacts(const Contact contacts[], int count);
void load_contacts(Contact contacts[], int* count); 

#endif 