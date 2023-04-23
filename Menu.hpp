#pragma once

#include <iostream>
#include <chrono>
#include <thread>
#include <string>
#include <conio.h>
#include <map>
#include <set>

enum class ESettingsMenu : int {
	ESC = -1,
	Size = 0,
	PlayerOne = 1,
	PlayerTwo = 2,
};

enum class EMainMenu : int {
	ESC = -1,
	Play = 0,
	Settings = 1
};

enum class EPlayMenu : int {
	ESC = -1,
	NO = 0,
	YES = 1,
};

template<class T>
class Menu {
private:
	T menu_;
public:
	Menu();
	T getMenu();
protected:
	void MenuPrint();
};