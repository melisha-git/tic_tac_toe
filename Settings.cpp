#include "Settings.hpp"

Settings::Settings(const size_t& sz, const std::string& playerOne, const std::string& playerTwo) : sz_(sz), playerOne_(playerOne), playerTwo_(playerTwo) {}

size_t Settings::getSize() const
{
	return sz_;
}

std::string Settings::getName(const EPlayers& player) const
{
	switch (player)
	{
	case EPlayers::playerOne:
		return playerOne_;
	case EPlayers::playerTwo:
		return playerTwo_;
	}
	return "";
}

void Settings::setSize(size_t sz) {
	sz_ = sz;
	if (sz_ > 20)
		sz_ = 20;
}

void Settings::setName(const EPlayers& player, const std::string& name) {
	switch (player)
	{
	case EPlayers::playerOne:
		playerOne_ = name;
	case EPlayers::playerTwo:
		playerTwo_ = name;
	}
}

void Settings::printSize() {
	int key = 0;
	std::string commandLine;
	do {
		if (_kbhit()) {
			key = _getch();
			switch (key)
			{
			case 13:
				if (std::all_of(commandLine.begin(), commandLine.end(), ::isdigit)) {
					setSize(std::stoul(commandLine));
				}
				break;
			case 27:
				break;
			default:
				commandLine += static_cast<char>(key);
				break;
			}
		}
		std::cout << "Size: " << commandLine << "|" << std::endl;
		using namespace std::chrono_literals;
		std::this_thread::sleep_for(10ms);
		system("cls");
	} while (key != 27 && key != 13);
}

void Settings::printPlayer(const EPlayers& player)
{
	int key = 0;
	std::string commandLine;
	do {
		if (_kbhit()) {
			key = _getch();
			switch (key)
			{
			case 13:
				setName(player, commandLine);
				break;
			case 27:
				break;
			default:
				commandLine += static_cast<char>(key);
				break;
			}
		}
		if (player == EPlayers::playerOne)
			std::cout << "Player One Name: " << commandLine << "|" << std::endl;
		else
			std::cout << "Player Two Name: " << commandLine << "|" << std::endl;
		using namespace std::chrono_literals;
		std::this_thread::sleep_for(10ms);
		system("cls");
	} while (key != 27 && key != 13);
}
