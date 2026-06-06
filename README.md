Hospital Scheduling System

Project Description

Hospital Scheduling System is a CLI-based C++ project developed for our Object-Oriented Programming II final project.

The system manages hospital users and appointment records. It includes three main roles: Admin, Doctor, and Patient. Admin can add and view doctors and patients. Patients can create, view, and cancel appointments. Doctors can view appointments assigned to them.

This project focuses on Object-Oriented Programming concepts such as classes, objects, inheritance, encapsulation, abstraction, polymorphism, exception handling, and file handling.

--------------------------------------------------

Main Features

- Admin login
- Doctor login
- Patient login
- Add doctor records
- Add patient records
- View doctor records
- View patient records
- Create appointments
- View appointments
- Cancel appointments
- Input validation
- Custom exception handling
- File save and load system

--------------------------------------------------

Default Admin Login

Email: admin@hospital.com
Password: admin123

--------------------------------------------------

User Roles

Admin

Admin can:
- View admin information
- Add doctors
- Add patients
- View doctors
- View patients
- View all appointments

Doctor

Doctor can:
- Login using email and password
- View assigned appointments

Patient

Patient can:
- Login using email and password
- Create appointments
- View personal appointments
- Cancel personal appointments

--------------------------------------------------

OOP Concepts Used

Classes and Objects

The project uses classes such as:
- User
- Admin
- Doctor
- Patient
- Appointment
- AppointmentException
- HospitalSystem

Objects are created from these classes to manage hospital records.

Encapsulation

Class data members are kept private or protected. Data is accessed through getter and setter functions.

Example:
string getEmail() const;
void setEmail(string newEmail);

Inheritance

Admin, Doctor, and Patient inherit from the User base class.

Example:
class Doctor : public User

This avoids repeating common user details such as ID, name, phone, email, and password.

Abstraction

The User class contains pure virtual functions:

virtual void displayInfo() const = 0;
virtual string getRole() const = 0;

This makes User an abstract base class.

Polymorphism

Admin, Doctor, and Patient each have their own version of:

displayInfo()
getRole()

This shows function overriding and polymorphism.

Exception Handling

The project uses a custom exception class called AppointmentException.

It handles appointment-related errors such as:
- Doctor not found
- Patient not found
- No appointments available
- Wrong appointment ID

File Handling

The system saves and loads records using text files.

Files used:
data/doctors.txt
data/patients.txt
data/appointments.txt

The records are saved using | as a separator.

Example doctor record:
1|Doctor Name|010-1234-5678|doctor@email.com|pass123|Cardiology|Monday, Wednesday|10:00-12:00

--------------------------------------------------

Folder Structure

Hospital_management_system/
|-- include/
|   |-- Admin.h
|   |-- Appointment.h
|   |-- AppointmentException.h
|   |-- Doctor.h
|   |-- HospitalSystem.h
|   |-- Patient.h
|   |-- User.h
|
|-- src/
|   |-- Admin.cpp
|   |-- Appointment.cpp
|   |-- AppointmentException.cpp
|   |-- Doctor.cpp
|   |-- HospitalSystem.cpp
|   |-- Patient.cpp
|   |-- User.cpp
|   |-- main.cpp
|
|-- data/
|   |-- doctors.txt
|   |-- patients.txt
|   |-- appointments.txt
|
|-- README.md
|-- Makefile
|-- .gitignore

--------------------------------------------------

How to Compile

Using g++:
g++ src/*.cpp -Iinclude -o app.exe

Using Makefile:
make

--------------------------------------------------

How to Run

On Windows Git Bash:
./app.exe

On Linux or Mac:
./app

--------------------------------------------------

How to Clean Build Files

make clean

--------------------------------------------------

Team Contribution

Dipesh Bastakoti
GitHub: @mrdipeshbastakoti
Role: Group Leader / Final Integration / Login and Validation

Worked on:
- GitHub repository setup and branch management
- Main system integration
- HospitalSystem controller
- Login system for Admin, Doctor, and Patient
- Input validation improvements
- Final testing
- README and documentation

Samir Rai
GitHub: @deurai000
Role: Doctor and Patient Classes

Worked on:
- Doctor class
- Patient class
- Inheritance from User class
- Doctor-specific attributes and methods
- Patient-specific attributes and methods
- Role-based display functions

Raha Nureen Nesa
GitHub: @Raha-Nureen-Nesa
Role: Appointment and File Handling

Worked on:
- Appointment class
- AppointmentException class
- Appointment creation and cancellation logic
- File handling support
- Save and load functions for doctors, patients, and appointments

--------------------------------------------------

Final Note

This project is fully CLI-based and focuses on applying Object-Oriented Programming concepts in C++.
github reppo link :https://github.com/mrdipeshbastakoti/Hospital_management_system