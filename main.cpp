#include <iostream>
#include <cstdlib>
#include <time.h>
#include <fstream>
#include <stdio.h>
#include <windows.h>    //sleep
#include <string>

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
void Display()
{
    fstream Dfile;
    system("cls");
    Dfile.open("database.txt");
    if (Dfile.fail())   // change to !good()
    {
        cout << "ERROR";
        return;
    }

    //int line_number=1;
    string line;
    int Linenumber=0;
    while (!Dfile.eof())
    {
        Linenumber++;
        getline(Dfile, line);
        if (!Dfile.eof())   // musi byc
        cout << Linenumber << ". " << line << endl;
    }

    Dfile.close();
}
void DisplayXline(int DtaskNr)
{
    fstream file;
    file.open("database.txt");
    if (file.fail())
    {
        cout << "ERROR";
        exit(0);
    }
    string line;
    int lineNr = 0;
    int option;
    int firstSpace, secondSpace, thirdSpace;
    //string X;
   
    while (getline(file, line))
    {
        lineNr++;
       
            if (lineNr == DtaskNr)
            {
                cout << line <<endl;
                //line = "NEW LINE";
                //cout << line << endl;

                //cout << "What do u want to modify (Topic = 1, Date = 2, Difficulty= 3): ";
                //cin >> option;
                firstSpace = line.find("  ");
                secondSpace = line.find("  ", firstSpace + 1);
                thirdSpace = line.find("  ", secondSpace + 1);

                cout << firstSpace << endl;
                cout << secondSpace << endl;
                cout << thirdSpace <<endl;

               // return line;
            }
    }


    getchar(); getchar();
    file.close();
}

int main()
{

    string topic;
    string date;
    int difficulty;
    int choice;
    string line;
    int taskNr;
    string describtion;
  

    while(true){
    cout<< "TO DO LIST MENU" <<endl;
    cout<< "1. Create new task"<<endl;
    cout<<"2. View your tasks"<<endl;
    cout << "3. Modify your tasks"<<endl;
    cout << "4. Delete the tasks" << endl;
    cout << "5. EXIT" <<endl;
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
                    if (cin.fail() == 1)
                    {
                        cin.clear();
                        cin.ignore(10000000, '\n');
                        cout << "ERROR ";
                        break;
                    }
                    cout << "Describe a task: ";    cin.ignore(100000, '\n');   getline(cin, describtion);
                        
                       // SAVE  INTO FILE
                        
                        
                    file.open("database.txt", ios::out| ios::app);
                    file << topic<<"  " <<date<<"  " <<difficulty<<"  " << describtion <<endl;
                    file.close();
                    cout << "File saved successfully. Click ENTER to go back";
                    getchar();
                        

        break;
        case 2:

            Display();
            cout << "Click anything to continue!";
            getchar(); getchar();


        break;
        case 3:
            cout<< "Modify"<<endl;
            Display();
            cout << "Choose task number: ";
            cin >> taskNr;
            DisplayXline(taskNr);
           
            
           
            
        break;
        case 4:
            cout << "DELETE"<<endl;
        break;
        case 5:
            exit(0);
        break;

        default: cout << "Error";

    }
    Sleep(1000);
    system("cls");

    }




    return 0;
}
