#include <iostream>

struct Person {
    std::string name;
    int age;

    Person(std::string name="", int age=0):
        name { name }, age { age } {
    }

    friend std::ostream& operator<<(std::ostream& os, Person& person) {
        os << person.name << " ";
        os << person. age;
        return os;
    }
};



struct Motorcycle {
    Person* person;
    int power;
    int time;

    Motorcycle(Person* person=nullptr, int power=1, int time=0):
        person { person }, power { power }, time { time } {
    }

    // Returns true if there is someone on the motorcycle
    // Else returns false and atributes someone to the motorcycle
    bool in(Person* person) {
        if (this->person == nullptr) {
            this->person = person;
            return false;
        }
        return true;
    }   

    friend std::ostream& operator<<(std::ostream& os, Motorcycle& motorcycle) {
        os << "power: " << motorcycle.power << ", ";
        os << "minutes: " << motorcycle.time << ", ";
        if (motorcycle.in(motorcycle.person)) {
            os << "person: " << motorcycle.person->name; 
            return os;
        }
        os << "person: null"; 
        return os;
    }
};



int main() {
    Person person { "Bryan", 23 };
    Motorcycle kx;
    std::cout << kx << '\n';
    std::cout << person << '\n';
}