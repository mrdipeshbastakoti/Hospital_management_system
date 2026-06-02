#include "../include/HospitalSystem.h"
#include <limits>
#include <cctype>

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

// Checks if the user entered nothing.
bool HospitalSystem::isEmpty(string value) const {
    return value.length() == 0;
}

// Simple email check.
// It rejects wrong values like 77 because email must contain @ and .
bool HospitalSystem::isValidEmail(string email) const {
    int atPosition = email.find('@');
    int dotPosition = email.find('.');

    if (email.length() < 5) {
        return false;
    }

    if (atPosition == string::npos || dotPosition == string::npos) {
        return false;
    }

    if (atPosition == 0 || atPosition == email.length() - 1) {
        return false;
    }

    if (dotPosition == 0 || dotPosition == email.length() - 1) {
        return false;
    }

    return true;
}

// Phone number should not accept random words.
// This allows only numbers and hyphen, like 010-1234-5678.
bool HospitalSystem::isValidPhone(string phone) const {
    if (phone.length() < 8 || phone.length() > 15) {
        return false;
    }

    for (char ch : phone) {
        if (!isdigit(ch) && ch != '-') {
            return false;
        }
    }

    return true;
}

// Only real week days are accepted.
bool HospitalSystem::isValidDay(string day) const {
    return day == "Monday" ||
           day == "Tuesday" ||
           day == "Wednesday" ||
           day == "Thursday" ||
           day == "Friday" ||
           day == "Saturday" ||
           day == "Sunday";
}

// Age should be realistic.
bool HospitalSystem::isValidAge(int age) const {
    return age > 0 && age <= 120;
}

// This is used for text fields that cannot be empty.
string HospitalSystem::getRequiredText(string message) {
    string value;

    do {
        cout << message;
        getline(cin, value);

        if (isEmpty(value)) {
            cout << "This field cannot be empty. Please try again." << endl;
        }

    } while (isEmpty(value));

    return value;
}

// This keeps asking until the email looks valid.
string HospitalSystem::getValidEmail() {
    string email;

    do {
        cout << "Enter email: ";
        getline(cin, email);

        if (!isValidEmail(email)) {
            cout << "Invalid email. Email must contain @ and ." << endl;
        }

    } while (!isValidEmail(email));

    return email;
}

// This keeps asking until the phone number is valid.
string HospitalSystem::getValidPhone() {
    string phone;

    do {
        cout << "Enter phone: ";
        getline(cin, phone);

        if (!isValidPhone(phone)) {
            cout << "Invalid phone. Use only numbers and hyphen, like 010-1234-5678." << endl;
        }

    } while (!isValidPhone(phone));

    return phone;
}

// This keeps asking until the user enters a real day name.
string HospitalSystem::getValidDay() {
    string day;

    do {
        cout << "Enter available day: ";
        getline(cin, day);

        if (!isValidDay(day)) {
            cout << "Invalid day. Please enter Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, or Sunday." << endl;
        }

    } while (!isValidDay(day));

    return day;
}

// This keeps asking until the user enters a valid age number.
int HospitalSystem::getValidAge() {
    int age;

    while (true) {
        cout << "Enter age: ";
        cin >> age;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid age. Please enter a number." << endl;
        } else if (!isValidAge(age)) {
            cout << "Invalid age. Age must be between 1 and 120." << endl;
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return age;
        }
    }
}

// This is used for menu choices and IDs.
// It prevents letters from breaking the program.
int HospitalSystem::getValidNumber(string message) {
    int number;

    while (true) {
        cout << message;
        cin >> number;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number." << endl;
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return number;
        }
    }
}

void HospitalSystem::showMainMenu() {
    int choice;

    do {
        cout << "\n===== Hospital Scheduling System =====" << endl;
        cout << "1. Admin Menu" << endl;
        cout << "2. Exit" << endl;

        choice = getValidNumber("Enter your choice: ");

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

        choice = getValidNumber("Enter your choice: ");

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

    name = getRequiredText("Enter doctor name: ");
    phone = getValidPhone();
    email = getValidEmail();
    specialization = getRequiredText("Enter specialization: ");
    availableDay = getValidDay();
    availableTime = getRequiredText("Enter available time: ");

    Doctor doctor(nextDoctorId, name, phone, email, specialization, availableDay, availableTime);
    doctors.push_back(doctor);

    cout << "Doctor added successfully. Doctor ID is " << nextDoctorId << endl;
    nextDoctorId++;
}

void HospitalSystem::addPatient() {
    string name, phone, email, diseaseType, medicalHistory;
    int age;

    name = getRequiredText("Enter patient name: ");
    phone = getValidPhone();
    email = getValidEmail();
    age = getValidAge();
    diseaseType = getRequiredText("Enter disease type: ");
    medicalHistory = getRequiredText("Enter medical history: ");

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
    doctorId = getValidNumber("Enter doctor ID: ");

    if (!doctorExists(doctorId)) {
        throw AppointmentException("Doctor ID not found.");
    }

    viewPatients();
    patientId = getValidNumber("Enter patient ID: ");

    if (!patientExists(patientId)) {
        throw AppointmentException("Patient ID not found.");
    }

    date = getRequiredText("Enter appointment date: ");
    time = getRequiredText("Enter appointment time: ");
    reason = getRequiredText("Enter reason for appointment: ");

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

    appointmentId = getValidNumber("Enter appointment ID to cancel: ");

    for (Appointment& appointment : appointments) {
        if (appointment.getAppointmentId() == appointmentId) {
            appointment.cancelAppointment();
            cout << "Appointment cancelled successfully." << endl;
            return;
        }
    }

    throw AppointmentException("Appointment ID not found.");
}
