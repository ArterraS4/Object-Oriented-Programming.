#ifndef POKEMON_H
#define POKEMON_H

#include <string>
#include <vector>
using namespace std;

class Pokemon {
public:
    // Constructors & Destructor
    Pokemon();
    Pokemon(const string& name, int hp, int att, int def, const vector<string>& type);
    virtual ~Pokemon() = default; 

    // Mutator / Behavior Functions
    virtual void speak();
    virtual void printStats() const;

    // Accessor Functions (Getters)
    string getName() const;
    int getHp() const;
    int getAttack() const;
    int getDefense() const;
    vector<string> getType() const;
        
protected:
    string name;
    int hp;
    int attack;
    int defense;
    vector<string> type;
};

#endif
