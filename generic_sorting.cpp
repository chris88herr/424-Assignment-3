#include <vector>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <functional>

using namespace std;

//Person class definition
class Person
{
public:
    Person() : age(0) {}
    Person(string name, int age)
    {
        this->age = age;
        this->name = name;
    }
    int age;
    string name;
};

//function to compare Person objects and overload sort
struct PersonSorting
{
    bool operator()(const Person &a, const Person &b)
    {

        if (a.age == b.age) //if age is the same, consider the name
            return a.name < b.name;
        else
            return a.age < b.age; //else sort by age
    }
};

struct floatSorting //object function
{
    bool operator()(const float &a, const float &b)
    {
        return a < b;
    }
};

template <class T, class ST> // generic sort using a object function as comparator
void myGenericSort(vector<T> &list, ST compare)
{
    sort(list.begin(), list.end(), compare); //use built in sort
}

void createPeople(Person people[])
{
    people[0] = Person("Hal", 20);
    people[1] = Person("Sussan", 31);
    people[2] = Person("Dwight", 19);
    people[3] = Person("Kassandra", 21);
    people[4] = Person("Lawrence", 25);
    people[5] = Person("Cory", 27);
    people[6] = Person("Mac", 19);
    people[7] = Person("Romana", 27);
    people[8] = Person("Doretha", 32);
    people[9] = Person("Danna", 20);
    people[10] = Person("Zara", 23);
    people[11] = Person("Rosalyn", 26);
    people[12] = Person("Risa", 24);
    people[13] = Person("Benny", 28);
    people[14] = Person("Juan", 33);
    people[15] = Person("Natalie", 25);
    people[16] = Person("Cindy", 22);
}

int main()
{

    float floats[12] = {645.32, 37.40, 76.30, 5.40, -34.23, 1.11, -34.94, 23.37, 635.46, -876.22, 467.73, 62.26};
    vector<float> float_vector(floats, floats + 12);                                     // create float vector
    myGenericSort(float_vector, floatSorting());                                         //sort floats with own generic sort
    for (vector<float>::iterator i = float_vector.begin(); i != float_vector.end(); i++) //print sorted floats
    {
        cout << ' ' << *i;
    }
    cout << "\n";

    Person people[17];
    createPeople(people);                           //instantiate Person elements
    vector<Person> people_vec(people, people + 16); //create Person vector
    for (vector<Person>::iterator i = people_vec.begin(); i != people_vec.end(); i++)
    {
        cout << ' ' << i->name << ' ' << i->age;
        cout << "\n";
    }
    cout << "\n";
    myGenericSort(people_vec, PersonSorting());
    for (vector<Person>::iterator i = people_vec.begin(); i != people_vec.end(); i++)
    {
        cout << ' ' << i->name << ' ' << i->age;
        cout << "\n";
    }
    cout << "\n";

    return 0;
}