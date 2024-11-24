#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

// Structure to store employee details
struct Employee {
    string empID;
    string name;
    string department;
    string address;
};

// Function prototypes
void addEmployee();
void deleteEmployee();
void displayEmployee();
void displayMenu();

int main() {
    int choice;
    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Clear the input buffer

        switch (choice) {
            case 1:
                addEmployee();
                break;
            case 2:
                deleteEmployee();
                break;
            case 3:
                displayEmployee();
                break;
            case 4:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}

// Function to display the menu
void displayMenu() {
    cout << "\nEmployee Management System\n";
    cout << "1. Add Employee\n";
    cout << "2. Delete Employee\n";
    cout << "3. Display Employee\n";
    cout << "4. Exit\n";
}

// Function to add an employee
void addEmployee() {
    Employee emp;
    cout << "Enter Employee ID: ";
    getline(cin, emp.empID);
    cout << "Enter Name: ";
    getline(cin, emp.name);
    cout << "Enter Department: ";
    getline(cin, emp.department);
    cout << "Enter Address: ";
    getline(cin, emp.address);

    ofstream outFile("employees.txt", ios::app);
    if (outFile.is_open()) {
        outFile << emp.empID << "," << emp.name << "," << emp.department << "," << emp.address << "\n";
        outFile.close();
        cout << "Employee added successfully!\n";
    } else {
        cout << "Error: Unable to open file.\n";
    }
}

// Function to delete an employee
void deleteEmployee() {
    string empID, line;
    cout << "Enter Employee ID to delete: ";
    getline(cin, empID);

    ifstream inFile("employees.txt");
    ofstream tempFile("temp.txt");
    bool found = false;

    if (inFile.is_open() && tempFile.is_open()) {
        while (getline(inFile, line)) {
            stringstream ss(line);
            string id;
            getline(ss, id, ',');

            if (id != empID) {
                tempFile << line << "\n";
            } else {
                found = true;
            }
        }
        inFile.close();
        tempFile.close();

        remove("employees.txt");
        rename("temp.txt", "employees.txt");

        if (found) {
            cout << "Employee deleted successfully!\n";
        } else {
            cout << "Employee ID not found.\n";
        }
    } else {
        cout << "Error: Unable to open file.\n";
    }
}

// Function to display an employee
void displayEmployee() {
    string empID, line;
    cout << "Enter Employee ID to display: ";
    getline(cin, empID);

    ifstream inFile("employees.txt");
    bool found = false;

    if (inFile.is_open()) {
        while (getline(inFile, line)) {
            stringstream ss(line);
            string id, name, department, address;
            getline(ss, id, ',');
            getline(ss, name, ',');
            getline(ss, department, ',');
            getline(ss, address, ',');

            if (id == empID) {
                cout << "Employee Details:\n";
                cout << "ID: " << id << "\n";
                cout << "Name: " << name << "\n";
                cout << "Department: " << department << "\n";
                cout << "Address: " << address << "\n";
                found = true;
                break;
            }
        }
        inFile.close();

        if (!found) {
            cout << "Employee ID not found.\n";
        }
    } else {
        cout << "Error: Unable to open file.\n";
    }
}

