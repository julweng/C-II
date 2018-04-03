//
// Julia Tzu-Ya Weng, U07487022
// julweng@gmail.com
// C/C++ Programming II : Dynamic Memory and File I/O Concepts
// Section: 121616
// Instructor: Raymond Mitchell
// Apr 10, 2017
// C2A1E8_Employee.h
// Mac OS X
// Xcode Version 8.3
//
// description:
// This file contains the definition of the Employee class and the Employee::Get
// function. The Employee class includes private data members and public member
// functions. Employee::Get is a function that takes a pointer to double type
// parameter that points to where the value of Employee class member salary is
// stored, and returns a type double that is the value of salary.
//

#ifndef C2A1E8_EMPLOYEE_H
#define C2A1E8_EMPLOYEE_H

class Employee
{
private:
    char *name;
    int age;
    float raise;
    double salary;
public:
    void Set(const char *setName);                   //prototype for Set to set name
    
    void Set(int setAge = 25)                        //set age
    {age = setAge;}
    
    void Set(const float &setRaise)                  //set raise
    {raise = setRaise;}
    
    void Set(const double *setSalary)                //set salary
    {salary = *setSalary;}
    
    char *Get(char **getName)                        //get name
    {
        *getName = &(*name);
        return *getName;
    }
    
    int Get(int &getAge) const                        //get age
    {
        getAge = age;
        return getAge;
    }
    
    float &Get(float &getRaise) const                 //get raise
    {
        getRaise = raise;
        return getRaise;
    }
    
    double Get(double *getSalary) const;              //prototype for Get to get salary
};

inline double Employee::Get(double *getSalary) const  //get salary
{
    *getSalary = salary;
    return *getSalary;
}

#endif
