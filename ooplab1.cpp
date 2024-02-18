#include <iostream>
#include <vector>

using namespace std;

class Dog 
{
 public:
    string name;
    string breed;
    int age;

    void show_dog()
    {
         cout << "Dog's Name: " << name << endl;
         cout << "Dog's Age: " << age << " years old" << endl;
         cout << "Dog's Breed: " << breed << endl;
     }

    void bark()
    {
        cout << name << " goes woof!" << endl;
     }
};

class Person {
public:
    string name;
    int age;
    Dog doggy;

    void show_person()
   {
        cout << "Person's Name: " << name << endl;
        cout << "Person's Age: " << age << " years old" << endl;
     }

    void show_dog() {
        cout << "I have a dog and its details are:" << endl;
        doggy.show_dog();
        doggy.bark();
    }

    void new_dog(Dog new_doggy)
   {
        doggy = new_doggy;
        cout << "Yay! Got a new dog named " << doggy.name << endl;
     }
};

class House 
{
  public:
    vector<Person> folks;

    void add_person()
    {
         Person new_person;
         cout << "Adding a new person. What's their name? ";
         cin.ignore();
         getline(cin, new_person.name);
         cout << "How old is the person? ";
         cin >> new_person.age;
         folks.push_back(new_person);
     }

    void show_folks() 
    {
         for (int i = 0; i < folks.size(); i++) 
	 {
             cout << "Person #" << (i + 1) << ":" << endl;
            folks[i].show_person();
         }
     }

    void change_dog(int which_person, Dog new_doggy)
    {
        which_person--;
	    
        if (which_person >= 0 && which_person < folks.size()) 
	{
            folks[which_person].new_dog(new_doggy);
         }
	else
	{
            cout << "Hmm, can't find that person." << endl;
         }
     }
};

class Neighborhood
{
 public:
     vector<House> blocks;

     void add_house()
    {
          House new_house;
          new_house.add_person(); 
          blocks.push_back(new_house);
     }

    void show_houses()
   {
         for (int i = 0; i < blocks.size(); i++)
         {
             cout << "House #" << (i + 1) << " has the following people:" << endl;
             blocks[i].show_folks();
          }
      }
};

int main()
{
    Neighborhood myNeighborhood; 

    char choice;
    do {
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
                myNeighborhood.show_houses(); 
                break;

            case '3': 
	    {
                int house_index, person_index;
                cout << "Enter house index (starting from 1): ";
                cin >> house_index;
                cout << "Enter person index (starting from 1): ";
                cin >> person_index;
                Dog new_pet;
                cout << "Enter new pet details:\n";
                cout << "Name: ";
                cin.ignore(); 
                getline(cin, new_pet.name);
                cout << "Age: ";
                cin >> new_pet.age;
                cout << "Breed: ";
                cin.ignore(); 
                getline(cin, new_pet.breed);

                myNeighborhood.blocks[house_index - 1].change_dog(person_index - 1, new_pet);
                break;
              }

            case '4':
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice!\n";
         }
     } while (choice != '4');

    return 0;
}
