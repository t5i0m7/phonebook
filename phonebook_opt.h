#ifndef _PHONEBOOK_H
#define _PHONEBOOK_H

#define MAX_LAST_NAME_SIZE 16

#define HASH_TABLE_SIZE 1024 // 2^10 size
/* TODO: After modifying the original version, uncomment the following
 * line to set OPT properly */
#define OPT 1


typedef struct __PHONE_BOOK_ENTRY {
    char lastName[MAX_LAST_NAME_SIZE];
    /*
    char firstName[16];
    char email[16];
    char phone[10];
    char cell[10];
    char addr1[16];
    char addr2[16];
    char city[16];
    char state[2];*/
    struct __PHONE_BOOK_ENTRY *pNext;
} entry;


#endif
