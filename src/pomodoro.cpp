// Define pomodoro functions

#include <iostream>
#include <thread>
#include <chrono>
#include "pomodoro.h"
#include "tasks.h"
#include "utils.h"
using namespace std::chrono;


// Pomodoro timer implementation
void startPomodoro(Task currentTask)
{    
    std::string changeTime;

    std::cout << "You selected " << currentTask.getName() << ".\n";
    std::cout << "The current work time is set to (minutes) " << currentTask.getWorkTime() << " minutes.\n";\
    std::cout << "The current break time is set to " << currentTask.getWorkTime() << " minutes.\n";
    std::cout << "Would you like to change these settings?\n";

    std::cin >> changeTime;

    if(convertBool(changeTime))
    {
        int newWorkTime, newBreakTime;

        std::cout << "Enter new work time: ";
        std::cin >> newWorkTime;
        currentTask.setWorkTime(newWorkTime);

        std::cout << "Enter new break time: ";
        std::cin >> newBreakTime;
        currentTask.setBreakTime(newBreakTime);

        std::cout << "Changes saved!\n";
    }


    std::cout << "Starting " << currentTask.getName() << "!\n";

    std::this_thread::sleep_for(std::chrono::seconds(currentTask.getWorkTime() ));
    std::cout << "Work time over! Now time for a break...\n";

    std::this_thread::sleep_for(std::chrono::seconds(currentTask.getBreakTime() ));
    std::cout << "Break time over! Time to get back to work!\n";


    std::cout << "Pomodoro Timer Ended!" << std::endl;
}