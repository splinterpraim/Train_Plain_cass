﻿#include "Plane.h"
Plane::Plane():Ticket()
{
    name="Plane";
}
Plane::~Plane()
{
    Element *ptr=_list;
    for(int i=0; i<_size;i++)
    {
       _list=ptr->_next;
       delete ptr->_next;
       ptr=_list;
    }
    _size=0;
    ptr=nullptr;
    delete ptr;
    delete next;

}


