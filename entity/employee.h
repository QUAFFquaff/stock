#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include "user.h"

#include <string>
using namespace std;
class Employee : public User
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
