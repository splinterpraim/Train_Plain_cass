#include <iostream>
#include <string>
#include "Work_w_file.h"
using namespace std;
Work_w_file::Work_w_file() : _size(0),_list(nullptr){ }

Work_w_file::Work_w_file(const Work_w_file& w)
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

Work_w_file::~Work_w_file()
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
    cout<<"Enter date\n";
    cout<<"Day:  ";   cin>>ptr->date[0];
    cout<<"Month: ";   cin>>ptr->date[1];
    cout<<"Year:   ";   cin>>ptr->date[2];
    cout<<"Enter cost: ";cin>>ptr->cost;cin.get();
    cout<<"Enter Destination: ";getline(cin,ptr->direction,'\n');

    ptr->_next=_list;
    _list=ptr; ptr=nullptr; delete ptr;
    _size++;
    Sort();

}

void Work_w_file::Del()
{
    Show();

    int ndel;
    cout<<"\nWrite the number of the ticket to be deleted\nNumber: ";cin>>ndel;
    ndel-=1;

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
    cout<<"Write the ticket number you want to edit\nNumber: ";cin>>ndel;
    ndel-=1;
      Element *ptr=_list;
    if(ndel)
    {
        for(int i=0; i<ndel;i++)
        {
            ptr=ptr->_next;
        }
    }
    cout<<"Choose what to edit \n";
    cout<<"1.The date\n2.The cost\n3.The Destination\n4.All items\n";
    cin>>ndel;
    if((ndel==1)||(ndel==4))
    {
        cout<<"Enter date\n";
        cout<<"Day:  ";   cin>>ptr->date[0];
        cout<<"Month: ";   cin>>ptr->date[1];
        cout<<"Year:   ";   cin>>ptr->date[2];
        Sort();
    }

    if((ndel==2)||(ndel==4))
    {
        cout<<"Enter cost: ";cin>>ptr->cost;
    }

    if((ndel==3)||(ndel==4))
    {   cin.get();
        cout<<"Enter Destination: "; getline(cin,ptr->direction,'\n');
    }
    ptr=nullptr;
    delete ptr;


 }


void Work_w_file::Show()
{
    if(!_list){cout<<"No tickets\n";}
    else
    {
        Element *ptr=_list;
        for(int i=0;i<_size;i++)
        {
            cout<<"TICKET # "<<i+1<<endl;
            cout<<"The date\n";
            cout<<"Day:  "<<ptr->date[0]<<endl;
            cout<<"Month: "<<ptr->date[1]<<endl;
            cout<<"Year:   "<<ptr->date[2]<<endl;
            cout<<"Cost:  "<<ptr->cost<<endl;
            cout<<"Destination: "<<ptr->direction<<endl;
            ptr=ptr->_next;
        }
        ptr=nullptr;
        delete ptr;
    }
}

void Work_w_file::Put_in_file(string f)
{
    Element *ptr=_list;

    ofstream fout("../"+f+".txt", std::ios::out);
    fout<<_size<<endl;
    for(int i=0;i<_size;i++)
    {
        fout<<ptr->date[0]<<" ";
        fout<<ptr->date[1]<<" ";
        fout<<ptr->date[2]<<" ";
        fout<<ptr->cost<<" ";
        fout<<ptr->direction<<endl;
        ptr=ptr->_next;

    }
    fout.close();
    ptr=nullptr;
    delete ptr;
}

void Work_w_file::Get_from_file(string f)
{

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
    Sort();
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

void Work_w_file::Sort()
{
    Element *ptr=_list;
    Element Tmp[_size];


    for(int i=0; i<_size;i++)
    {
        Tmp[i].date[0]=ptr->date[0];     ptr->date[0]=0;
        Tmp[i].date[1]=ptr->date[1];     ptr->date[1]=0;
        Tmp[i].date[2]=ptr->date[2];     ptr->date[2]=0;
        Tmp[i].cost=ptr->cost;           ptr->cost=0;
        Tmp[i].direction=ptr->direction; ptr->direction="";
        ptr=ptr->_next;
    }


    int buf[3];
    float buf_c;
    string buf_di;
    int k=0;
    for(int j=0; j<_size;j++)
    {
        for(int i=0; i<_size-1-k;i++)
        {
            if( Tmp[i].date[2] > Tmp[i+1].date[2])
            {
                buf[0]=Tmp[i].date[0];
                buf[1]=Tmp[i].date[1];
                buf[2]=Tmp[i].date[2];
                buf_c=Tmp[i].cost;
                buf_di=Tmp[i].direction;

                Tmp[i].date[0]=Tmp[i+1].date[0];
                Tmp[i].date[1]=Tmp[i+1].date[1];
                Tmp[i].date[2]=Tmp[i+1].date[2];
                Tmp[i].cost=Tmp[i+1].cost;
                Tmp[i].direction=Tmp[i+1].direction;

                Tmp[i+1].date[0]=buf[0];
                Tmp[i+1].date[1]=buf[1];
                Tmp[i+1].date[2]=buf[2];
                Tmp[i+1].cost=buf_c;
                Tmp[i+1].direction=buf_di;

            }
            else if(Tmp[i].date[2] == Tmp[i+1].date[2])
            {
                if( Tmp[i].date[1] > Tmp[i+1].date[1])
                {
                    buf[0]=Tmp[i].date[0];
                    buf[1]=Tmp[i].date[1];
                    buf[2]=Tmp[i].date[2];
                    buf_c=Tmp[i].cost;
                    buf_di=Tmp[i].direction;

                    Tmp[i].date[0]=Tmp[i+1].date[0];
                    Tmp[i].date[1]=Tmp[i+1].date[1];
                    Tmp[i].date[2]=Tmp[i+1].date[2];
                    Tmp[i].cost=Tmp[i+1].cost;
                    Tmp[i].direction=Tmp[i+1].direction;

                    Tmp[i+1].date[0]=buf[0];
                    Tmp[i+1].date[1]=buf[1];
                    Tmp[i+1].date[2]=buf[2];
                    Tmp[i+1].cost=buf_c;
                    Tmp[i+1].direction=buf_di;
                }
                else if( Tmp[i].date[1] == Tmp[i+1].date[1])
                {
                    if( Tmp[i].date[0] > Tmp[i+1].date[0])
                    {
                        buf[0]=Tmp[i].date[0];
                        buf[1]=Tmp[i].date[1];
                        buf[2]=Tmp[i].date[2];
                        buf_c=Tmp[i].cost;
                        buf_di=Tmp[i].direction;

                        Tmp[i].date[0]=Tmp[i+1].date[0];
                        Tmp[i].date[1]=Tmp[i+1].date[1];
                        Tmp[i].date[2]=Tmp[i+1].date[2];
                        Tmp[i].cost=Tmp[i+1].cost;
                        Tmp[i].direction=Tmp[i+1].direction;

                        Tmp[i+1].date[0]=buf[0];
                        Tmp[i+1].date[1]=buf[1];
                        Tmp[i+1].date[2]=buf[2];
                        Tmp[i+1].cost=buf_c;
                        Tmp[i+1].direction=buf_di;
                    }
                }
            }
        }
        k++;
    }

    ptr=_list;

    for(int i=0;i<_size;i++)
    {
        ptr->date[0]=Tmp[i].date[0];
        ptr->date[1]=Tmp[i].date[1];
        ptr->date[2]=Tmp[i].date[2];
        ptr->cost=Tmp[i].cost;
        ptr->direction=Tmp[i].direction;
        ptr=ptr->_next;
    }
     ptr=nullptr;
     delete ptr;
}



