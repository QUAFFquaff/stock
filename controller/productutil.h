#ifndef PRODUCTUTIL_H
#define PRODUCTUTIL_H

#include <entity/purchase.h>
#include "util.h"



class ProductUtil : public Util
{
public:
    ProductUtil();
    ~ProductUtil();
    void addItem();
    Purchase searchItem();
    bool changeItem();
    bool recallItem();
    bool deleteItem();
};

#endif // PRODUCTUTIL_H
