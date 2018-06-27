#include "purchase.h"

Purchase::Purchase()
{

}

Purchase::~Purchase()
{

}

int Purchase::getId() const {
    return id;
}

void Purchase::setId(int id) {
    Purchase::id = id;
}

int Purchase::getProductId() const {
    return productId;
}

void Purchase::setProductId(int productId) {
    Purchase::productId = productId;
}

double Purchase::getUnitPrice() const {
    return unitPrice;
}

void Purchase::setUnitPrice(double unitPrice) {
    Purchase::unitPrice = unitPrice;
}

double Purchase::getTotalPrice() const {
    return totalPrice;
}

void Purchase::setTotalPrice(double totalPrice) {
    Purchase::totalPrice = totalPrice;
}

double Purchase::getAmount() const {
    return amount;
}

void Purchase::setAmount(double amount) {
    Purchase::amount = amount;
}

int Purchase::getIdentify() const {
    return identify;
}

void Purchase::setIdentify(int identify) {
    Purchase::identify = identify;
}

int Purchase::getAdminId() const {
    return adminId;
}

void Purchase::setAdminId(int adminId) {
    Purchase::adminId = adminId;
}

bool Purchase::isFinished() const {
    return finished;
}

void Purchase::setFinished(bool finished) {
    Purchase::finished = finished;
}
