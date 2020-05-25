#include "Ticket.h"
Ticket::Ticket(){cout<<"конструктор"<<endl;}
Ticket::Ticket(const Ticket& t){cout<<"конструктор коп"<<endl;}
Ticket::~Ticket()
{
    cout<<"деструктор"<<endl;
    delete next;
}



Ticket* Ticket::setNext(Ticket* b)
{
    next = b;
    return next;
}
//    int find_(int f){return f;}

/*void Ticket::buy(int day, int month, int year, float cost, string direction)
{
       //


        if(find_(file)==par)
        {
            cout<<"маршрут найден ("<<name<<")\n";
        }
        else if(next!=0)
        {
            next->step(par);
        }
        else
        {
            cout<<"маршрут не найден \n";
        }

}*/
