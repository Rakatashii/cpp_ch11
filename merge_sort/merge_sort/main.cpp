#include <iostream>
#include <vector>
#include "util.hpp"

using namespace std;

void merge_sort(vector<int>& a, int from, int to);
void merge(vector<int>& a, int from, int mid, int to);

int main(int argc, const char * argv[]) {
    UTIL::rand_seed();
    vector<int> v(20);
    for (int i = 0; i < v.size(); i++){
        v[i] = UTIL::rand_int(1, 100);
    }
    UTIL::print_vector(v, "(before merge_sort) v");
    merge_sort(v, 0, v.size()-1);
    cout << "\n";
    UTIL::print_vector(v, "(after merge_sort)  v");
    cout << "\n";
    return 0;
}

void merge_sort(vector<int>& a, int from, int to){
    if (from == to) return; // base case - going to keep making smaller subvecters until they are finally sorted
    // and then, through recursion, they return to the original merge_sort call and the sorted halves are merged.
    int mid = (from + to)/2;
    merge_sort(a, from, mid);
    merge_sort(a, mid+1, to);
    merge(a, from, mid, to);
}
void merge(vector<int>& a, int from, int mid, int to){
    int n = to-from+1; // This is the size of the range to be merged
    // i.e., vect size = 100 == (last index) 99 - (first index) 0 + 1
    vector<int> b(n); // Merge both halves into a temporary vector b
    
    int i1 = from; // next element to consider in first half
    int i2 = mid+1; // next element to consider in second half
    int j = 0; // Next open position in b
    
    // So long as neither i1 nor i2 are past their ends, move the smaller element into b
    while (i1 <= mid && i2 <= to){
        if (a[i1] < a[i2]){
            b[j] = a[i1];
            i1++;
        } else { // a[i1] > a[i2]
            b[j] = a[i2];
            i2++;
        }
        j++;
    }
    
    /* Note, after the above loop is ran, either the first half or the second half will
     have elements that have not been stored in b. It is possible that both halves will
     have had all of their elements stored. But if not, only one of the two following loops
     will be executed to take care of the remaining elements that have not yet been stored.
     */
    
    // Copy any remaining entries from the first half
    while (i1 <= mid){
        b[j] = a[i1];
        i1++;
        j++;
    }
    // Copy any remaining entries from the second half
    while (i2 <= to){
        b[j] = a[i2];
        i2++;
        j++;
    }
    
    // Copy elements into a back from temp vector b
    for (j = 0; j < n; j++){
        a[from + j] = b[j];
    }
}





