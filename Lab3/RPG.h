//RPG.h
#ifndef RPG_h
#define RPG_h
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

