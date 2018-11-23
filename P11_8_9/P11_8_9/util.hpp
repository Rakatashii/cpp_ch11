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
    extern void print_vector(std::vector<int> v, std::string name = "v");
    extern void print_two_vectors(std::vector<int> v, std::vector<int> u, std::string vname = "v", std::string uname = "u");
    extern void seed_rand();
    extern int rand_int(int a, int b);
    extern double rand_double(double min, double max);
}

#endif /* util_hpp */
