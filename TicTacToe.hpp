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
    EPalyers playerMove_ = EPalyers::playerOne;
    EPalyers winner_ = EPalyers::Undefined;

    Field field_;
    std::string commands_;
    int stroke_ = 0;
public:
    TicTacToe(const std::string& playerOne, const std::string& playerTwo, const Field& field = Field());
    TicTacToe(std::map<EPalyers, std::string> playersName, const Field& field = Field());
    TicTacToe() = delete;

    static std::map<EPalyers, std::string> Register();
    void print();
    void keyHandler();

    ~TicTacToe();
private:
    void sleepPrint();
};