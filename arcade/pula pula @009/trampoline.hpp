#pragma once
#include <iostream>
#include <memory>
#include <algorithm>
#include <list>
#include "kid.hpp"

class Trampoline {
private:
    std::list<std::shared_ptr<Kid>> playing{};
    std::list<std::shared_ptr<Kid>> waiting{};

public:
    ///////////////////////////////////////////////////////////////////////////
    ///////////////Constructor/////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////

    Trampoline(){
    }

    ///////////////////////////////////////////////////////////////////////////
    ///////////////Constructor/////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////

    // Pushes the kid to the end of the waiting list
    void arrive(std::shared_ptr<Kid> kid) {
        waiting.push_front(kid);
    }

    // Pushes the kid to the end of the playing list
    // And removes it from the front of the waiting list
    void enter() {
        playing.push_front(waiting.back());
        waiting.pop_back();
    }

    void leave() {
        waiting.push_front(playing.back());
        playing.pop_back();
    }
    
    ///////////////////////////////////////////////////////////////////////////
    ///////////////To String Methods///////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////

    friend std::ostream& operator<<(std::ostream& os, Trampoline& trampoline) {
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
};