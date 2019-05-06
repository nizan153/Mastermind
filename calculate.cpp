#include "calculate.hpp"
#include "play.hpp"
#include "DummyChoosers.hpp"
#include "DummyGuessers.hpp"
#include "SmartGuesser.hpp"

string calculateBullAndPgia(const string chosen, const string guess) {
    
    int bull = 0;
    int pgia = 0;
    int count[10] = { 0 };

    for(int i = 0; i < chosen.length(); i++) {
        if(guess.at(i) == chosen.at(i)) { bull++; }
        else {
            if(count[guess.at(i)-'0']++ < 0) { pgia++; }
            if(count[chosen.at(i)-'0']-- > 0) { pgia++; }
            
        }
    }
    std::string str = std::to_string(bull) + "," + std::to_string(pgia);
    return str;

}