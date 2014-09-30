//{=================================================================================
//! @file    main.cpp
//! @date    2014-09-27 2:46
//! @author  Yashukhin Artem
//!
//! Dynamic array class
//!
//! @par     You can add new elements in any place and delete any elements
//!
//!
//!
//!
//}=================================================================================

#include <iostream>
#include <stdlib.h>
#include <assert.h>


class CArray {
    private:
    //! указатель на начало динамического массива
    int* buffer;
    //! размер массива в байтах
    int  byte_size;
    public:
    //! размер массива в элементах
    int  realsize;

    public:
          CArray    ();
          ~CArray   ();
    int  AddAt      (int pos);
    void  InsertAt   (int pos, int el);
    int  GetAt      (int pos);
    void Delete     (int pos);

};
//{=================================================================================
//! CArray () - конструктор класса, создаёт указатель на начало массива и обнуляет
//!             все переменные
//!
//!
//}=================================================================================
CArray :: CArray () {
    realsize = 0;
    byte_size     = realsize * sizeof (*buffer);
    buffer   = (int*) malloc (byte_size);

}
//{=================================================================================
//! ~CArray () - деструктор класса, освобождает память по адресу buffer
//!
//}=================================================================================
CArray :: ~CArray () {
    free(buffer);
}
//{=================================================================================
//! AddAt - добавляет ячейку в массив
//! @param pos - номер, куда нужно вставить ячейку
//! @return pos - номер, куда нужно вставить ячейку
//! @par          Пример (создание массива из 20 - и элементов):
//! @code
//! CArray din_arr;
//!     for(int i = 0; i < 20; i++)
//!         din_arr.AddAt(i);
//! @endcode
//!
//}=================================================================================
int CArray :: AddAt(int pos)
{
    assert (buffer != NULL);
    assert (pos >=0 && pos <= realsize);

    realsize++;
    byte_size+=sizeof(*buffer);
    buffer = (int*) realloc(buffer, realsize * sizeof (*buffer));
    for (int i = realsize-2; i >= pos; i--)
    {
        buffer [i + 1] = buffer [i];
    }
    return pos;
}
//{=================================================================================
//! InsertAt - записывает в ячейку массива значение переменной
//! @param pos - номер ячейки, по которой нужно что-то записать
//! @param el  - значение, которое нужно присвоить ячейке
//!
//! @par          Пример (создание массива из 20 - и элементов и его обнуление):
//! @code
//! CArray din_arr;
//!     for(int i = 0; i < 20; i++)
//!     {
//!         din_arr.AddAt(i);
//!         din_arr.InsertAt(i,0);
//!     }
//! @endcode
//}=================================================================================
void CArray :: InsertAt (int pos, int el)
{
    assert (pos >=0 && pos < realsize);

    buffer [pos] = el;
}
//{=================================================================================
//! GetAt - возврат значения ячейки
//! @param pos - номер ячейки
//! @return    - значение ячейки
//!
//}=================================================================================
int CArray :: GetAt (int pos){
    assert (pos >=0 && pos < realsize);
    return buffer[pos];
}
//{=================================================================================
//! AddAt - удаляет ячейку из массива
//! @param pos - номер ячейки, которую удалить
//! @par          Пример (удаление ячейки из массива):
//! @code
//! CArray din_arr;
//! din_arr.Delete(5);
//!
//! @endcode
//!
//}=================================================================================
void CArray :: Delete (int pos){
    assert (pos >=0 && pos < realsize);
    for (int i=pos; i<realsize-1; i++)
    {
        buffer[i] = buffer[i+1];
    }
    realsize--;
    byte_size -= sizeof(*buffer);
    buffer = (int*) realloc(buffer, byte_size);
}
//{=================================================================================
//! main - пример работы с классов
//! @param din_arr - переменная класса
//! @par       Действия:
//!            - создание массива из 20 - и элементов
//!            - забивание значениями от 0 до 20 - и
//!            - Вывод на массива экран
//!            - Удаление 0-ого и 5-ого элемента
//!            - Вывод нового массива на экран
//}=================================================================================
int main()
{
    CArray din_arr;
    for(int i = 0; i < 20; i++)
    {
        din_arr.AddAt(i);
        din_arr.InsertAt(i,i);
        std :: cout << din_arr.GetAt(i) << ' ';

    }
    std :: cout << std:: endl;

    din_arr.Delete(5);

    din_arr.InsertAt(din_arr.AddAt(5), 300);

    din_arr.AddAt(20);
    din_arr.AddAt(21);

    din_arr.Delete(0);

    for (int i = 0; i < din_arr.realsize; i++)
    {
        std :: cout << din_arr.GetAt(i) << ' ';

    }

    return 0;
}
