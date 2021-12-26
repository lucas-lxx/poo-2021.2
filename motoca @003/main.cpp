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

    void drive(int time) {
        if (this->person == nullptr) {
            std::cout << "fail: ghosts don't drive motorcycles\n";
        } else if (this->person->age < 11) {
            if (this->time == 0) {
                std::cout << "fail: time limit is 0\n";
            } else if (this->time >= time) {
                this->time -= time;
            } else {
                std::cout << "fail: drove " << this->time << " minutes and the time ended\n";
            }
        } else {
            std::cout << "fail: too old to drive\n";
        }
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
    Person person { "Brian O'Conner", 27 };
    Person person2 { "Don Toretto", 30 };
    Person person3 { "Jack O'Conner"};
    Motorcycle kx;
    Motorcycle yz{ 74 };
    std::cout << person << '\n';
    kx.show();
    yz.show();
    yz.buy(40);
    yz.show();
    yz.enter(&person);
    yz.drive(20);
    yz.show();
    kx.enter(&person3);
    kx.drive(20);
    kx.show();
    kx.buy(20);
    kx.drive(17);
    kx.show();
    kx.drive(20);
    kx.show();
}