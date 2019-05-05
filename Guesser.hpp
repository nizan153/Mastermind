#pragma once

#include <string>

namespace bullpgia {
    class Guesser {
        public: 
            uint length;
            virtual void startNewGame(uint length){this->length = length;}
            virtual void learn(std::string s){};
            virtual std::string guess()=0;
    };
}
