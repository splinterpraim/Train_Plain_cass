#ifndef ELEMENT_H_INCLUDED
#define ELEMENT_H_INCLUDED
#include <iostream>
using namespace std;
struct Element
{
    int date[3];//дата [день, месяц, год]
	float cost;//стоимость
	string direction;//направление
	Element *_next;


};


#endif // ELEMENT_H_INCLUDED
