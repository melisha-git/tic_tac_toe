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

    int getSize() const;

    void setSize(const size_t& sz);

    EPlayers checkWinner();
};