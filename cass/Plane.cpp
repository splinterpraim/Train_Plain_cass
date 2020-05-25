#include "Plane.h"
 Plane::Plane()
 {
cout<<"конструктор P "<<endl;
 }
    //Plane(const Plane& p);
    Plane::Plane(const Plane& p){cout<<"конструктор коп P"<<endl;}
Plane::~Plane()
{
    cout<<"деструктор P "<<endl;

}
