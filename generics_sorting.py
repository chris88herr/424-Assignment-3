##python uses a key parameter in the sorted function
#which takes a function with a single argument and returns a key 
# to use for sorting purposes

#operator module functions
#this allows us to do multiple levels of sorting

from operator import attrgetter

#Person class definition
class Person:
    def __init__(self, name, age):
        self.name = name
        self.age = age

    def __repr__(self):
        return repr((self.name, self.age))


## generic sorting functio that takes the objexts and a key function
## whose job is tu return a value to base the sorting on
def mySortFunction(objects, key): 
    return sorted(objects, key=key)

def float_comp(self): ##comp for floats, simple send the values themselves
    return self

def people_comp(obj):#comp function for person objects
    attr = attrgetter("age", "name") #get the attributes in which to order and return them
    return attr(obj) 

#main 
def main():
    floats = {645.32, 37.40, 76.30, 5.40, -34.23, 1.11, -34.94, 23.37, 635.46, -876.22, 467.73, 62.26}
    print(mySortFunction(floats, float_comp))

    people = [Person("Mac", 19), Person("Hal", 20) , Person("Susann", 31) , Person("Dwight", 19), Person("Kassandra", 21), Person("Lawrence", 25), Person("Cindy", 22), Person("Cory", 27),  Person("Romana", 27), Person("Doretha", 32), Person("Danna", 20), Person("Zara", 23), Person("Rosalyn", 26), Person("Risa", 24), Person("Benny", 28), Person("Juan", 33), Person("Natalie", 25)]
    print(mySortFunction(people, key=people_comp))

#driver
if __name__ == "__main__":
    main()