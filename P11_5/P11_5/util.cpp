#include "util.hpp"

void UTIL::swap(int& x, int& y){
    int temp = x;
    x = y;
    y = temp;
}
void UTIL::swap_people(Person& x, Person& y){
    Person temp(x);
    x = y;
    y = temp;
}
void UTIL::print_vector(std::vector<int> v, std::string name){
    for (int i = 0; i < v.size(); i++) std::cout << name << "[" << i << "]: " << v[i] << std::endl;
}
void UTIL::print_people(std::vector<Person> v, std::string name){
    for (int i = 0; i < v.size(); i++){
        printf("%s[%*i]: Name = %*s | Telephone = %s\n", name.c_str(), 4, i, 24, v[i].get_name().c_str(), v[i].get_telephone().c_str());
    }
}
void UTIL::rand_seed(){
    srand(static_cast<int>(time(NULL)));
}
int UTIL::rand_int(int a, int b){
    return rand()%(b-a+1);
}
