#include "My_list.h"

int main() {

    list <int> li(1, 0, 0);

    li.newElem(0, 2);
    li.newElem(1, 3);
    li.delElem(2);
    li.dump(li.listOk(&li));

    return 0;
}