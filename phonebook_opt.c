#include <stdlib.h>

#include "phonebook_opt.h"

/* TODO: FILL YOUR OWN IMPLEMENTATION HERE! */
// this is DJB implement on findname and append


entry *findName(char lastName[], entry *pHead)
{
    /* TODO: implement */
    int index = DJBHash(lastName);
    entry *temp;
    temp = hash_table[index].pNext;

    while (temp != NULL) {
        if (strcasecmp(lastName, temp->lastName) == 0) {
            return temp;
        }

        temp = temp->pNext;
    }
    return NULL;

}

entry *append(char lastName[], entry *e)
{
    /* TODO: implement */
    int index = DJBHash(lastName);
    entry* table_entry = (entry *) malloc(sizeof(entry));

    /* need to check if slot is empty or not */
    if (hash_table[index].pNext == NULL) {
        hash_table[index].pNext = table_entry;
        strcpy(table_entry->lastName, lastName);
    } else {
        table_entry->pNext = hash_table[index].pNext;
        hash_table[index].pNext = table_entry;
        strcpy(table_entry->lastName, lastName);
    }

    return e;

}


// DJB Hash Function
unsigned int DJBHash(char lastName[])
{
    unsigned int hash = 5381;

    while (*lastName) {
        hash += (hash << 5) + (*lastName++);
    }

    return (hash & 0x3FF);
}
