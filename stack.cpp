#include<iostream>
#include<string>
using namespace std;

class Stack {
private:
    int top;
    int stack[5];
    const int MAX = 5;

public:
    Stack() {
        top = -1; // initialize the stack as empty
    }

    // Create stack (already initialized in constructor)
    void create() {
        top = -1;
        cout << "Stack created with size " << MAX << endl;
    }

    // Push an element onto the stack
    void push(int value) {
        if (isFull()) {
            cout << "Stack is full! Cannot push " << value << endl;
        } else {
            stack[++top] = value;
            cout << "Pushed " << value << " onto the stack." << endl;
        }
    }

    // Pop an element from the stack
    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty! Cannot pop." << endl;
        } else {
            cout << "Popped " << stack[top--] << " from the stack." << endl;
        }
    }

    // Check if the stack is empty
    bool isEmpty() {
        return top == -1;
    }

    // Check if the stack is full
    bool isFull() {
        return top == MAX - 1;
    }

    // Display the elements in the stack
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
        } else {
            cout << "Stack elements are: ";
            for (int i = 0; i <= top; i++) {
                cout << stack[i] << " ";
            }
            cout << endl;
        }
    }
};

// Function to check if a string is a palindrome
bool isPalindrome(string str) {
    int start = 0;
    int end = str.length() - 1;

    while (start < end) {
        if (str[start] != str[end]) {
            return false; // If characters at start and end are not equal, it's not a palindrome
        }
        start++;
        end--;
    }
    return true; // If all characters match, it's a palindrome
}

int main() {
    Stack s;
    int choice, value;
    string str;

    do {
        cout << "\nMenu:\n";
        cout << "1. Create Stack\n";
        cout << "2. Push Element\n";
        cout << "3. Pop Element\n";
        cout << "4. Check if Stack is Empty\n";
        cout << "5. Check if Stack is Full\n";
        cout << "6. Display Stack\n";
        cout << "7. Check if String is Palindrome\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                s.create(); // Create the stack
                break;

            case 2:
                cout << "Enter value to push: ";
                cin >> value;
                s.push(value); // Push the element onto the stack
                break;

            case 3:
                s.pop(); // Pop the top element from the stack
                break;

            case 4:
                if (s.isEmpty()) {
                    cout << "Stack is empty." << endl;
                } else {
                    cout << "Stack is not empty." << endl;
                }
                break;

            case 5:
                if (s.isFull()) {
                    cout << "Stack is full." << endl;
                } else {
                    cout << "Stack is not full." << endl;
                }
                break;

            case 6:
                s.display(); // Display the stack elements
                break;

            case 7:
                cout << "Enter a string to check if it is a palindrome: ";
                cin >> str;
                if (isPalindrome(str)) {
                    cout << str << " is a palindrome." << endl;
                } else {
                    cout << str << " is not a palindrome." << endl;
                }
                break;

            case 8:
                cout << "Exiting program..." << endl;
                break;

            default:
                cout << "Invalid choice! Please try again." << endl;
                break;
        }
    } while (choice != 8);

    return 0;
}
