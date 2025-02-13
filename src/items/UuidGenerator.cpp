
#include "UuidGenerator.h"
#include <algorithm>
#include <random>
#include <sstream>
#include <iomanip>

string UuidGenerator::generate() {
     
     std::random_device rd;
     std::mt19937 gen(rd());
     std::uniform_int_distribution<> dis(0, 15);
     std::uniform_int_distribution<> dis2(8, 11);

     stringstream ss;

     ss << hex;

     for (int i = 0; i < 8; i++) {
          ss << dis(gen);
     }
     ss << "-";
     for (int i = 0; i < 4; i++) {
          ss << dis(gen);
     }
     ss << "-4"; // v4
     for (int i = 0; i < 3; i++) {
          ss << dis(gen);
     }
     ss << "-";
     ss << dis2(gen); // custom variant must be in these digits
     for (int i = 0; i < 4; i++) {
          ss << dis(gen);
     }
     ss << "-";
     for (int i = 0; i < 12; i++) {
          ss << dis(gen);
     }

     return ss.str();
}
