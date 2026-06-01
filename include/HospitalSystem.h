#ifndef HOSPITAL_SYSTEM_H
#define HOSPITAL_SYSTEM_H

#include "Admin.h"
#include "Doctor.h"
#include "Patient.h"
#include "Appointment.h"
#include "AppointmentException.h"

#include <iostream>
#include <vector>
using namespace std;

// This class controls the whole hospital system.
// It connects admin, doctors, patients, and appointments together.
class HospitalSystem {
private:
    Admin admin;

    vector<Doctor> doctors;
    vector<Patient> patients;
    vector<Appointment> appointments;

    int nextDoctorId;
    int nextPatientId;
    int nextAppointmentId;

    bool doctorExists(int doctorId) const;
    bool patientExists(int patientId) const;

public:
    HospitalSystem();

    void showMainMenu();
    void showAdminMenu();

    void addDoctor();
    void addPatient();

    void viewDoctors() const;
    void viewPatients() const;

    void createAppointment();
    void viewAppointments() const;
    void cancelAppointment();
};

#endif