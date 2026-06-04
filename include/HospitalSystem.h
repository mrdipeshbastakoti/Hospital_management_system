#ifndef HOSPITAL_SYSTEM_H
#define HOSPITAL_SYSTEM_H

#include "Admin.h"
#include "Doctor.h"
#include "Patient.h"
#include "Appointment.h"
#include "AppointmentException.h"

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// This class controls the whole hospital system.
// It connects admin, doctors, patients, appointments, login, validation, and files.
class HospitalSystem {
private:
    Admin admin;

    vector<Doctor> doctors;
    vector<Patient> patients;
    vector<Appointment> appointments;

    int nextDoctorId;
    int nextPatientId;
    int nextAppointmentId;

    // These functions check if the entered ID really exists.
    bool doctorExists(int doctorId) const;
    bool patientExists(int patientId) const;

    // These functions check whether the user input is acceptable.
    bool isEmpty(string value) const;
    bool isValidEmail(string email) const;
    bool isValidPhone(string phone) const;
    bool isValidDay(string day) const;
    bool isValidAge(int age) const;
    bool isValidPassword(string password) const;

    // These functions keep asking until the user enters correct data.
    string getRequiredText(string message);
    string getValidEmail();
    string getValidPhone();
    string getValidDay();
    string getValidPassword();
    int getValidAge();
    int getValidNumber(string message);

    // Login helper functions.
    bool checkAdminLogin();
    int findDoctorByLogin(string email, string password) const;
    int findPatientByLogin(string email, string password) const;

    // File handling functions.
    void loadData();
    void saveData() const;

    void loadDoctors();
    void loadPatients();
    void loadAppointments();

    void saveDoctors() const;
    void savePatients() const;
    void saveAppointments() const;

public:
    HospitalSystem();

    void showMainMenu();

    void showAdminMenu();
    void showDoctorMenu(int doctorIndex);
    void showPatientMenu(int patientIndex);

    void addDoctor();
    void addPatient();

    void viewDoctors() const;
    void viewPatients() const;

    void createAppointment();
    void viewAppointments() const;
    void cancelAppointment();

    void viewDoctorAppointments(int doctorId) const;
    void viewPatientAppointments(int patientId) const;
    void createPatientAppointment(int patientId);
    void cancelPatientAppointment(int patientId);
};

#endif
