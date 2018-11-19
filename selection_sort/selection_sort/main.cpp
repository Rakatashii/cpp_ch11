#include <iostream>
#include <vector>
#include "util.hpp"

using namespace std;

int min_position(vector<int>&a , int from, int to);
void selection_sort(vector<int>& a);

int main(int argc, const char * argv[]) {
    UTIL::rand_seed();
    vector<int> v(20);
    for (int i = 0; i < v.size(); i++){
        v[i] = UTIL::rand_int(1, 100);
    }
    UTIL::print_vector(v, "(before selection_sort) v");
    cout << "\n";
    selection_sort(v);
    UTIL::print_vector(v, "(after selection_sort)  v");
    cout << "\n";
    return 0;
}

int min_position(vector<int>&a , int from, int to){
    int min_pos = from;
    for (int i = from + 1; i <= to; i++)
        if (a[i] < a[min_pos]) min_pos = i;
    return min_pos;
};
void selection_sort(vector<int>& a){
    int next; // This is the next position to be set to the minimum.
    for (next = 0; next < a.size() - 1; next++){
        int min_pos = min_position(a, next, a.size() - 1);
        if (min_pos != next){
            UTIL::swap(a[min_pos], a[next]);
        }
    }
}
