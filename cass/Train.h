#ifndef TRAIN_H_INCLUDED
#define TRAIN_H_INCLUDED
#include <iostream>
#include  <windows.h>
#include "Ticket.h"
class Train : public Ticket
{

    public:
    Train();
    Train(const Train& t);
    ~Train();

};

#endif // TRAIN_H_INCLUDED
