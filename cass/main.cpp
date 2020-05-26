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
        SetConsoleCP(1251);//ввод кодировки
        SetConsoleOutputCP(1251);//вывод


/*



        int prov=0;


        fstream creat_T(username+"_Train"+".txt");
        if(!(creat_T.is_open()))
        {
            creat_T.open(username+"_Train"+".txt", ios::out);
            creat_T<<0<<endl;
        }
        creat_T.close();

        fstream creat_P(username+"_Plane"+".txt");
        if(!(creat_P.is_open()))
        {
            creat_P.open(username+"_Plane"+".txt", ios::out);
            creat_P<<0<<endl;
        }
        creat_P.close();








        */




        //найти билет
        //посмотреть купленные билеты
        //посмотреть все билеты Самолетом
        //выход
    int c;
    int exi=1;
    string username;
    cout<<"\n                       Добро пожаловать в программу \"ЭЛЕКТРОННАЯ КАССА\"\n";
    cout<<"                      -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --\n";
    cout<<"                            -- -- -- -- -- -- -- -- -- -- -- -- --  \n";
    cout<<"\nВведите имя пользователя\n"; cout<<"Имя: ";cin>>username;

    ///Создание файлов пользователя
    int prov=0;
    fstream creat_T("users/"+username+"_Train"+".txt");
    if(!(creat_T.is_open()))
    {
        creat_T.open("users/"+username+"_Train"+".txt", ios::out);
        creat_T<<0<<endl;
    }
    creat_T.close();

    fstream creat_P("users/"+username+"_Plane"+".txt");
    if(!(creat_P.is_open()))
    {
        creat_P.open("users/"+username+"_Plane"+".txt", ios::out);
        creat_P<<0<<endl;
    }
    creat_P.close();
    ///





    Ticket *first= new Train();
    first->setNext(new Plane());


    do
     {
        system("cls");
        cout<<"Выбирите что вы хотите сделать!\n";
        cout<<"1.Найти билет\n2.Посмотреть купленные билеты на Поезд\n3.Посмотреть купленные билеты на Самолет\n4.Выход\n";
        cin>>c;
        switch(c)
        {
        case 1:{system("cls");
                int day=0,month=0,year=0;
                float cost=0;
                string direction="";
                cout<<"Введите данные для поиска билета\n (если вы не знаете что написать или не хотите вводить в какое-то поле, то просто нажмите Enter)\n";
                cout<<"Введите дату\n";
                cout<<"День:  ";   cin>>day;
                cout<<"Месяц: ";   cin>>month;
                cout<<"Год:   ";   cin>>year;
                cout<<"Введите стоимость: ";cin>>cost;cin.get();
                cout<<"Введите Пункт назначения: ";getline(cin,direction,'\n');
                first->buy(day, month,year, cost, direction,username);
                cout<<"\nНажмите Enter чтобы вернутся в меню. . .";
                cin.get();cin.get();
                break;}
        case 2:{system("cls");
                first->Show_user_s_ticket(username,1);
                cout<<"\nНажмите Enter чтобы вернутся в меню. . .";
                cin.get();cin.get();
                break;}
        case 3:{system("cls");
                first->Show_user_s_ticket(username,2);
                cout<<"\nНажмите Enter чтобы вернутся в меню. . .";
                cin.get();cin.get();
                break;}
        case 4:{system("cls");
                exi=0;
                break;}
        default:
                break;
        }
    }while(exi);

   delete first;

    return 0;
}
