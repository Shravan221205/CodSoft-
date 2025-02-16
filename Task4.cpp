#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct Task
{
    string description;
    bool completed;
};
vector<Task> tasks;
void addTask()
{
    Task newTask;
    cout << "Enter task description: ";
    cin.ignore();
    getline(cin, newTask.description);
    newTask.completed = false;
    tasks.push_back(newTask);
    cout << "Task added.\n";
}
void viewTasks()
{
    cout << "\nTo-Do List:\n";
    for (size_t i = 0; i < tasks.size(); ++i)
    {
        cout << i + 1 << ". " << tasks[i].description << " [" << (tasks[i].completed ? "Completed" : "Pending") << "]\n";
    }
    cout << endl;
}
void markTaskAsCompleted()
{
    int taskNumber;
    cout << "Enter the task number to mark as completed: ";
    cin >> taskNumber;
    if (taskNumber > 0 && taskNumber <= tasks.size())
    {
        tasks[taskNumber - 1].completed = true;
        cout << "Task marked as completed.\n";
    }
    else
    {
        cout << "Invalid task number.\n";
    }
}
void removeTask()
{
    int taskNumber;
    cout << "Enter the task number to remove: ";
    cin >> taskNumber;
    if (taskNumber > 0 && taskNumber <= tasks.size())
    {
        tasks.erase(tasks.begin() + taskNumber - 1);
        cout << "Task removed.\n";
    }
    else
    {
        cout << "Invalid task number.\n";
    }
}
void showMenu()
{
    cout << "To-Do List Manager\n";
    cout << "1. Add Task\n";
    cout << "2. View Tasks\n";
    cout << "3. Mark Task as Completed\n";
    cout << "4. Remove Task\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
}
int main()
{
    int choice;
    while (true)
    {
        showMenu();
        cin >> choice;
        switch (choice)
        {
        case 1:
            addTask();
            break;
        case 2:
            viewTasks();
            break;
        case 3:
            markTaskAsCompleted();
            break;
        case 4:
            removeTask();
            break;
        case 5:
            cout << "Goodbye!\n";
            return 0;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
}
