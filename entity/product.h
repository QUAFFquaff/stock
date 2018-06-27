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
        void getId();
        void setType(string type);
        void getType();
        void setPrice(double price);
        void getPrice();
        void setAmount(double amount);
        void getAmount();
private:
    int id;
    string name;
    string type;
    double price;
    double amount;
};

#endif // PRODUCT_H
