#include <iostream>



struct Person {
    int age;
    std::string name;

    Person(int age=0, std::string name=""):
        age { age }, name { name } {
    }
};



struct Motorcycle {
    Person* person;
    int power;
    int time;

    Motorcycle(Person* person=nullptr, int power=1, int time=0):
        person { person }, power { power }, time { time } {
    }

    
};



int main() {
    
}