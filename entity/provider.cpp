#include "provider.h"

Provider::Provider()
{

}

Provider::~Provider()
{

}

void Provider::setId(int id)
{
    this->id = id;
}

int Provider::getId()
{
    return this->id;
}

void Provider::setName(string name)
{
    this->name = name;
}

string Provider::getName()
{
    return this->name;
}

void Provider::setPrincipal(string principal)
{
    this->principal = principal;
}

string Provider::getPrincipal()
{
    return this->principal;
}

void Provider::setTel(long tel)
{
    this->tel =tel;
}

long Provider::getTel()
{
    return this->tel;
}

