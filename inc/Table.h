#ifndef TABLE_H
#define TABLE_H


#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

#include "Player.h"

struct PlayerTable {
    std::vector<Player> players;

    void addPlayer(const Player& player) {
        players.push_back(player);
    }

    std::vector<Player> searchByCriteria(const std::string& criteria) {
        std::vector<Player> result;

        for (const auto& player : players) {
            if (player.matchesCriteria(criteria)) {
                result.push_back(player);
            }
        }

        return result;
    }

bool sortByStatistic(const int& with_stat, int numPlayers, int order) {
    std::sort(players.begin(), players.end(), [&with_stat, order](const Player& player1, const Player& player2) {
        if (with_stat == 1) {
            if (order == 1)
                return player1.getAge() < player2.getAge();
            else
                return player1.getAge() > player2.getAge();
        } else if (with_stat == 2) {
            if (order == 1)
                return player1.getHeight() < player2.getHeight();
            else
                return player1.getHeight() > player2.getHeight();
        } else if (with_stat == 3) {
            if (order == 1)
                return player1.getWeight() < player2.getWeight();
            else
                return player1.getWeight() > player2.getWeight();
        } else if (with_stat == 4) {
            if (order == 1)
                return player1.getSalary() < player2.getSalary();
            else
                return player1.getSalary() > player2.getSalary();
        }

        return false;
    });

    if (numPlayers > players.size()) {
        numPlayers = players.size();
    }

    std::string stat;

    if (with_stat == 1) {
        stat = "Age";
    } else if (with_stat == 2) {
        stat = "Height";
    } else if (with_stat == 3) {
        stat = "Weight";
    } else if (with_stat == 4) {
        stat = "Salary";
    }

    std::cout << "Top " << numPlayers << " players sorted by " << stat << ":\n";
    std::cout << std::endl;
    for (int i = 0; i < numPlayers; ++i) {
        std::cout << players[i] << "\n";
    }

    return true;
}
};

#endif // TABLE_H
