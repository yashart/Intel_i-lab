#ifndef My_list_h
#define My_list_h
#include <iostream>

enum list_errors
{
    OK = 0,
    NULLPTR = 1,
    OVERFLOAT = 2
};

template <typename elem_t> class list
{
public:
    elem_t data;
    list* lastElem;
    list* nextElem;
public:
    list();
    list(elem_t data, list<elem_t> *last, list<elem_t> *next);
    ~list();

    list_errors listOk(const list* ls);
    void    dump(const list_errors error);
    list_errors newElem(list<elem_t> *pos, const elem_t data);
    list_errors delElem(list<elem_t> *pos);
};



template <typename elem_t>
list<elem_t>::list()
{
    data = 0;
    lastElem = 0;
    nextElem = 0;
}

template <typename elem_t>
list<elem_t>::list(elem_t data, list<elem_t> *last, list<elem_t> *next)
{
    this->data = data;
    lastElem = last;
    nextElem = next;
}

template <typename elem_t>
list<elem_t>::~list()
{
    data = 0;
    lastElem = NULL;
    nextElem = NULL;
}

template <typename elem_t>
list_errors list<elem_t>::listOk(const list* ls)
{
    if(ls->nextElem == NULL)
    {
        return OVERFLOAT;
    }
    return OK;
}

template <typename elem_t>
void list<elem_t>::dump(list_errors const error)
{
    std::cout<<error<<std::endl;
    list<elem_t>* ls = this;
    while(ls->nextElem != NULL)
    {
        std::cout<<ls->data<<std::endl;
        ls = (list<elem_t>*)ls->nextElem;
    }
    std::cout<<ls->data<<std::endl;
}

template <typename elem_t>
list_errors list<elem_t>::newElem(list<elem_t> *pos, const elem_t data)
{
    list<elem_t>* ls = this;
    for(ls; ls != pos ; ls =(list<elem_t>*) ls->nextElem)
    {

        if(listOk(ls) != OK)
        {
            dump(OVERFLOAT);
            return OVERFLOAT;
        }
    }
    list<elem_t>* nextList = NULL;
    nextList = new list(data, ls, NULL);
    nextList->lastElem = ls;
    ls->nextElem = nextList;
    return OK;
}

template <typename elem_t>
list_errors list<elem_t>::delElem(list<elem_t> *pos)
{
    list<elem_t>* ls = pos;
    list<elem_t>* past = ls->lastElem;
    list<elem_t>* next = ls->nextElem;
    if((past != NULL))
        past->nextElem = (elem_t*) next;
    if(next != NULL)
        next->lastElem = (elem_t*) past;
    delete ls;
    return OK;
}

#endif