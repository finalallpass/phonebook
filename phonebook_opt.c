#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "phonebook_opt.h"

/* initial hash table */
hashTable *hashInitial()
{
    int i;
    hashTable *ht = NULL;
    ht = (hashTable *)malloc(sizeof(hashTable));
    ht -> list = (entry **)malloc(sizeof(entry *)*sizetable);
    for(i = 0 ; i < sizetable ; i++);{
        ht -> list[i] = NULL;
    }
    return ht;
}
/*
hashIndex hash(char *key)
{  
    unsigned int hashVal = 0;
    while (*key != '\0') {
        hashVal = (hashVal << 5) + *key++;
    }
    return hashVal % sizetable;
}
*/
/*use BKDR hash funtion yo gey hash value*/
hashIndex hash(char *key)
{  
    unsigned int seed = 13;
    unsigned int hashVal = 0;
    while (*key) {
        hashVal = hashVal * seed + (*key++);
    }
    return hashVal % sizetable;
}
/*append*/
int appendHash(char *key, hashTable *ht)
{
    entry *newEntry;
    newEntry = (entry *)malloc(sizeof(entry));
    strcpy(newEntry -> lastName, key);
    newEntry -> pNext = ht -> list[(hash(key))];
    ht -> list[(hash(key))] = newEntry;
    return 0;
}

/*findName*/
entry *findNameHash(char *key, hashTable *ht)
{
    entry *e;
    e = ht -> list[hash(key)];
    while( e -> pNext != NULL)
    {
        if(strcasecmp( key, e -> lastName) == 1)
        {
            return NULL;
        }
        e = e -> pNext;
    }
    return 0;
}
