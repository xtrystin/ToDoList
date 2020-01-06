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
    if (cin.fail() == 1)
    {
        cin.clear();
        cin.ignore(10000000, '\n');
        cout << "ERROR ";
    }

}
int Display()
{
    
    cout << "Nr Topic  Date  Difficulty  Describtion \n";
    fstream Dfile;
    Dfile.open("database.txt");
    if (!Dfile.good())   // change to !good()
    {
        cout << "ERROR";
        return 0;
    }

    string line;
    int Linenumber = 0;
    while (!Dfile.eof())
    {
        Linenumber++;
        getline(Dfile, line);
        if (!Dfile.eof())   // necessary    
            cout << Linenumber << ". " << line << endl;
    }

    Dfile.close();
    return 1;
}
void DisplayXline(int DtaskNr)
{
    fstream file;
    file.open("database.txt");
    if (!file.good())
    {
        cout << "ERROR";
        exit(0);
    }
    string line[100];
    int lineNr = 0;
    int option;
    size_t firstSpace, secondSpace, thirdSpace;
    string newTopic, newDate, newDifficulty, newDescribtion;
    size_t lineSize, dateLength, diffLength, descrLength;
    string lastLetter;
    size_t lastLetterPosition;

    while (getline(file, line[lineNr]))
    {

        //cout << line[lineNr] << endl;
        if (lineNr + 1 == DtaskNr)        // +1 because line[] start from [0]
        {
            cout << "Selected task to modify: " << line[lineNr] << endl;

            cout << "What do u want to modify (Topic = 1, Date = 2, Difficulty = 3, Describtion = 4, EXIT = 5): ";
            cin >> option;  check_error();

            firstSpace = line[lineNr].find("  ");                   //USEFUL
            secondSpace = line[lineNr].find("  ", firstSpace + 1);      //USEFUL
            thirdSpace = line[lineNr].find("  ", secondSpace + 1);      //USEFUL


            //cout << firstSpace << endl;
           // cout << secondSpace << endl;
           // cout << thirdSpace << endl;

            switch (option)
            {
            case 1:
                //lineSize = line[lineNr].size();
                cout << "Write a new topic for your task:  ";
                cin >> newTopic;    check_error();
                line[lineNr].erase(0, firstSpace);
                line[lineNr].insert(0, newTopic);


                cout << "Modified task: " << line[lineNr] << endl;

                // cout << file.tellg() << endl;
                // file.seekg(20);
                // file << line;
                // cout << line << endl;
                break;
            case 2:
                //Date
                dateLength = secondSpace - firstSpace - 2;   // without 2 spaces
               //cout << dateLength << endl;

                cout << "Write a new Date for your task: ";
                cin >> newDate; check_error();

                line[lineNr].erase(firstSpace + 2, dateLength);
                line[lineNr].insert(firstSpace + 2, newDate);
                cout << "Modified task: " << line[lineNr] << endl;
                break;
            case 3:
                //Difficulty
                diffLength = thirdSpace - secondSpace - 2; // without 2 spaces spaceXspace - 2spaces = X

                cout << "Write a new Difficulty for your task: ";
                cin >> newDifficulty; check_error();

                line[lineNr].erase(secondSpace + 2, diffLength);
                line[lineNr].insert(secondSpace + 2, newDifficulty);
                cout << "Modified task: " << line[lineNr] << endl;


                break;
            case 4:
                //Describtion
                //lineSize = line[lineNr].find_last_of(qwertyuiopasdfghjklzxcvbnm123456789.);     //find last letter in describtion
               
                lastLetter = line[lineNr].back();
              //  cout << lastLetter << endl;
                lastLetterPosition = line[lineNr].rfind(lastLetter);
               // cout << lastLetterPosition<<endl;
                descrLength = lastLetterPosition - thirdSpace - 1;
               // cout << descrLength << endl;
                
                cout << "Write a new Describtion for your task: ";
                cin.ignore(100000, '\n');   getline(cin, newDescribtion);   check_error();
                
                
                line[lineNr].erase(thirdSpace + 2, descrLength);
                line[lineNr].insert(thirdSpace + 2, newDescribtion);
                cout << "Modified task: " << line[lineNr] << endl;
                break;
            case 5:
                return;
                break;
            default:
                cout << "Error";
                return;
            }

        }
        lineNr++;
        
    }
    if (DtaskNr > lineNr)
    {
        cout << "ERROR \n";
        return;
    }
    //cout << "TEST" << endl;
    string newFile;
    for (int i = 0; i < lineNr; i++)
    {
        newFile += line[i] + "\n";
    }
    //cout << newFile;
    file.close();

    file.open("database.txt", ios::out | ios::trunc);
    //check error
    file << newFile;
    file.close();


    cout << "Click anything to exit \n";
    getchar(); getchar();

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
        //cout << line[lineNr] << endl;
    }
    if (taskNr > lineNr)
    {
        cout << "ERROR \n";
        return;
    }
    for (int i = 0; i < lineNr; i++)
    {
        if (i + 1 != taskNr)
            newFile += line[i] + "\n";
    }
    //cout << newFile << endl;
    file.close();

    file.open("database.txt", ios::out | ios::trunc);
    //check error
    file << newFile;
    file.close();

    cout << "Click anything to exit";
    getchar(); getchar();
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


    while (true) {
        cout << "TO DO LIST MENU" << endl;
        cout << "1. Create new task" << endl;
        cout << "2. View your tasks" << endl;
        cout << "3. Modify your tasks" << endl;
        cout << "4. Delete the tasks" << endl;
        cout << "5. EXIT" << endl;
        cout << "What do u want: ";
        cin >> choice;
        check_error();
        fstream file;
        switch (choice) {
        case 1:
            system("cls");
            cout << "Create new task (exit = 0)" << endl;
            cout << "Topic: ";    cin >> topic;     if (topic == "0") break;
            cout << "Date: ";    cin >> date;       if (date == "0") break;
            cout << "Difficulty (1-3): ";    cin >> difficulty;     if (difficulty == 0) break;
            if (cin.fail() == 1)
            {
                cin.clear();
                cin.ignore(10000000, '\n');
                cout << "ERROR ";
                break;
            }
            cout << "Describe a task: ";    cin.ignore(100000, '\n');   getline(cin, describtion);      if (describtion == "0") break;

            // SAVING  INTO FILE
            file.open("database.txt", ios::out | ios::app);
            file << topic << "  " << date << "  " << difficulty << "  " << describtion << endl;
            file.close();
            cout << "File saved successfully. Click ENTER to go back";
            getchar();


            break;
        case 2:
            system("cls");
            if (Display() == 0)
                break;
            cout << "Click anything to exit";
            getchar(); getchar();


            break;
        case 3:
            system("cls");
            cout << "Modify (exit = 0)" << endl;
            if (Display() == 0)
                break;
            cout << "Choose task number: ";    
            cin >> taskNr;  check_error();      if (taskNr == 0) break;
            DisplayXline(taskNr);

            break;
        case 4:
            system("cls");
            cout << "DELETE (exit = 0)" << endl;
            Display();
            cout << "Choose task number: ";   
            cin >> taskD; check_error();        if (taskD == 0) break;
            Delete(taskD);  
            // undo option
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
