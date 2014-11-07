#include "My_list.h"

int main() {

    list <int> li(-128, 0, 0);
    list <int>* list = &li;
    for(int i = 0; i<50000; i++)
    {
        li.newElem(list, 5);
        list = list->nextElem;
    }
    printf("Азаз");
    //li.dump(li.listOk(&li));

    return 0;
}