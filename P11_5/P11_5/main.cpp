/*
 Exercise P11.5.
 Write a telephone lookup program.
 Read a data set of 1,000 names and telephone numbers from a file that contains the numbers in random order.
 Handle lookups by name and also reverse lookups by phone number. Use a binary search for both lookups.
 
 Note: Not really sure what a reverse lookup is... best guess would be to switch from ascending order to descending order, or something along those lines. Phone numbers aren't sorted yet, so there has to be more to it than that. Since haven't learned templates yet, and Person operators have already been overloaded to deal with names, seems only way to continue would be to write new quicksort and binary search functions that would deal with phone numbers.
*/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "util.hpp"

using namespace std;
using namespace UTIL;

int partition_names(vector<Person> &v, int from, int to);
int partition_telephones(vector<Person> &v, int from, int to);
void quicksort(vector<Person> &v, int from, int to, bool phone = false);
int binary_search(vector<Person> v, int from, int to, string n, bool phone = false);

int main(int argc, const char * argv[]) {
    const string datafile = "/Users/christianmeyer/cpp/ch11/P11_5/data";
    
    int sz = 1000;
    vector<Person> v;
    
    fstream fs(datafile.c_str());
    string name, telephone;
    while(getline(fs, name, '|')){
        getline(fs, telephone);
        if (v.size() < sz) v.push_back(Person(name, telephone));
        else break;
    }
    fs.close();
    
    UTIL::print_people(v, "(before) v");
    cout << "\n";
    quicksort(v, 0, sz-1);
    UTIL::print_people(v, "(after)  v");
    cout << "\n";
    
    string searchname = "Zackary";
    cout << "Searching for \'" << searchname << "\'..." << endl;
    int idx = binary_search(v, 0, v.size()-1, searchname);
    if (idx != -1) cout << "v[" << idx << "]: " << v[idx] << endl;
    else cout << "No match found. \n" << endl;
    
    searchname = "Zackary Buckridge";
    cout << "Searching for \'" << searchname << "\'..." << endl;
    idx = binary_search(v, 0, v.size()-1, searchname);
    if (idx != -1) cout << "v[" << idx << "]: " << v[idx] << endl;
    else cout << "No match found. \n" << endl;
    
    vector<Person> z = v;
    quicksort(z, 0, z.size()-1, true);
    
    string searchnum = "590-836-8718";
    cout << "Searching for \'" << searchnum << "\'..." << endl;
    idx = binary_search(z, 0, z.size()-1, searchnum, true);
    if (idx != -1) cout << "z[" << idx << "]: " << z[idx] << endl;
    else cout << "No match found. \n" << endl;
    
    
    // TODO: reverse phone number lookup ???
    
    return 0;
}

int binary_search(vector<Person> v, int from, int to, string word, bool phone){
    if (from >= to) return -1;
    int mid = (from+to)/2;
    string match;
    if (phone){
        match = v[mid].get_telephone();
        if (word == match) return mid;
        else if (word < v[mid].get_telephone()) return binary_search(v, from, mid, word, phone);
        else return binary_search(v, mid+1, to, word, phone);
    }
    // Won't get to this point if phone is true and searching for phone nums instead of names
    match = v[mid].get_name();
    if (word == match) return mid;
    else if (word < v[mid].get_name()) return binary_search(v, from, mid, word, phone);
    else return binary_search(v, mid+1, to, word, phone);
}
int partition_names(vector<Person> &v, int from, int to){
    Person p = v[from];
    int i = from-1;
    int j = to+1;
    while (i < j){
        i++; while(v[i] < p) i++;
        j--; while(v[j] > p) j--;
        if (i < j) UTIL::swap_people(v[i], v[j]);
    }
    return j;
}
int partition_telephones(vector<Person> &v, int from, int to){
    Person p = v[from];
    int i = from-1;
    int j = to+1;
    while (i < j){
        i++; while(v[i].get_telephone() < p.get_telephone()) i++;
        j--; while(v[j].get_telephone() > p.get_telephone()) j--;
        if (i < j) UTIL::swap_people(v[i], v[j]);
    }
    return j;
}
void quicksort(vector<Person> &v, int from, int to, bool phone){
    if (from >= to) return;
    int p;
    if (!phone) p = partition_names(v, from, to);
    else p = partition_telephones(v, from, to);
    quicksort(v, from, p, phone);
    quicksort(v, p+1, to, phone);
}
