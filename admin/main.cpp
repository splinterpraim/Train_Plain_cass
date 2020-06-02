#include <iostream>
#include "windows.h"
#include "Work_w_file.h"


using namespace std;




int main()
{
     setlocale(LC_ALL, "Rus");
     SetConsoleCP(1251);
     SetConsoleOutputCP(1251);

     int c;
     int exi=1;
     string type_BD;
     Work_w_file s;

     do
     {
        system("cls");
        cout<<"Choose which database you want to work with\n";
        cout<<"1.The trains\n2.Aircraft\n3.Exit\n";
        cin>>c;
        if(c==1) type_BD="Train";
        else if(c==2) type_BD="Plane";
        else if(c==3) return 0;
        s.Get_from_file(type_BD);

        do
        {
            system("cls");
            cout<<"1.Show\n2.Add\n3.Delete\n4.Edit\n5.Backup save\n6.Record Recovery\n7.Exit to the menu\n";
            cin>>c;
            switch(c)
            {
            case 1:{system("cls");
                    s.Show();
                    cout<<"\nPress Enter to return to the menu. . .";
                    cin.get();cin.get();
                    break;}
            case 2:{system("cls");
                    s.Add();
                    cout<<"\nYou added a ticket!\nPress Enter to return to the menu. . .";
                    cin.get();
                    break;}
            case 3:{system("cls");
                    s.Del();
                    cout<<"\nTicket Deleted!\nPress Enter to return to the menu. . .";
                    cin.get();cin.get();
                    break;}
            case 4:{system("cls");
                    s.Redact();
                    cout<<"\nTicket edited!\nPress Enter to return to the menu. . .";
                    cin.get();cin.get();
                    break;}
            case 5:{system("cls");
                    s.SaveBackup(type_BD);
                    cout<<"\nÐbackup done!\nPress Enter to return to the menu. . .";
                    cin.get();cin.get();
                    break;}
            case 6:{system("cls");
                    s.Recovery(type_BD);
                    cout<<"\nRecords restored!\nPress Enter to return to the menu. . .";
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
