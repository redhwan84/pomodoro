#include <iostream>
#include "tasks.h"
#include "pomodoro.h"

using namespace std;

int main() {

    TaskManager manager;

    while (true) {
        cout << "\n  Pomodoro Timer  \n";
        cout << "1. View Tasks\n";
        cout << "2. Add Task\n";
        cout << "3. Delete Task\n";
        cout << "4. Start Pomodoro\n";
        cout << "5. Exit\n";
        cout << "\nSelect an option: ";

        int choice;
        cin >> choice;

        if (choice == 1) {
            manager.viewTasks();
        }
        if (choice == 2) {
            manager.addTask();
        }
        if (choice == 3) {
            manager.deleteTask();
        }
        if (choice == 4) {
            startPomodoro();
        }
        if (choice == 5) {
            cout << "ENDING PROGRAM\n";
            break;
        }

    
    }
    return 0;
} 