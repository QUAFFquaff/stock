#ifndef PROVIDERUTIL_H
#define PROVIDERUTIL_H

#include <entity/purchase.h>



class ProviderUtil
{
public:
    ProviderUtil();
    ~ProviderUtil();
    void addItem();
    Purchase searchItem();
    bool changeItem();
    bool recallItem();
    bool deleteItem();
};

#endif // PROVIDERUTIL_H
