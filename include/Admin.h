#ifndef ADMIN_H
#define ADMIN_H

#include "User.h"
#include <string>
using namespace std;

// Admin is one type of user in the hospital system.
// Admin will manage doctors, patients, and appointments.
class Admin : public User {
private:
    int adminLevel;

public:
    Admin();
    Admin(int id, string name, string phone, string email, int adminLevel);

    int getAdminLevel() const;
    void setAdminLevel(int newAdminLevel);

    void displayInfo() const override;
    string getRole() const override;
};

#endif