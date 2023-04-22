#pragma once

#include <vector>
#include <string>

enum EPalyers {
    Undefined = 0,
    playerOne = 1,
    playerTwo = 2
};

class Field {
private:
    std::vector<std::vector<char>> field_;
    size_t size_;
public:
    Field(const size_t& sz = 3);
    Field& operator=(const Field& other);

    char getElement(const int& posX, const int& posY) const;
    bool setElement(const std::string& line, EPalyers& player);
    bool setElement(const int& posX, const int& posY, const EPalyers& player);

    int getSize() const;

    void setSize(const size_t& sz);

    EPalyers checkWinner();
};