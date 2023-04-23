#pragma once

#include <iostream>
#include <chrono>
#include <thread>
#include <conio.h>
#include <map>
#include "Field.hpp"
#include "Settings.hpp"
#include "Menu.hpp"

class TicTacToe {
private:
    std::map<EPlayers, std::string> playersName_;
    EPlayers playerMove_ = EPlayers::playerOne;
    EPlayers winner_ = EPlayers::Undefined;

    Field field_;
    std::string commands_;
    int stroke_ = 0;
public:
    TicTacToe(const Settings &settings, const Field& field = Field(3));
    TicTacToe() = delete;

    bool print();
    bool keyHandler();

    EPlayers getWinner();
private:
    void sleepPrint();
};