#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>
using namespace std;
class Employee
{
public:
    Employee();
    ~Employee();
private:
    string name;
    string employmentDate;
    bool gender;
    string bornDate;
    double salary;
    int idCard;
    string position;
};

#endif // EMPLOYEE_H
