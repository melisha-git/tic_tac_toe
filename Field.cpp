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

bool Field::setElement(const std::string& line, EPlayers& player) {
    char ch = player == EPlayers::playerOne ? 'X' : 'O';

    for (char c = 'A'; c <= size_ + 'A'; ++c) {
        for (int i = 1; i <= size_; ++i) {
            std::string s = c + std::to_string(i);
            if (line == s && field_[c - 'A'][i - 1] == ' ') {
                field_[c - 'A'][i - 1] = ch;
                player = player == EPlayers::playerOne ? EPlayers::playerTwo : EPlayers::playerOne;
                return true;
            }
        }
    }
    return false;
}

bool Field::setElement(const int& posX, const int& posY, const EPlayers& player) {
    switch (player)
    {
    case EPlayers::playerOne:
        field_[posX][posY] = 'X';
        return true;
    case EPlayers::playerTwo:
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

EPlayers Field::checkWinner() {
    if (checkWinner('X')) {
        return EPlayers::playerOne;
    }
    else if (checkWinner('O')) {
        return EPlayers::playerTwo;
    }
    return EPlayers::Undefined;
}

bool Field::checkWinner(const char& ch)
{
    bool result = true;
    for (int i = 0; i < size_; ++i) {
        result = true;
        for (int j = 0; j < size_; ++j) {
            if (field_[i][j] != ch) {
                result = false;
                break;
            }
        }
        if (result == true)
            return result;
    }
    for (int i = 0; i < size_; ++i) {
        result = true;
        for (int j = 0; j < size_; ++j) {
            if (field_[j][i] != ch) {
                result = false;
                break;
            }
        }
        if (result == true)
            return result;
    }
    result = true;
    for (int i = 0, j = 0; i < size_ && j < size_; ++i, ++j) {
        if (field_[i][j] != ch) {
            result = false;
            break;
        }
    }
    if (result == true)
        return result;
    for (int i = 0, j = size_ - 1; i < size_ && j >= 0; ++i, --j) {
        if (field_[i][j] != ch)
            return false;
    }
    return true;
}

