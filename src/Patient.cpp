#include "../include/Patient.h"

// Empty values are used when no patient details are given.
Patient::Patient()
    : User(), age(0), diseaseType(""), medicalHistory("") {
}

// This constructor is used when we create a patient with full details.
Patient::Patient(int id, string name, string phone, string email,
                 int age, string diseaseType, string medicalHistory)
    : User(id, name, phone, email),
      age(age),
      diseaseType(diseaseType),
      medicalHistory(medicalHistory) {
}

int Patient::getAge() const {
    return age;
}

string Patient::getDiseaseType() const {
    return diseaseType;
}

string Patient::getMedicalHistory() const {
    return medicalHistory;
}

void Patient::setAge(int newAge) {
    age = newAge;
}

void Patient::setDiseaseType(string newDiseaseType) {
    diseaseType = newDiseaseType;
}

void Patient::setMedicalHistory(string newMedicalHistory) {
    medicalHistory = newMedicalHistory;
}

void Patient::displayInfo() const {
    cout << "Patient ID: " << id << endl;
    cout << "Name: " << name << endl;
    cout << "Phone: " << phone << endl;
    cout << "Email: " << email << endl;
    cout << "Age: " << age << endl;
    cout << "Disease Type: " << diseaseType << endl;
    cout << "Medical History: " << medicalHistory << endl;
}

string Patient::getRole() const {
    return "Patient";
}
