#ifndef UTILITIES_H_INCLUDED
#define UTILITIES_H_INCLUDED

#include <cstdlib>
#include <iostream>
#include <sstream>

#include "../runner/configs.h"

class Utilities
{
    public:
        static void print(std::string m);
        static void print(std::string *m);
        static void print(char c);
        static void println();
        static void println(std::string m);
        static void core_clearScr();
        static void core_pauseScr();
        static bool core_isDevEnvironment();
        static std::string core_formatNumber(int number);
};

#endif // UTILITIES_H_INCLUDED
