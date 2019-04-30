#pragma once

#include <string>
using std::string;

namespace bullpgia {
    class Chooser {
        public: 
            uint length;
            virtual string choose(uint length)=0; 
    };
}