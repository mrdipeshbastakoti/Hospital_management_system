#include "../include/Doctor.h"

// Empty values are used when no doctor details are given.
Doctor::Doctor()
    : User(), specialization(""), availableDay(""), availableTime("") {
}

// This constructor is used when we create a doctor with full details.
Doctor::Doctor(int id, string name, string phone, string email, string password,
               string specialization, string availableDay, string availableTime)
    : User(id, name, phone, email, password),
      specialization(specialization),
      availableDay(availableDay),
      availableTime(availableTime) {
}

string Doctor::getSpecialization() const {
    return specialization;
}

string Doctor::getAvailableDay() const {
    return availableDay;
}

string Doctor::getAvailableTime() const {
    return availableTime;
}

void Doctor::setSpecialization(string newSpecialization) {
    specialization = newSpecialization;
}

void Doctor::setAvailableDay(string newAvailableDay) {
    availableDay = newAvailableDay;
}

void Doctor::setAvailableTime(string newAvailableTime) {
    availableTime = newAvailableTime;
}

// Shows doctor details.
// Password is not displayed for security.
void Doctor::displayInfo() const {
    cout << "Doctor ID: " << id << endl;
    cout << "Name: " << name << endl;
    cout << "Phone: " << phone << endl;
    cout << "Email: " << email << endl;
    cout << "Specialization: " << specialization << endl;
    cout << "Available Day: " << availableDay << endl;
    cout << "Available Time: " << availableTime << endl;
}

string Doctor::getRole() const {
    return "Doctor";
}