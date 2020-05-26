#ifndef TICKET_H_INCLUDED
#define TICKET_H_INCLUDED
#include <iostream>
#include  <windows.h>
#include "../admin/Element.h"
using namespace std;

class Ticket
{
    protected:
    string name;
    Ticket *next;

    int _size;
    Element *_list;

    public:
    Ticket();
    Ticket(const Ticket& t);
    virtual ~Ticket();


    Ticket* setNext(Ticket* b);

    bool find_ticket(int day, int month, int year, float cost, string direction);
    void Show();
    void Show_user_s_ticket(string username,int choose);
    void buy(int day, int month, int year, float cost, string direction,string username);


};
#endif // TICKET_H_INCLUDED
