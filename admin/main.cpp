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
        cout<<"Выберите с какой базой данных вы хотите работать\n";
        cout<<"1.Поезда\n2.Самолеты\n3.Выход\n";
        cin>>c;
        if(c==1) type_BD="Train";
        else if(c==2) type_BD="Plane";
        else if(c==3) return 0;
        s.Get_from_file(type_BD);

        do
        {
            system("cls");
            cout<<"1.Показать\n2.Добавить\n3.Удалить\n4.Редактировать\n5.Резервное сохранение\n6.Восстановление записей\n7.Выход в меню\n";
            cin>>c;
            switch(c)
            {
            case 1:{system("cls");
                    s.Show();
                    cout<<"\nНажмите Enter чтобы вернутся в меню. . .";
                    cin.get();cin.get();
                    break;}
            case 2:{system("cls");
                    s.Add();
                    cout<<"\nВы добавили билет!\nНажмите Enter чтобы вернутся в меню. . .";
                    cin.get();
                    break;}
            case 3:{system("cls");
                    s.Del();
                    cout<<"\nБилет удален!\nНажмите Enter чтобы вернутся в меню. . .";
                    cin.get();cin.get();
                    break;}
            case 4:{system("cls");
                    s.Redact();
                    cout<<"\nБилет отредактирован!\nНажмите Enter чтобы вернутся в меню. . .";
                    cin.get();
                    break;}
            case 5:{system("cls");
                    s.SaveBackup(type_BD);
                    cout<<"\nРезервное копирование сделано!\nНажмите Enter чтобы вернутся в меню. . .";
                    cin.get();cin.get();
                    break;}
            case 6:{system("cls");
                    s.Recovery(type_BD);
                    cout<<"\nЗаписи восстановлены!\nНажмите Enter чтобы вернутся в меню. . .";
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
