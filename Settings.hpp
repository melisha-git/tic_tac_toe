/**
* _______                                                    _   _                                  _          _____                        _  _
*(_______)   _      _                                       | | (_)                                | |        / __  \                      (_)| |
* _        _| |_  _| |_    _____   ___  _____  _   _  _____ | |  _  _____  _   _   ____   ___    __| | _____ | | /   )  ____  ____   _____  _ | |      ____   ___   ____
*| |      (_   _)(_   _)  | ___ | /___)(____ || | | || ___ || | | || ___ || | | | / ___) / _ \  / _  || ___ || | \__/  / _  ||    \ (____ || || |     / ___) / _ \ |    \
*| |_____   |_|    |_|    | ____||___ |/ ___ | \ V / | ____|| | | || ____| \ V / ( (___ | |_| |( (_| || ____|| |____  ( (_| || | | |/ ___ || || |  _ ( (___ | |_| || | | |
* \______)                |_____)(___/ \_____|  \_/  |_____) \_)|_||_____)  \_/   \____) \___/  \____||_____) \_____)  \___ ||_|_|_|\_____||_| \_)(_) \____) \___/ |_|_|_|
*                                                                                                                     (_____|
**/

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
	static void setPlayerName(std::string& thisName, const std::string& otherName);

	void printSize();
	void printPlayer(const EPlayers& player);
};