#ifndef UTIL_H
#define UTIL_H

#include <entity/purchase.h>



class Util
{
public:
    Util();

    ~Util();
    virtual void addItem()=0;
    virtual Purchase searchItem()=0;
    virtual bool changeItem()=0;
    virtual bool recallItem()=0;
    virtual bool deleteItem()=0;
    void test();
};

#endif // UTIL_H
