#include "TicTacToe.hpp"

TicTacToe::TicTacToe(const std::string& playerOne, const std::string& playerTwo, const Field& field) :
    playersName_{ {EPalyers::Undefined, "TIE!"},  {EPalyers::playerOne, playerOne}, {EPalyers::playerTwo, playerTwo} }, field_(4) {}

TicTacToe::TicTacToe(std::map<EPalyers, std::string> playersName, const Field& field) : playersName_(playersName), field_(4) {
    if (playersName_.count(Undefined) == 0)
        playersName_[Undefined] = "TIE!";
}

std::map<EPalyers, std::string> TicTacToe::Register() {
    std::string name;
    std::map<EPalyers, std::string> players;

    std::cout << "Write Player One Name: ";
    std::getline(std::cin, name);
    players[playerOne] = name;

    std::cout << "Write Player Two Name: ";
    name.clear();
    std::getline(std::cin, name);
    players[playerTwo] = name;

    return players;
}

void TicTacToe::print() {
    sleepPrint();
    system("cls");
    std::cout << " \t";
    for (int i = 1; i <= field_.getSize(); ++i)
        std::cout << "  " << i << "   ";
    std::cout << std::endl;
    std::cout << " \t";
    for (int i = 0; i < field_.getSize(); ++i) {
        if (i == 0)
            std::cout << "_______";
        else
            std::cout << "______";
    }
    std::cout << std::endl;
    char ch = 'A';
    for (int i = 0; i < field_.getSize(); ++i) {
        std::cout << ch++ << "\t";
        for (int j = 0; j < field_.getSize(); ++j) {
            if (j == 0)
                std::cout << "|  " << field_.getElement(i, j) << "  |";
            else
                std::cout << "  " << field_.getElement(i, j) << "  |";
        }
        std::cout << std::endl;
        std::cout << " \t";
        for (int j = 0; j < field_.getSize(); ++j) {
            if (j == 0)
                std::cout << "|_____|";
            else
                std::cout << "_____|";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    EPalyers win = field_.checkWinner();
    if (win != EPalyers::Undefined || stroke_ == field_.getSize() * field_.getSize()) {
        winner_ = win;
        throw std::exception();
    }
    std::cout << commands_;
}

void TicTacToe::keyHandler() {
    if (_kbhit()) {
        int key = _getch();
        switch (key) {
        case 13:
            if (field_.setElement(commands_, playerMove_))
                ++stroke_;
            commands_.clear();
            break;
        case 8:
            if (!commands_.empty()) {
                commands_.resize(commands_.size() - 1);
            }
            break;
        default:
            commands_ += key;
        }
    }
}

TicTacToe::~TicTacToe() {
    if (playerMove_ != Undefined)
        std::cout << "Winner is ";
    std::cout << playersName_[winner_];
}

void TicTacToe::sleepPrint() {
    using namespace std;
    std::this_thread::sleep_for(60ms);
}
