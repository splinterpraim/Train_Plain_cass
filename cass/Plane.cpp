#include "Plane.h"
Plane::Plane():Ticket()
{
    name="Plane";
    cout<<"����������� P "<<endl;
}
Plane::Plane(const Plane& p){cout<<"����������� ��� P"<<endl;}
Plane::~Plane()
{
    cout<<"���������� P "<<endl;
}


