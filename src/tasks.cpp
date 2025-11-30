// Define tasks functions

#include <iostream>
#include "tasks.h"
#include <vector>
#include <string>
#include <limits>
#include <thread>
#include <chrono>

using namespace std;



    Task::Task(string name, int workTime, int breakTime) {
            this->name = name;
            workTimeMinutes = workTime;
            breakTimeMinutes = breakTime;
        }

    string Task::getName() {
            return name;
        }


    void TaskManager::viewTasks() {
        
        if (tasks.empty() == true) {
            cout << "\nThere are no tasks\n";
            std::this_thread::sleep_for(std::chrono::seconds(1));
            return;
        }

        cout << "\n  Tasks\n";
        for (int i = 0; i < tasks.size(); i++) {
            cout << (i+1) << ". " << tasks[i].getName() << endl;
        }
    }


    void TaskManager::addTask() {
        
        string name;
        int workMinutes, breakMinutes;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "What would you like to name the task?: ";
        getline(cin,name);

        cout << "How long do you want the work time be?(in minutes): ";
        cin >> workMinutes;

        cout << "How long do want the break to be? ";
        cin >> breakMinutes;

        tasks.push_back(Task(name, workMinutes, breakMinutes));
        

    }

    void TaskManager::deleteTask() {
        // Remove tasks from the list
        viewTasks();
        
        if (tasks.empty() == true) {
            return;
        }
        
        cout << "\nWhich task would you like to delete?(input number): ";

        int taskNumber;
        cin >> taskNumber;

        string taskName = tasks[taskNumber-1].getName();

        tasks.erase(tasks.begin() + taskNumber - 1);
        cout << "\nSuccessfully deleted " << taskName << endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
