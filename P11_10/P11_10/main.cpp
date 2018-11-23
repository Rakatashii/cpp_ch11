/*
 Exercise P11.10.
 Write a program that sorts a vector of Employee objects by increasing salary and prints the results. Use the sort function from the C++ library.
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include "employee.hpp"

using namespace std;

bool compare_salary(const Employee& a, const Employee &b) {
    return a.get_salary() < b.get_salary();
}

int main(int argc, const char * argv[]) {
    vector<Employee> v;
    string name, salary_str;
    long double salary;
    
    string file = "/Users/christianmeyer/cpp/ch11/P11_10/names.txt";
    fstream fs(file.c_str());
    while (v.size() < 100){
        getline(fs, name, '|');
        getline(fs, salary_str, '\n');
        salary = stold(salary_str);
        v.push_back(Employee(name, salary));
    }
    fs.close();
    
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++){
        cout << "v[" << i << "]: " << "NAME: " << v[i].get_name() << " | SALARY: $" << v[i].get_salary() << endl;
    }
    
    
    return 0;
}
