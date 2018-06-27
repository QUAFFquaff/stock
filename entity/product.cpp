#include "product.h"

Product::Product()
{

}

Product::~Product()
{

}

void Product::setId(int id)
{
    this->id = id;
}

int Product::getId()
{
    return id;
}

void Product::setType(string type)
{
    this->type = type;
}

string Product::getType()
{
    return this->type;
}

void Product::setPrice(double price)
{
    this->price = price;
}

double Product::getPrice()
{
    return price;
}

void Product::setAmount(double amount)
{
    this->amount = amount;
}

double Product::getAmount()
{
    return this->amount;
}

