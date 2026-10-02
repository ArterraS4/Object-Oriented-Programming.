//main.cpp
#include <iostream>
#include "RPG.h"
using namespace std;

int main()
{
    RPG p1 = RPG("Wiz", 0, 0.2, 60, 1);
    RPG p2 = RPG();

    printf("%s Current Stats\n", p1.getName().c_str());
    printf("Hits Taken: %i\t Luck: %f\t Exp: %f\t Level: %i\n", p1.gethits_taken(), p1.getluck(), p1.getexp(), p1.getlevel());

    // PRINT the same for p2
    printf("%s Current Stats\n", p2.getName().c_str());
    printf("Hits Taken: %i\t Luck: %f\t Exp: %f\t Level: %i\n", p2.gethits_taken(), p2.getluck(), p2.getexp(), p2.getlevel());

    // CALL setHitsTaken(new_hit) on either p1 and p2
    p2.setHitsTaken(3); 

    cout << "\nP2 hits taken ";
    // PRINT out the hits_taken
    cout << p2.gethits_taken() << endl;

    cout << "0 is dead, 1 is alive\n";
    // CALL isAlive() on both p1 and p2
    cout << "p1 alive status: " << p1.isAlive() << endl;
    cout << "p2 alive status: " << p2.isAlive() << endl;

    return 0;
}

