#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Contact
{
    public:
    string phoneno;

    Contact(string phone) : phoneno(phone) {}

    Contact() : phoneno("") {}

};

class Contactmanager
{
    public:
    map<string, Contact> contacts;

     void addContact(string name, string phone)
     { contacts[name] = Contact(phone); }

     void searchContact(string name)
     {
        auto iterator = contacts.find(name);
        if (iterator != contacts.end())
        {
            cout << "Name: " << iterator->first << ", Phone: " << iterator->second.phoneno << endl;
         }

        else
         {
            cout << "Contact not found." << endl;
          }
    }
};

int main()
{
    Contactmanager manager;
    char ch;
    do{
    string name, phonenum;


    cout << "Please select an option from the following:" << endl;
    cout << "(a) Add a Contact    (b) Search a contact (by name)" << endl;
    cout << "               (c) Exit                            " << endl;
    cin >> ch;

    switch(ch) {
        case 'a':
            cout << "Enter the contact name: ";
            cin >> name;
            cout << "Enter the contact number: ";
            cin >> phonenum;

            manager.addContact(name, phonenum);
            break;

        case 'b':
            cout << "Enter the contact name: ";
            cin >> name;
            cout << "Searching for contact by name:" << endl;
            manager.searchContact(name);
            break;

        case 'c':
             cout << "BYE" << endl;
             exit(0);

        default:
            cout << "Invalid choice";
    }
     cout << "Do you want to continue (y/n): ";
     cin >> ch;
     system("clear");
    }while(ch == 'y' || ch == 'Y');

    return 0;
}


