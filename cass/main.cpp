#include <iostream>
#include  <windows.h>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "Ticket.h"
#include "Train.h"
#include "Plane.h"
using namespace std;

bool srvn_date(int day, int month, int year);
int main()
{
        setlocale(LC_ALL, "Rus");
        SetConsoleCP(1251);
        SetConsoleOutputCP(1251);




    int c;
    int exi=1;
    int proverka=1;
    string username;


    do
    {
        try
        {
            system("cls");
            cout<<"\n                       Welcome to program \"ELECTRONIC CASH\"\n";
            cout<<"                      -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --\n";
            cout<<"                            -- -- -- -- -- -- -- -- -- -- -- -- --  \n";
            cout<<"\nEnter username\n(The name must consist of Cyrillic letters or Latin letters, or numbers)\n(No characters allowed: ? \ | / * \" : ) \n";
            cout<<"Username: ";
            getline(cin,username);
           if((username.find('?') != string::npos)||(username.find('\\') != string::npos)||(username.find('|') != string::npos)||
              (username.find('/') != string::npos)||(username.find('*') != string::npos)||(username.find('\"') != string::npos)||(username.find(':') != string::npos)||(cin.fail()))
                throw runtime_error("Errore INPUT! (No characters allowed: ? \ | / * \" : )");
                proverka=0;
        }
        catch(const runtime_error &ex)
        {
            cout <<  ex.what() << endl;
            cout<<"\nPress Enter to enter again. . .";
            cin.get();
        }
    }while(proverka);


    ///Creating user files
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
        cout<<"Choose what you want to do!\n";
        cout<<"1.Find a ticket\n2.View purchased Train tickets\n3.View purchased Plane tickets\n4.Exit\n";

        try
        {
            cin>>c;
           if((c<1)||(c>4)||(cin.fail())||(cin.peek()!='\n'))
                throw runtime_error("Errore INPUT! You cannot enter letters and you cannot enter numbers greater than 4 or less than 1");

        }
        catch(const runtime_error &ex)
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout <<  ex.what() << endl;
            cout<<"\nPress Enter to enter again. . .";
            cin.get();
            c=0;

        }

        switch(c)
        {
        case 1:{system("cls");
                stringstream sstreambuf;
                int day=0,month=0,year=0;
                float cost=0;
                string direction="";
                string buf="";
                string panel="Enter your ticket search details\n (if you don’t know what to write or don’t want to type in any field, then just press Enter)\n";
                cin.ignore(10000, '\n');
                do
                {
                    system("cls");
                    cout<<panel<<"Enter date\n";
                    cout<<"Day: ";
                    getline(cin,buf,'\n');
                        if(buf==""){  day=0; proverka=0;}
                        else {
                                try
                                {sstreambuf.clear();  sstreambuf<<buf;buf="";  sstreambuf>>day;
                                    if((sstreambuf.fail())||(day>31)||(day<1)||(sstreambuf.peek()!=EOF))
                                        throw runtime_error("Errore INPUT! You cannot enter letters or enter numbers greater than 31 or less than 1");
                                    proverka=0;
                                }
                                catch(const runtime_error &ex)
                                {
                                    sstreambuf.clear();   sstreambuf.ignore(1000,'\n');
                                    cout <<  ex.what() << endl;
                                    cout<<"\nPress Enter to enter again. . .";cin.get();
                                    proverka=1;  day=0;
                                }
                            }
                }while(proverka);

                do
                {
                    system("cls");
                    cout<<panel<<"Enter date\n";
                    cout<<"Day: "<<day<<endl;
                    cout<<"Month: ";
                    getline(cin,buf,'\n');
                        if(buf==""){  month=0; proverka=0;}
                        else {
                                try
                                {sstreambuf.clear();   sstreambuf<<buf;buf="";   sstreambuf>>month;
                                    if((sstreambuf.fail())||(month>12)||(month<1)||(sstreambuf.peek()!=EOF))
                                        throw runtime_error("Errore INPUT! You cannot enter letters or enter numbers greater than 12 or less than 1");
                                    proverka=0;
                                }
                                catch(const runtime_error &ex)
                                {
                                    sstreambuf.clear();  sstreambuf.ignore(1000,'\n');
                                    cout <<  ex.what() << endl;
                                    cout<<"\nPress Enter to enter again. . .";cin.get();
                                    proverka=1;  month=0;
                                }
                            }
                }while(proverka);

                do
                {
                    system("cls");
                    cout<<panel<<"Enter date\n";
                    cout<<"Day: "<<day<<endl;
                    cout<<"Month: "<<month<<endl;
                    cout<<"Year:   ";
                    getline(cin,buf,'\n');
                        if(buf==""){  year=0; proverka=0;}
                        else {
                                try
                                {sstreambuf.clear();   sstreambuf<<buf;buf="";   sstreambuf>>year;
                                    if((sstreambuf.fail())||(srvn_date(day,month,year))||(sstreambuf.peek()!=EOF))
                                        throw runtime_error("Errore INPUT! You cannot enter letters or enter a date that is in the past");
                                    proverka=0;
                                }
                                catch(const runtime_error &ex)
                                {
                                    sstreambuf.clear();  sstreambuf.ignore(1000,'\n');
                                    cout <<  ex.what() << endl;
                                    cout<<"\nPress Enter to enter again. . .";cin.get();
                                    proverka=1;  year=0;
                                }
                            }
                }while(proverka);

                do
                {
                    system("cls");
                    cout<<panel<<"Enter date\n";
                    cout<<"Day: "<<day<<endl;
                    cout<<"Month: "<<month<<endl;
                    cout<<"Year:   "<<year<<endl;
                    cout<<"Enter cost: ";
                    getline(cin,buf,'\n');
                        if(buf==""){  cost=0; proverka=0;}
                        else {
                                try
                                {sstreambuf.clear();   sstreambuf<<buf;buf="";   sstreambuf>>cost;
                                    if((sstreambuf.fail())||(cost<0)||(sstreambuf.peek()!=EOF))
                                        throw runtime_error("Errore INPUT! You can not enter letters and you can not enter numbers less than 0, also enter the cost using \'.\' (1226.56) ");
                                    proverka=0;
                                }
                                catch(const runtime_error &ex)
                                {
                                    sstreambuf.clear();  sstreambuf.ignore(1000,'\n');
                                    cout <<  ex.what() << endl;
                                    cout<<"\nPress Enter to enter again. . .";cin.get();
                                    proverka=1;  cost=0;
                                }
                            }
                }while(proverka);

                system("cls");
                cout<<panel<<"Enter date\n";
                cout<<"Day: "<<day<<endl;
                cout<<"Month: "<<month<<endl;
                cout<<"Year:   "<<year<<endl;
                cout<<"Enter cost: "<<cost<<endl;



                cout<<"Enter Destination: ";getline(cin,direction,'\n');

                system("cls");
                cout<<panel<<"Enter date\n";
                cout<<"Day: "<<day<<endl;
                cout<<"Month: "<<month<<endl;
                cout<<"Year:   "<<year<<endl;
                cout<<"Enter cost: "<<cost<<endl;
                cout<<"Enter Destination: ";
                if(direction=="")cout<<"-"<<endl;
                else cout<<direction<<endl;


                first->buy(day, month,year, cost, direction,username);
                cout<<"\nPress Enter to return to the menu. . .";
                cin.get();
                break;}
        case 2:{system("cls");
                first->Show_user_s_ticket(username,1);
                cout<<"\nPress Enter to return to the menu. . .";
                cin.get();cin.get();
                break;}
        case 3:{system("cls");
                first->Show_user_s_ticket(username,2);
                cout<<"\nPress Enter to return to the menu. . .";
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

bool srvn_date(int day, int month, int year)
{
     SYSTEMTIME lt;
    GetLocalTime(&lt);


    if(((day==0)&&(month==0))||((day!=0)&&(month==0)))
    {
        if(year<lt.wYear) return 1;
        else return 0;
    }

    if((day==0)&&(month!=0))
    {
        if(year<lt.wYear) return 1;
        else if(year>lt.wYear) return 0;
        else
        {
            if(month<lt.wMonth) return 1;
            else if(month>lt.wMonth) return 0;
        }
     }

     if((day!=0)&&(month!=0))
     {

        if(year<lt.wYear) return 1;
        else if(year>lt.wYear) return 0;
        else
        {
            if(month<lt.wMonth) return 1;
            else if(month>lt.wMonth) return 0;
            else
            {
                if(day<lt.wDay) return 1;
                else return 0;
            }
        }
     }

}
