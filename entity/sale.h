#ifndef SALE_H
#define SALE_H

#include <string>
using namespace std;

class Sale
{
public:
    Sale();
    ~Sale();
    int getId() const;

    void setId(int id);

    int getProductId() const;

    void setProductId(int productId);

    int getAdminId() const;

    void setAdminId(int adminId);

    double getUnitPrice() const;

    void setUnitPrice(double unitPrice);

    double getTotalPrice() const;

    void setTotalPrice(double totalPrice);

    double getAmount() const;

    void setAmount(double amount);

    int getIdentify() const;

    void setIdentify(int identify);

    const string &getDate() const;

    void setDate(const string &date);

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
