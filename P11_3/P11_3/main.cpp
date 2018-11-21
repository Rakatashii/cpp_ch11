#include <iostream>
#include <vector>
#include "util.hpp"
#include <chrono>

using namespace std;

int min_position(vector<int>&a , int from, int to);
void selection_sort(vector<int>& a);
void print_time_elapsed(vector<int>& a, string a_name, int name_width = 5, int duration_width = 5);

int main(int argc, const char * argv[]) {
    UTIL::rand_seed();
    vector<vector<int> > vector_holder;
    vector<int> v20(20);
    for (int i = 0; i < v20.size(); i++) v20[i] = UTIL::rand_int(1, 100);
    vector_holder.push_back(v20);
    vector<int> v100(100);
    for (int i = 0; i < v100.size(); i++) v100[i] = UTIL::rand_int(1, 100);
    vector_holder.push_back(v100);
    vector<int> v500(500);
    for (int i = 0; i < v500.size(); i++) v500[i] = UTIL::rand_int(1, 100);
    vector_holder.push_back(v500);
    vector<int> v1000(1000);
    for (int i = 0; i < v1000.size(); i++) v1000[i] = UTIL::rand_int(1, 100);
    vector_holder.push_back(v1000);
    vector<int> v5000(5000);
    for (int i = 0; i < v5000.size(); i++) v5000[i] = UTIL::rand_int(1, 100);
    vector_holder.push_back(v5000);
    vector<int> v10000(10000);
    for (int i = 0; i < v10000.size(); i++) v10000[i] = UTIL::rand_int(1, 100);
    vector_holder.push_back(v10000);
    vector<int> v50000(50000);
    for (int i = 0; i < v50000.size(); i++) v50000[i] = UTIL::rand_int(1, 100);
    vector_holder.push_back(v50000);
    vector<int> v100000(100000);
    for (int i = 0; i < v100000.size(); i++) v100000[i] = UTIL::rand_int(1, 100);
    vector_holder.push_back(v100000);
    
    vector<string> vect_names = {"v20", "v100", "v500", "v1000", "v5000", "v10000", "v50000", "100000"};
    
    const int duration_width = 5;
    const int name_width = 7;
    
    for (int i = 0; i < vector_holder.size(); i++){
        print_time_elapsed(vector_holder[i], vect_names[i], name_width, duration_width);
    }
    
    cout << "\n";
    return 0;
}

void print_time_elapsed(vector<int>& a, string a_name, int name_width, int duration_width){
    chrono::high_resolution_clock::time_point t0 = chrono::high_resolution_clock::now();
    selection_sort(a);
    chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
    auto ms_dur = chrono::duration_cast<chrono::milliseconds>( t1-t0 ).count();
    auto s_dur = chrono::duration_cast<chrono::seconds>( t1-t0 ).count();
    printf("vector %*s took %*lld milliseconds to complete.\n", name_width, a_name.c_str(), duration_width, ms_dur);
    printf("%*lld seconds\n", 13+name_width+duration_width, s_dur);
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

