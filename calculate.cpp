#include "calculate.hpp"
#include "play.hpp"
#include "DummyChoosers.hpp"
#include "DummyGuessers.hpp"
#include "SmartGuesser.hpp"

string calculateBullAndPgia(const string chosen, const string guess) {
    if(chosen.length() != guess.length()) {
        throw "Guess too long/short";
    }
    uint bull = 0;
    uint pgia = 0;

    uint count[10] = { 0 };

    for(uint i = 0; i < chosen.length(); i++) {
        if(guess.at(i) == chosen.at(i)) { bull++; }
        else {
            if(count[chosen.at(i)-'0']++ != 0) { pgia++; }
            if(count[guess.at(i)-'0']-- != 0) { pgia++; }
            
        }
    }
    return std::to_string(bull) + "," + std::to_string(pgia);

}