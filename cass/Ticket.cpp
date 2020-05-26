#include <fstream>
#include "Ticket.h"
Ticket::Ticket(){
    name="";
    next=nullptr;
    _size=0;
    _list=nullptr;
    cout<<"конструктор"<<endl;}
Ticket::Ticket(const Ticket& t){cout<<"конструктор коп"<<endl;}
Ticket::~Ticket()
{
    cout<<"деструктор"<<endl;
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



Ticket* Ticket::setNext(Ticket* b)
{
    next = b;
    return next;
}
bool Ticket::find_ticket(int day, int month, int year, float cost, string direction)
{
    Element *pt=_list;
    for(int i=0; i<_size;i++)
    {
       _list=pt->_next;
       delete pt->_next;
       pt=_list;
    }
    _size=0;
    pt=nullptr;
    delete pt;


    bool result=0;
    int s=0;
    int d[3];
    float cost_f;
    string dir_f;
    ifstream fin("../"+name+".txt", ios::in);
    fin>>s;
    Element mass[s];
    for(int i=0;i<s;i++)
    {
        fin>>d[0];
        fin>>d[1];
        fin>>d[2];
        fin>>cost_f;fin.get();
        getline(fin,dir_f);

        if(((d[0]==day)||(day==0))&&((d[1]==month)||(month==0))&&((d[2]==year)||(year==0))&&((cost_f==cost)||(cost==0))&&((dir_f==direction)||(direction=="")))
        {
            mass[_size].date[0]=d[0];
            mass[_size].date[1]=d[1];
            mass[_size].date[2]=d[2];
            mass[_size].cost=cost_f;
            mass[_size].direction=dir_f;
            _size++;
            result=1;
        }

    }
    fin.close();

    if(result)
    {
        for(int i=_size;i>0;i--)
        {
            Element *ptr=new Element;
            ptr->date[0]= mass[i-1].date[0];
            ptr->date[1]=mass[i-1].date[1];
            ptr->date[2]=mass[i-1].date[1];
            ptr->cost=mass[i-1].cost;
            ptr->direction=mass[i-1].direction;
            ptr->_next=_list;
            _list=ptr;

            ptr=nullptr;
            delete ptr;
        }

    }


    return result;
}
void Ticket::Show()
{

        Element *ptr=_list;
        for(int i=0;i<_size;i++)
        {

            cout<<endl<<"БИЛЕТ № "<<i+1<<endl;
            cout<<"Дата\n";
            cout<<"День:  "<<ptr->date[0]<<endl;
            cout<<"Месяц: "<<ptr->date[1]<<endl;
            cout<<"Год:   "<<ptr->date[2]<<endl;
            cout<<"Cтоимость:  "<<ptr->cost<<endl;
            cout<<"Пункт назначения: "<<ptr->direction<<endl;
            ptr=ptr->_next;
        }
        ptr=nullptr;
        delete ptr;
}

void Ticket::Show_user_s_ticket(string username,int choose)
{


    int s=0;
    int d[3];
    float cost_f;
    string dir_f;
    if(choose==2){next->Show_user_s_ticket(username,1);return;}
    cout<<"Купленные билеты\n";
    ifstream fin("users/"+username+"_"+name+".txt", ios::in);
    fin>>s;
    if(!s){cout<<"Билетов нет\n";}
    else
    for(int i=0;i<s;i++)
    {
        fin>>d[0];
        fin>>d[1];
        fin>>d[2];
        fin>>cost_f;fin.get();
        getline(fin,dir_f);

        cout<<endl<<"БИЛЕТ № "<<i+1<<endl;
        cout<<"Дата\n";
        cout<<"День:  "<<d[0]<<endl;
        cout<<"Месяц: "<<d[1]<<endl;
        cout<<"Год:   "<<d[2]<<endl;
        cout<<"Cтоимость:  "<<cost_f<<endl;
        cout<<"Пункт назначения: "<<dir_f<<endl;
    }
    fin.close();
}
void Ticket::buy(int day, int month, int year, float cost, string direction,string username)
{

        if(find_ticket(day, month, year, cost, direction))
        {
            cout<<"                     ===================="<<endl;
            cout<<"                    || Билеты на "<<name<<" ||"<<endl;
            cout<<"=============================================================="<<endl;
            Show();
            cout<<"=============================================================="<<endl;
            cout<<"Билетов найдено: "<<_size<<endl;
            int num=1;
            if(_size>1){cout<<endl<<"Выбирите билет который хотите купить\nНомер: ";cin>>num;}

            Element *ptr=_list;
            if(num>1)
            {
                for(int i=1;i<num;i++)
                {
                    ptr=ptr->_next;
                }
                cout<<endl<<"БИЛЕТ № "<<num<<endl;
                cout<<"Дата\n";
                cout<<"День:  "<<ptr->date[0]<<endl;
                cout<<"Месяц: "<<ptr->date[1]<<endl;
                cout<<"Год:   "<<ptr->date[2]<<endl;
                cout<<"Cтоимость:  "<<ptr->cost<<endl;
                cout<<"Пункт назначения: "<<ptr->direction<<endl;
            }


            char T='n';
            cout<<endl<<"Подтвердите покупку Билета №"<<num<<"\n(y/n): ";cin>>T;
            if(T=='y')
            {
                int s=0;

                fstream fuser("users/"+username+"_"+name+".txt", ios::in | ios::out);
                fuser>>s;
                fuser.seekg(0,ios::beg);
                fuser<<s+1;
                fuser.seekg(0,ios::end);
                fuser<<ptr->date[0];    fuser<<" ";
                fuser<<ptr->date[0];    fuser<<" ";
                fuser<<ptr->date[0];    fuser<<" ";
                fuser<<ptr->cost;       fuser<<" ";
                fuser<<ptr->direction;  fuser<<"\n";

                fuser.close();

            }
            ptr=nullptr;
            delete ptr;
            cout<<"Билет куплен\n";

        }
        else if(next!=0)
        {
            next->buy(day, month, year, cost, direction,username);
        }
        else
        {
            cout<<"Маршрут не найден \n";
        }

}
