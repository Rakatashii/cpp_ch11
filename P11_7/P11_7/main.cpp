/*
 Exercise P11.7.
 Use the modification of the binary search function from Exercise P11.6 to sort a vector.
 
 Make a second vector of the same size as the vector to be sorted.
 For each element in the first vector, call binary search on the second vector to find out where the new element should be inserted.
 Then move all elements above the insertion point up by one slot and insert the new element.
 Thus, the second vector is always kept sorted.
 Implement this algorithm and measure its performance.
*/

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include "util.hpp"

using namespace std;

static int max_value;

int partition(vector<int> &v, int from, int to);
void quicksort(vector<int> &v, int from, int to);
bool binary_search(vector<int> &v, int from, int to, int target, int &m);
void insert(vector<int> &v, int new_val, int pos, bool resize = false);

int main(int argc, const char * argv[]) {
    UTIL::rand_seed();
    int vsz = 50;
    vector<int> v(vsz);
    max_value = 100;
    for (int i = 0; i < vsz; i++){
        int x = UTIL::rand_int(1, max_value);
        //if (x == 0) cout << "WARNING x in v = 0";
        v[i] = x;
    }
    int usz = vsz/2;
    vector<int> u(usz);
    for (int i = 0; i < usz; i++){
        int x = UTIL::rand_int(1, max_value);
        //if (x == 0) cout << "WARNING x in u = 0";
        u[i] = x;
    }
    
    UTIL::print_two_vectors(v, u, "(before binary searches) v", "u");
    cout << "\n";
    
    quicksort(v, 0, vsz-1);
    
    vector<int> positions;
    int m;
    for (int i = 0; i < usz-1; i++){
        m = -1;
        binary_search(v, 0, v.size()-1, u[i], m);
        if (m < v.size()) insert(v, u[i], m, true);
        else cout << "(m > v.size())" << endl;
    }
    cout << "\n";
    UTIL::print_two_vectors(v, u, "(after binary searches)  v", "u");
    
    cout << "\n";
    return 0;
}

int partition(vector<int> &v, int from, int to){
    int p = v[from];
    int i = from-1;
    int j = to+1;
    while(i<j){
        i++; while (v[i] < p) i++;
        j--; while (v[j] > p) j--;
        if (i < j) UTIL::swap(v[i], v[j]);
    }
    return j;
}
void quicksort(vector<int> &v, int from, int to){
    if (from >= to) return;
    int p = partition(v, from, to);
    quicksort(v, from, p);
    quicksort(v, p+1, to);
}
bool binary_search(vector<int> &v, int from, int to, int target, int &m){
    if (from >= to) {
        /*
        if (abs(v[from] - target) <= abs(v[to] - target)) m = from;
        else */ m = to;
        return false;
    }
    if (m == -1 && target > max_value){ // m is initialized at -1 so that the first BS call can be recognized. At this point, since the vector is sorted, if the highest value in the vector is already greater that the target value, BS returns the size of the vector. Strangely, v[v.size()] is returning 0. Don't think I should take purposefully though.
        cout << "TARGET " << target << " is less than v[to]: v[" << to << "] = " << v[to] << endl;
        m = v.size();
        cout << "m = " << m << endl;
        return false;
    }
    int mid = (from + to) / 2;
    if (v[mid] == target) {
        m = mid;
        return true;
    }
    else if (v[mid] > target) return binary_search(v, from, mid, target, m);
    else return binary_search(v, mid+1, to, target, m);
}
void insert(vector<int> &v, int new_val, int pos, bool resize){
    if (v[v.size()-1] <= 0 || v[v.size()-1] > max_value || resize){
        cout << "v.size() increased from " << v.size();
        v.push_back(new_val);
        cout << " to " << v.size() << endl;
        cout << "inserting " << new_val << " at index " << pos << endl;
    }
    for (int i = v.size()-1; i > pos; i--){
        v[i] = v[i-1];
    }
    v[pos] = new_val;
}


























