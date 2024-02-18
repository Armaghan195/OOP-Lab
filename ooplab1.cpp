#include <iostream>
#include <vector>

using namespace std;

// Let's start with Dog. Dogs can bark and have details like name, breed and age.
class Dog {
public:
    string name;
    string breed;
    int age;

    // Show the details of the dog
    void show_dog() {
        cout << "Dog's Name: " << name << endl;
        cout << "Dog's Age: " << age << " years old" << endl;
        cout << "Dog's Breed: " << breed << endl;
    }

    // Make the dog bark
    void bark() {
        cout << name << " goes woof!" << endl;
    }
};

// Now, let's talk about a Person. People have a name, age and they can have a dog.
class Person {
public:
    string name;
    int age;
    Dog doggy; // I'm going to call my dog 'doggy'

    // I need to see the person's details too
    void show_person() {
        cout << "Person's Name: " << name << endl;
        cout << "Person's Age: " << age << " years old" << endl;
    }

    // I want to see my dog details and hear it bark!
    void show_dog() {
        cout << "I have a dog and its details are:" << endl;
        doggy.show_dog();
        doggy.bark();
    }

    // If I get a new dog, I need to update my doggy details
    void new_dog(Dog new_doggy) {
        doggy = new_doggy;
        cout << "Yay! Got a new dog named " << doggy.name << endl;
    }
};

// A house can have multiple people living in it.
class House {
public:
    vector<Person> folks; // I'm going to call people living in the house 'folks'

    // Adding a new person to the house
    void add_person() {
        Person new_person;
        cout << "Adding a new person. What's their name? ";
        cin.ignore(); // Have to ignore the newline
        getline(cin, new_person.name);
        cout << "How old is the person? ";
        cin >> new_person.age;
        folks.push_back(new_person);
    }

    // Show me everyone living in the house
    void show_folks() {
        for (int i = 0; i < folks.size(); i++) {
            cout << "Person #" << (i + 1) << ":" << endl;
            folks[i].show_person();
        }
    }

    // I can change the dog of any person in the house
    void change_dog(int which_person, Dog new_doggy) {
        if (which_person >= 0 && which_person < folks.size()) {
            folks[which_person].new_dog(new_doggy);
        } else {
            cout << "Hmm, can't find that person." << endl;
        }
    }
};

// Let's create a neighborhood with lots of houses!
class Neighborhood {
public:
    vector<House> blocks; // A neighborhood has blocks of houses

    // Add a new house to the neighborhood
    void add_house() {
        House new_house;
        new_house.add_person(); // Let's add a person right away for demonstration
        blocks.push_back(new_house);
    }

    // Show me all the houses and their people
    void show_houses() {
        for (int i = 0; i < blocks.size(); i++) {
            cout << "House #" << (i + 1) << " has the following people:" << endl;
            blocks[i].show_folks();
        }
    }
};

// Finally, the main function where everything happens
int main()
{
    neighborhood myNeighborhood;

    char choice;
    do
	{
        cout << "\n1. Add a house\n";
        cout << "2. List all houses and their residents\n";
        cout << "3. Change pet of a person\n";
        cout << "4. Quit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
		{
            case '1':
                myNeighborhood.add_house();
                break;

            case '2':
                myNeighborhood.list_houses();
                break;

            case '3':
			{
                int house_index, person_index;
                cout << "Enter house index: ";
                cin >> house_index;
                cout << "Enter person index: ";
                cin >> person_index;
                dog new_pet;
                cout << "Enter new pet details:\n";
                cout << "Name: ";
                cin.ignore(); // ignore any remaining newline character in the buffer
                getline(cin, new_pet.name);
                cout << "Age: ";
                cin >> new_pet.age;
                cout << "Breed: ";
                cin.ignore(); // ignore any remaining newline character in the buffer
                getline(cin, new_pet.breed);
                myNeighborhood.houses[house_index].change_pet(person_index, new_pet);
                break;
            }

            case '4':
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }
    }while(choice != '4');

    return 0;
}
