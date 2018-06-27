#ifndef PURCHASEUTIL_H
#define PURCHASEUTIL_H

#include <entity/purchase.h>



class PurchaseUtil
{
public:
    PurchaseUtil();
    ~PurchaseUtil();
    void addItem();
    Purchase searchItem();
    bool changeItem();
    bool recallItem();
    bool deleteItem();
};

#endif // PURCHASEUTIL_H
