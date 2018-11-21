#include "person.hpp"

Person::Person(){
}
Person::Person(std::string n, std::string t){
    name = n;
    telephone = t;
    if (telephone.length() > 0) make_numeric_telephone();
}
Person::Person(const Person& p){
    this->name = p.get_name();
    this->telephone = p.get_telephone();
    if (telephone.length() > 0) make_numeric_telephone();
}
void Person::make_numeric_telephone(){
    numeric_telephone = 0; // in case telephone string was set more than once
    std::string temp;
    for (int i = 0; i < telephone.length(); i++){
        if ((int)telephone[i] >= 48 && (int)telephone[i] <= 57) temp.push_back(telephone[i]);
    }
    char* dash;
    numeric_telephone = strtol(temp.c_str(), &dash, 10);
}

bool Person::operator<(const Person& p){
    std::string pname = p.get_name();
    std::locale loc;
    for (int i = 0; i < name.size() && i < pname.size(); i++){
        if ((int)tolower(name[i], loc) < (int)tolower(pname[i], loc)) return true;
        else if ((int)tolower(name[i], loc) > (int)tolower(pname[i], loc)) return false;
    }
    return false;
}
bool Person::operator>(const Person& p){
    std::string pname = p.get_name();
    std::locale loc;
    for (int i = 0; i < name.size() && i < pname.size(); i++){
        if ((int)tolower(name[i], loc) > (int)tolower(pname[i], loc)) return true;
        else if ((int)tolower(name[i], loc) < (int)tolower(pname[i], loc)) return false;
        
    }
    return false;
}
bool Person::operator<=(const Person& p){
    std::string pname = p.get_name();
    std::locale loc;
    for (int i = 0; i < name.size() && i < pname.size(); i++){
        if ((int)tolower(name[i], loc) < (int)tolower(pname[i], loc)) return true;
        else if ((int)tolower(name[i], loc) > (int)tolower(pname[i], loc)) return false;
    }
    return true;
    
}
bool Person::operator>=(const Person& p){
    std::string pname = p.get_name();
    std::locale loc;
    for (int i = 0; i < name.size() && i < pname.size(); i++){
        if ((int)tolower(name[i], loc) > (int)tolower(pname[i], loc)) return true;
        else if ((int)tolower(name[i], loc) < (int)tolower(pname[i], loc)) return false;
    }
    return true;
}

void Person::set_name(std::string& n){
    name = n;
}
void Person::set_telephone(std::string& t){
    telephone = t;
    if (telephone.length() > 0) make_numeric_telephone();
}
std::string Person::get_name() const{
    return name;
}
std::string Person::get_telephone() const{
    return telephone;
}
long int Person::get_numeric_telephone() const{
    if (numeric_telephone > 0) return numeric_telephone;
    else return -1;
}
std::ostream& operator<<(std::ostream& out, const Person& p){
    out << "name: " << p.get_name() << " | telephone: " << p.get_telephone() << std::endl;
    return out;
}

