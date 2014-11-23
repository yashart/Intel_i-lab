#include "hash.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int hashFunc1(listData data, hashTable* hash)
{
    return 1;
}

int hashFunc2(listData data, hashTable *hash)
{
    return abs(data[0]%(hash->quantityElements));
}

int hashFunc3(listData data, hashTable *hash) {
    return abs(strlen(data)%(hash->quantityElements));
}

int hashFunc4(listData data, hashTable* hash)
{
    int sumascii = 0;
    for(int i = 0; i < strlen(data); i++)
    {
        sumascii += abs(data[i]);
    }
    return sumascii;
}

int hashFunc5(listData data, hashTable* hash)
{
    int sum = 0;
    sum = data[0] << 1;
    for(int i = 1; i < strlen(data); i++)
    {
        sum += (sum << 1) ^ data[i];
    }
    return abs(sum%(hash->quantityElements));
}

bool haveEquialSting(hashTable* hash, int numberList, listData data)
{
    if(listOK(&(hash->table[numberList])))
    {
        listDump(&(hash->table[numberList]), listOK(&(hash->table[numberList])));
        PLEASE_KILL_MY_VERY_BAD_FUNCTION(listOK(&(hash->table[numberList])));
    }
    list* pos = hash->table[numberList].firstList;
    for(int i = 0; i < hash->table[numberList].quantityElements; i++)
    {
        if(!strcmp(pos->data, data))
            return true;
        pos = pos->nextList;
    }
    return false;
}

errors addNewInHash(int pos, listData data, hashTable* hash)
{
    if(!haveEquialSting(hash, pos%(hash->quantityElements), data))
        addNewList(&hash->table[pos%(hash->quantityElements)], hash->table[pos%(hash->quantityElements)].firstList, data);
    return OK;
}

errors hashTableConstructor(hashTable* hash) {
    hash->quantityElements = 113;
    hash->table = (listHeader*) calloc(hash->quantityElements,  sizeof(*(hash->table)));
    for(int i = 0; i < hash->quantityElements; i++)
    {
        listHeaderConstructor(&(hash->table[i]));
    }
    return OK;
}

void hashDump(hashTable *hash)
{
    for(int i = 0; i < hash->quantityElements; i++)
    {
        listDump(&(hash->table[i]), OK);
        printf("\n");
    }
}

errors hashTableDestruktor(hashTable *hash)
{
    for(int i = 0; i < hash->quantityElements; i++)
    {
        listHeaderDestruktor(&(hash->table[i]));
    }
    //free(hash);
    return OK;
}
