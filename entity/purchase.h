#ifndef PURCHASE_H
#define PURCHASE_H


#include <string>
using namespace std;
class Purchase
{
public:
    Purchase();
    ~Purchase();

private:
    int id;
public:
    int getId() const;

    void setId(int id);

    int getProductId() const;

    void setProductId(int productId);

    double getUnitPrice() const;

    void setUnitPrice(double unitPrice);

    double getTotalPrice() const;

    void setTotalPrice(double totalPrice);

    double getAmount() const;

    void setAmount(double amount);

    int getIdentify() const;

    void setIdentify(int identify);

    int getAdminId() const;

    void setAdminId(int adminId);

    bool isFinished() const;

    void setFinished(bool finished);

private:
    int productId;
    double unitPrice;
    double totalPrice;
    double amount;
    int identify;
    int adminId;
    bool finished;
};

#endif // PURCHASE_H
