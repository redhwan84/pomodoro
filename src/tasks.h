// Declare tasks functions

#ifndef TASKS_H
#define TASKS_H

#include <vector>
#include <string>


class Task {
    private:
        std::string name;
        int workTimeMinutes;
        int breakTimeMinutes;

    public:
        Task(std::string name, int workTime, int breakTime);

        std::string getName();
};

class TaskManager {
    private:
        std::vector<Task> tasks;

    public:
        TaskManager() = default;
        void viewTasks();
        void deleteTask();
        void addTask();

};

#endif