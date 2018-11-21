#ifndef util_hpp
#define util_hpp

#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>

namespace UTIL{
    extern void swap(int& x, int& y);
    extern void print_vector(std::vector<int> a, std::string name = "a");
    extern void rand_seed();
    extern int rand_int(int a, int b);
}

#endif /* util_hpp */
