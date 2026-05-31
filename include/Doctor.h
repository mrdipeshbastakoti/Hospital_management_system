#ifndef DOCTOR_H
#define DOCTOR_H

#include "User.h"
#include <string>
using namespace std;

// Doctor is a child class of User.
// It stores the doctor's specialization and available schedule.
class Doctor : public User {
private:
    string specialization;
    string availableDay;
    string availableTime;

public:
    Doctor();
    Doctor(int id, string name, string phone, string email,
           string specialization, string availableDay, string availableTime);

    string getSpecialization() const;
    string getAvailableDay() const;
    string getAvailableTime() const;

    void setSpecialization(string newSpecialization);
    void setAvailableDay(string newAvailableDay);
    void setAvailableTime(string newAvailableTime);

    void displayInfo() const override;
    string getRole() const override;
};

#endif
