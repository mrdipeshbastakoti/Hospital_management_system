#include "../include/HospitalSystem.h"

HospitalSystem::HospitalSystem()
    : admin(1, "System Admin", "010-0000-0000", "admin@hospital.com", 1) {
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
        cout << "2. Back to Main Menu" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                admin.displayInfo();
                break;
            case 2:
                cout << "Returning to main menu..." << endl;
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
        }

    } while (choice != 2);
}