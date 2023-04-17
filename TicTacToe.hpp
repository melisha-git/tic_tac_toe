#pragma once

#include <iostream>
#include <chrono>
#include <thread>
#include <conio.h>
#include <map>
#include "Field.hpp"

class TicTacToe {
private:
    std::map<EPalyers, std::string> playersName_;
    EPalyers winner_ = EPalyers::Undefined;
    Field field_;
    std::string line_;
public:
    TicTacToe(const std::string& playerOne, const std::string& playerTwo, const Field& field = Field());
    TicTacToe(std::map<EPalyers, std::string> playersName, const Field& field = Field());
    TicTacToe() = delete;

    void setField(const Field& field);

    static std::map<EPalyers, std::string> Register();
    void print();
    void keyHandler();

    ~TicTacToe();
private:
    void sleepPrint();
};