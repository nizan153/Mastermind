#pragma once

#include <string>
#include <math.h>
#include <iostream>
#include <iomanip>
#include <iostream>
#include <unordered_set>
#include "calculate.hpp"
#include "Guesser.hpp"

namespace bullpgia {
    class SmartGuesser : public Guesser {
        private:
            std::unordered_set<std::string> set1;
            std::unordered_set<std::string> set2;
            std::string lastGuess;
            void initList();
            string numToGuess(int num, int length);
        public: 
            void startNewGame(uint length) override;
            void learn(std::string s) override;
            std::string guess() override;
    };
}