#include "TicTacToe.hpp"
#include "Menu.hpp"

int main()
{
    Settings settings;
    Menu<EMainMenu> mainMenu;
    switch (mainMenu.getMenu()) {
    case EMainMenu::ESC: {
        std::cout << "Good Bye :)\n";
        return 0;
    }
    case EMainMenu::Play: {
        TicTacToe game(settings);
        try {
            while (1) {
                game.print();
                game.keyHandler();
            }
        }
        catch (...) {}
        return 0;
    }
    case EMainMenu::Settings: {
        break;
    }
    }
    return 0;
}
