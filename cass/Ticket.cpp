#include "Ticket.h"
Ticket::Ticket(){cout<<"�����������"<<endl;}
Ticket::Ticket(const Ticket& t){cout<<"����������� ���"<<endl;}
Ticket::~Ticket()
{
    cout<<"����������"<<endl;
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
            cout<<"������� ������ ("<<name<<")\n";
        }
        else if(next!=0)
        {
            next->step(par);
        }
        else
        {
            cout<<"������� �� ������ \n";
        }

}*/
