#pragma once
#include <iostream>
#include <map>
#include "inbox.hpp"


class User {
    std::map<std::string, User*> followers;
    std::map<std::string, User*> following;
    Inbox inbox;
    
};