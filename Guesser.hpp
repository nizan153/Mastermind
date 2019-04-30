#pragma once

#include <string>
using std::string;

namespace bullpgia {
    class Guesser {
        public: 
            uint length;
            virtual void startNewGame(uint length){};
            virtual void learn(string s){};
            virtual string guess()=0;
    };
}