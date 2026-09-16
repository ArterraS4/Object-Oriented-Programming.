#include<iostream>
#include<fstream>
/**
 * @brief Added 4 new include for our functions to use.
 * TO DO: 
 * Add <vector>, <cstdlib>, and <ctime>​
 */
#include<vector>
#include<cstdlib>
#include<ctime>
#include <random>
using namespace std;

/**
 * TO DO: 
 * Create function prototypes for all the functions.
 * Write their function declarations below mai()).
 * 
 * See promptFile(...) and printVec(...), which serve as examples.
 * @brief one int, to fix the random gen, 2 bools, for the readfile and writefile to make our new functions work and including the string filename.
 */
int ranGen(size_t max_size);
bool readFile(string filename, vector<string> & vec);
bool writeFile(string filename, const vector<string> & v0, const vector<string> & v1);

//------------------------PROTOTYPE-------------------------------------------
void promptFile(vector<string> &); 
void printVec(vector<string>);

/**
 * @brief randomly returns base on the SIZE instead of the numbers.
 * - It is hardcoded to be from the SIZE.
 * - Uses srand(nullptr) in main()
 * TO DO:
 * Modify it so that randGen() reads in 
 * the size of the questions instead of 6 (e.g. questions.size())
 * 
 * TO DO:
 * Use <random> for modern C++ random generation instead 
 * 
 * @return int: the distrib(gen)
 */
int ranGen(size_t max_size){
    if (max_size == 0) return 0;
    static random_device rd;
    static mt19937 gen(rd());
    uniform_int_distribution<int> distrib(0, max_size - 1);
    
    return distrib(gen);
}

/**
 * @brief reads contents of file name and decides whether to accept it or not on bool.
 * 
 * @param filename :string 
 * @param vec: vector<string> &
 * 
 * TO DO: 
 * ​​​Return a bool instead in order to indicate whether the operation
 * succeeded or not
 */
bool readFile(string filename, vector<string> & vec) {

   ifstream inputFile(filename);

    //error handling
    if (!inputFile.is_open()) {
        cerr << "Error: Could not open file: " << filename << "\n";
        return false;
    }

    string line;

    while (getline(inputFile, line)) {
        vec.push_back(line);
    }

    inputFile.close();
    return true;
}
/**
 * @brief writes to filename with the first column from v0, second column from v1, now deciding whether or not to accept with using a bool function.
 * @param filename: string
 * @param v0: vector<string> (for students names)
 * @param v1: vector<string> (for questions)
 * 
 * TO DO: 
 * ​​​Return a bool instead in order to indicate whether the operation
 * succeeded or not
 * 
 * TO DO:
 * ​​Use pass by const reference (const vector<string> & v0, const vector<string> & v1)
 * as opposed to pass by value (vector<string> v0, vector<string> v1). 
 * 
 * What is the differennce between:
 * -  pass by reference (e.g. vector<string> & v0),
 * -  pass by value (e.g. vector<string> v0),
 * -  pass by const reference (e.g. const vector<string> & v0),
 */
bool writeFile(string filename, const vector<string> & v0, const vector<string> & v1){

    ofstream outputFile(filename);
    if (!outputFile) {
        cout << "Error: Could not create " << filename << endl;
        return false;
    }

    // write under the structure:
    // Student_Name, Question_#
    for(int i = 0; i < v0.size(); i++){
        outputFile << v0[i] << "," << v1[ranGen(v1.size())] << endl;
    }
    outputFile.close();
    
    return true;

}


int main()
{
    srand(time(nullptr));
    vector<string> roster;
    vector<string> qBank;
    readFile("2310_F26_Rosters.csv", roster);
    readFile("Questions.csv", qBank);
    // printVec(roster);
    // printVec(qBank);

    // cout << "Size of roster: " << roster.size() << endl; 
    // cout << "Size of qBank: " << qBank.size() << endl;

    writeFile("Student_question_bank.csv",roster, qBank);

}

//------------------------DECLARATIONS-------------------------------------------
/**
 * @brief prompts the user to give a file to read
 * 
 */
void promptFile(vector<string> & v){
    cout << "file to read?\n";
    string myFile = "";
    cin >> myFile;
    readFile(myFile, v);
}


/**
 * @brief prints out the elements in v
 * 
 * @param v: vector<string>
 */
void printVec(vector<string> v){
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << endl;
    }
}
