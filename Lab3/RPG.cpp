#include "RPG.h"
#include <string>
#include <iostream>
#include <iomanip>
#include <random>

using namespace std;

//Default constructor
RPG::RPG() {
    name = "NPC";
    hits_taken = 0;
    luck = 0.1;
    exp = 50.0;
    level = 1;
}

//Overloaded constructor
RPG::RPG(string name, int hits_taken, float luck, float exp, int level) {
    this->name = name;
    this->hits_taken = hits_taken;
    this->luck = luck;
    this->exp = exp;
    this->level = level;
}

//MUTATOR
void RPG::setHitsTaken(int new_hits) {
    hits_taken = new_hits;
}

//ACCESSOR
bool RPG::isAlive() const {
    return hits_taken < MAX_HITS_TAKEN;
}

string RPG::getName() const {
    return name;
}

// Fixed capitalization to match RPG.h and Game.cpp
int RPG::getHitsTaken() const {
    return hits_taken;
}

// Fixed capitalization to match RPG.h and Game.cpp
float RPG::getLuck() const {
    return luck;
}

float RPG::getexp() const {
    return exp;
}

int RPG::getlevel() const {
    return level;
}

// -------------------------------------------------------------
// EXTENDED FUNCTIONS IMPLEMENTATIONS
// -------------------------------------------------------------

void RPG::setName(string name) {
    this->name = name;
}

void RPG::updateExpLevel() { 
    exp += 50;
    if (exp >= 100) {
        level = level + 1;
        exp = 0;
        luck += 0.1;
    }
}

void RPG::attack(RPG * opponent) {
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<double> dis(0.0, 1.0);
    float random_num = dis(gen);
    bool hit = false;
    
    if (random_num > HIT_FACTOR * (*opponent).getLuck()) {
        hit = true;
    }
    if (hit) {
        (*opponent).setHitsTaken((*opponent).getHitsTaken() + 1);
    }
}

void RPG::printStats() {
    cout << "Name: " << name << "\tHits Taken: " << hits_taken << "\tLuck: " << fixed << setprecision(6) << luck << "\tExp: " << fixed << setprecision(6) << exp << "\tLevel: " << level << "\tStatus: " << (isAlive() ? "Alive" : "Dead") << endl;
}

RPG::~RPG() {
}
