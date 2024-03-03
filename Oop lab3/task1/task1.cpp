#include <iostream>
#include<fstream>
#include <vector>
using namespace std;

class students
{
    public:
    string studentname; string grades;
    students(string s, string g) : studentname(s), grades(g) {}

};


class records
{
    public:
    vector<students*> student;

    void addstudent(students* student1)
     {
         student.push_back(student1);
         saverecord();
         }

    void saverecord()
    {
        ofstream file("student_record.txt");
        for (auto &student1 : student) file << student1->studentname << " , " << student1->grades << endl;
        file.close();
    }
      ~records() { for (auto &student1 : student) delete student1; }
};

int main()
{
    records myrecord;
    myrecord.addstudent(new students("Aisha", "F"));
    return 0;

}
