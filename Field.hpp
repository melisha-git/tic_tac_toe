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

#include <vector>
#include <string>
#include "EPlayers.hpp"

class Field {
private:
    std::vector<std::vector<char>> field_;
    size_t size_;
public:
    Field(const size_t& sz);
    Field& operator=(const Field& other);

    char getElement(const int& posX, const int& posY) const;
    bool setElement(const std::string& line, EPlayers& player);
    bool setElement(const int& posX, const int& posY, const EPlayers& player);

    size_t getSize() const;

    void setSize(const size_t& sz);

    EPlayers checkWinner();
    bool checkWinner(const char& ch);
};