#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include <iostream>
#include <string>
using namespace std;

// This class stores one appointment record.
// It connects one doctor with one patient using their IDs.
class Appointment {
private:
    int appointmentId;
    int doctorId;
    int patientId;
    string date;
    string time;
    string status;
    string reason;

public:
    Appointment();
    Appointment(int appointmentId, int doctorId, int patientId,
                string date, string time, string status, string reason);

    int getAppointmentId() const;
    int getDoctorId() const;
    int getPatientId() const;
    string getDate() const;
    string getTime() const;
    string getStatus() const;
    string getReason() const;

    void cancelAppointment();
    void displayAppointment() const;
};

#endif
