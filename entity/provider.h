#ifndef PROVIDER_H
#define PROVIDER_H
#include <string>
using namespace std;
class Provider
{
public:
    Provider();
    ~Provider();
    void setId(int id);
    void getId();
    void setName(string name);
    void getName();
    void setPrincipal(string principal);
    void getPrincipal();
    void setTel(long tel);
    void getTel();
private:
    int id;
    string name;
    string principal;
    long tel;
};

#endif // PROVIDER_H
