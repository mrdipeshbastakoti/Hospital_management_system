#ifndef HOSPITAL_SYSTEM_H
#define HOSPITAL_SYSTEM_H

#include "Admin.h"
#include <iostream>
using namespace std;

// This class controls the main flow of the hospital system.
class HospitalSystem {
private:
    Admin admin;

public:
    HospitalSystem();

    void showMainMenu();
    void showAdminMenu();
};

#endif