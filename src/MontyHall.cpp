#include <cstdlib>
#include <ctime>
#include <vector>
#include <utility>
#include "../include/MontyHall.h"

namespace MontyHall {
    namespace {
        std::vector<int> generateDoors(int numDoors) {
            int spot = rand() % numDoors;
            std::vector<int> doors(numDoors, 0);
            doors[spot] = 1;
            return doors;
        }

        int switchDoors(int choice, int reveal, int numDoors) {
            for (int i = 0; i < numDoors; ++i) {
                if (i != choice && i != reveal) {
                    return i;
                }
            }
            return -1;
        }

        int revealDoors(const std::vector<int>& doors, int choice, int numDoors) {
            for (int i = 0; i < numDoors; ++i) {
                if (doors[i] == 0 && i != choice) {
                    return i;
                }
            }
            return -1;
        }
    }

    std::pair<double, double> playGame(int numGames, int numDoors) {
        int successIfSwitch = 0;
        int successIfNotSwitch = 0;
        srand(time(0));
        for (int i = 0; i < numGames; ++i) {
            std::vector<int> doors = generateDoors(numDoors);
            int choice = rand() % numDoors;
            int reveal = revealDoors(doors, choice, numDoors);
            if (doors[choice] == 1) { // Assume user doesn't switch
                successIfNotSwitch++;
            }

            choice = switchDoors(choice, reveal, numDoors); // Assume user switches

            if (doors[choice] == 1) {
                successIfSwitch++;
            }
        }

        return std::make_pair(
            static_cast<double>(successIfNotSwitch) / numGames,
            static_cast<double>(successIfSwitch) / numGames
        );
    }
}