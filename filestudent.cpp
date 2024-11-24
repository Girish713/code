#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>
using namespace std;

// Student record structure
struct Student {
    int id;
    char name[50];
    char department[30];
    float gpa;
};

// Index map to store mappings of student ID to file position
unordered_map<int, streampos> indexMap;

// Function to load the index from the index file
void loadIndex(const string& indexFile) {
    ifstream file(indexFile, ios::binary);
    if (!file) return;

    indexMap.clear();
    int id;
    streampos pos;
    while (file.read(reinterpret_cast<char*>(&id), sizeof(id))) {
        file.read(reinterpret_cast<char*>(&pos), sizeof(pos));
        indexMap[id] = pos;
    }
    file.close();
}

// Function to save the index to the index file
void saveIndex(const string& indexFile) {
    ofstream file(indexFile, ios::binary | ios::trunc);
    for (const auto& entry : indexMap) {
        file.write(reinterpret_cast<const char*>(&entry.first), sizeof(entry.first));
        file.write(reinterpret_cast<const char*>(&entry.second), sizeof(entry.second));
    }
    file.close();
}

// Function to add a student record
void addStudent(const string& dataFile, const string& indexFile) {
    Student student;
    cout << "Enter Student ID: ";
    cin >> student.id;
    cin.ignore(); // Clear input buffer
    cout << "Enter Name: ";
    cin.getline(student.name, sizeof(student.name));
    cout << "Enter Department: ";
    cin.getline(student.department, sizeof(student.department));
    cout << "Enter GPA: ";
    cin >> student.gpa;

    if (indexMap.find(student.id) != indexMap.end()) {
        cout << "Error: Student ID already exists.\n";
        return;
    }

    fstream file(dataFile, ios::binary | ios::app);
    streampos pos = file.tellp();
    file.write(reinterpret_cast<const char*>(&student), sizeof(student));
    file.close();

    indexMap[student.id] = pos;
    saveIndex(indexFile);
    cout << "Student record added successfully.\n";
}

// Function to update a student record
void updateStudent(const string& dataFile, const string& indexFile) {
    int id;
    cout << "Enter Student ID to update: ";
    cin >> id;

    if (indexMap.find(id) == indexMap.end()) {
        cout << "Error: Student ID not found.\n";
        return;
    }

    Student student;
    cout << "Enter New Name: ";
    cin.ignore(); // Clear input buffer
    cin.getline(student.name, sizeof(student.name));
    cout << "Enter New Department: ";
    cin.getline(student.department, sizeof(student.department));
    cout << "Enter New GPA: ";
    cin >> student.gpa;
    student.id = id;

    fstream file(dataFile, ios::binary | ios::in | ios::out);
    file.seekp(indexMap[id]);
    file.write(reinterpret_cast<const char*>(&student), sizeof(student));
    file.close();

    cout << "Student record updated successfully.\n";
}

// Function to delete a student record
void deleteStudent(const string& dataFile, const string& indexFile) {
    int id;
    cout << "Enter Student ID to delete: ";
    cin >> id;

    if (indexMap.find(id) == indexMap.end()) {
        cout << "Error: Student ID not found.\n";
        return;
    }

    indexMap.erase(id);
    saveIndex(indexFile);
    cout << "Student record deleted successfully.\n";
}

// Function to search for a student record
void searchStudent(const string& dataFile) {
    int id;
    cout << "Enter Student ID to search: ";
    cin >> id;

    if (indexMap.find(id) == indexMap.end()) {
        cout << "Error: Student ID not found.\n";
        return;
    }

    fstream file(dataFile, ios::binary | ios::in);
    file.seekg(indexMap[id]);
    Student student;
    file.read(reinterpret_cast<char*>(&student), sizeof(student));
    file.close();

    cout << "\nStudent Record:\n";
    cout << "ID: " << student.id << "\n";
    cout << "Name: " << student.name << "\n";
    cout << "Department: " << student.department << "\n";
    cout << "GPA: " << student.gpa << "\n";
}

int main() {
    const string dataFile = "students.dat";
    const string indexFile = "index.dat";
    loadIndex(indexFile);

    int choice;

    do {
        cout << "\nMenu:\n";
        cout << "1. Add Student\n";
        cout << "2. Update Student\n";
        cout << "3. Delete Student\n";
        cout << "4. Search Student\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent(dataFile, indexFile);
                break;
            case 2:
                updateStudent(dataFile, indexFile);
                break;
            case 3:
                deleteStudent(dataFile, indexFile);
                break;
            case 4:
                searchStudent(dataFile);
                break;
            case 5:
                saveIndex(indexFile);
                cout << "Exiting the program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}

