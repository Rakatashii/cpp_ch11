/*
 Exercise P11.2. Modify the selection sort algorithm to sort a vector of employees by
 salary.
*/

#include <iostream>
#include <vector>
#include "util.hpp"
#include "employee.hpp"
#include <fstream>

using namespace std;

int min_position(vector<Employee> &a, int from, int to);
void selection_sort(vector<Employee> &a);

int main(int argc, const char * argv[]) {
    UTIL::rand_seed();
    
    int sz = 20;
    vector<Employee> v(sz);
    
    const string names_file = "/Users/christianmeyer/cpp/ch11/P11_2/names.txt";
    fstream fs(names_file.c_str());
    
    string name;
    for (int i = 0; i < v.size(); i++){
        if (getline(fs, name)){
            double salary = UTIL::rand_double(1.0, 500000.0);
            v[i] = Employee(name, salary);
        }
        else break;
    }
    fs.close();
    
    UTIL::print_employees(v, "(before selection_sort) v");
    cout << "\n";
    selection_sort(v);
    UTIL::print_employees(v, "(after selection_sort)  v");
    cout << "\n";
    return 0;
}

int min_position(vector<Employee> &a, int from, int to){
    int min_pos = from;
    for (int i = from + 1; i <= to; i++)
        if (a[i] < a[min_pos]){
            min_pos = i;
        }
    return min_pos;
};
void selection_sort(vector<Employee> &a){
    int next; // This is the next position to be set to the minimum.
    for (next = 0; next < a.size() - 1; next++){
        int min_pos = min_position(a, next, a.size()-1);
        if (min_pos != next)
            UTIL::swap_employees(a[min_pos], a[next]);
    }
}

