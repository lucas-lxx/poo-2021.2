#include <iostream>

struct Person {
    std::string name;
    int age;

    Person(std::string name="", int age=0):
        name { name }, age { age } {
    }

    ////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////IgotYouBaby/////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////
    int getAge() {
        return this->age;
    }

    std::string& getName() {
        return this->name;
    }

    // Teach the operator<< how to turn the object Person into a output stream
    friend std::ostream& operator<<(std::ostream& os, const Person& person) {
        os << person.name << " ";
        os << person.age;
        return os;
    }
};



struct Motorcycle {
    Person* person { nullptr };
    int power { 1 };
    int time { 0 };

    // Default constructor
    Motorcycle(Person* person=nullptr, int power=1, int time=0):
        person { person }, power { power }, time { time } {
    }

    // Only power assignment constructor
    Motorcycle(int power) : 
        power { power } {
    }

    // Adds time to the current amount of a Motorcycle
    void buy(int time) {
        this->time += time;
    }


    // Returns true if there is someone on the motorcycle
    // Else returns false and atributes someone to the motorcycle
    bool enter(Person* person) {
        if (this->person == nullptr) {
            this->person = person;
            return false;
        }
        return true;
    }   


    ////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////IgotYouBaby/////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////
    Person getPerson() {
        return *this->person;
    }

    int getPower() {
        return this->power;
    }

    int getTime() {
        return this->time;
    }

    void show() {
        std::cout << "power: " << this->power << ", " << "minutes: " << this->time << ", ";
        if (this->enter(person)) {
            std::cout << "person: " << person->name << '\n'; 
        } else {
            std::cout << "person: null\n";
        }
    }

    // teach the operator<< how to turn a Motorcycle object into a output stream
    friend std::ostream& operator<<(std::ostream& os, Motorcycle& motorcycle) {
        os << "power: " << motorcycle.power << ", ";
        os << "minutes: " << motorcycle.time << ", ";
        if (motorcycle.enter(motorcycle.person)) {
            os << "person: " << motorcycle.person->name; 
            return os;
        }
        os << "person: null"; 
        return os;
    }
};



int main() {
    Person person { "Bryan", 23 };
    Person person2 { "Toretto", 27 };
    Motorcycle kx;
    Motorcycle yz{ 74 };
    std::cout << person << '\n';
    kx.show();
    yz.show();
    yz.buy(40);
    std::cout << yz << '\n';
}