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
    int getId();
    void setName(string name);
    string getName();
    void setPrincipal(string principal);
    string getPrincipal();
    void setTel(long tel);
    long getTel();
private:
    int id;
    string name;
    string principal;
    long tel;
};

#endif // PROVIDER_H
