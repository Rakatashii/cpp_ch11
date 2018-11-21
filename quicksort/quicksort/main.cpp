#include <iostream>
#include <vector>
#include "util.hpp"

using namespace std;

static int call = 0; // This tracks num of recursive calls.
int width; // The number of digits in the size of the vector. Helps with formatting printf
void quicksort(vector<int>& v, int from, int to);
int partition(vector<int>& v, int from, int to);

int main(int argc, const char * argv[]) {
    int sz = 100;
    vector<int> v(sz);
    
    if (sz > 1000) width = 4;
    else if (sz > 100) width = 3;
    else if (sz > 10) width = 2;
    
    UTIL::rand_seed();
    for (int i = 0; i < sz; i++){
        v[i] = UTIL::rand_int(1, 100);
    }
    UTIL::print_vector(v, "(before quicksort) v");
    cout << endl;
    quicksort(v, 0, sz-1);
    cout << endl;
    UTIL::print_vector(v, "(after quicksort)  v");
    cout << endl;
    printf("num of recursive quicksort calls = %i\n\n", call);
    return 0;
}

//static int n = 0;
void quicksort(vector<int>& v, int from, int to){
    if (from >= to) return;
    int p = partition(v, from, to);
    printf("call %*i: pivot[%*i] = %i\n", width, ++call, width, p, v[p]);
    quicksort(v, from, p);
    quicksort(v, p + 1, to);
}

int partition(vector<int>& v, int from, int to){
    int i = from-1;
    int j = to+1;
    int pivot = v[from];
    while (i < j){
        i++; while (v[i] < pivot) i++;
        j--; while (v[j] > pivot) j--;
        if (i < j) UTIL::swap(v[i], v[j]);
    }
    return j;
}




