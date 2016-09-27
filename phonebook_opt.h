#ifndef _PHONEBOOK_H
#define _PHONEBOOK_H

#define MAX_LAST_NAME_SIZE 16
#define sizetable 42737

/* TODO: After modifying the original version, uncomment the following
 * line to set OPT properly */
#define OPT 1
/*
typedef struct __PHONE_BOOK{
    char firstName[16];
    char email[16];
    char phone[10];
    char cell[10];
    char addr1[16];
    char addr2[16];
    char city[16];
    char state[2];
    char zip[5];
}more;
*/
typedef struct _PHONE_BOOK_ENTRY{
	char lastName[MAX_LAST_NAME_SIZE];
	//struct __PHONE_BOOK *more;
	struct _PHONE_BOOK_ENTRY  *pNext;
}entry;

typedef unsigned int hashIndex;

typedef struct _PHONE_BOOK_HASH_TABLE{
    entry **list;
//    unsigned int tableSize;
}hashTable;

hashTable *hashInitial();
hashIndex hash(char *key);

entry *findNameHash(char *key, hashTable *ht);
int appendHash(char *key, hashTable *ht);

#endif
