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

    // s.Add();
    // s.Add();
    // s.Add();s.Show();

    // s.Redact();
     //s.Show();
    // s.Put_in_file("../Plane.txt");
//s.Recovery("Plane");
//s.Get_from_file("../Plane.txt");
//s.Show();





     do
     {
        system("cls");
        cout<<"�������� � ����� ����� ������ �� ������ ��������\n";
        cout<<"1.������\n2.��������\n3.�����\n";
        cin>>c;
        if(c==1) type_BD="Train";
        else if(c==2) type_BD="Plane";
        else if(c==3) return 0;
        s.Get_from_file(type_BD);

        do
        {
            system("cls");
            cout<<"1.��������\n2.��������\n3.�������\n4.�������������\n5.��������� ����������\n6.�������������� �������\n7.����� � ����\n";
            cin>>c;
            switch(c)
            {
            case 1:{system("cls");
                    s.Show();
                    cout<<"\n������� Enter ����� �������� � ����. . .";
                    cin.get();cin.get();
                    break;}
            case 2:{system("cls");
                    s.Add();
                    cout<<"\n�� �������� �����!\n������� Enter ����� �������� � ����. . .";
                    cin.get();
                    break;}
            case 3:{system("cls");
                    s.Del();
                    cout<<"\n����� ������!\n������� Enter ����� �������� � ����. . .";
                    cin.get();cin.get();
                    break;}
            case 4:{system("cls");
                    s.Redact();
                    cout<<"\n����� ��������������!\n������� Enter ����� �������� � ����. . .";
                    cin.get();
                    break;}
            case 5:{system("cls");
                    s.SaveBackup(type_BD);
                    cout<<"\n��������� ����������� �������!\n������� Enter ����� �������� � ����. . .";
                    cin.get();cin.get();
                    break;}
            case 6:{system("cls");
                    s.Recovery(type_BD);
                    cout<<"\n������ �������������!\n������� Enter ����� �������� � ����. . .";
                    cin.get();cin.get();
                    break;}
            case 7:{system("cls");
                    s.Put_in_file(type_BD);
                    exi=0;
                    break;}
            default:
                    break;


            }
        }while(exi);
        exi=1;
    }while(exi);
    return 0;
}
