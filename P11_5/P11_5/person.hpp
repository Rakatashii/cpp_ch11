#ifndef person_hpp
#define person_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>

class Person{
public:
    Person();
    Person(std::string n, std::string t);
    Person(const Person& p);
    void make_numeric_telephone();
    
    bool operator<(const Person& p);
    bool operator>(const Person& p);
    bool operator<=(const Person& p);
    bool operator>=(const Person& p);
    friend std::ostream& operator<<(std::ostream& out, const Person& p);
    
    void set_name(std::string& n);
    void set_telephone(std::string& t);
    
    std::string get_name() const;
    std::string get_telephone() const;
    long int get_numeric_telephone() const;
    
private:
    std::string name, telephone, first_name;
    long int numeric_telephone;
};


#endif /* person_hpp */
