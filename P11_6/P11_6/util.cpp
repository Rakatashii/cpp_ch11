#include "util.hpp"

void UTIL::swap(int& x, int& y){
    int temp = x;
    x = y;
    y = temp;
}
void UTIL::print_vector(std::vector<int> v, std::string name){
    for (int i = 0; i < v.size(); i++) std::cout << name << "[" << i << "]: " << v[i] << std::endl;
}
void UTIL::rand_seed(){
    srand(static_cast<int>(time(NULL)));
}
int UTIL::rand_int(int a, int b){
    return rand()%(b-a+1);
}
double UTIL::rand_double(double min, double max){
    double d = (double)rand() / RAND_MAX;
    return min + d * (max - min);
}
