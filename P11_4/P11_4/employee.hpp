/*
 Exercise P8.3.
 Derive a class Manager from Employee. Add a data field, named department, of type string. Supply a function print that prints the manager’s name, department, and salary. Derive a class Executive from Manager. Supply a function print that prints the string Executive, followed by the information stored in the Manager base object.
 */

#ifndef employee_hpp
#define employee_hpp

#include <stdio.h>
#include <string>

/**
 A basic employee class that is used in many examples
 in the book "Computing Concepts with C++ Essentials"
 */
class Employee{
public:
    /**
     Constructs an employee with empty name and no salary.
     */
    Employee();
    /**
     Constructs an employee with a given name and salary.
     @param employee_name the employee name
     @param initial_salary the initial salary
     */
    Employee(std::string employee_name, double initial_salary);
    Employee(const Employee &e); // Copy Constructor

    bool operator<(const Employee &e);
    bool operator>(const Employee &e);
    bool operator<=(const Employee &e);
    bool operator>=(const Employee &e);
    /**
     Sets the salary of this employee.
     @param new_salary the new salary value
     */
    void set_salary(double new_salary);
    void set_name(std::string new_name);
    /**
     Gets the salary of this employee.
     @return the current salary
     */
    double get_salary() const;
    /**
     Gets the name of this employee.
     @return the employee name
     */
    std::string get_name() const;
private:
    std::string name;
    double salary;
};

#endif /* employee_hpp */
