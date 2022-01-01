#pragma once
#include <iostream>
#include <memory>
#include <algorithm>
#include <list>
#include <sstream>
#include "kid.hpp"

class Trampoline {
private:
    std::list<std::shared_ptr<Kid>> playing{};
    std::list<std::shared_ptr<Kid>> waiting{};

    // Looks for a kid and returns where she/he is
    // If not found returns the end of the list
    static std::list<std::shared_ptr<Kid>>::iterator find_kid(std::string name, std::list<std::shared_ptr<Kid>>& list) {
        for (auto it = list.begin(); it != list.end(); ++it) {
            if ((*it)->getName() == name) {
                return it;
            }
        }
        return list.end();
    }

    // Returns a kid and removes it's place from a list
    // If there is no kid matching on the list then returns a default Kid object
    static Kid remove_kid(std::string name, std::list<std::shared_ptr<Kid>>& list) {
        auto it = find_kid(name, list);
        Kid kid;
        if (it != list.end()) {
            kid = *(*it);
            list.erase(it);
        }
        return kid;
    }

public:
    ///////////////////////////////////////////////////////////////////////////
    ///////////////Constructor/////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////

    Trampoline() {
    }

    ///////////////////////////////////////////////////////////////////////////
    ///////////////Constructor/////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////

    // Pushes the kid to the end of the waiting list
    void arrive(std::shared_ptr<Kid> kid) {
        waiting.push_front(kid);
    }

    // Pushes the first kid waiting on the line to play on the trampoline
    void enter() {
        if (!waiting.empty()) {
            playing.push_front(waiting.back());
            waiting.pop_back();
        } else {
            std::cout << "fail: there is no one waiting to play\n";
        }
    }


    // Pushes the first kid that entered the trampoline to the back of the line
    void leave() {
        if (!playing.empty()){
            waiting.push_front(playing.back());
            playing.pop_back();
        } else {
            std::cout << "fail: there is no one playing\n";
        }
    }

    // Returns a kid and removes her from wherever she/he is
    Kid remove(const std::string& name) {
        Kid kid;
        if (find_kid(name, this->waiting) != this->waiting.end()) {
            kid = remove_kid(name, this->waiting);
            return kid;
        } else if (find_kid(name, this->playing) != this->playing.end()) {
            kid = remove_kid(name, this->playing);
            return kid;
        }
        std::cout << "fail: no kid with this name found\n";
        return kid;
    }

    ///////////////////////////////////////////////////////////////////////////
    ///////////////Solver//////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////

    void cases() {
        std::string command;
        std::string line;
        while (true)
        {
            std::cout << "$ ";
            std::getline(std::cin >> std::ws, line);
            std::stringstream ss{line};
            ss >> command;
            if (command == "end") {
                break;
            } else if (command == "show") {
                show();
            } else if (command == "arrive") {
                std::string name;
                int age;
                ss >> name >> age;
                arrive(std::make_shared<Kid>(name, age));
            } else if (command == "enter") {
                enter();
            } else if (command == "leave") {
                leave();
            } else if (command == "remove") {
                std::string name;
                ss >> name;
                remove(name);
            } else {
                std::cout << "fail: invalid command\n";
            }
        }
    }

    ///////////////////////////////////////////////////////////////////////////
    ///////////////Solver//////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////
    
    ///////////////////////////////////////////////////////////////////////////
    ///////////////To String Methods///////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////

    friend std::ostream& operator<<(std::ostream& os, const Trampoline& trampoline) {
        os << "=> ";
        for (auto i : trampoline.waiting) {
            os << *i << " ";
        }
        os << "=> [ ";
        for (auto i : trampoline.playing) {
            os << *i << " ";
        }
        os << "]\n";
        return os;
    }

    void show() const {
        std::cout << "=> ";
        for (auto i : this->waiting) {
            std::cout << *i << " ";
        }
        std::cout << "=> [ ";
        for (auto i : this->playing) {
            std::cout << *i << " ";
        }
        std::cout << "]\n";
    }
};