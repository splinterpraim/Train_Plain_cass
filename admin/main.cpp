#include <iostream>
#include "windows.h"
#include "Work_w_file.h"


using namespace std;




int main()
{
     setlocale(LC_ALL, "Rus");
     SetConsoleCP(1251);//ввод кодировки
     SetConsoleOutputCP(1251);//вывод

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
        cout<<"Выберите с какой базой данных вы хотите работать\n";
        cout<<"1.Поезда\n2.Самолеты\n3.Выход\n";
        cin>>c;
        if(c==1) type_BD="Train";
        else if(c==2) type_BD="Plane";
        else if(c==3) return 0;


        do
        {
            system("cls");
            cout<<"1.Показать\n2.Добавить\n3.Удалить\n4.Редоктировать\n5.Резервное сохранение\n6.Восстановление записей\n7.Выход в меню\n";
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
