#include "errors.h"
typedef double listData;

struct list
{
    listData data;
    list* previousList;
    list* nextList;
};

struct listHeader
{
    int quantityElements;
    list* firstList;
};

errors listHeaderConstructor (listHeader* header);

errors listConstructor(list* list);

errors listOK(listHeader* header);

void listDump(listHeader* header, errors ERROR);

errors addNewList(listHeader *header, list **pointer, listData data);

errors deleteList(listHeader *header, list **pointer);
