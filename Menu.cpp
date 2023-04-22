#include "Menu.hpp"

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
	    std::this_thread::sleep_for(60ms);
		system("cls");
	} while (key != 27 && key != 13);
	if (key == 27)
	    return EPlayMenu::ESC;
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
        std::this_thread::sleep_for(60ms);
		system("cls");
    } while (key != 27 && key != 13);
    if (key == 27)
        return EMainMenu::ESC;
    return menu_;
}