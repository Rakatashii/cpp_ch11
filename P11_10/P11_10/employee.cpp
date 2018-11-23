#include "employee.hpp"

Employee::Employee(){
    salary = 0;
}

Employee::Employee(std::string employee_name, long double initial_salary){
    name = employee_name;
    salary = initial_salary;
}

bool Employee::operator<(const Employee& e) const {
    return (this->salary < e.salary);
}

void Employee::set_salary(long double new_salary){
    salary = new_salary;
}

long double Employee::get_salary() const{
    return salary;
}

std::string Employee::get_name() const{
    return name;
}



