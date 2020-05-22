#include <iostream>
#include <string>
#include "Work_w_file.h"
using namespace std;
Work_w_file::Work_w_file() : _size(0),_list(nullptr){cout<<"����������� ������� \n"; }// ��� ����������

Work_w_file::Work_w_file(const Work_w_file& w)//����������� �����������
{   cout<<"����������� ����� \n";
    if(w._list)
    {
        Element *ptr=w._list;
        Element Tmp[w._size];
        for(int i=0; i<w._size;i++)
        {
            Tmp[i].date[0]=ptr->date[0];
            Tmp[i].date[1]=ptr->date[1];
            Tmp[i].date[2]=ptr->date[2];
            Tmp[i].cost=ptr->cost;
            Tmp[i].direction=ptr->direction;
            ptr=ptr->_next;
        }
        _size= w._size;
        _list=nullptr;
        for(int i=_size; i>0;i--)
        {
            ptr= new Element;
            ptr->date[0]=Tmp[i-1].date[0];
            ptr->date[1]=Tmp[i-1].date[1];
            ptr->date[2]=Tmp[i-1].date[2];
            ptr->cost=Tmp[i-1].cost;
            ptr->direction=Tmp[i-1].direction;
            ptr->_next=_list;
            _list=ptr;
        }
        delete ptr;
    }
    else
    {
        _size=0;
        _list=nullptr;
    }
    cout<<"END ����������� ����� \n";

}

Work_w_file::~Work_w_file()//����������
{   cout<<"���������� \n";
    Element *ptr=_list;
    for(int i=0; i<_size;i++)
    {
        ptr=_list;
       _list=_list->_next;
       delete ptr;
    }
    delete _list;
}

void Work_w_file::Add()
{
    Element *ptr=new Element;
    cout<<"������� ����\n";
    cout<<"����:  ";   cin>>ptr->date[0];
    cout<<"�����: ";   cin>>ptr->date[1];
    cout<<"���:   ";   cin>>ptr->date[2];
    cout<<"������� ���������: ";cin>>ptr->cost;cin.get();
    cout<<"������� ����� ����������: "; getline(cin,ptr->direction,'\n');

    ptr->_next=_list;

    _list=ptr;
    _size++;

    delete ptr;

}

void Work_w_file::Del()
{
    Show();
    int ndel;
    cout<<"�������� ����� ������, ������� ����� �������\n�����: ";cin>>ndel;
    ndel=_size-ndel;
    Element ptr=ptr_last->_next, ptr_last=_list;
    for(int i=0; i<ndel;i++)
    {   ptr_last=ptr;
        ptr=ptr_last->_next;
    }
    _list=ptr;
    delete ptr_last;
    delete ptr;

}

void Work_w_file::Show()
{
    if(!_list){cout<<"������� ���\n";}
    else
    {
        Element *ptr=_list;
        Element Tmp[_size];
        for(int i=0; i<_size;i++)
        {
            Tmp[i].date[0]=ptr->date[0];
            Tmp[i].date[1]=ptr->date[1];
            Tmp[i].date[2]=ptr->date[2];
            Tmp[i].cost=ptr->cost;
            Tmp[i].direction=ptr->direction;
            ptr=ptr->_next;
        }

        for(int i=_size; i>0;i--)
        {
            cout<<"����� � "<<_size-i+1<<endl;
            cout<<"����\n";
            cout<<"����:  "<<Tmp[i-1].date[0]<<endl;
            cout<<"�����: "<<Tmp[i-1].date[1]<<endl;
            cout<<"���:   "<<Tmp[i-1].date[2]<<endl;
            cout<<"C��������:  "<<Tmp[i-1].cost<<endl;
            cout<<"����� ����������: "<<Tmp[i-1].direction<<endl;
        }
        delete ptr;
    }
}
