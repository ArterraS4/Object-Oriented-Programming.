//RPG.h
#ifndef RPG_h
#define RPG_h
#include <string> 
using namespace std;

const int INVENTORY_SIZE = 10;
const float HIT_FACTOR = 0.05;
const int MAX_HITS_TAKEN = 3;

class RPG {
    public:
        //constructors
        RPG();
        RPG(string name, int hits_taken, float luck, float exp, int level);

        //mutators
        bool isAlive() const;
        void setHitsTaken(int new_hits);

        //accessors
        string getName() const;
        int gethits_taken() const;
        float getluck() const;
        float getexp() const;
        int getlevel() const;
        

    private:
        string name;
        int hits_taken;
        float luck;
        float exp;
        int level;
};
#endif

/** Extended functions */
void RPG::setName(string name){
    this->name = name;
}
void RPG::updateExpLevel(){ 
exp += 50;
if(exp >= 100){
level = level + 1;
exp = 0;
luck += 0.1;}
}
void RPG::attack(RPG * opponent){
random_device rd;
mt19937 gen(rd());
uniform_real_distribution<double> dis(0.0, 1.0);
float random_num = dis(gen);
bool hit = false;
if(random_num > HIT_FACTOR * (*opponent).getluck()){
hit = true;}
if(hit){
(*opponent).setHitsTaken((*opponent).gethits_taken() + 1);}
}

void RPG::printStats() {
cout << "Name: " << name << "\tHits Taken: " << hits_taken << "\tLuck: " << fixed << setprecision(6) << luck << "\tExp: " << fixed << setprecision(6) << exp << "\tLevel: " << level << "\tStatus: " << (isAlive() ? "Alive" : "Dead") << endl;
}
RPG::~RPG()
{
}


