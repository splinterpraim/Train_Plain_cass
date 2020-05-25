#include <iostream>
#include  <windows.h>
#include <fstream>
#include "Ticket.h"
#include "Train.h"
#include "Plane.h"
using namespace std;


int main()
{
        setlocale(LC_ALL, "Rus");



        //найти билет
        //посмотреть все билеты ѕоездом
        //посмотреть все билеты —амолетом
        //выход

       // Ticket *first= new Train();
       //  first->setNext(new Plane());
        // first->step(2);
     //    delete first;





     //добавление в файл дл€ людей
      /*int s;
         fstream f("r.txt", ios::in | ios::out);


         f>>s;
         f.seekg(0,ios::beg);
         f<<s+1;
        f.seekg(0,ios::end);
         f<<5<< " "<<6<<endl;
         //cout<<" "<<s;
         f.close();*/

    return 0;
}
