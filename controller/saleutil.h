#ifndef SALEUTIL_H
#define SALEUTIL_H

#include <entity/purchase.h>
#include "util.h"


class SaleUtil : public Util
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
