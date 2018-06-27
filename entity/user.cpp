#include "user.h"

User::User()
{

}

User::~User()
{

}

int User::getId() const {
    return id;
}

void User::setId(int id) {
    User::id = id;
}

const string &User::getUsename() const {
    return usename;
}

void User::setUsename(const string &usename) {
    User::usename = usename;
}

const string &User::getPassword() const {
    return password;
}

void User::setPassword(const string &password) {
    User::password = password;
}

const string &User::getAuthority() const {
    return authority;
}

void User::setAuthority(const string &authority) {
    User::authority = authority;
}

Util *User::getUtil() const {
    return util;
}

void User::setUtil(Util *util) {
    User::util = util;
}

