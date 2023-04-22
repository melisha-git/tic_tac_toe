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
