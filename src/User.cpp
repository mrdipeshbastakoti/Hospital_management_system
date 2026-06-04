#include "../include/User.h"

// Default values are used when no user information is given.
User::User()
    : id(0), name(""), phone(""), email(""), password("") {
}

// This constructor is used when we already have user details.
User::User(int id, string name, string phone, string email, string password)
    : id(id), name(name), phone(phone), email(email), password(password) {
}

// Nothing special is needed here, but we keep it for safe inheritance.
User::~User() {
}

int User::getId() const {
    return id;
}

string User::getName() const {
    return name;
}

string User::getPhone() const {
    return phone;
}

string User::getEmail() const {
    return email;
}

string User::getPassword() const {
    return password;
}

void User::setName(string newName) {
    name = newName;
}

void User::setPhone(string newPhone) {
    phone = newPhone;
}

void User::setEmail(string newEmail) {
    email = newEmail;
}

void User::setPassword(string newPassword) {
    password = newPassword;
}