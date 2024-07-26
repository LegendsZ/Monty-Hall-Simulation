//Created by LegendsZ
//Simulation to observe the different outcomes for the Monty Hall problem

#include <iostream>

#include "/Users/abaskar/Projects/Monty-Hall-Simulation/include/MontyHall.h"

int main(int argc, char* arg[]){
	if (argc != 2){
		std::cerr << "Missing input for # of runs for simulation!\n";
	}
	for (int i = 0; i < strlen(arg[1]); ++i){
		if (!std::isdigit(arg[1][i])){
			std::cerr << "Invalid input - Should be a number!\n";
		}
	}

	int simCount = std::stoi(arg[1]);
	std::pair<double,double> results = MontyHall::playGame(simCount);
	std::cout << "Success rate if you don't switch doors: " << results.first * 100 << "%!\n";
	std::cout << "Success rate if you switch doors: " << results.second * 100 << "%!\n";
	return 0;
}
