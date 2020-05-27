#include <iostream>
#include  <windows.h>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "Ticket.h"
#include "Train.h"
#include "Plane.h"
using namespace std;


int main()
{
        setlocale(LC_ALL, "Rus");
        SetConsoleCP(1251);//ввод кодировки
        SetConsoleOutputCP(1251);//вывод


    int c;
    int exi=1;
    int proverka=1;
    string username;
    cout<<"\n                       Добро пожаловать в программу \"ЭЛЕКТРОННАЯ КАССА\"\n";
    cout<<"                      -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --\n";
    cout<<"                            -- -- -- -- -- -- -- -- -- -- -- -- --  \n";
    cout<<"\nВведите имя пользователя\n(Имя должно состоять из букв кирилицы или латинских букв, или цифр)\n(Не допускаются символы: ? \ | / * \" : ) \n";


    do
    {
        try
        {
            cout<<"Имя: ";
            cin>>username;
           if((username.find('?') != string::npos)||(username.find('\\') != string::npos)||(username.find('|') != string::npos)||
              (username.find('/') != string::npos)||(username.find('*') != string::npos)||(username.find('\"') != string::npos)||(username.find(':') != string::npos)||(cin.fail()))
                throw runtime_error("Errore INPUT! (Не допускаются символы: ? \ | / * \" : )");
                proverka=0;
        }
        catch(const runtime_error &ex)
        {
            cout <<  ex.what() << endl;
            cout<<"\nНажмите Enter чтобы ввести еще раз. . .";
            cin.get();cin.get();

        }
    }while(proverka);


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
                stringstream sstreambuf;
                int day=0,month=0,year=0;
                float cost=0;
                string direction="";
                string buf="";
                cout<<"Введите данные для поиска билета\n (если вы не знаете что написать или не хотите вводить в какое-то поле, то просто нажмите Enter)\n";
                cout<<"Введите дату\n";cin.get();
                cout<<"День:  ";   getline(cin,buf);
                    if(buf==""){  sstreambuf<<0<<" "; }
                    else { sstreambuf<<buf<<" ";  buf="";}
                cout<<"Месяц: ";   getline(cin,buf);
                    if(buf==""){  sstreambuf<<0<<" "; }
                    else { sstreambuf<<buf<<" ";  buf="";}
                cout<<"Год:   ";   getline(cin,buf);
                    if(buf==""){  sstreambuf<<0<<" "; }
                    else { sstreambuf<<buf<<" ";  buf="";}
                cout<<"Введите стоимость: ";getline(cin,buf);
                    if(buf==""){  sstreambuf<<0<<" "; }
                    else { sstreambuf<<buf<<" ";  buf="";}
                cout<<"Введите Пункт назначения: ";getline(cin,buf,'\n');
                    if(buf==""){  sstreambuf<<""<<" "; }
                    else { sstreambuf<<buf;  buf="";}
                sstreambuf>>day;
                sstreambuf>>month;
                sstreambuf>>year;
                sstreambuf>>cost;
                sstreambuf.get();
                getline(sstreambuf,direction);
                getline(sstreambuf,buf);
               // cout<<endl<<day<<endl<<month<<endl<<year<<endl<<cost<<endl<<direction<<"ffff";
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
