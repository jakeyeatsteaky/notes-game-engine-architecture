#pragma once

/*------------------------------------------------------------------------
    This example shows the nuance of using inline functions and the
    static keyword as they pertain to the linker.
------------------------------------------------------------------------*/

inline int max(int a, int b)
{
    return (a >= b) ? a : b;
}

int slowMax(int a, int b);

namespace linkage
{
    void runExperiment();
}

