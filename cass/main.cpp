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
        SetConsoleCP(1251);//���� ���������
        SetConsoleOutputCP(1251);//�����




    int c;
    int exi=1;
    int proverka=1;
    string username;


    do
    {
        try
        {
            system("cls");
            cout<<"\n                       ����� ���������� � ��������� \"����������� �����\"\n";
            cout<<"                      -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --\n";
            cout<<"                            -- -- -- -- -- -- -- -- -- -- -- -- --  \n";
            cout<<"\n������� ��� ������������\n(��� ������ �������� �� ���� �������� ��� ��������� ����, ��� ����)\n(�� ����������� �������: ? \ | / * \" : ) \n";
            cout<<"���: ";
            getline(cin,username);
           if((username.find('?') != string::npos)||(username.find('\\') != string::npos)||(username.find('|') != string::npos)||
              (username.find('/') != string::npos)||(username.find('*') != string::npos)||(username.find('\"') != string::npos)||(username.find(':') != string::npos)||(cin.fail()))
                throw runtime_error("Errore INPUT! (�� ����������� �������: ? \ | / * \" : )");
                proverka=0;
        }
        catch(const runtime_error &ex)
        {
            cout <<  ex.what() << endl;
            cout<<"\n������� Enter ����� ������ ��� ���. . .";
            cin.get();
        }
    }while(proverka);


    ///�������� ������ ������������
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
        cout<<"�������� ��� �� ������ �������!\n";
        cout<<"1.����� �����\n2.���������� ��������� ������ �� �����\n3.���������� ��������� ������ �� �������\n4.�����\n";

        try
        {
            cin>>c;
           if((c<1)||(c>4)||(cin.fail())||(cin.peek()!='\n'))
                throw runtime_error("Errore INPUT! ������ ������� ����� � ������ ������� ����� ������ 4 ��� ������ 1");

        }
        catch(const runtime_error &ex)
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout <<  ex.what() << endl;
            cout<<"\n������� Enter ����� ������ ��� ���. . .";
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
                string panel="������� ������ ��� ������ ������\n (���� �� �� ������ ��� �������� ��� �� ������ ������� � �����-�� ����, �� ������ ������� Enter)\n";
                cin.ignore(10000, '\n');
                do
                {
                    system("cls");
                    cout<<panel<<"������� ����\n";
                    cout<<"����: ";
                    getline(cin,buf,'\n');
                        if(buf==""){  day=0; proverka=0;}
                        else {
                                try
                                {sstreambuf.clear();  sstreambuf<<buf;buf="";  sstreambuf>>day;
                                    if((sstreambuf.fail())||(day>31)||(day<1)||(sstreambuf.peek()!=EOF))
                                        throw runtime_error("Errore INPUT! ������ ������� ����� � ������ ������� ����� ������ 31 ��� ������ 1");
                                    proverka=0;
                                }
                                catch(const runtime_error &ex)
                                {
                                    sstreambuf.clear();   sstreambuf.ignore(1000,'\n');
                                    cout <<  ex.what() << endl;
                                    cout<<"\n������� Enter ����� ������ ��� ���. . .";cin.get();
                                    proverka=1;  day=0;
                                }
                            }
                }while(proverka);

                do
                {
                    system("cls");
                    cout<<panel<<"������� ����\n";
                    cout<<"����: "<<day<<endl;
                    cout<<"�����: ";
                    getline(cin,buf,'\n');
                        if(buf==""){  month=0; proverka=0;}
                        else {
                                try
                                {sstreambuf.clear();   sstreambuf<<buf;buf="";   sstreambuf>>month;
                                    if((sstreambuf.fail())||(month>12)||(month<1)||(sstreambuf.peek()!=EOF))
                                        throw runtime_error("Errore INPUT! ������ ������� ����� � ������ ������� ����� ������ 12 ��� ������ 1");
                                    proverka=0;
                                }
                                catch(const runtime_error &ex)
                                {
                                    sstreambuf.clear();  sstreambuf.ignore(1000,'\n');
                                    cout <<  ex.what() << endl;
                                    cout<<"\n������� Enter ����� ������ ��� ���. . .";cin.get();
                                    proverka=1;  month=0;
                                }
                            }
                }while(proverka);

                do
                {
                    system("cls");
                    cout<<panel<<"������� ����\n";
                    cout<<"����: "<<day<<endl;
                    cout<<"�����: "<<month<<endl;
                    cout<<"���:   ";
                    getline(cin,buf,'\n');
                        if(buf==""){  year=0; proverka=0;}
                        else {
                                try
                                {sstreambuf.clear();   sstreambuf<<buf;buf="";   sstreambuf>>year;
                                    if((sstreambuf.fail())||(srvn_date(day,month,year))||(sstreambuf.peek()!=EOF))
                                        throw runtime_error("Errore INPUT! ������ ������� ����� � ������ ������� ����, ������� ��������� � �������");
                                    proverka=0;
                                }
                                catch(const runtime_error &ex)
                                {
                                    sstreambuf.clear();  sstreambuf.ignore(1000,'\n');
                                    cout <<  ex.what() << endl;
                                    cout<<"\n������� Enter ����� ������ ��� ���. . .";cin.get();
                                    proverka=1;  year=0;
                                }
                            }
                }while(proverka);

                do
                {
                    system("cls");
                    cout<<panel<<"������� ����\n";
                    cout<<"����: "<<day<<endl;
                    cout<<"�����: "<<month<<endl;
                    cout<<"���:   "<<year<<endl;
                    cout<<"������� ���������: ";
                    getline(cin,buf,'\n');
                        if(buf==""){  cost=0; proverka=0;}
                        else {
                                try
                                {sstreambuf.clear();   sstreambuf<<buf;buf="";   sstreambuf>>cost;
                                    if((sstreambuf.fail())||(cost<0)||(sstreambuf.peek()!=EOF))
                                        throw runtime_error("Errore INPUT! ������ ������� ����� � ������ ������� ����� ������ 0, ����� ������� ��������� ����� \'.\' (1226.56) ");
                                    proverka=0;
                                }
                                catch(const runtime_error &ex)
                                {
                                    sstreambuf.clear();  sstreambuf.ignore(1000,'\n');
                                    cout <<  ex.what() << endl;
                                    cout<<"\n������� Enter ����� ������ ��� ���. . .";cin.get();
                                    proverka=1;  cost=0;
                                }
                            }
                }while(proverka);

                system("cls");
                cout<<panel<<"������� ����\n";
                cout<<"����: "<<day<<endl;
                cout<<"�����: "<<month<<endl;
                cout<<"���:   "<<year<<endl;
                cout<<"������� ���������: "<<cost<<endl;



                cout<<"������� ����� ����������: ";getline(cin,direction,'\n');

                system("cls");
                cout<<panel<<"������� ����\n";
                cout<<"����: "<<day<<endl;
                cout<<"�����: "<<month<<endl;
                cout<<"���:   "<<year<<endl;
                cout<<"������� ���������: "<<cost<<endl;
                cout<<"������� ����� ����������: ";
                if(direction=="")cout<<"-"<<endl;
                else cout<<direction<<endl;


                first->buy(day, month,year, cost, direction,username);
                cout<<"\n������� Enter ����� �������� � ����. . .";
                cin.get();
                break;}
        case 2:{system("cls");
                first->Show_user_s_ticket(username,1);
                cout<<"\n������� Enter ����� �������� � ����. . .";
                cin.get();cin.get();
                break;}
        case 3:{system("cls");
                first->Show_user_s_ticket(username,2);
                cout<<"\n������� Enter ����� �������� � ����. . .";
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
