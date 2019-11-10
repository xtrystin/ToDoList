#include <iostream>
#include <cstdlib>
#include <time.h>
#include <fstream>
#include <stdio.h>
#include <windows.h>    //sleep

using namespace std;

void check_error()            // if wrong input
{
     if (cin.fail()==1)
        {
            cin.clear();
            cin.ignore(10000000, '\n');
            cout << "ERROR ";
        }

}
int main()
{

    string topic;
    string date;
    int difficulty;
    int choice;
    string line;

    while(true){
    cout<< "TO DO LIST MENU" <<endl;
    cout<< "1. Create new task"<<endl;
    cout<<"2. View your tasks"<<endl;
    cout << "3. Modify your tasks"<<endl;
    cout << "4. EXIT" <<endl;
     //Delete task     delete line in file
    cout << "What do u want: ";
    cin >> choice;
    check_error();

    fstream file;
    switch(choice){
        case 1:
                    system("cls");
                    cout << "Create new task"<<endl;
                    cout <<"Topic: ";    cin >> topic;
                    cout << "Date: ";    cin >> date;
                    cout << "Difficulty (1-3): ";    cin >>difficulty;
                        if (cin.fail()==1)
                        {
                            cin.clear();
                            cin.ignore(10000000, '\n');
                            cout << "ERROR ";
                        }
                       // SAVE  INTO FILE
                        else
                        {
                    file.open("database.txt", ios::out| ios::app);
                    file << topic<<"  " <<date<<"  " <<difficulty<<"  "<<endl;
                    file.close();
                    cout << "File saved successfully. Click ENTER to go back";
                        }

        break;
        case 2:
                system("cls");
                file.open("database.txt", ios::in);


                //int line_number=1;

                do{
                getline(file,line);
                cout <<line<<endl;
                }while(line !="");

                file.close();
        break;
        case 3:
            cout<< "Option 2"<<endl;
            cout<< "Option 244444";
        break;
        case 4:
            exit(0);
        break;

        default: cout << "Error";

    }
    Sleep(1000);
    system("cls");

    }











    return 0;
}
