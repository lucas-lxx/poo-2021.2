#pragma once

#include <iostream>
#include <exception>

class TweetException : public std::exception {
private:
    std::string message;

public:
    TweetException(const std::string& message):
        message(message){
    }

    const char* what() const noexcept override {
        return message.c_str();
    }
};