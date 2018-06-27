#ifndef SALEUTIL_H
#define SALEUTIL_H

#include <entity/purchase.h>



class SaleUtil
{
public:
    SaleUtil();
    ~SaleUtil();
    void addItem();
    Purchase searchItem();
    bool changeItem();
    bool recallItem();
    bool deleteItem();
};

#endif // SALEUTIL_H
