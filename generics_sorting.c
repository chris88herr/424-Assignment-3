//Generics Sorting Assignment
#include <string.h>
#include <stdio.h>

#define BUFF_SIZE (20)

//struct Person definition
typedef struct Person
{
        char pname[BUFF_SIZE];
        int age;
} Person;

int float_comp(const void *a, const void *b);
int str_com(const void *a, const void *b);
int int_com(const void *a, const void *b);
int person_com(const void *a, const void *b);

int float_comp(const void *a, const void *b) //cmp function for floats
{
        int res;
        if (*(float *)a < *(float *)b)
                res = -1; //a is less than b
        else if (*(float *)a == *(float *)b)
                res = 0; // a and b are equivalent
        else
                res = 1; //a and b are equivalent

        return res;
}

// function to compare strings
//uses built in function  strcmp to evaluate result
int str_com(const void *a, const void *b)
{
        return strcmp((char *)a, (char *)b);
}

int int_comp(const void *a, const void *b) //cmp function for ints
{
        int res;
        if (*(int *)a < *(int *)b)
                res = -1; //a is less than b
        else if (*(int *)a == *(int *)b)
                res = 0; // a and b are equivalent
        else
                res = 1; //a and b are equivalent
        return res;
}

int person_com(const void *a, const void *b) //cmp function for our own struct Person
{
        int res;
        Person *p1 = (Person *)a;
        Person *p2 = (Person *)b;

        if (p1->age < p2->age)
                res = -1;
        else if (p1->age == p2->age) // if same age, sort lexicographically
                res = str_com(p1->pname, p2->pname);
        else
                res = 1; //p1  is older than p2

        return res;
}
void createPeopleArray(struct Person people[]) // function to create people array
{

        strcpy(people[0].pname, "Hall");
        people[0].age = 20;
        strcpy(people[1].pname, "Susann");
        people[1].age = 31;
        strcpy(people[2].pname, "Dwight");
        people[2].age = 19;
        strcpy(people[3].pname, "Kassandra");
        people[3].age = 21;
        strcpy(people[4].pname, "Lawrance");
        people[4].age = 25;
        strcpy(people[5].pname, "Cindy");
        people[5].age = 22;
        strcpy(people[6].pname, "Cory");
        people[6].age = 27;
        strcpy(people[7].pname, "Mac");
        people[7].age = 19;
        strcpy(people[8].pname, "Romana");
        people[8].age = 27;
        strcpy(people[9].pname, "Doretha");
        people[9].age = 32;
        strcpy(people[10].pname, "Danna");
        people[10].age = 20;
        strcpy(people[11].pname, "Zara");
        people[11].age = 23;
        strcpy(people[12].pname, "Rosalyn");
        people[12].age = 26;
        strcpy(people[13].pname, "Risa");
        people[13].age = 24;
        strcpy(people[14].pname, "Benny");
        people[14].age = 28;
        strcpy(people[15].pname, "Juan");
        people[15].age = 33;
        strcpy(people[16].pname, "Nataly");
        people[16].age = 25;
}

int main()
{
        int i = 0;
        float floats[12] = {645.32, 37.40, 76.30, 5.40, -34.23, 1.11, -34.94, 23.37, 635.46, -876.22, 467.73, 62.26};
        Person people[17];
        createPeopleArray(people); //create people

        for (i = 0; i <= 16; i++)
        {
                printf("%s, %d \n", people[i].pname, people[i].age);
        }
        qsort(floats, 12, sizeof(float), float_comp);
        printf("\n");

        qsort(people, 17, sizeof(Person), person_com);

        for (i = 0; i <= 16; i++)
        {
                printf("%s, %d \n", people[i].pname, people[i].age);
        }
        printf("\n");

        return 0;
}