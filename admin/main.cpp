#include <iostream>
#include "windows.h"
#include "Work_w_file.h"


using namespace std;




int main()
{
     setlocale(LC_ALL, "Rus");
     SetConsoleCP(1251);//���� ���������
     SetConsoleOutputCP(1251);//�����

     int c;
     int exi=1;
     string type_BD;
     Work_w_file s;

     s.Add();
     s.Add();
     s.Add();



     s.Redact();
     s.Show();
    /* Work_w_file d(s);
     Work_w_file e;*/


   /*  do
     {
        system("cls");
        cout<<"�������� � ����� ����� ������ �� ������ ��������\n";
        cout<<"1.������\n2.��������\n3.�����\n";
        cin>>c;
        if(c==1) type_BD="Train";
        else if(c==2) type_BD="Plane";
        else if(c==3) return 0;


        do
        {
            system("cls");
            cout<<"1.��������\n2.��������\n3.�������\n4.�������������\n5.��������� ����������\n6.�������������� �������\n7.����� � ����\n";
            cin>>c;
            switch(c)
            {
            case 1:{system("cls");

                    break;}
            case 2:{system("cls");

                    break;}
            case 3:{system("cls");

                    break;}
            case 4:{system("cls");

                    break;}
            case 5:{system("cls");

                    break;}
            case 6:{system("cls");

                    break;}
            case 7:{system("cls");
                    exi=0;
                    break;}
            default:
                    break;


            }
        }while(exi);
        exi=1;
    }while(exi);*/
    return 0;
}
