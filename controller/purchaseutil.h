#ifndef PURCHASEUTIL_H
#define PURCHASEUTIL_H

#include <entity/purchase.h>
#include "util.h"



class PurchaseUtil : public Util
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
