#include "SmartGuesser.hpp"

using namespace bullpgia;
using namespace std;

void SmartGuesser::startNewGame(uint length) {
    set1.clear();
    this->length = length;
    initList();
}

void SmartGuesser::learn(string str) {
    for (auto it = set1.begin(); it != set1.end(); it++) {
        if( str == calculateBullAndPgia(*it, lastGuess)) {
            set2.insert(*it);
        }
    }

    set1 = set2;
    set2.clear();
}

string SmartGuesser::guess() {
    if (set1.size() == pow(10, length)){
        lastGuess.clear();
        for (uint i = 0; i < length; i++) {
            lastGuess += '0' + i;
        } 
    }
    else{
        lastGuess = *set1.begin();
    }
    return lastGuess;
}

void SmartGuesser::initList() {
    for(uint i = 0; i < pow(10, length); i++) {
        set1.insert(numToGuess(i,length));
    }
}
string SmartGuesser::numToGuess(int num, int length){
    string guess = to_string(num);
    int numOfZeros = length - guess.length();
    for (int i = 0; i < numOfZeros; i++) {
        guess = "0" + guess;
    }
    return guess;
}