#include "TicTacToe.hpp"

TicTacToe::TicTacToe(const Settings& settings, const Field& field) :
    playersName_{ {EPlayers::Undefined, "TIE!"},  {EPlayers::playerOne, settings.getName(EPlayers::playerOne)}, {EPlayers::playerTwo, settings.getName(EPlayers::playerTwo)}}, field_(settings.getSize()) {}

bool TicTacToe::print() {
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
    EPlayers win = field_.checkWinner();
    if (win != EPlayers::Undefined || stroke_ == field_.getSize() * field_.getSize()) {
        winner_ = win;
        return true;
    }
    std::cout << commands_;
    sleepPrint();
    system("cls");
    return keyHandler();
}

bool TicTacToe::keyHandler() {
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
        case 27: {
            Menu<EPlayMenu> playMenu;
            switch (playMenu.getMenu())
            {
            case EPlayMenu::YES:
                return false;
            case EPlayMenu::ESC:
            case EPlayMenu::NO:
                break;
            }
        }
        default:
            commands_ += key;
        }
    }
    return print();
}

EPlayers TicTacToe::getWinner()
{
    return winner_;
}

void TicTacToe::sleepPrint() {
    using namespace std;
    std::this_thread::sleep_for(60ms);
}
