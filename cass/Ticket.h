#ifndef TICKET_H_INCLUDED
#define TICKET_H_INCLUDED
#include <iostream>
#include  <windows.h>
using namespace std;

class Ticket
{

    string name;
    Ticket *next;

   // int _size;
  //  Element *_list;

    public:
    Ticket();
    Ticket(const Ticket& t);
    virtual ~Ticket();


    Ticket* setNext(Ticket* b);

    //  int find_(int f);
    void buy(int day, int month, int year, float cost, string direction);


};
#endif // TICKET_H_INCLUDED
