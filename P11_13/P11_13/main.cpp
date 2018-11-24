/*
Exercise P11.13.
 Modify the binary search algorithm so that you can search the records stored in a database file without actually reading them into a vector. Use the employee database of Section 9.6, sort it by name, and make lookups for employees.
 
 This program is sorting names mostly correct, but still with some error and unreliability. Probably need to re-attempt this problem in a different project since #sort/#partition are becoming hard to keep track of.
 - Problem in #partition? 'if (i == j) goto bottom' Why is it that i == j is occurring so often that the program cannot run without these lines? And why is this not an issue in the vector version of the function?
*/

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

bool binary_search(fstream& fs, string word, int& char_pos);
void sort(fstream& fs, string file, int from, int to);
int partition(fstream& fs, string file, int from, int to);
bool less_than(const string& a, const string& b);
bool greater_than(const string& a, const string& b);

int main(int argc, const char * argv[]) {
    string data = "/Users/christianmeyer/cpp/ch11/P11_13/data.txt";
    fstream fs(data.c_str(), ios::in | ios::out);
    
    fs.seekg(0, ios::beg);
    int from = fs.tellg();
    fs.seekg(0, ios::end);
    int to = fs.tellg();
    
    fs.close();
    
    sort(fs, data, from, to);
    
    if (fs.is_open()){
        cout << "fs was open...";
        fs.close();
    } else cout << "fs is closed!" << endl;
    
    return 0;
}

bool binary_search(fstream& fs, string word, int& char_pos);
void sort(fstream& fs, string file, int from, int to){
    cout << "ENTER SORT: from = " << from << " | to = " << to << endl << endl;
    if (from >= to) {
        if (fs.is_open()) fs.close();
        return;
    }
    int p = partition(fs, file, from, to);
    
    fs.open(file.c_str(), ios::in | ios::out);
    sort(fs, file, from, p);
    if (fs.is_open()) fs.close();
    
    fs.open(file.c_str(), ios::in | ios::out);
    sort(fs, file, p+32, to);
    if (fs.is_open()) fs.close();
}
int partition(fstream& fs, string file, int from, int to){
    string pivot, iline, jline;
    
    if (fs.is_open()) fs.close();
    fs.open(file.c_str(), ios::in | ios::out);
    
    fs.seekg(from, ios::beg);
    getline(fs, pivot);
    fs.seekg(from, ios::beg);
    
    int i = from-32;
    int j = to+32;
    
    fs.seekg(0, ios::end);
    const int eof = fs.tellg();
    fs.seekg(from, ios::beg);
    
    while (i < j) {
        if (fs.is_open()) fs.close();
        fs.open(file.c_str(), ios::in | ios::out);
        
        i+=32;
        fs.seekg(i, ios::beg);
        getline(fs, iline);
        
        while (less_than(iline, pivot) ) {
            i+=32;
            fs.seekg(i, ios::beg);
            getline(fs, iline);
        }
        
        j-=32;
        fs.seekg(j, ios::beg);
        getline(fs, jline);
        
        while (greater_than(jline, pivot) ) {
            if (i == j) goto bottom;
            
            j-=32;
            fs.seekg(j, ios::beg);
            getline(fs, jline);
            
            //if (i == j) goto bottom;
        }
        
        if (i < j) {
            fs.seekg(i, ios::beg);
            getline(fs, iline);
            iline += '\n';
            
            fs.seekg(j, ios::beg);
            getline(fs, jline);
            jline += '\n';
            
            // ONLY time using puts instead of gets
            fs.seekp(i, ios::beg);
            fs << jline;
            fs.seekp(j, ios::beg);
            fs << iline;
        }
    bottom:
        fs.close();
    }
    if (fs.is_open()) fs.close();
    return j;
}

// Both of these functions need refactoring. Consider functions to check which case or whether char is alphabetic at all.
bool less_than(const string& a, const string& b){
    if (a.size() == 0 || b.size() == 0) return false;
    
    string astr = a, bstr = b;
    int i = 0;
    for (i = 0; i < a.length()-1 && i < b.length()-1; i++){
        if ((int)astr[i] >= 97 && (int)astr[i] <= 122) astr[i] -= 32; // stick with one case only
        if ((int)bstr[i] >= 97 && (int)bstr[i] <= 122) bstr[i] -= 32;
        if ((int)astr[i] < 65 || (int)astr[i] > 90) // ensures all chars are letters so long as strings are being compared
            if (!((int)bstr[i] < 65 || (int)bstr[i] > 90)) return true;
        else if ((int)bstr[i] < 65 || (int)bstr[i] > 90) return false;
        
        // lesser than
        if ((int)astr[i] < (int)bstr[i]) return true;
        else if ((int)astr[i] > (int)bstr[i]) return false;
        
        if (i >= b.length()-1) return false;
    }
    // if b is longer than a at this point then a must be smaller
    if (i < b.length()) return true;
    else return false;
}
bool greater_than(const string& a, const string& b){
    if (a.size() == 0 || b.size() == 0) return false;

    string astr = a, bstr = b;
    int i = 0;
    for (i = 0; i < a.length()-1 && i < b.length()-1; i++){
        if ((int)astr[i] >= 97 && (int)astr[i] <= 122) astr[i] -= 32;
        if ((int)bstr[i] >= 97 && (int)bstr[i] <= 122) bstr[i] -= 32;
        if ((int)astr[i] < 65 || (int)astr[i] > 90)
            if (!((int)bstr[i] < 65 || (int)bstr[i] > 90)) return false;
        else if ((int)bstr[i] < 65 || (int)bstr[i] > 90) return true;
        
        if ((int)astr[i] > (int)bstr[i]) return true;
        else if ((int)astr[i] < (int)bstr[i]) return false;
        
        if (i >= b.length()-1) return true;
    }
    if (i < b.length()) return false;
    else return true;
}





               
