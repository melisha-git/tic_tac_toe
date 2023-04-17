#include "Field.hpp"

Field::Field(const int& width, const int& height)
    : field_(std::vector<std::vector<char>>(height, std::vector<char>(width, ' '))),
    width_(width),
    height_(height) {}

Field& Field::operator=(const Field& other) {
    this->width_ = other.width_;
    this->height_ = other.height_;
    this->field_ = other.field_;
    return (*this);
}

char Field::getElement(const int& posX, const int& posY) const {
    return field_[posX][posY];
}

void Field::setElement(const std::string& line, EPalyers& player) {
    char ch = player == EPalyers::playerOne ? 'X' : 'Y';
    ++move_;

    if (line == "A1" && field_[0][0] == ' ')
        field_[0][0] = ch;
    else if (line == "A2" && field_[0][1] == ' ')
        field_[0][1] = ch;
    else if (line == "A3" && field_[0][2] == ' ')
        field_[0][2] = ch;
    else if (line == "B1" && field_[1][0] == ' ')
        field_[1][0] = ch;
    else if (line == "B2" && field_[1][1] == ' ')
        field_[1][1] = ch;
    else if (line == "B3" && field_[1][2] == ' ')
        field_[1][2] = ch;
    else if (line == "C1" && field_[2][0] == ' ')
        field_[2][0] = ch;
    else if (line == "C2" && field_[2][1] == ' ')
        field_[2][1] = ch;
    else if (line == "C3" && field_[2][2] == ' ')
        field_[2][2] = ch;
    else {
        player = player == EPalyers::playerOne ? EPalyers::playerTwo : EPalyers::playerOne;
        --move_;
    }
}

void Field::setElement(const int& posX, const int& posY, const EPalyers& player) {
    switch (player)
    {
    case EPalyers::playerOne:
        field_[posX][posY] = 'X';
        break;
    case EPalyers::playerTwo:
        field_[posX][posY] = 'O';
        break;
    }
}

int Field::getWidth() const {
    return width_;
}

int Field::getHeight() const {
    return height_;
}

void Field::setWidth(const int& width) {
    width_ = width;
}

void Field::setHeight(const int& height) {
    height_ = height;
}

bool Field::isAllFields() {
    return move_ == width_ * height_;
}

EPalyers Field::checkWinner() {
    for (int i = 0; i < width_; ++i) {
        int countX_1 = 0, countO_1 = 0;
        int countX_2 = 0, countO_2 = 0;
        for (int j = 0; j < height_; ++j) {
            if (field_[i][j] == 'O')
                ++countO_1;
            if (field_[i][j] == 'X')
                ++countX_1;

            if (field_[j][i] == 'O')
                ++countO_2;
            if (field_[j][i] == 'X')
                ++countX_2;

            if (countX_1 == 3 || countX_2 == 3)
                return EPalyers::playerOne;
            if (countO_1 == 3 || countO_2 == 3)
                return EPalyers::playerTwo;
        }
    }

    int countX = 0, countO = 0;
    for (int i = 0, j = 0; i < width_ && j < height_; ++i, ++j) {
        if (field_[i][j] == 'O')
            ++countO;
        if (field_[i][j] == 'X')
            ++countX;

        if (countX == 3)
            return EPalyers::playerOne;
        if (countO == 3)
            return EPalyers::playerTwo;
    }
    countX = 0, countO = 0;
    for (int i = 0, j = height_ - 1; i < width_ && j >= 0; ++i, --j) {
        if (field_[i][j] == 'O')
            ++countO;
        if (field_[i][j] == 'X')
            ++countX;

        if (countX == 3)
            return EPalyers::playerOne;
        if (countO == 3)
            return EPalyers::playerTwo;
    }

    return EPalyers::Undefined;
}

