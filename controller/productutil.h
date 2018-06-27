#ifndef PRODUCTUTIL_H
#define PRODUCTUTIL_H

#include <entity/purchase.h>



class ProductUtil
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
