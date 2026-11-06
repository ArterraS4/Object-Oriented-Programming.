#ifndef CHARMANDER_H    
#define CHARMANDER_H

#include <string>
#include <vector>
#include "Pokemon.h"
using namespace std;

class Charmander : public Pokemon {
public:
    // ------------------ Constructors ------------------
    Charmander();
    
    
    Charmander(const string& name, int hp, int att, int def, const vector<string>& t, const vector<string>& s);
    
    // ------------------ Mutator Functions ------------------

    void speak() override;
    void printStats() const  override;

private:
    vector<string> skills;
};

#endif

