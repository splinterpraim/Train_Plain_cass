#ifndef PLANE_H_INCLUDED
#define PLANE_H_INCLUDED
#include <iostream>
#include  <windows.h>
#include "Ticket.h"
class Plane : public Ticket
{
    public:
        Plane();
        ~Plane();
        Plane(const Plane& p);


};

#endif // PLANE_H_INCLUDED
