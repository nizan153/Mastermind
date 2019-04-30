#pragma once

#include <string>
#include "calculate.hpp"
#include "Guesser.hpp"
using std::string;

namespace bullpgia {
    class SmartGuesser : public Guesser {
        public: 
            void startNewGame(uint length) override;
            void learn(string s) override;
            string guess() override;
    };
}