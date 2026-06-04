#include "../include/HospitalSystem.h"
#include <limits>
#include <cctype>

// Removes spaces from the beginning and end of text.
string trimText(string text) {
    while (!text.empty() && text[0] == ' ') {
        text.erase(0, 1);
    }

    while (!text.empty() && text[text.length() - 1] == ' ') {
        text.erase(text.length() - 1, 1);
    }

    return text;
}

// Converts text to lowercase.
// Example: Monday, monday, MONDAY all become monday.
string toLowerText(string text) {
    for (char& ch : text) {
        ch = tolower(ch);
    }

    return text;
}

// Converts a valid day into clean format.
string formatDay(string day) {
    day = trimText(day);
    day = toLowerText(day);

    if (day == "monday") return "Monday";
    if (day == "tuesday") return "Tuesday";
    if (day == "wednesday") return "Wednesday";
    if (day == "thursday") return "Thursday";
    if (day == "friday") return "Friday";
    if (day == "saturday") return "Saturday";
    if (day == "sunday") return "Sunday";

    return "";
}

HospitalSystem::HospitalSystem()
    : admin(1, "System Admin", "010-0000-0000", "admin@hospital.com", "admin123", 1),
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

// Checks one day only.
// The real multiple-day input is handled in getValidDay().
bool HospitalSystem::isValidDay(string day) const {
    return formatDay(day) != "";
}

// Age should be realistic.
bool HospitalSystem::isValidAge(int age) const {
    return age > 0 && age <= 120;
}

// Password should not be too short.
bool HospitalSystem::isValidPassword(string password) const {
    return password.length() >= 4;
}

// This is used for text fields that cannot be empty.
string HospitalSystem::getRequiredText(string message) {
    string value;

    do {
        cout << message;
        getline(cin, value);

        value = trimText(value);

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

        email = trimText(email);

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

        phone = trimText(phone);

        if (!isValidPhone(phone)) {
            cout << "Invalid phone. Use only numbers and hyphen, like 010-1234-5678." << endl;
        }

    } while (!isValidPhone(phone));

    return phone;
}

// This asks how many days the doctor is available.
// Then it asks each day one by one and saves them neatly.
string HospitalSystem::getValidDay() {
    int numberOfDays;
    vector<string> availableDays;

    while (true) {
        numberOfDays = getValidNumber("How many available days? ");

        if (numberOfDays >= 1 && numberOfDays <= 7) {
            break;
        }

        cout << "Invalid number. Please enter between 1 and 7." << endl;
    }

    for (int i = 1; i <= numberOfDays; i++) {
        string day;
        string fixedDay;
        bool duplicate;

        do {
            cout << "Enter available day " << i << ": ";
            getline(cin, day);

            fixedDay = formatDay(day);
            duplicate = false;

            if (fixedDay == "") {
                cout << "Invalid day. Please enter Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, or Sunday." << endl;
                continue;
            }

            for (const string& existingDay : availableDays) {
                if (existingDay == fixedDay) {
                    duplicate = true;
                    break;
                }
            }

            if (duplicate) {
                cout << "This day is already added. Please enter another day." << endl;
            }

        } while (fixedDay == "" || duplicate);

        availableDays.push_back(fixedDay);
    }

    string result = "";

    for (int i = 0; i < availableDays.size(); i++) {
        result += availableDays[i];

        if (i != availableDays.size() - 1) {
            result += ", ";
        }
    }

    return result;
}

// This keeps asking until the password is acceptable.
string HospitalSystem::getValidPassword() {
    string password;

    do {
        cout << "Enter password: ";
        getline(cin, password);

        password = trimText(password);

        if (!isValidPassword(password)) {
            cout << "Invalid password. Password must be at least 4 characters." << endl;
        }

    } while (!isValidPassword(password));

    return password;
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

// Checks admin email and password.
bool HospitalSystem::checkAdminLogin() {
    string email, password;

    cout << "\n===== Admin Login =====" << endl;
    email = getRequiredText("Enter admin email: ");
    password = getRequiredText("Enter admin password: ");

    if (email == admin.getEmail() && password == admin.getPassword()) {
        cout << "Admin login successful." << endl;
        return true;
    }

    cout << "Invalid admin email or password." << endl;
    return false;
}

// Returns doctor index if login is correct. Otherwise returns -1.
int HospitalSystem::findDoctorByLogin(string email, string password) const {
    for (int i = 0; i < doctors.size(); i++) {
        if (doctors[i].getEmail() == email && doctors[i].getPassword() == password) {
            return i;
        }
    }

    return -1;
}

// Returns patient index if login is correct. Otherwise returns -1.
int HospitalSystem::findPatientByLogin(string email, string password) const {
    for (int i = 0; i < patients.size(); i++) {
        if (patients[i].getEmail() == email && patients[i].getPassword() == password) {
            return i;
        }
    }

    return -1;
}

void HospitalSystem::showMainMenu() {
    int choice;

    do {
        cout << "\n===== Hospital Scheduling System =====" << endl;
        cout << "1. Admin Login" << endl;
        cout << "2. Doctor Login" << endl;
        cout << "3. Patient Login" << endl;
        cout << "4. Exit" << endl;

        choice = getValidNumber("Enter your choice: ");

        switch (choice) {
            case 1:
                if (checkAdminLogin()) {
                    showAdminMenu();
                }
                break;

            case 2: {
                string email, password;

                cout << "\n===== Doctor Login =====" << endl;
                email = getRequiredText("Enter doctor email: ");
                password = getRequiredText("Enter doctor password: ");

                int doctorIndex = findDoctorByLogin(email, password);

                if (doctorIndex != -1) {
                    cout << "Doctor login successful." << endl;
                    showDoctorMenu(doctorIndex);
                } else {
                    cout << "Invalid doctor email or password." << endl;
                }

                break;
            }

            case 3: {
                string email, password;

                cout << "\n===== Patient Login =====" << endl;
                email = getRequiredText("Enter patient email: ");
                password = getRequiredText("Enter patient password: ");

                int patientIndex = findPatientByLogin(email, password);

                if (patientIndex != -1) {
                    cout << "Patient login successful." << endl;
                    showPatientMenu(patientIndex);
                } else {
                    cout << "Invalid patient email or password." << endl;
                }

                break;
            }

            case 4:
                cout << "Exiting system..." << endl;
                break;

            default:
                cout << "Invalid choice. Try again." << endl;
        }

    } while (choice != 4);
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
        cout << "6. View Appointments" << endl;
        cout << "7. Back to Main Menu" << endl;

        choice = getValidNumber("Enter your choice: ");

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
                viewAppointments();
                break;

            case 7:
                cout << "Returning to main menu..." << endl;
                break;

            default:
                cout << "Invalid choice. Try again." << endl;
        }

    } while (choice != 7);
}

void HospitalSystem::showDoctorMenu(int doctorIndex) {
    int choice;
    int doctorId = doctors[doctorIndex].getId();

    do {
        cout << "\n===== Doctor Menu =====" << endl;
        cout << "Logged in as: " << doctors[doctorIndex].getName() << endl;
        cout << "1. View My Appointments" << endl;
        cout << "2. Back to Main Menu" << endl;

        choice = getValidNumber("Enter your choice: ");

        switch (choice) {
            case 1:
                viewDoctorAppointments(doctorId);
                break;

            case 2:
                cout << "Returning to main menu..." << endl;
                break;

            default:
                cout << "Invalid choice. Try again." << endl;
        }

    } while (choice != 2);
}

void HospitalSystem::showPatientMenu(int patientIndex) {
    int choice;
    int patientId = patients[patientIndex].getId();

    do {
        cout << "\n===== Patient Menu =====" << endl;
        cout << "Logged in as: " << patients[patientIndex].getName() << endl;
        cout << "1. Create Appointment" << endl;
        cout << "2. View My Appointments" << endl;
        cout << "3. Cancel My Appointment" << endl;
        cout << "4. Back to Main Menu" << endl;

        choice = getValidNumber("Enter your choice: ");

        try {
            switch (choice) {
                case 1:
                    createPatientAppointment(patientId);
                    break;

                case 2:
                    viewPatientAppointments(patientId);
                    break;

                case 3:
                    cancelPatientAppointment(patientId);
                    break;

                case 4:
                    cout << "Returning to main menu..." << endl;
                    break;

                default:
                    cout << "Invalid choice. Try again." << endl;
            }
        } catch (const AppointmentException& error) {
            cout << "Error: " << error.what() << endl;
        }

    } while (choice != 4);
}

void HospitalSystem::addDoctor() {
    string name, phone, email, password, specialization, availableDay, availableTime;

    name = getRequiredText("Enter doctor name: ");
    phone = getValidPhone();
    email = getValidEmail();
    password = getValidPassword();
    specialization = getRequiredText("Enter specialization: ");
    availableDay = getValidDay();
    availableTime = getRequiredText("Enter available time: ");

    Doctor doctor(nextDoctorId, name, phone, email, password, specialization, availableDay, availableTime);
    doctors.push_back(doctor);

    cout << "Doctor added successfully. Doctor ID is " << nextDoctorId << endl;
    nextDoctorId++;
}

void HospitalSystem::addPatient() {
    string name, phone, email, password, diseaseType, medicalHistory;
    int age;

    name = getRequiredText("Enter patient name: ");
    phone = getValidPhone();
    email = getValidEmail();
    password = getValidPassword();
    age = getValidAge();
    diseaseType = getRequiredText("Enter disease type: ");
    medicalHistory = getRequiredText("Enter medical history: ");

    Patient patient(nextPatientId, name, phone, email, password, age, diseaseType, medicalHistory);
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

void HospitalSystem::createPatientAppointment(int patientId) {
    int doctorId;
    string date, time, reason;

    if (doctors.empty()) {
        throw AppointmentException("No doctors available. Please contact admin first.");
    }

    viewDoctors();
    doctorId = getValidNumber("Enter doctor ID: ");

    if (!doctorExists(doctorId)) {
        throw AppointmentException("Doctor ID not found.");
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

void HospitalSystem::viewDoctorAppointments(int doctorId) const {
    bool found = false;

    cout << "\n===== My Appointments =====" << endl;

    for (const Appointment& appointment : appointments) {
        if (appointment.getDoctorId() == doctorId) {
            appointment.displayAppointment();
            cout << "------------------------" << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "No appointments found for this doctor." << endl;
    }
}

void HospitalSystem::viewPatientAppointments(int patientId) const {
    bool found = false;

    cout << "\n===== My Appointments =====" << endl;

    for (const Appointment& appointment : appointments) {
        if (appointment.getPatientId() == patientId) {
            appointment.displayAppointment();
            cout << "------------------------" << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "No appointments found for this patient." << endl;
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

void HospitalSystem::cancelPatientAppointment(int patientId) {
    int appointmentId;

    if (appointments.empty()) {
        throw AppointmentException("No appointments available to cancel.");
    }

    viewPatientAppointments(patientId);

    appointmentId = getValidNumber("Enter appointment ID to cancel: ");

    for (Appointment& appointment : appointments) {
        if (appointment.getAppointmentId() == appointmentId &&
            appointment.getPatientId() == patientId) {
            appointment.cancelAppointment();
            cout << "Appointment cancelled successfully." << endl;
            return;
        }
    }

    throw AppointmentException("Appointment ID not found for this patient.");
}