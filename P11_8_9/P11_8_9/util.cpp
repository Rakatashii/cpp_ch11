#include "util.hpp"

void UTIL::swap(int& x, int& y){
    int temp = x;
    x = y;
    y = temp;
}
void UTIL::print_vector(std::vector<int> v, std::string name){
    for (int i = 0; i < v.size(); i++) std::cout << name << "[" << i << "]: " << v[i] << std::endl;
}
void UTIL::print_two_vectors(std::vector<int> v, std::vector<int> u, std::string vname, std::string uname){
    int sz = (v.size() >= u.size()) ? v.size() : u.size();
    for (int i = 0; i < sz; i++){
        if (i >= u.size()-1 || u[i] == 0)
            printf("%s[%*i]:  %*i  |  %s[%*i]:  EMPTY\n", vname.c_str(), 2, i, 3, v[i], uname.c_str(), 2, i);
        else if (i >= v.size()-1 || v[i] == 0)
            printf("%s[%*i]:  EMPTY  |  %s[%*i]:  %*i\n", vname.c_str(), 2, i, uname.c_str(), 2, i, 3, u[i]);
        else printf("%s[%*i]:  %*i  |  %s[%*i]:  %*i\n", vname.c_str(), 2, i, 3, v[i], uname.c_str(), 2, i, 3, u[i]);
    }
}
void UTIL::seed_rand(){
    srand(static_cast<int>(time(NULL)));
}
int UTIL::rand_int(int a, int b){
    return a + rand() % (b - a + 1);
}
double UTIL::rand_double(double min, double max){
    double d = (double)rand() / RAND_MAX;
    return min + d * (max - min);
}
