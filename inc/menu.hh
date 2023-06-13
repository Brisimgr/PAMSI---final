#ifndef MENU_HH
#define MENU_HH

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

#include "Player.h"
#include "Table.h"

void printMenu()
{
    std::cout << "|**************************" << " NBA STATS 2022 " << "**************************|" << std::endl;
    std::cout << "|*                    " << "                " << "                              *|" << std::endl;
    std::cout << "|*                     " << "   SELECT WHAT TO DO  " << "                       *|" << std::endl;
    std::cout << "|*             " << "    1. SEARCH BY GIVEN CRITERIA   " << "                   *|" << std::endl;
    std::cout << "|*             " << "    2. SORT PLAYERS BY GIVEN CRITERIA   " << "             *|" << std::endl;
    std::cout << "|*                     " << "                " << "                             *|" << std::endl;
    std::cout << "|**************************" << "****************" << "**************************|" << std::endl;
}

void printSearch()
{
    std::cout << "|**************************" << " NBA STATS 2022 " << "**************************|" << std::endl;
    std::cout << "|*                   " << "                " << "                               *|" << std::endl;
    std::cout << "|* Type in the criteria you want to search (name/height/etc): ";
}

void printSort()
{
    std::cout << "|**************************" << " NBA STATS 2022 " << "**************************|" << std::endl;
    std::cout << "|*                    " << "                " << "                              *|" << std::endl;
    std::cout << "|*                     " << " SELECT WHAT TO SORT BY  " << "                    *|" << std::endl;
    std::cout << "|*             " << "             1. AGE   " << "                               *|" << std::endl;
    std::cout << "|*             " << "             2. HEIGHT   " << "                            *|" << std::endl;
    std::cout << "|*             " << "             3. WEIGHT   " << "                            *|" << std::endl;
    std::cout << "|*             " << "             4. SALARY   " << "                            *|" << std::endl;
    std::cout << "|*                     " << "                " << "                             *|" << std::endl;
    std::cout << "|**************************" << "****************" << "**************************|" << std::endl;
    std::cout << "|*                     " << "                " << "                             *|" << std::endl;
    std::cout << "|* Type in the chosen option:  ";
    
}

void printHowMany()
{
    std::cout << "|**************************" << " NBA STATS 2022 " << "**************************|" << std::endl;
    std::cout << "|*                    " << "                " << "                              *|" << std::endl;
    std::cout << "|* Type in how many to display (must be less than 100): ";
}

void printWhatOrder()
{
    std::cout << "|**************************" << " NBA STATS 2022 " << "**************************|" << std::endl;
    std::cout << "|*                    " << "                " << "                              *|" << std::endl;
    std::cout << "|*                       " << " SELECT HOW TO SORT  " << "                      *|" << std::endl;
    std::cout << "|*             " << "            1. ASCENDING   " << "                          *|" << std::endl;
    std::cout << "|*             " << "            2. DESCENDING   " << "                         *|" << std::endl;
    std::cout << "|*                     " << "                " << "                             *|" << std::endl;
    std::cout << "|**************************" << "****************" << "**************************|" << std::endl;
}

void searchReady(PlayerTable* table)
{
    system("clear");
    std::string criteriaToSearch;
    printSearch();
    std::cin>>criteriaToSearch;
    std::vector<Player> searchResult = table->searchByCriteria(criteriaToSearch);
    std::cout << "Players matching the criteria: " << criteriaToSearch << std::endl;
    for (const auto& player : searchResult) {
        std::cout << player << std::endl;
    }
}

void sortReady(PlayerTable* table, int crit)
{
    system("clear");

    int howMany = 0;
    printHowMany();
    std::cin >> howMany;

    system("clear");

    int order = 0;
    printWhatOrder();
    std::cin >> order;

    system("clear");
    table->sortByStatistic(crit, howMany, order);
}

int sortMenu(PlayerTable* table)
{
    int option = 0;
    do
    {
        system("clear");
        printSort();
        std::cin >> option;

        switch(option)
        {
        case 0:
            return 0;
            break;

        case 1:
        {
            sortReady(table, option);
            return 1;
        }
            break;
        
        case 2:
        {
            sortReady(table, option);
            return 1;
        }
            break;

        case 3:
        {
            sortReady(table, option);
            return 1;
        }
            break;

        case 4:
        {
            sortReady(table, option);
            return 1;
        }
            break;
        
        default:
        {
            std::cout << "THAT'S NOT A VALID OPTION, TRY AGAIN" << std::endl;
            std::cout << std::endl;
        }
            break;
        }
    } while (option != 0);

}

int menu()
{
    int option = 0;
    std::ifstream file("players.csv");
    if (!file) {
        std::cout << "Failed to open file." << std::endl;
        return 1;
    }

    std::string line;
    std::getline(file, line); // Skip header line

    PlayerTable table;

    Player player;
    while (file >> player) {
        table.addPlayer(player);
    }

    file.close();

    do
    {
        system("clear");
        printMenu();
        std::cout << "|*                    " << "                " << "                              *|" << std::endl;
        std::cout << "|* Type in the chosen option:  ";
        std::cin >> option;

        switch(option)
        {
        case 0:
            return 0;
            break;

        case 1:
        {
            searchReady(&table);
            return 1;
        }
            break;
        
        case 2:
        {
            sortMenu(&table);
            return 1;
        }
            break;
        
        default:
        {
            std::cout << "THAT'S NOT A VALID OPTION, TRY AGAIN" << std::endl;
            std::cout << std::endl;
        }
            break;
        }
    } while (option != 0);

    return 0;
}

#endif