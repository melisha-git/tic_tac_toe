#pragma once

#include <string>
#include "EPlayers.hpp"

class Settings {
private:
	size_t sz_;
	std::string playerOne_;
	std::string playerTwo_;
public:
	Settings(const size_t &sz = 3, const std::string &playerOne = "Player 1", const std::string &playerTwo = "Player 2");

	size_t getSize() const;
	std::string getName(const EPlayers& player) const;

	void setSize(size_t sz);

	void setName(const EPlayers& player, const std::string& name);
};