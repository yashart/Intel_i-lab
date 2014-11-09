#include "list.h"
#include <stdio.h>
#include <stdlib.h>

errors listHeaderConstructor (listHeader* header)
{
    header->quantityElements = 0;
    header->firstList        = NULL;

    return OK;
}

errors listConstructor(list* list)
{
    //list->data = 0; //<- some types of listData can haven't value 0
    list->nextList = NULL;
    list->previousList = NULL;
    return OK;
}

errors listOK(listHeader* header)
{
    list* pointer = header->firstList;
    for(int i = 0; i < header->quantityElements; i++)
    {
        if(pointer == NULL)
        {
            return BAD_LIST_SIZE;
        }
        if(pointer != pointer->nextList->previousList)
        {
            return BAD_LIST;
        }
        pointer = pointer->nextList;
    }
    for(int i = header->quantityElements - 1; i >= 0; i--)
    {
        if(pointer == NULL)
        {
            return BAD_LIST_SIZE;
        }
        if(pointer != pointer->previousList->nextList)
        {
            return BAD_LIST;
        }
        pointer = pointer->previousList;
    }
    return OK;
}

void listDump(listHeader *header, errors ERROR) {
    list* pointer = header->firstList;
    printf("List(%d)\n", ERROR);
    while(pointer->nextList != NULL)
    {
        if(pointer == pointer->nextList->previousList)
        {
            printf("<-(");
        }
        printf("%lg)->",pointer->data);
        pointer = pointer->nextList;
    }
    printf("(%lg)->",pointer->data);
    pointer = pointer->nextList;
}

errors addNewList(listHeader *header, list **pointer, listData data)
{
    if(listOK(header))
    {
        listDump(header, listOK(header));
        PLEASE_KILL_MY_VERY_BAD_FUNCTION(listOK(header));
    }

    list* newList = NULL;
    newList = (list*) calloc (1, sizeof(*newList));
    if(newList == NULL)
    {
        PLEASE_DONT_KILL_MY_VERY_BAD_FUNCTION(BAD_MALLOC);
        return BAD_MALLOC;
    }
    listConstructor(newList);
    newList->data = data;
    newList->previousList   = *pointer;
    newList->nextList       = (*pointer)->nextList;
    (*pointer)->nextList       = newList;
    if(newList->nextList != NULL)
    {
        newList->nextList->previousList = newList;
    }
    *pointer = newList;
    header->quantityElements++;

    if(listOK(header))
    {
        listDump(header, listOK(header));
        PLEASE_KILL_MY_VERY_BAD_FUNCTION(listOK(header));
    }
    return OK;
}

errors deleteList(listHeader *header, list **pointer)
{
    if (listOK(header))
    {
        listDump(header, listOK(header));
        PLEASE_KILL_MY_VERY_BAD_FUNCTION(listOK(header));
    }

    list *newPointerPosition = NULL;

    header->quantityElements--;
    if ((*pointer)->nextList != NULL)
    {
        (*pointer)->nextList->previousList = (*pointer)->previousList;
        newPointerPosition = (*pointer)->nextList;
    }
    if ((*pointer)->previousList != NULL)
    {
        (*pointer)->previousList->nextList = (*pointer)->nextList;
        newPointerPosition = (*pointer)->previousList;
    }

    free(*pointer);
    *pointer = newPointerPosition;

    if(listOK(header))
    {
        listDump(header, listOK(header));
        PLEASE_KILL_MY_VERY_BAD_FUNCTION(listOK(header));
    }
}
