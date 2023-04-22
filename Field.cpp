#include "Field.hpp"

Field::Field(const size_t& sz)
    : field_(std::vector<std::vector<char>>(sz, std::vector<char>(sz, ' '))),
    size_(sz) {}

Field& Field::operator=(const Field& other) {
    this->size_ = other.size_;
    this->field_ = other.field_;
    return (*this);
}

char Field::getElement(const int& posX, const int& posY) const {
    return field_[posX][posY];
}

bool Field::setElement(const std::string& line, EPalyers& player) {
    char ch = player == EPalyers::playerOne ? 'X' : 'O';

    for (char c = 'A'; c <= size_ + 'A'; ++c) {
        for (int i = 1; i <= size_; ++i) {
            std::string s = c + std::to_string(i);
            if (line == s && field_[c - 'A'][i - 1] == ' ') {
                field_[c - 'A'][i - 1] = ch;
                player = player == EPalyers::playerOne ? EPalyers::playerTwo : EPalyers::playerOne;
                return true;
            }
        }
    }
    return false;
}

bool Field::setElement(const int& posX, const int& posY, const EPalyers& player) {
    switch (player)
    {
    case EPalyers::playerOne:
        field_[posX][posY] = 'X';
        return true;
    case EPalyers::playerTwo:
        field_[posX][posY] = 'O';
        return true;
    }
    return false;
}

int Field::getSize() const {
    return size_;
}

void Field::setSize(const size_t& sz) {
    size_ = sz;
}

EPalyers Field::checkWinner() {
    for (int i = 0; i < size_; ++i) {
        int countX_1 = 0, countO_1 = 0;
        int countX_2 = 0, countO_2 = 0;
        for (int j = 0; j < size_; ++j) {
            if (field_[i][j] == 'O')
                ++countO_1;
            if (field_[i][j] == 'X')
                ++countX_1;

            if (field_[j][i] == 'O')
                ++countO_2;
            if (field_[j][i] == 'X')
                ++countX_2;

            if (countX_1 == size_ || countX_2 == size_)
                return EPalyers::playerOne;
            if (countO_1 == size_ || countO_2 == size_)
                return EPalyers::playerTwo;
        }
    }

    int countX = 0, countO = 0;
    for (int i = 0, j = 0; i < size_ && j < size_; ++i, ++j) {
        if (field_[i][j] == 'O')
            ++countO;
        if (field_[i][j] == 'X')
            ++countX;

        if (countX == size_)
            return EPalyers::playerOne;
        if (countO == size_)
            return EPalyers::playerTwo;
    }
    countX = 0, countO = 0;
    for (int i = 0, j = size_ - 1; i < size_ && j >= 0; ++i, --j) {
        if (field_[i][j] == 'O')
            ++countO;
        if (field_[i][j] == 'X')
            ++countX;

        if (countX == size_)
            return EPalyers::playerOne;
        if (countO == size_)
            return EPalyers::playerTwo;
    }

    return EPalyers::Undefined;
}

