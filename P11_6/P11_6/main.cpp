/*
 Exercise P11.6.
 Consider the binary search function in Section 11.7. If no match is found, the function returns –1.
 Modify the function so that it returns a bool value indicating whether a match was found.
 Add a reference parameter m, which is set to the location of the match if the search was successful.
 If a was not found, set m to the index of the next larger value instead,
 or to a.size() if a is larger than all the elements of the vector. ???
    - What does it mean for a to be larger than all the elements of the vector? Isn't a the vector itself?
    - Thinking if the target value is higher than the max value in the vector, then return the size of the vector.
    Not sure how this becomes useful though.
*/

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include "util.hpp"

using namespace std;

int partition(vector<int> &v, int from, int to);
void quicksort(vector<int> &v, int from, int to);
bool binary_search(vector<int> &v, int from, int to, int target, int &m);

int main(int argc, const char * argv[]) {
    UTIL::rand_seed();
    int sz = 50;
    vector<int> v(sz);
    for (int i = 0; i < sz; i++) v[i] = UTIL::rand_int(1, 100);
    
    UTIL::print_vector(v, "(before sort) v");
    cout << "\n";
    quicksort(v, 0, sz-1);
    UTIL::print_vector(v, "(after sort)  v");
    cout << "\n";
    
    vector<int> targets = {4, 16, 32, 107, 41, 49, 55, 67, 215, 76, 83, 95, 99, 103};
    /* targets.push_back(50);
    targets.push_back(15);
    targets.push_back(85); */
    int m;
    for (int i = 0; i < targets.size(); i++){
        m = -1;
        cout << "Searching for target \'" << targets[i] << "\'..." << endl;
        if (binary_search(v, 0, sz-1, targets[i], m)){
            cout << "Match Found at Index " << m << " | v[m] = " << v[m] << endl;
        } else cout << "No match found. m = " << m << " | v[m] = " << v[m] << endl;
        cout << endl;
    }
    
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
        if (abs(v[from] - target) <= abs(v[to] - target)) m = from;
        else m = to;
        return false;
    }
    if (m == -1 && v[to] < target){ // m is initialized at -1 so that the first BS call can be recognized. At this point, since the vector is sorted, if the highest value in the vector is already greater that the target value, BS returns the size of the vector. Strangely, v[v.size()] is returning 0. Don't think I should take purposefully though.
        m = v.size();
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

























