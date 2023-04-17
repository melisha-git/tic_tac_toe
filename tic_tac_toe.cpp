#include "TicTacToe.hpp"

int main()
{
    TicTacToe game(TicTacToe::Register());
    try {
        while (1) {
            game.print();
            game.keyHandler();
        }
    } catch(...) {}
    return 0;
}
