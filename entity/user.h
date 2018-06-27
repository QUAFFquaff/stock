#ifndef USER_H
#define USER_H


#include <string>

#include <controller/util.h>
using namespace std;

class User
{
public:
    User();
    ~User();
    void setId(int id);
    void getId();
    void setName(string name);
    void getName();
    void setAuthority(string authority);
    void getAuthority();
private:
    int id;
    string usename;
    string password;
    string authority;
    Util *util;
};

#endif // USER_H
