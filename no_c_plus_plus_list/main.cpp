#include "list.h"

int main()
{
    listHeader head;
    listHeaderConstructor(&head);
    list x;
    listConstructor(&x);
    x.data = 13;
    head.firstList = &x;
    list* point = head.firstList;
    for(int i = 0; i < 10; i++)
    {
        addNewList(&head, &point, i);

    }
    point = head.firstList->nextList->nextList->nextList->previousList;
    deleteList(&head, &point);
    listDump(&head, OK);
}