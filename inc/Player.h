#ifndef PLAYER_H
#define PLAYER_H


#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

class Player {
    std::string _name;
    std::string _team;
    std::string _position;
    int _age;
    float _height;
    int _weight;
    std::string _college;
    int _salary;

public:
    // Constructors
    Player();
    Player(std::string n, std::string t, std::string p, int a, float h, int w, std::string c, int s);

    bool matchesCriteria(const std::string& criteria) const; 

    int getAge() const { return _age; }
    int getWeight() const { return _weight; }
    float getHeight() const { return _height; }
    int getSalary() const { return _salary; }


    // Operator overloading
    friend std::istream& operator>>(std::istream& input, Player& player);
    friend std::ostream& operator<<(std::ostream& output, const Player& player);
};

// Constructor definitions

Player::Player() {
    // Default constructor
}

Player::Player(std::string n, std::string t, std::string p, int a, float h, int w, std::string c, int s)
    : _name(n), _team(t), _position(p), _age(a), _height(h), _weight(w), _college(c), _salary(s) {
    // Parameterized constructor
}

bool Player::matchesCriteria(const std::string& criteria) const {
    std::istringstream iss(criteria);
    std::string word;

    // Podziel kryterium na wyrazy i porównaj z polami zawodnika
    while (iss >> word) {
        if (_name.find(word) != std::string::npos ||
            _team.find(word) != std::string::npos ||
            _position.find(word) != std::string::npos ||
            std::to_string(_age).find(word) != std::string::npos ||
            std::to_string(_height).find(word) != std::string::npos ||
            std::to_string(_weight).find(word) != std::string::npos ||
            _college.find(word) != std::string::npos ||
            std::to_string(_salary).find(word) != std::string::npos) {
            return true;
        }
    }

    return false;
}

// Operator overloading definitions

std::istream& operator>>(std::istream& input, Player& player) {
    std::string line;
    if (std::getline(input, line)) {
        std::istringstream iss(line);
        std::string name, team, position, age, height, height_i, weight, college, salary;

        if (std::getline(iss, name, ',') && std::getline(iss, team, ',') && std::getline(iss, position, ',') &&
            std::getline(iss, age, ',') && std::getline(iss, height, ',') && std::getline(iss, height_i, ',') &&
            std::getline(iss, weight, ',') && std::getline(iss, college, ',') && std::getline(iss, salary)) {
            // Assign values to player object
            player._name = name;
            player._team = team;
            player._position = position;
            player._age = std::stoi(age);
            player._height = std::stof(height_i);
            player._weight = std::stoi(weight);
            player._college = college;
            player._salary = (salary == "nan") ? 0 : std::stoi(salary);
        }
    }

    return input;
}

std::ostream& operator<<(std::ostream& output, const Player& player) {
    output << "Name: " << player._name << "\n";
    output << "Team: " << player._team << "\n";
    output << "Position: " << player._position << "\n";
    output << "Age: " << player._age << "\n";
    output << "Height: " << player._height << "\n";
    output << "Weight: " << player._weight << "\n";
    output << "College: " << player._college << "\n";
    output << "Salary: " << player._salary << "\n";

    return output;
}

#endif // PLAYER_H
