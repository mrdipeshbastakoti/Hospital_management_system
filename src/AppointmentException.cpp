#include "../include/AppointmentException.h"

// Stores the error message.
AppointmentException::AppointmentException(string message)
    : message(message) {
}

// Returns the error message when the exception is caught.
const char* AppointmentException::what() const noexcept {
    return message.c_str();
}
