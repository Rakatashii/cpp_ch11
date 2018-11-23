/*
 Exercise P11.8.
 Implement the merge_sort procedure without recursion, where the size of the vector is a power of 2.
 First merge adjacent regions of size 1, then adjacent regions of size 2, then adjacent regions of size 4, and so on.
 
 Exercise P11.9.
 Implement the merge_sort procedure without recursion, where the size of the vector is an arbitrary number. Hint: Keep merging adjacent areas whose size is a power of 2, and pay special attention to the last area in the sequence.
*/

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include "util.hpp"

using namespace std;

void merge(vector<int> &v, int from, int mid, int to);
void merge_sort(vector<int> &v, int from, int to);

int main(int argc, const char * argv[]) {
    UTIL::seed_rand();
    int sz = 69; // Not the merge_sort function will not only sort up to a power of 2. If sz == 68, it would only sort v[0]..v[63]
    // v[64]..v[67] would appear as a sorted subvector within v, but both v[64] and v[67] could be less than or greater than v[64]
    vector<int> v(sz);
    for (int i = 0; i < sz; i++) v[i] = UTIL::rand_int(1, 100);
    UTIL::print_vector(v, "(before merge_sort) v");
    cout << endl;
    merge_sort(v, 0, sz-1);
    UTIL::print_vector(v, "(after merge_sort)  v");
    cout << endl;
    
    vector<int> a(100, 5);
    UTIL::print_vector(a, "a");
    cout << endl;
    a.insert(a.begin(), 10);
    a.insert(a.begin()+1, 20);
    UTIL::print_vector(a, "a");
    
    
    
    return 0;
}

void merge_sort(vector<int> &v, int from, int to){
    int super = 0; // this is the superscript (2^superscript_value), begins at 0 since 2^0 == 1
    // The function works when super == 1, since sorting a single value does nothing aside from serve to indicate any issues with the merge function.
    int coef = 0; // This tracks the merge intervals, so can do (0, 2), (0 + coef, 2 + coef) == (2, 4), ...
    int power = pow(2, super);
    while (power <= v.size()){ // size must be a power of 2, the last merge could be when power == 2^6 == 64 == v.size()
        int inner_from = coef; // always 0 before entering inner while loop
        int inner_to = power+coef-1;
        while (inner_to < v.size()){
            int mid = (inner_from + inner_to) / 2;
            merge(v, inner_from, mid, inner_to);
            coef += power;
            inner_from = coef;
            inner_to = coef+power-1;
        }
        if (inner_to > v.size()-1 && inner_from < to){
            cout << "super: " << super << " | power: " << power << endl;
            cout << "inner_to: " << inner_to << "| inner from: " << inner_from << endl;
            for (int i = v.size()-1; i > inner_from; i--){
                v.insert(v.begin(), v[i]);
                v.pop_back();
            }
            merge_sort(v, 0, inner_from);
        } // Got really close here. Not seeing another way to solve aside from putting the merge in the for loop itself, or else calling merge or merge_sort A LOT of times and being very inefficient.
        power = pow(2, ++super);
        coef = 0;
    }
}
void merge(vector<int> &v, int from, int mid, int to){
    int n = to-from+1;
    vector<int> b(n);
    
    int i1 = from; // Next element from first half
    int i2 = mid+1; // Next element from second half
    int j = 0; // Next open position in b
    
    while (i1 <= mid && i2 <= to){
        if (v[i1] < v[i2]){
            b[j] = v[i1];
            i1++;
        } else { // when a[i1] > a[i2]
            b[j] = v[i2];
            i2++;
        }
        j++;
    }
    while (i1 <= mid){ // Handles the rest of the first half values if they were not put into b in the previous loop
        b[j] = v[i1];
        j++;
        i1++;
    }
    while (i2 <= to){ // Handles the rest of the second half values if they were not put into b in the previous loop
        b[j] = v[i2];
        j++;
        i2++;
    }
    for (j = 0; j < n; j++){ // Copies the newly sorted values in b (derived from v) into the previously unsorted v
        v[from+j] = b[j];
    }
}

















