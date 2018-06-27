#ifndef PRODUCT_H
#define PRODUCT_H
#include <string>
using namespace std;

class Product
{
public:
    Product();
    ~Product();
    void setId(int id);
    int getId();
    void setType(string type);
    string getType();
    void setPrice(double price);
    double getPrice();
    void setAmount(double amount);
    double getAmount();
private:
    int id;
    string name;
    string type;
    double price;
    double amount;
};

#endif // PRODUCT_H
