#ifndef util_hpp
#define util_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include "person.hpp"

namespace UTIL{
    extern void swap(int& x, int& y);
    extern void swap_people(Person& x, Person& y);
    extern void print_vector(std::vector<int> v, std::string name = "v");
    extern void print_people(std::vector<Person> v, std::string name = "v");
    extern void rand_seed();
    extern int rand_int(int a, int b);
}

#endif /* util_hpp */
