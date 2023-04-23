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
		return Settings::setPlayerName(playerOne_, name);
	case EPlayers::playerTwo:
		return Settings::setPlayerName(playerTwo_, name);
	}
}

void Settings::setPlayerName(std::string& thisName, const std::string& otherName)
{
	thisName = otherName;
}

void Settings::printSize() {
	CommandLine<size_t> commands;
	commands.print(sz_, "Size", [](size_t &size, const std::string& param) {
		if (std::all_of(param.begin(), param.end(), ::isdigit))
			size = std::stol(param);
		if (size > 20)
			size = 20;
	});
}

void Settings::printPlayer(const EPlayers& player)
{
	CommandLine<std::string> commands;
	if (player == EPlayers::playerOne) {
		commands.print(playerOne_, "Player One Name", [](std::string&paramether, const std::string &name) {
			paramether = name;
		});
	}
	else {
		commands.print(playerTwo_, "Player Two Name", [](std::string& paramether, const std::string& name) {
			paramether = name;
		});
	}
}
