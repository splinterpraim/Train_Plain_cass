#include "Plane.h"
Plane::Plane():Ticket()
{
    name="Plane";
    cout<<"конструктор P "<<endl;
}
Plane::Plane(const Plane& p){cout<<"конструктор коп P"<<endl;}
Plane::~Plane()
{
    cout<<"деструктор P "<<endl;
}


