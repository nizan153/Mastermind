#pragma once

#include <string>
#include <math.h>
#include <iostream>
#include <iomanip>
#include <iostream>
#include <set>
#include "calculate.hpp"
#include "Guesser.hpp"

namespace bullpgia {
    class SmartGuesser : public Guesser {
        private:
            std::set<std::string> permSet;
            std::string lastGuess;
            void initList();
        public: 
            void startNewGame(uint length) override;
            void learn(std::string s) override;
            std::string guess() override;
    };
}