/**
* _______                                                    _   _                                  _          _____                        _  _
*(_______)   _      _                                       | | (_)                                | |        / __  \                      (_)| |
* _        _| |_  _| |_    _____   ___  _____  _   _  _____ | |  _  _____  _   _   ____   ___    __| | _____ | | /   )  ____  ____   _____  _ | |      ____   ___   ____
*| |      (_   _)(_   _)  | ___ | /___)(____ || | | || ___ || | | || ___ || | | | / ___) / _ \  / _  || ___ || | \__/  / _  ||    \ (____ || || |     / ___) / _ \ |    \
*| |_____   |_|    |_|    | ____||___ |/ ___ | \ V / | ____|| | | || ____| \ V / ( (___ | |_| |( (_| || ____|| |____  ( (_| || | | |/ ___ || || |  _ ( (___ | |_| || | | |
* \______)                |_____)(___/ \_____|  \_/  |_____) \_)|_||_____)  \_/   \____) \___/  \____||_____) \_____)  \___ ||_|_|_|\_____||_| \_)(_) \____) \___/ |_|_|_|
*                                                                                                                     (_____|
**/

#pragma once

#include <map>
#include "Field.hpp"
#include "Settings.hpp"

class TicTacToe {
private:
    std::map<EPlayers, std::string> playersName_;
    EPlayers playerMove_ = EPlayers::playerOne;
    EPlayers winner_ = EPlayers::Undefined;

    Field field_;
    std::string commands_;
    int stroke_ = 0;
public:
    TicTacToe(const Settings &settings);
    TicTacToe() = delete;

    bool print();
    bool keyHandler();

    std::string getWinner();
private:
    void sleepPrint();
};