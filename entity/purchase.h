#ifndef PURCHASE_H
#define PURCHASE_H


#include <string>
using namespace std;
class Purchase
{
public:
    Purchase();
    ~Purchase();
    void setId(int id);
    void getId();
    void setProductId(int productId);
    void getProductId();
    void setUnitPrice(double unitPrice);
    void getUnitPrice();
    void setTotalPrice(double totalPrice);
    void getTotalPrice();
    void setAmount(double amount);
    void getAmount();
    void setIdentify(int identify);
    void getIdentify();
    void setAdminId(int adminId);
    void getAdminId();
    void setFinished(bool finished);
    void getFinished();
private:
    int id;
    int productId;
    double unitPrice;
    double totalPrice;
    double amount;
    int identify;
    int adminId;
    bool finished;
};

#endif // PURCHASE_H
