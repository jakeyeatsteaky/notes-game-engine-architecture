#include "linkage.hpp"
#include <chrono>
#include <iostream>

/*------------------------------------------------------------------------
    Detailed notes on this example found in the header file
------------------------------------------------------------------------*/

typedef std::ratio<1, 1000000000000> pico;
typedef std::chrono::duration<long long, pico> picoseconds;

int slowMax(int a, int b)
{
    return (a >= b) ? a : b;
}

namespace linkage
{
    void runExperiment()
    {
        std::cout << "\nRunning Inline Experiment. . .\n";
        
        auto start = std::chrono::high_resolution_clock::now();
        max(123123123,123123122);
        max(1,100000);
        max(0,5000);
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<picoseconds>( stop - start);
        std::cout << "Using Inline Functions, time: " << duration.count() << std::endl;

        auto start2 = std::chrono::high_resolution_clock::now();
        slowMax(123123123,123123122);
        slowMax(1,100000);
        slowMax(0,5000);
        auto stop2 = std::chrono::high_resolution_clock::now();
        auto duration2 = std::chrono::duration_cast<picoseconds>( stop2 - start2);
        std::cout << "Using Declared/defined Functions, time: " << duration2.count() << std::endl;
    }
}

