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
        SetConsoleCP(1251);//���� ���������
        SetConsoleOutputCP(1251);//�����


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




        //����� �����
        //���������� ��������� ������
        //���������� ��� ������ ���������
        //�����
    int c;
    int exi=1;
    string username;
    cout<<"\n                       ����� ���������� � ��������� \"����������� �����\"\n";
    cout<<"                      -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --\n";
    cout<<"                            -- -- -- -- -- -- -- -- -- -- -- -- --  \n";
    cout<<"\n������� ��� ������������\n"; cout<<"���: ";cin>>username;

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
        cin>>c;
        switch(c)
        {
        case 1:{system("cls");
                int day=0,month=0,year=0;
                float cost=0;
                string direction="";
                cout<<"������� ������ ��� ������ ������\n (���� �� �� ������ ��� �������� ��� �� ������ ������� � �����-�� ����, �� ������ ������� Enter)\n";
                cout<<"������� ����\n";
                cout<<"����:  ";   cin>>day;
                cout<<"�����: ";   cin>>month;
                cout<<"���:   ";   cin>>year;
                cout<<"������� ���������: ";cin>>cost;cin.get();
                cout<<"������� ����� ����������: ";getline(cin,direction,'\n');
                first->buy(day, month,year, cost, direction,username);
                cout<<"\n������� Enter ����� �������� � ����. . .";
                cin.get();cin.get();
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
