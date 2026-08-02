#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;


struct Student {
    string name;
    int id;
    vector<double> scores;
};


void displayMenu();
void addStudent(vector<Student>& students);
void displayAllStudents(const vector<Student>& students);
void calculateAverageForStudent(const vector<Student>& students);
double computeAverage(const vector<double>& scores);
int findStudentIndex(const vector<Student>& students, int id);


int main() {
    vector<Student> students;
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
                addStudent(students);
                break;
            case 2:
                displayAllStudents(students);
                break;
            case 3:
                calculateAverageForStudent(students);
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
    cout << "\n================================" << endl;
    cout << "   STUDENT RECORD SYSTEM MENU" << endl;
    cout << "================================" << endl;
    cout << "1. Add student" << endl;
    cout << "2. Display all students" << endl;
    cout << "3. Calculate average score" << endl;
    cout << "4. Quit" << endl;
    cout << "Enter your choice (1-4): ";
}


double computeAverage(const vector<double>& scores) {
    if (scores.empty()) {
        return 0.0;
    }

    double sum = 0.0;
    for (double s : scores) {
        sum += s;
    }
    return sum / scores.size();
}


int findStudentIndex(const vector<Student>& students, int id) {
    for (size_t i = 0; i < students.size(); i++) {
        if (students[i].id == id) {
            return static_cast<int>(i);
        }
    }
    return -1;
}


void addStudent(vector<Student>& students) {
    Student s;

    cout << "Student name: ";
    getline(cin, s.name);

    cout << "Student ID: ";
    cin >> s.id;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Invalid ID. Student was not added." << endl;
        return;
    }

    int numScores;
    cout << "How many scores? ";
    cin >> numScores;
    if (cin.fail() || numScores <= 0) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Invalid number of scores. Student was not added." << endl;
        return;
    }
    cin.ignore(10000, '\n');

    for (int i = 0; i < numScores; i++) {
        double score;
        cout << "Enter score " << (i + 1) << ": ";
        cin >> score;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid score entered. Student was not added." << endl;
            return;
        }
        s.scores.push_back(score);
    }
    cin.ignore(10000, '\n');

    students.push_back(s);
    cout << "Student \"" << s.name << "\" added successfully." << endl;
}


void displayAllStudents(const vector<Student>& students) {
    if (students.empty()) {
        cout << "No students have been added yet." << endl;
        return;
    }

    cout << fixed << setprecision(2);

    for (const Student& s : students) {
        cout << "\nName:    " << s.name << endl;
        cout << "ID:      " << s.id << endl;
        cout << "Scores:  ";
        for (size_t i = 0; i < s.scores.size(); i++) {
            cout << s.scores[i];
            if (i < s.scores.size() - 1) {
                cout << ", ";
            }
        }
        cout << endl;
        cout << "Average: " << computeAverage(s.scores) << endl;
    }
}


void calculateAverageForStudent(const vector<Student>& students) {
    if (students.empty()) {
        cout << "No students have been added yet." << endl;
        return;
    }

    int id;
    cout << "Enter student ID: ";
    cin >> id;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Invalid ID entered." << endl;
        return;
    }
    cin.ignore(10000, '\n');

    int index = findStudentIndex(students, id);
    if (index == -1) {
        cout << "Error: No student found with ID " << id << "." << endl;
        return;
    }

    double avg = computeAverage(students[index].scores);
    cout << fixed << setprecision(2);
    cout << students[index].name << "'s average score: " << avg << endl;
}
