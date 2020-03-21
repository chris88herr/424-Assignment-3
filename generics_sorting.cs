using System; 
using System.Collections.Generic; 

using  System.Collections; 


public class GenericSorting{

    public class Person : IComparable<Person>{
        public String name;
        public int age;

        public Person(String name, int age){
            this.name = name;
            this.age =  age;
        }

        public int CompareTo(Person other){ // implement the interface IComaparable function
            if(other == null) // if other is null, this object is placed on sorting algorithm
                return 1;
            
            if(this.age == other.age){
                return this.name.CompareTo(other.name);
            }
            else return this.age.CompareTo(other.age);
            
        }
    }

    public static void createPeople(List<Person> people){
        people.Add(new Person("Hal", 20));
        people.Add(new Person("Sussan", 31));
        people.Add(new Person("Dwight", 19));
        people.Add(new Person("Kassandra", 21));
        people.Add(new Person("Lawrence", 25));
        people.Add(new Person("Cory", 27));
        people.Add(new Person("Mac", 19));
        people.Add(new Person("Romana", 27));
        people.Add(new Person("Doretha", 32));
        people.Add(new Person("Danna", 20));
        people.Add( new Person("Zara", 23));
        people.Add( new Person("Rosalyn", 26));
        people.Add( new Person("Risa", 24));
        people.Add( new Person("Benny", 28));
        people.Add( new Person("Juan", 33));
        people.Add( new Person("Natalie", 25));
        people.Add( new Person("Cindy", 22));
    }


    public static void Main(){
        float[] floats = new float[12] {645.32f, 37.40f, 76.30f, 5.40f, -34.23f, 1.11f, -34.94f, 23.37f, 635.46f, -876.22f, 467.73f, 62.26f};
        List<float> floatList = new List<float>(floats.Length);
        // foreach(float f in floats){
        //    floatList.Add(f);
        // }
        floatList.Sort();
        // foreach(float f in floatList){
        //     Console.WriteLine(f);
        // }
        List<Person> people = new List<Person>();
        createPeople(people);
        foreach(Person p in people){
            Console.WriteLine("{0}, {1}", p.name, p.age);
        }
        Console.WriteLine("");
        people.Sort();
        foreach(Person p in people){
            Console.WriteLine("{0}, {1}", p.name, p.age);
        }
    }
}