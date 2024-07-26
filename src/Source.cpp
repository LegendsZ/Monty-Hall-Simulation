//Created by LegendsZ
//Simulation to observe the different outcomes for the Monty Hall problem

#include <iostream>

#include "../include/MontyHall.h"

int main(int argc, char* arg[]){
	if (argc != 3){
		std::cerr << "Missing input for # of runs for simulation!\n";
		return 1;
	}
	for (int i = 0; i < strlen(arg[1]); ++i){
		if (!std::isdigit(arg[1][i])){
			std::cerr << "Invalid input for simulation count - Should be a number!\n";
			return 1;
		}
	}
	for (int i = 0; i < strlen(arg[2]); ++i){
		if (!std::isdigit(arg[2][i])){
			std::cerr << "Invalid input for door count - Should be a number!\n";
			return 1;
		}
	}

	int simCount = std::stoi(arg[1]);
	int doorCount = std::stoi(arg[2]);
	std::pair<double,double> results = MontyHall::playGame(simCount, doorCount);
	std::cout << "Success rate if you don't switch doors: " << results.first * 100 << "%!\n";
	std::cout << "Success rate if you switch doors: " << results.second * 100 << "%!\n";
	return 0;
}
