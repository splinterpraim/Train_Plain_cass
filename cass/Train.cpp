#include "Train.h"
 Train::Train():Ticket()
 {
     name="Train";
    cout<<"конструктор T "<<endl;
 }
Train::Train(const Train& t){cout<<"конструктор коп T"<<endl;}
Train::~Train()
{
    cout<<"деструктор T "<<endl;

}
