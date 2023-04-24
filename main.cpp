/**
* _______                                                    _   _                                  _          _____                        _  _
*(_______)   _      _                                       | | (_)                                | |        / __  \                      (_)| |
* _        _| |_  _| |_    _____   ___  _____  _   _  _____ | |  _  _____  _   _   ____   ___    __| | _____ | | /   )  ____  ____   _____  _ | |      ____   ___   ____
*| |      (_   _)(_   _)  | ___ | /___)(____ || | | || ___ || | | || ___ || | | | / ___) / _ \  / _  || ___ || | \__/  / _  ||    \ (____ || || |     / ___) / _ \ |    \
*| |_____   |_|    |_|    | ____||___ |/ ___ | \ V / | ____|| | | || ____| \ V / ( (___ | |_| |( (_| || ____|| |____  ( (_| || | | |/ ___ || || |  _ ( (___ | |_| || | | |
* \______)                |_____)(___/ \_____|  \_/  |_____) \_)|_||_____)  \_/   \____) \___/  \____||_____) \_____)  \___ ||_|_|_|\_____||_| \_)(_) \____) \___/ |_|_|_|
*                                                                                                                     (_____|
**/

#include <iostream>
#include "TicTacToe.hpp"
#include "Menu.hpp"
#include "EnumsMenu.hpp"

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
