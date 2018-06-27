#include "employee.h"

Employee::Employee()
{

}

Employee::~Employee()
{

}

const string &Employee::getName() const {
    return name;
}

void Employee::setName(const string &name) {
    Employee::name = name;
}

const string &Employee::getEmploymentDate() const {
    return employmentDate;
}

void Employee::setEmploymentDate(const string &employmentDate) {
    Employee::employmentDate = employmentDate;
}

bool Employee::isGender() const {
    return gender;
}

void Employee::setGender(bool gender) {
    Employee::gender = gender;
}

const string &Employee::getBornDate() const {
    return bornDate;
}

void Employee::setBornDate(const string &bornDate) {
    Employee::bornDate = bornDate;
}

double Employee::getSalary() const {
    return salary;
}

void Employee::setSalary(double salary) {
    Employee::salary = salary;
}

int Employee::getIdCard() const {
    return idCard;
}

void Employee::setIdCard(int idCard) {
    Employee::idCard = idCard;
}

const string &Employee::getPosition() const {
    return position;
}

void Employee::setPosition(const string &position) {
    Employee::position = position;
}

