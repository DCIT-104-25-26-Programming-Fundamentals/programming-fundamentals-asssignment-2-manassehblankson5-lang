#include <iostream>
#include <vector>
#include <string>
using namespace std;


void displayMenu();
void addTask(vector<string>& tasks);
void viewTasks(const vector<string>& tasks);
void deleteTask(vector<string>& tasks);


int main() {
    vector<string> tasks;
    int choice;

    do {
        displayMenu();
        cin >> choice;

       
        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input. Please enter a number between 1 and 4." << endl;
            continue;
        }

        
        cin.ignore(10000, '\n');

        switch (choice) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                deleteTask(tasks);
                break;
            case 4:
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 4." << endl;
        }
    } while (choice != 4);

    return 0;
}


void displayMenu() {
    cout << "\n============================" << endl;
    cout << "     TO-DO LIST MENU" << endl;
    cout << "============================" << endl;
    cout << "1. Add task" << endl;
    cout << "2. View tasks" << endl;
    cout << "3. Delete task" << endl;
    cout << "4. Quit" << endl;
    cout << "Enter your choice (1-4): ";
}


void addTask(vector<string>& tasks) {
    string description;
    cout << "Enter task: ";
    getline(cin, description);

    tasks.push_back(description);
    cout << "Task added: \"" << description << "\"" << endl;
}


void viewTasks(const vector<string>& tasks) {
    if (tasks.empty()) {
        cout << "Your to-do list is empty. Add a task to get started!" << endl;
        return;
    }

    cout << "Your Tasks:" << endl;
    for (size_t i = 0; i < tasks.size(); i++) {
        cout << (i + 1) << ". " << tasks[i] << endl;
    }
}


void deleteTask(vector<string>& tasks) {
    if (tasks.empty()) {
        cout << "Your to-do list is empty. There is nothing to delete." << endl;
        return;
    }

    viewTasks(tasks);

    int taskNumber;
    cout << "Enter task number to delete: ";
    cin >> taskNumber;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Invalid input. Please enter a valid task number." << endl;
        return;
    }
    cin.ignore(10000, '\n');

    if (taskNumber < 1 || taskNumber > static_cast<int>(tasks.size())) {
        cout << "Error: There is no task with that number." << endl;
        return;
    }

    string removed = tasks[taskNumber - 1];
    tasks.erase(tasks.begin() + (taskNumber - 1));
    cout << "Task \"" << removed << "\" has been removed." << endl;
}
