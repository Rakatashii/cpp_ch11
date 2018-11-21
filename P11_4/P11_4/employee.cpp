#include "employee.hpp"

Employee::Employee(){
    salary = 0;
}

Employee::Employee(std::string employee_name, double initial_salary){
    name = employee_name;
    salary = initial_salary;
}
Employee::Employee(const Employee &e) {
    name = e.name;
    salary = e.salary;
}
bool Employee::operator<(const Employee &e) {
    bool b = (salary < e.get_salary()) ? true : false;
    return b;
}
bool Employee::operator>(const Employee &e) {
    bool b = (salary > e.get_salary()) ? true : false;
    return b;
}
bool Employee::operator<=(const Employee &e) {
    bool b = (salary <= e.get_salary()) ? true : false;
    return b;
}
bool Employee::operator>=(const Employee &e) {
    bool b = (salary >= e.get_salary()) ? true : false;
    return b;
}

void Employee::set_name(std::string new_name){
    name = new_name;
}
void Employee::set_salary(double new_salary)
{
    salary = new_salary;
}

double Employee::get_salary() const
{
    return salary;
}

std::string Employee::get_name() const
{
    return name;
}



