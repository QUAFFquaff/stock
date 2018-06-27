#include "sale.h"

Sale::Sale()
{

}

Sale::~Sale()
{

}

int Sale::getId() const {
    return id;
}

void Sale::setId(int id) {
    Sale::id = id;
}

int Sale::getProductId() const {
    return productId;
}

void Sale::setProductId(int productId) {
    Sale::productId = productId;
}

int Sale::getAdminId() const {
    return adminId;
}

void Sale::setAdminId(int adminId) {
    Sale::adminId = adminId;
}

double Sale::getUnitPrice() const {
    return unitPrice;
}

void Sale::setUnitPrice(double unitPrice) {
    Sale::unitPrice = unitPrice;
}

double Sale::getTotalPrice() const {
    return totalPrice;
}

void Sale::setTotalPrice(double totalPrice) {
    Sale::totalPrice = totalPrice;
}

double Sale::getAmount() const {
    return amount;
}

void Sale::setAmount(double amount) {
    Sale::amount = amount;
}

int Sale::getIdentify() const {
    return identify;
}

void Sale::setIdentify(int identify) {
    Sale::identify = identify;
}

const string &Sale::getDate() const {
    return date;
}

void Sale::setDate(const string &date) {
    Sale::date = date;
}

