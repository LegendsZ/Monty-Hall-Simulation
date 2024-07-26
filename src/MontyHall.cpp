#include <cstdlib>
#include <time.h>

#include "/Users/abaskar/Projects/Monty-Hall-Simulation/include/MontyHall.h"

namespace MontyHall{
    namespace {
        std::array<int, 3> generateDoors() {
            int spot = rand() % 3;
            std::array<int, 3> doors = {0, 0, 0};
            doors[spot] = 1;
            return doors;
        }

        int switchDoors(int choice, int reveal){
            for (int i = 0; i < 3; ++i){
                if (i != choice && i != reveal){
                    return i;
                }
            }
            return -1;
        }

        int revealDoors(const std::array<int, 3>& doors, int choice) {
            for (int i = 0; i < 3; ++i) {
                if (doors[i] == 0 && i != choice) {
                    return i;
                }
            }
            return -1;
        }
    }

    std::pair<double, double> playGame(int numGames) {
        int successIfSwitch = 0;
        int successIfNotSwitch = 0;
        srand(time(0));
        for (int i = 0; i < numGames; ++i) {
            std::array<int, 3> doors = generateDoors();
            int choice = rand() % 3;
            int reveal = revealDoors(doors, choice);
            if (doors[choice] == 1) { // Assume user doesn't switch
                successIfNotSwitch++;
            }

            choice = switchDoors(choice, reveal); // Assume user switches

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