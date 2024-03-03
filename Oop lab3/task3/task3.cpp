#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Student {
    int id;
    string name;
    float grade;
    Student(int i, string n, float g) : id(i), name(n), grade(g) {}
};

class StudentManager {
private:
    vector<Student*> records;
public:
    void addStudent(int id, string name, float grade) {
        Student* newStudent = new Student(id, name, grade);
        records.push_back(newStudent);
    }

    void updateGrade(int id, float newGrade)
     {
        bool found = false;
        for (Student* student : records)
        {
            if (student->id == id)
             {
                student->grade = newGrade;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Student ID not found." << endl;
        }
    }

    void displayRecords()
     {
        if (records.empty())
        {
            cout << "No student records found." << endl;
        }
        else
        {
            for (Student* student : records)
            {
                cout << "ID: " << student->id << ", Name: " << student->name << ", Grade: " << student->grade << endl;
            }
        }
    }

    ~StudentManager()
     {
        for (Student* student : records) {
            delete student;
        }
    }
};

int main() {
    StudentManager manager;
    char ch;
    do{
        int id; string name; float grades;
        cout << "Please select an option from the following:" << endl;
    cout << "(a) Add a Student record    (b) Update a record" << endl;
    cout << "   (c) Display records         (d) Exit        " << endl;
    cin >> ch; // Read the user's choice

    switch(ch) {
        case 'a':
            cout << "Enter the Student name: ";
            cin >> name;
            cout << "Enter the ID number: ";
            cin >> id;
            cout << "Enter Grades: ";
            cin >> grades;
            manager.addStudent(id, name, grades);
            break;

        case 'b':
            cout << "Enter the ID number: ";
            cin >> id;
            cout << "Enter updated grades:";
            cin >> grades;
            manager.updateGrade(id, grades);
            cout << "After grade update:" << endl;
            manager.displayRecords();
            break;

        case 'c':
             manager.displayRecords();
             break;

        case 'd':
             exit(0);

        default:
            cout << "Invalid choice";
    }
     cout << "Do you want to continue (y/n): ";
     cin >> ch;
     system("clear");
    }while(ch == 'y' || ch == 'Y');



    // manager.addStudent(1, "John Doe", 92.5);
    // manager.addStudent(2, "Jane Doe", 88.0);
    // manager.displayRecords();
    // manager.updateGrade(1, 95.0);
    // cout << "After grade update:" << endl;
    // manager.displayRecords();

    return 0;
}
