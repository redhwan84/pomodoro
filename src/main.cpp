#include <iostream>
#include "tasks.h"
#include "pomodoro.h"
#include <limits>
#include <thread>
#include <chrono>
using namespace std::chrono;
using namespace std;

int main() {

    TaskManager manager;

    while (true) {
        cout << "\n  Pomodoro Timer  \n";
        cout << "1. View Tasks\n";
        cout << "2. Add Task\n";
        cout << "3. Delete Task\n";
        cout << "4. Edit Task\n";
        cout << "5. Start Pomodoro\n";
        cout << "6. Exit\n";
        cout << "7. Info\n";
        
        cout << "\nSelect an option: ";

        int choice;
        cin >> choice;

        if (choice == 1) 
        {
            manager.viewTasks();
        }
        if (choice == 2) 
        {
            manager.addTask();
        }
        if (choice == 3) 
        {
            manager.deleteTask();
        }
        if (choice == 4)
        {
            manager.viewTasks();
            cout << "Which task would you like to edit?\n";
        }
        if (choice == 5) 
        {
            int taskNumber;
           
            if (manager.isEmpty())
            {
                cout << "There are no tasks!\n";
                std::this_thread::sleep_for(std::chrono::seconds(1));
                continue;
            }

            manager.viewTasks();
            cout << "Which task would you like to do?\n";
            cin >> taskNumber;


            startPomodoro(manager.getTask(taskNumber-1));
        }
        if (choice == 6) 
        {
            cout << "ENDING PROGRAM\n";
            break;
        }
        if (choice == 7)
        {
            cout<< "The Pomodoro Timer is a way to help you focus on whatever task you are working on. " <<
            "It works by alternating between a set amount of time for work (usually 20-45 minutes) and "<<
            "a set amount of break time (usually 5-10 minutes). After 4 times you get a longer break of " <<
            "30 minutes before it loop repeats.\n";

            std::this_thread::sleep_for(std::chrono::seconds(5));
            continue;
        }
        if (cin.fail()) 
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number between 1 and 7.\n";
        }

    
    }
    return 0;
} 