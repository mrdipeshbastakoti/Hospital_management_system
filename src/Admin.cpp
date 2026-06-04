#include "../include/Admin.h"

// Default admin details.
Admin::Admin()
    : User(), adminLevel(1) {
}

// This constructor creates an admin with full information.
Admin::Admin(int id, string name, string phone, string email, string password, int adminLevel)
    : User(id, name, phone, email, password), adminLevel(adminLevel) {
}

int Admin::getAdminLevel() const {
    return adminLevel;
}

void Admin::setAdminLevel(int newAdminLevel) {
    adminLevel = newAdminLevel;
}

// Shows admin details.
// Password is not displayed for security.
void Admin::displayInfo() const {
    cout << "Admin ID: " << id << endl;
    cout << "Name: " << name << endl;
    cout << "Phone: " << phone << endl;
    cout << "Email: " << email << endl;
    cout << "Admin Level: " << adminLevel << endl;
}

string Admin::getRole() const {
    return "Admin";
}