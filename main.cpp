#include <iostream>
#include <cstdlib>
#include <time.h>
#include <fstream>
#include <stdio.h>
using namespace std;

string topic;
string date;
int difficulty;
int choice;
string line;

int main()
{
    while(true){
    cout<< "TO DO LIST MENU" <<endl;
    cout<< "1. Create new task"<<endl;
    cout<<"2. View your tasks"<<endl;
    cout << "3. Modify your tasks"<<endl;
    cout << "4. EXIT" <<endl;
    cout << "What do u want: "; cin >> choice;
    fstream file;
    switch(choice){
        case 1:
                    system("cls");
                    cout << "Create new task"<<endl;
                    cout <<"Topic: ";    cin >> topic;
                    cout << "Date: ";    cin >> date;
                    cout << "Difficulty (1-3): ";    cin >>difficulty;
                       // SAVE  INTO FILE

                    file.open("database.txt", ios::out| ios::app);
                    file << topic<<"  " <<date<<"  " <<difficulty<<"  "<<endl;
                    file.close();
                    cout << "File saved successfully. Click ENTER to go back";

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
    getchar();getchar();
    system("cls");

    }











    return 0;
}
