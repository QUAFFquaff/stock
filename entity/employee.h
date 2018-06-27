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
public:
    const string &getName() const;

    void setName(const string &name);

    const string &getEmploymentDate() const;

    void setEmploymentDate(const string &employmentDate);

    bool isGender() const;

    void setGender(bool gender);

    const string &getBornDate() const;

    void setBornDate(const string &bornDate);

    double getSalary() const;

    void setSalary(double salary);

    int getIdCard() const;

    void setIdCard(int idCard);

    const string &getPosition() const;

    void setPosition(const string &position);

private:
    string employmentDate;
    bool gender;
    string bornDate;
    double salary;
    int idCard;
    string position;
};

#endif // EMPLOYEE_H
