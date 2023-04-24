/**
* _______                                                    _   _                                  _          _____                        _  _
*(_______)   _      _                                       | | (_)                                | |        / __  \                      (_)| |
* _        _| |_  _| |_    _____   ___  _____  _   _  _____ | |  _  _____  _   _   ____   ___    __| | _____ | | /   )  ____  ____   _____  _ | |      ____   ___   ____
*| |      (_   _)(_   _)  | ___ | /___)(____ || | | || ___ || | | || ___ || | | | / ___) / _ \  / _  || ___ || | \__/  / _  ||    \ (____ || || |     / ___) / _ \ |    \
*| |_____   |_|    |_|    | ____||___ |/ ___ | \ V / | ____|| | | || ____| \ V / ( (___ | |_| |( (_| || ____|| |____  ( (_| || | | |/ ___ || || |  _ ( (___ | |_| || | | |
* \______)                |_____)(___/ \_____|  \_/  |_____) \_)|_||_____)  \_/   \____) \___/  \____||_____) \_____)  \___ ||_|_|_|\_____||_| \_)(_) \____) \___/ |_|_|_|
*                                                                                                                     (_____|
**/

#include "Menu.hpp"

#include <iostream>
#include <chrono>
#include <thread>
#include <string>
#include <conio.h>
#include <map>
#include <set>
#include "EnumsMenu.hpp"

template <typename T>
Menu<T>::Menu() {}

template <>
Menu<EMainMenu>::Menu() {
	menu_ = EMainMenu::Play;
}

template <>
Menu<EPlayMenu>::Menu() {
	menu_ = EPlayMenu::NO;
}

template <>
Menu<ESettingsMenu>::Menu() {
	menu_ = ESettingsMenu::Size;
}

template <>
void Menu<ESettingsMenu>::MenuPrint() {
	switch (menu_)
	{
	case ESettingsMenu::Size:
		std::cout << "\t<\\\\Size//>\n\t<Player One>\n\t<Player Two>" << std::endl;
		break;
	case ESettingsMenu::PlayerOne:
		std::cout << "\t<Size>\n\t<\\\\Player One//>\n\t<Player Two>" << std::endl;
		break;
	case ESettingsMenu::PlayerTwo:
		std::cout << "\t<Size>\n\t<Player One>\n\t<\\\\Player Two//>" << std::endl;
		break;
	default:
		break;
	}
}

template <>
void Menu<EMainMenu>::MenuPrint() {
	switch (menu_)
	{
	case EMainMenu::Play:
		std::cout << "<\\\\Play//>\t\t<Settings>";
		break;
	case EMainMenu::Settings:
		std::cout << "<Play>\t\t<\\\\Settings//>";
	default:
		break;
	}
}

template <>
void Menu<EPlayMenu>::MenuPrint() {
	std::cout << "    Do you want to go out?" << std::endl;
	switch (menu_)
	{
	case EPlayMenu::NO:
		std::cout << "<\\\\No//>\t\t<Yes>";
		break;
	case EPlayMenu::YES:
		std::cout << "<No>\t\t<\\\\Yes//>";
	default:
		break;
	}
}

template<typename T>
void Menu<T>::MenuPrint()
{
	std::cout << "Undefined Menu\n";
}

template<typename T>
T Menu<T>::getMenu()
{
	return T();
}

EPlayMenu Menu<EPlayMenu>::getMenu() {
	int key = 0;
	do {
		if (_kbhit()) {
			key = _getch();
			switch (key)
			{
			case 75:
				if (menu_ == EPlayMenu::NO)
					menu_ = EPlayMenu::YES;
				else
					menu_ = EPlayMenu::NO;
				break;
			case 77:
				if (menu_ == EPlayMenu::YES)
					menu_ = EPlayMenu::NO;
				else
					menu_ = EPlayMenu::YES;
				break;
			}
		}
		MenuPrint();
		using namespace std::chrono_literals;
		std::this_thread::sleep_for(10ms);
		system("cls");
	} while (key != 27 && key != 13);
	if (key == 27)
		return EPlayMenu::ESC;
	return menu_;
}

ESettingsMenu Menu<ESettingsMenu>::getMenu() {
	int key = 0;
	do {
	    if (_kbhit()) {
	        key = _getch();
			switch (key)
			{
			case 72:
				if (menu_ == ESettingsMenu::Size)
					menu_ = ESettingsMenu::PlayerTwo;
				else if (menu_ == ESettingsMenu::PlayerTwo)
					menu_ = ESettingsMenu::PlayerOne;
				else
					menu_ = ESettingsMenu::Size;
				break;
			case 80:
				if (menu_ == ESettingsMenu::PlayerTwo)
					menu_ = ESettingsMenu::Size;
				else if (menu_ == ESettingsMenu::PlayerOne)
					menu_ = ESettingsMenu::PlayerTwo;
				else
					menu_ = ESettingsMenu::PlayerOne;
				break;
			}
	    }
	    MenuPrint();
	    using namespace std::chrono_literals;
	    std::this_thread::sleep_for(10ms);
		system("cls");
	} while (key != 27 && key != 13);
	if (key == 27)
	    return ESettingsMenu::ESC;
	return menu_;
}

EMainMenu Menu<EMainMenu>::getMenu() {
	int key = 0;
    do {
        if (_kbhit()) {
            key = _getch();
            switch (key)
            {
            case 75:
                if (menu_ == EMainMenu::Play)
                    menu_ = EMainMenu::Settings;
                else
					menu_ = EMainMenu::Play;
                break;
            case 77:
                if (menu_ == EMainMenu::Settings)
                    menu_ = EMainMenu::Play;
                else
					menu_ = EMainMenu::Settings;
                break;
            }
        }
        MenuPrint();
        using namespace std::chrono_literals;
        std::this_thread::sleep_for(10ms);
		system("cls");
    } while (key != 27 && key != 13);
    if (key == 27)
        return EMainMenu::ESC;
    return menu_;
}