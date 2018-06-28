#ifndef PROVIDERUTIL_H
#define PROVIDERUTIL_H

#include <entity/provider.h>
#include <entity/purchase.h>
#include "util.h"
#include <vector>



class ProviderUtil : public Util
{
public:
    ProviderUtil();
    ~ProviderUtil();
    void addItem();
    Purchase searchItem();
    bool changeItem();
    bool recallItem();
    bool deleteItem();
    vector<Provider> *getProvider();
private:
    vector<Provider> *v;
};

#endif // PROVIDERUTIL_H
