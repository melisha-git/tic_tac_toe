#include "TicTacToe.hpp"
#include "Menu.hpp"

void MainMenu();

Settings settings;

void printSettingsMenu() {
    Menu<ESettingsMenu> settingsMenu;
    ESettingsMenu menuObject = settingsMenu.getMenu();
    switch (menuObject)
    {
    case ESettingsMenu::ESC:
        return MainMenu();
    case ESettingsMenu::Size:
        settings.printSize();
        return printSettingsMenu();
    case ESettingsMenu::PlayerOne:
        settings.printPlayer(EPlayers::playerOne);
        return printSettingsMenu();
    case ESettingsMenu::PlayerTwo:
        settings.printPlayer(EPlayers::playerTwo);
        return printSettingsMenu();
    default:
        break;
    }
}

void PlayOrSettings(const EMainMenu& objMenu) {
    switch (objMenu) {
        case EMainMenu::Play: {
            TicTacToe game(settings);
            if (game.print()) {
                std::cout << "Winner is " << game.getWinner();
                return;
            }
            return MainMenu();
        }
        case EMainMenu::Settings: {
            printSettingsMenu();
        }
    }
}

void MainMenu() {
    Menu<EMainMenu> mainMenu;
    EMainMenu objMenu;
    do {
        objMenu = mainMenu.getMenu();
        if (objMenu == EMainMenu::ESC) {
            Menu<EPlayMenu> playMenu;
            switch (playMenu.getMenu())
            {
            case EPlayMenu::ESC:
            case EPlayMenu::NO:
                break;
            case EPlayMenu::YES:
                std::cout << "Good Luck!" << std::endl;
                return;
            }
        }
    } while (objMenu != EMainMenu::Play && objMenu != EMainMenu::Settings);
    return PlayOrSettings(objMenu);
}

int main()
{
    MainMenu();
    return 0;
}
