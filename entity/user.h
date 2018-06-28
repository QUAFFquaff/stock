#ifndef USER_H
#define USER_H


#include <string>

#include <controller/util.h>
#include "../controller/util.h"

using namespace std;

class User
{
public:
    User();
    ~User();

public:
    int getId() const;

    void setId(int id);

    const string &getUsename() const;

    void setUsename(const string &usename);

    const string &getPassword() const;

    void setPassword(const string &password);

    const string &getAuthority() const;

    void setAuthority(const string &authority);

    Util *getUtil() const;

    void setUtil(Util *util);

private:
    string usename;
    string password;
    string authority;
    Util *util;
    int id;
};

#endif // USER_H
