#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>
using namespace std;

// This is the main parent class for all users in the system.
// Doctor, Patient, and Admin will share these common details.
class User {
protected:
    int id;
    string name;
    string phone;
    string email;

public:
    User();
    User(int id, string name, string phone, string email);

    // Destructor is virtual because this class will be inherited.
    virtual ~User();

    int getId() const;
    string getName() const;
    string getPhone() const;
    string getEmail() const;

    void setName(string newName);
    void setPhone(string newPhone);
    void setEmail(string newEmail);

    // These functions must be written differently in each child class.
    virtual void displayInfo() const = 0;
    virtual string getRole() const = 0;
};

#endif