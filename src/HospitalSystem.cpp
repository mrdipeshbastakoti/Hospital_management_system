#include "../include/HospitalSystem.h"
#include <limits>

HospitalSystem::HospitalSystem()
    : admin(1, "System Admin", "010-0000-0000", "admin@hospital.com", 1),
      nextDoctorId(1),
      nextPatientId(101),
      nextAppointmentId(1001) {
}

// Checks if a doctor ID exists in the doctor list.
bool HospitalSystem::doctorExists(int doctorId) const {
    for (const Doctor& doctor : doctors) {
        if (doctor.getId() == doctorId) {
            return true;
        }
    }
    return false;
}

// Checks if a patient ID exists in the patient list.
bool HospitalSystem::patientExists(int patientId) const {
    for (const Patient& patient : patients) {
        if (patient.getId() == patientId) {
            return true;
        }
    }
    return false;
}

void HospitalSystem::showMainMenu() {
    int choice;

    do {
        cout << "\n===== Hospital Scheduling System =====" << endl;
        cout << "1. Admin Menu" << endl;
        cout << "2. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                showAdminMenu();
                break;

            case 2:
                cout << "Exiting system..." << endl;
                break;

            default:
                cout << "Invalid choice. Try again." << endl;
        }

    } while (choice != 2);
}

void HospitalSystem::showAdminMenu() {
    int choice;

    do {
        cout << "\n===== Admin Menu =====" << endl;
        cout << "1. View Admin Info" << endl;
        cout << "2. Add Doctor" << endl;
        cout << "3. Add Patient" << endl;
        cout << "4. View Doctors" << endl;
        cout << "5. View Patients" << endl;
        cout << "6. Create Appointment" << endl;
        cout << "7. View Appointments" << endl;
        cout << "8. Cancel Appointment" << endl;
        cout << "9. Back to Main Menu" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        try {
            switch (choice) {
                case 1:
                    admin.displayInfo();
                    break;

                case 2:
                    addDoctor();
                    break;

                case 3:
                    addPatient();
                    break;

                case 4:
                    viewDoctors();
                    break;

                case 5:
                    viewPatients();
                    break;

                case 6:
                    createAppointment();
                    break;

                case 7:
                    viewAppointments();
                    break;

                case 8:
                    cancelAppointment();
                    break;

                case 9:
                    cout << "Returning to main menu..." << endl;
                    break;

                default:
                    cout << "Invalid choice. Try again." << endl;
            }
        } catch (const AppointmentException& error) {
            cout << "Error: " << error.what() << endl;
        }

    } while (choice != 9);
}

void HospitalSystem::addDoctor() {
    string name, phone, email, specialization, availableDay, availableTime;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter doctor name: ";
    getline(cin, name);

    cout << "Enter phone: ";
    getline(cin, phone);

    cout << "Enter email: ";
    getline(cin, email);

    cout << "Enter specialization: ";
    getline(cin, specialization);

    cout << "Enter available day: ";
    getline(cin, availableDay);

    cout << "Enter available time: ";
    getline(cin, availableTime);

    Doctor doctor(nextDoctorId, name, phone, email, specialization, availableDay, availableTime);
    doctors.push_back(doctor);

    cout << "Doctor added successfully. Doctor ID is " << nextDoctorId << endl;
    nextDoctorId++;
}

void HospitalSystem::addPatient() {
    string name, phone, email, diseaseType, medicalHistory;
    int age;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter patient name: ";
    getline(cin, name);

    cout << "Enter phone: ";
    getline(cin, phone);

    cout << "Enter email: ";
    getline(cin, email);

    cout << "Enter age: ";
    cin >> age;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter disease type: ";
    getline(cin, diseaseType);

    cout << "Enter medical history: ";
    getline(cin, medicalHistory);

    Patient patient(nextPatientId, name, phone, email, age, diseaseType, medicalHistory);
    patients.push_back(patient);

    cout << "Patient added successfully. Patient ID is " << nextPatientId << endl;
    nextPatientId++;
}

void HospitalSystem::viewDoctors() const {
    if (doctors.empty()) {
        cout << "No doctors found." << endl;
        return;
    }

    cout << "\n===== Doctor List =====" << endl;

    for (const Doctor& doctor : doctors) {
        doctor.displayInfo();
        cout << "------------------------" << endl;
    }
}

void HospitalSystem::viewPatients() const {
    if (patients.empty()) {
        cout << "No patients found." << endl;
        return;
    }

    cout << "\n===== Patient List =====" << endl;

    for (const Patient& patient : patients) {
        patient.displayInfo();
        cout << "------------------------" << endl;
    }
}

void HospitalSystem::createAppointment() {
    int doctorId, patientId;
    string date, time, reason;

    if (doctors.empty()) {
        throw AppointmentException("No doctors available. Please add a doctor first.");
    }

    if (patients.empty()) {
        throw AppointmentException("No patients available. Please add a patient first.");
    }

    viewDoctors();
    cout << "Enter doctor ID: ";
    cin >> doctorId;

    if (!doctorExists(doctorId)) {
        throw AppointmentException("Doctor ID not found.");
    }

    viewPatients();
    cout << "Enter patient ID: ";
    cin >> patientId;

    if (!patientExists(patientId)) {
        throw AppointmentException("Patient ID not found.");
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter appointment date: ";
    getline(cin, date);

    cout << "Enter appointment time: ";
    getline(cin, time);

    cout << "Enter reason for appointment: ";
    getline(cin, reason);

    Appointment appointment(nextAppointmentId, doctorId, patientId, date, time, "Scheduled", reason);
    appointments.push_back(appointment);

    cout << "Appointment created successfully. Appointment ID is " << nextAppointmentId << endl;
    nextAppointmentId++;
}

void HospitalSystem::viewAppointments() const {
    if (appointments.empty()) {
        cout << "No appointments found." << endl;
        return;
    }

    cout << "\n===== Appointment List =====" << endl;

    for (const Appointment& appointment : appointments) {
        appointment.displayAppointment();
        cout << "------------------------" << endl;
    }
}

void HospitalSystem::cancelAppointment() {
    int appointmentId;

    if (appointments.empty()) {
        throw AppointmentException("No appointments available to cancel.");
    }

    viewAppointments();

    cout << "Enter appointment ID to cancel: ";
    cin >> appointmentId;

    for (Appointment& appointment : appointments) {
        if (appointment.getAppointmentId() == appointmentId) {
            appointment.cancelAppointment();
            cout << "Appointment cancelled successfully." << endl;
            return;
        }
    }

    throw AppointmentException("Appointment ID not found.");
}