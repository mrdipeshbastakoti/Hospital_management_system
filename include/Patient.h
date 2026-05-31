#ifndef PATIENT_H
#define PATIENT_H

#include "User.h"
#include <string>
using namespace std;

// Patient is a child class of User.
// It stores patient health details needed for appointments.
class Patient : public User {
private:
    int age;
    string diseaseType;
    string medicalHistory;

public:
    Patient();
    Patient(int id, string name, string phone, string email,
            int age, string diseaseType, string medicalHistory);

    int getAge() const;
    string getDiseaseType() const;
    string getMedicalHistory() const;

    void setAge(int newAge);
    void setDiseaseType(string newDiseaseType);
    void setMedicalHistory(string newMedicalHistory);

    void displayInfo() const override;
    string getRole() const override;
};

#endif
