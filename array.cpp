#include <iostream>
using namespace std;

void createArray(int arr[], int &size, int maxSize) {
    cout << "Enter the number of elements (max " << maxSize << "): ";
    cin >> size;
    if (size > maxSize || size < 0) {
        cout << "Invalid size! Please enter a value between 1 and " << maxSize << ".\n";
        size = 0; // Reset size
        return;
    }
    cout << "Enter " << size << " elements:\n";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
}

void displayArray(const int arr[], int size) {
    if (size == 0) {
        cout << "Array is empty.\n";
        return;
    }
    cout << "Array elements: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insertElement(int arr[], int &size, int maxSize) {
    if (size == maxSize) {
        cout << "Array is full. Cannot insert new element.\n";
        return;
    }
    int position, element;
    cout << "Enter the position (1 to " << size + 1 << ") to insert the element: ";
    cin >> position;
    if (position < 1 || position > size + 1) {
        cout << "Invalid position.\n";
        return;
    }
    cout << "Enter the element to insert: ";
    cin >> element;
    for (int i = size; i >= position; i--) {
        arr[i] = arr[i - 1];
    }
    arr[position - 1] = element;
    size++;
    cout << "Element inserted successfully.\n";
}

void deleteElement(int arr[], int &size) {
    if (size == 0) {
        cout << "Array is empty. Cannot delete any element.\n";
        return;
    }
    int position;
    cout << "Enter the position (1 to " << size << ") of the element to delete: ";
    cin >> position;
    if (position < 1 || position > size) {
        cout << "Invalid position.\n";
        return;
    }
    for (int i = position - 1; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;
    cout << "Element deleted successfully.\n";
}

int main() {
    const int maxSize = 100;
    int arr[maxSize];
    int size = 0;
    int choice;

    do {
        cout << "\nMenu:\n";
        cout << "1. Create an Array\n";
        cout << "2. Display Array Elements\n";
        cout << "3. Insert an Element\n";
        cout << "4. Delete an Element\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                createArray(arr, size, maxSize);
                break;
            case 2:
                displayArray(arr, size);
                break;
            case 3:
                insertElement(arr, size, maxSize);
                break;
            case 4:
                deleteElement(arr, size);
                break;
            case 5:
                cout << "Exiting program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}

