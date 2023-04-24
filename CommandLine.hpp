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

#include <iostream>
#include <string>
#include <functional>
#include <chrono>
#include <thread>
#include <conio.h>

template <typename T>
class CommandLine {
private:
	std::string commandLine_;
public:
	CommandLine();

	int print(T& paramether, const std::string& parametherName, std::function<void(T&, const std::string&)> enterFunction);
};

template<typename T>
CommandLine<T>::CommandLine()
{
}

template<typename T>
int CommandLine<T>::print(T& paramether, const std::string& parametherName, std::function<void(T&, const std::string&)> enterFunction)
{
	int key = 0;
	do {
		if (_kbhit()) {
			key = _getch();
			switch (key)
			{
			case 13:
				enterFunction(paramether, commandLine_);
				break;
			case 8:
				if (commandLine_.size() > 0)
					commandLine_.resize(commandLine_.size() - 1);
			case 27:
				break;
			default:
				commandLine_ += static_cast<char>(key);
				break;
			}
		}
		std::cout << parametherName << ": " << commandLine_ << "|" << std::endl;
		using namespace std::chrono_literals;
		std::this_thread::sleep_for(10ms);
		system("cls");
	} while (key != 27 && key != 13);
	commandLine_.clear();
	return key;
}