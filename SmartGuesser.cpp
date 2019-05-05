#include "SmartGuesser.hpp"

using namespace bullpgia;
using namespace std;

void SmartGuesser::startNewGame(uint length) {
    permSet.clear();
    this->length = length;
    initList();
}

void SmartGuesser::learn(string str) {
    for (auto i = permSet.begin(); i != permSet.end(); i++) {
        if(calculateBullAndPgia(*i, this->lastGuess).compare(str) != 0) {
            permSet.erase(*i); 
        }
    }
}

string SmartGuesser::guess() {
    if (permSet.size() == pow(10, length)){
        lastGuess.clear();
        for (uint i = 0; i < length; i++) {
            lastGuess += '0' + i;
        } 
    }
    else{
        set<string>::iterator it = permSet.begin();
        advance(it, rand()%permSet.size());
        lastGuess = *it;
    }
    return lastGuess;
}

void SmartGuesser::initList() {
    for(uint i = 0; i < pow(10, length); i++) {
        stringstream ss;
        ss << setw(length) << setfill('0') << i; 
        string s = ss.str();
        permSet.insert(s);
    }
}