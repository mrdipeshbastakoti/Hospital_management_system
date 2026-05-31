#include "../include/Appointment.h"

// Default appointment details.
Appointment::Appointment()
    : appointmentId(0),
      doctorId(0),
      patientId(0),
      date(""),
      time(""),
      status("Scheduled"),
      reason("") {
}

// This constructor is used when we create a full appointment record.
Appointment::Appointment(int appointmentId, int doctorId, int patientId,
                         string date, string time, string status, string reason)
    : appointmentId(appointmentId),
      doctorId(doctorId),
      patientId(patientId),
      date(date),
      time(time),
      status(status),
      reason(reason) {
}

int Appointment::getAppointmentId() const {
    return appointmentId;
}

int Appointment::getDoctorId() const {
    return doctorId;
}

int Appointment::getPatientId() const {
    return patientId;
}

string Appointment::getDate() const {
    return date;
}

string Appointment::getTime() const {
    return time;
}

string Appointment::getStatus() const {
    return status;
}

string Appointment::getReason() const {
    return reason;
}

// Instead of deleting the appointment, we mark it as cancelled.
void Appointment::cancelAppointment() {
    status = "Cancelled";
}

// Shows appointment details on the console.
void Appointment::displayAppointment() const {
    cout << "Appointment ID: " << appointmentId << endl;
    cout << "Doctor ID: " << doctorId << endl;
    cout << "Patient ID: " << patientId << endl;
    cout << "Date: " << date << endl;
    cout << "Time: " << time << endl;
    cout << "Status: " << status << endl;
    cout << "Reason: " << reason << endl;
}
