#include "Train.h"
 Train::Train():Ticket()
 {
     name="Train";
    cout<<"����������� T "<<endl;
 }
Train::Train(const Train& t){cout<<"����������� ��� T"<<endl;}
Train::~Train()
{
    cout<<"���������� T "<<endl;

}
