#include <iostream>
#include <vector>
using namespace std;

class Task {
public:
    int id;
    string description;
    bool completed;
    Task( int i, string desc, bool stat) : id(i), description(desc), completed(stat) {}
};

class ToDoList {
    vector<Task*> tasks;
public:
    void addTask(const int i, const string& desc, bool stat)
    {tasks.push_back(new Task(i, desc, stat)); }


    void listtask()
    {
        if (tasks.empty())
        {
            cout << "No task found." << endl;
        }
        else
        {
            for (Task* task : tasks)
            {   string status = "uncompleted";
                if((task->completed) == false)
                {cout <<"Task no: "<< task->id << ", Task: " << task->description << ", Completion Status: " << status << endl;}

                else
                {
                    status = "completed";
                    cout <<"Task no: "<< task->id << ", Task: " << task->description << ", Completion Status: " << status << endl;
                 }


            }
        }
    }

    void marktask(int id, bool newstat)
    {
        bool found = false;
        for (Task* task : tasks)
        {
            if (task->id == id)
             {
                task->completed = newstat;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Task ID not found." << endl;
        }


    }

    ~ToDoList() { for (auto &task : tasks) delete task; }
};

int main() {
    ToDoList myList;
    myList.addTask(1, "Finish Lab 3", false);

    myList.listtask();
    myList.marktask(1, true);
    cout << "Task status after update: " << endl;
    myList.listtask();
    return 0;
}

