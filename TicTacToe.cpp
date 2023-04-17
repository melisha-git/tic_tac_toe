#include "TicTacToe.hpp"

TicTacToe::TicTacToe(const std::string& playerOne, const std::string& playerTwo, const Field& field) :
    playersName_{ {EPalyers::Undefined, "TIE!"},  {EPalyers::playerOne, playerOne}, {EPalyers::playerTwo, playerTwo} } {}

TicTacToe::TicTacToe(std::map<EPalyers, std::string> playersName, const Field& field) : playersName_(playersName) {
    if (playersName_.count(Undefined) == 0)
        playersName_[Undefined] = "TIE!";
}

void TicTacToe::setField(const Field& field) {
    field_ = field;
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
    for (int i = 0; i < field_.getWidth(); ++i) {
        for (int j = 0; j < field_.getHeight(); ++j)
            std::cout << "  " << field_.getElement(i, j) << "  |";
        std::cout << std::endl;
        for (int j = 0; j < field_.getHeight(); ++j)
            std::cout << "_____|";
        std::cout << std::endl;
    }
    std::cout << std::endl;
    EPalyers win = field_.checkWinner();
    if (win != Undefined || field_.isAllFields()) {
        winner_ = win;
        throw std::exception();
    }
    std::cout << line_;
}

void TicTacToe::keyHandler() {
    if (_kbhit()) {
        int key = _getch();
        switch (key) {
        case 13:
            switch (winner_) {
            case EPalyers::playerTwo:
            case EPalyers::Undefined:
                winner_ = EPalyers::playerOne;
                break;
            case EPalyers::playerOne:
                winner_ = EPalyers::playerTwo;
                break;
            }
            field_.setElement(line_, winner_);
            line_.clear();
            break;
        case 8:
            if (!line_.empty()) {
                line_.resize(line_.size() - 1);
            }
            break;
        default:
            line_ += key;
        }
    }
}

TicTacToe::~TicTacToe() {
    if (winner_ != Undefined)
        std::cout << "Winner is ";
    std::cout << playersName_[winner_];
}

void TicTacToe::sleepPrint() {
    using namespace std;
    std::this_thread::sleep_for(60ms);
}
