#include <iostream>
#include  <windows.h>
using namespace std;


class base
{

    string name;
    int file;
    base *next;

    public:
     base(string n,int f): name(n),file(f),next(nullptr){}
    virtual ~base()
    {
        delete next;
    }

     int find_(int f){return f;}

    base* setNext(base* b)
    {
        next = b;
        return next;
    }

    void step(int par)
    {
        if(find_(file)==par)
        {
            cout<<"маршрут найден ("<<name<<")\n";
        }
        else if(next!=0)
        {
            next->step(par);
        }
        else
        {
            cout<<"маршрут не найден \n";
        }

    }

};
class train : public base
{

    public:
    train(string n,int f): base(n,f){}

};
class plane : public base
{

    public:
    plane(string n,int f): base(n,f){}

};

int main()
{
        setlocale(LC_ALL, "Rus");

        base *first= new train("Поезд",1);
         first->setNext(new plane("Самолет",2));
         first->step(2);

    return 0;
}
