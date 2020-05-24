#include <iostream>
#include <string>
#include "Work_w_file.h"
using namespace std;
Work_w_file::Work_w_file() : _size(0),_list(nullptr){ }// ��� ����������

Work_w_file::Work_w_file(const Work_w_file& w)//����������� �����������
{
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


}

Work_w_file::~Work_w_file()//����������
{
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
    cout<<"������� ����� ����������: ";getline(cin,ptr->direction,'\n');

    ptr->_next=_list;
    _list=ptr; ptr=nullptr; delete ptr;
    _size++;

}

void Work_w_file::Del()
{
    Show();

    int ndel;
    cout<<"\n�������� ����� ������, ������� ����� �������\n�����: ";cin>>ndel;
    ndel=_size-ndel;

    Element *ptr=_list, *ptr_last=nullptr;
    if(ndel)
    {
        for(int i=0; i<ndel;i++)
        {   ptr_last=ptr;
            ptr=ptr_last->_next;
        }
        ptr_last->_next=ptr->_next;
    }
    else
    {
        _list=ptr->_next;
    }
    _size--;
    ptr_last=nullptr;
    ptr=nullptr;
    delete ptr_last;
    delete ptr;

}

 void Work_w_file::Redact()
 {
       Show();

    int ndel;
    cout<<"�������� ����� ������, ������� ����� �������������\n�����: ";cin>>ndel;
    ndel=_size-ndel;
      Element *ptr=_list;
    if(ndel)
    {
        for(int i=0; i<ndel;i++)
        {
            ptr=ptr->_next;
        }
    }
    cout<<"�������� ��� ����� ������������� \n";
    cout<<"1.����\n2.C��������\n3.����� ����������\n4.��� ������\n";
    cin>>ndel;
    if((ndel==1)||(ndel==4))
    {
        cout<<"������� ����\n";
        cout<<"����:  ";   cin>>ptr->date[0];
        cout<<"�����: ";   cin>>ptr->date[1];
        cout<<"���:   ";   cin>>ptr->date[2];
    }

    if((ndel==2)||(ndel==4))
    {
        cout<<"������� ���������: ";cin>>ptr->cost;
    }

    if((ndel==3)||(ndel==4))
    {   cin.get();
        cout<<"������� ����� ����������: "; getline(cin,ptr->direction,'\n');
    }
    ptr=nullptr;
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

    ptr=nullptr;
    delete ptr;
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
    }
}

void Work_w_file::Put_in_file(string f)
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
    ptr=nullptr;
    delete ptr;

    ofstream fout("../"+f+".txt", std::ios::out);
    fout<<_size<<endl;
    for(int i=_size; i>0;i--)
    {
        ptr= new Element;
        fout<<Tmp[i-1].date[0]<<" ";
        fout<<Tmp[i-1].date[1]<<" ";
        fout<<Tmp[i-1].date[2]<<" ";
        fout<<Tmp[i-1].cost<<" ";
        fout<<Tmp[i-1].direction<<endl;

    }
    fout.close();

}

void Work_w_file::Get_from_file(string f)
{
    //������� ���������� �������
    Element *ptr=_list;
    for(int i=0; i<_size;i++)
    {
       _list=ptr->_next;
       delete ptr->_next;
       ptr=_list;
    }
    _size=0;

    ifstream fin("../"+f+".txt", std::ios::in);
    fin>>_size;
    ptr=nullptr;
    for(int i=0;i<_size;i++)
    {
        ptr=new Element;
        fin>>ptr->date[0];
        fin>>ptr->date[1];
        fin>>ptr->date[2];
        fin>>ptr->cost;
        fin.get();
        getline(fin,ptr->direction,'\n');
        ptr->_next=_list;
        _list=ptr;
    }

    fin.close();
}

 void Work_w_file::SaveBackup(string f)
 {
     Put_in_file(f);

    ifstream fin("../"+f+".txt", std::ios::in);
    ofstream fout("../R_"+f+".txt", std::ios::out);

    fout << fin.rdbuf();

    fout.close();
    fin.close();



 }
void Work_w_file::Recovery(string f)
{

     ifstream fin("../R_"+f+".txt", std::ios::in);
    ofstream fout("../"+f+".txt", std::ios::out);
    fout << fin.rdbuf();
    fout.close();
    fin.close();
     Get_from_file(f);

}
