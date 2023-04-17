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
    int width_;
    int height_;
    int move_ = 0;
public:
    Field(const int& width = 3, const int& height = 3);
    Field& operator=(const Field& other);

    char getElement(const int& posX, const int& posY) const;
    void setElement(const std::string& line, EPalyers& player);
    void setElement(const int& posX, const int& posY, const EPalyers& player);

    int getWidth() const;
    int getHeight() const;

    void setWidth(const int& width);
    void setHeight(const int& height);

    bool isAllFields();
    EPalyers checkWinner();
};