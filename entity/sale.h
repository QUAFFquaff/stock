#ifndef SALE_H
#define SALE_H

#include <string>
using namespace std;

class Sale
{
public:
    Sale();
    ~Sale();
    void setId(int id);
    void getId();
    void setProductId(int productId);
    void getProductId();
    void setAdminId(int adminId);
    void getAdminId();
    void setUnitPrice(double unitPrice);
    void getUnitPrice();
    void setTotalPrice(double totalPrice);
    void getTotalPrice();
    void setAmount(double amount);
    void getAmount();
    void setIdentify(int identify);
    void getIdentify();
    void setDate(string date);
    void getDate();
private:
    int id;
    int productId;
    int adminId;
    double unitPrice;
    double totalPrice;
    double amount;
    int identify;
    string date;
};

#endif // SALE_H
