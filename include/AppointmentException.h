#ifndef APPOINTMENT_EXCEPTION_H
#define APPOINTMENT_EXCEPTION_H

#include <exception>
#include <string>
using namespace std;

// This custom exception is used for appointment-related errors.
class AppointmentException : public exception {
private:
    string message;

public:
    AppointmentException(string message);

    const char* what() const noexcept override;
};

#endif
