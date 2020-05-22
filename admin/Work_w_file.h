#ifndef WORK_W_FILE_H_INCLUDED
#define WORK_W_FILE_H_INCLUDED
#include <iostream>
#include <string>
#include "Element.h"

/*1.Показать  2.Добавить  3.Удалить  4.Редоктировать  5.Резервное сохранение  6.Восстановление записей
*/
using namespace std;

class Work_w_file{

private:
    int _size;
    Element *_list;


public:
	Work_w_file();//конструктор
	Work_w_file(const Work_w_file& w);//конструктор копирования
	~Work_w_file();//деструктор


    void Add();//+
    void Del();
    void Redact();
    void Show();//+
    void SaveRez();
    void Upload();

    void Put_in_file();
    void Get_from_file();



};
#endif // WORK_W_FILE_H_INCLUDED
