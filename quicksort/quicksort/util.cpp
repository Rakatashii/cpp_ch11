#include "util.hpp"

void UTIL::swap(int& x, int& y){
    int temp = x;
    x = y;
    y = temp;
}
extern int width;
void UTIL::print_vector(std::vector<int> a, std::string name){
    for (int i = 0; i < a.size(); i++)
        printf("%s[%*i]: %i\n", name.c_str(), width, i, a[i]);
}
void UTIL::rand_seed(){
    srand(static_cast<int>(time(NULL)));
}
int UTIL::rand_int(int a, int b){
    return a + rand() % (b-a+1);
}
