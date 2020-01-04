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
    cout << "Topic  Date  Difficulty  Describtion \n";
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
    string line[100];
    int lineNr = 0;
    int option;
    size_t firstSpace, secondSpace, thirdSpace;
    string newTopic, newDate, newDescribtion;
    int newDifficulty;
    size_t lineSize;
    //string X;
   
    while (getline(file, line[lineNr]))
    {
        
        cout << line[lineNr] << endl;
            if (lineNr+1 == DtaskNr)        // +1 because line[] start from [0]
            {
                cout <<"TO  " << line[lineNr] <<endl;
              
                cout << "What do u want to modify (Topic = 1, Date = 2, Difficulty = 3, Describtion = 4, EXIT = 5): ";
                cin >> option;  check_error();  
                    
                firstSpace = line[lineNr].find("  ");                   //USEFUL do policzenia odlegnosci do  seekg()
                secondSpace = line[lineNr].find("  ", firstSpace + 1);      //USEFUL
                thirdSpace = line[lineNr].find("  ", secondSpace + 1);      //USEFUL

                cout << firstSpace << endl;         
                cout << secondSpace << endl;        
                cout << thirdSpace <<endl;      

                switch (option)
                {
                case 1:
                    lineSize = line[lineNr].size();
                    cout << "Write a new topic for your task:  ";
                    cin >> newTopic;    check_error();
                    line[lineNr].erase(0,firstSpace);
                    line[lineNr].insert(0, newTopic);
                    cout << line[lineNr]<<endl;
                    
                   // cout << file.tellg() << endl;
                   // file.seekg(20);
                   // file << line;
                   // cout << line << endl;
                    break;
                case 2:

                    break;
                case 3:

                    break;
                case 4:

                    break;
                case 5:
                    break;
                default:
                    cout << "Error";
                }
                


                
               // return line;
            }
        lineNr++;
    }
    string newFile;
    for (int i = 0; i < lineNr; i++)
    {
        newFile += line[i] + "\n";
    }
    cout << newFile;
    // SAVE TO FILE
    
                //if wrong task number WRITE CODE
    getchar(); getchar();
    file.close();
}
void Delete(int taskNr)
{
    fstream file;
    file.open("database.txt");
    if (file.fail())
    {
        cout << "ERROR";
        exit(0);
    }
    string line[100];
    int lineNr = 0;
    string newFile;
    while (getline(file, line[lineNr]))
    {
        
        lineNr++;
        //cout << c << endl;
    }
    for (int i = 0; i < lineNr; i++)
    {
        if (i+1 != taskNr)
            newFile += line[i] + "\n";
    }
    //cout << newFile << endl;
    file.close();
    
    file.open("database.txt", ios::out | ios::trunc);
    file << newFile;
    file.close();

    system("pause");
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
    int taskD;
  

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
            cout << "Click anything to exit";
            getchar(); getchar();


        break;
        case 3:
            cout<< "Modify"<<endl;
            Display();
            cout << "Choose task number: ";
            cin >> taskNr;  check_error();
            DisplayXline(taskNr);
           
            
           
            
        break;
        case 4:
            cout << "DELETE"<<endl;
            Display();
            cout << "Choose task number: ";
            cin >> taskD; check_error();
            Delete(taskD);

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
