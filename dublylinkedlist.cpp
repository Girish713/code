#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node *next;
    Node *prev;

    Node(int d)
    {
        data = d;
        next = NULL;
        prev = NULL;
    }
};

class DoublyLinkedList
{
    public:
    Node *head = NULL;

    void createList(int val);  
    void display();
    void insertAtBeg();
    void insertAtEnd();
    void insertAtAny();
    void delHead();
    void delTail();
    void delAny();
    void search();
    void Min();
    void Max();
};

// Create the doubly linked list
void DoublyLinkedList::createList(int val)
{
    Node *temp, *newNode;
    int d;
    cout << "Enter the elements of the list:" << endl;
    
    for (int i = 0; i < val; i++) {
        cin >> d;
        newNode = new Node(d);  // Create a new node for each element
        
        if (head == NULL) {  // If it's the first node, set head
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            newNode->prev = temp;  // Set the previous pointer for the new node
            temp = temp->next;     // Move to the next node
        }
    }
    cout << endl;
}

// Display the doubly linked list
void DoublyLinkedList::display()
{
    Node *temp = head;
    if (temp == NULL) {
        cout << "List is empty." << endl;
        return;
    }
    while (temp != NULL) {
        cout << temp->data << " <-> ";  // Use <-> to show both directions
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Insert at the beginning of the list
void DoublyLinkedList::insertAtBeg()
{
    Node *newNode;
    int d;
    cout << "Enter value to insert at beginning: ";
    cin >> d;
    newNode = new Node(d);
    
    if (head == NULL) {
        head = newNode;  // If list is empty, new node becomes the head
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

// Insert at the end of the list
void DoublyLinkedList::insertAtEnd()
{
    Node *newNode;
    int d;
    cout << "Enter value to insert at end: ";
    cin >> d;
    newNode = new Node(d);

    if (head == NULL) {
        head = newNode;
    } else {
        Node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

// Insert at a specific position
void DoublyLinkedList::insertAtAny()
{
    Node *newNode;
    int d, pos;
    cout << "Enter value to insert: ";
    cin >> d;
    cout << "Enter position to insert: ";
    cin >> pos;

    newNode = new Node(d);
    if (pos == 1) {
        insertAtBeg();
        return;
    }
    Node *temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        cout << "Position out of bounds." << endl;
    } else {
        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next != NULL) {
            temp->next->prev = newNode;
        }
        temp->next = newNode;
    }
}

// Delete the head node
void DoublyLinkedList::delHead()
{
    if (head == NULL) {
        cout << "List is empty." << endl;
    } else {
        Node *temp = head;
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        delete temp;
    }
}

// Delete the tail node
void DoublyLinkedList::delTail()
{
    if (head == NULL) {
        cout << "List is empty." << endl;
    } else if (head->next == NULL) {
        delete head;
        head = NULL;
    } else {
        Node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->prev->next = NULL;
        delete temp;
    }
}

// Delete any node by value
void DoublyLinkedList::delAny()
{
    Node *newNode;
    int d;
    cout << "Enter value to delete: ";
    cin >> d;

    if (head == NULL) {
        cout << "List is empty." << endl;
    } else if (head->data == d) {
        delHead();
    } else {
        Node *temp = head;
        while (temp != NULL && temp->data != d) {
            temp = temp->next;
        }
        if (temp == NULL) {
            cout << "Element not found." << endl;
        } else {
            if (temp->next != NULL) {
                temp->next->prev = temp->prev;
                temp->prev->next = temp->next;
            }
            delete temp;
        }
    }
}

// Search for an element
void DoublyLinkedList::search()
{
    Node *newNode;
    int d;
    cout << "Enter value to search: ";
    cin >> d;

    Node *temp = head;
    int pos = 1;
    while (temp != NULL) {
        if (temp->data == d) {
            cout << "Element " << d << " found at position " << pos << "." << endl;
            return;
        }
        temp = temp->next;
        pos++;
    }
    cout << "Element " << d << " not found." << endl;
}

// Find the minimum value
void DoublyLinkedList::Min()
{
    if (head == NULL) {
        cout << "List is empty." << endl;
    } else {
        int min = head->data;
        Node *temp = head;
        while (temp != NULL) {
            if (temp->data < min) {
                min = temp->data;
            }
            temp = temp->next;
        }
        cout << "Minimum value is: " << min << endl;
    }
}

// Find the maximum value
void DoublyLinkedList::Max()
{
    if (head == NULL) {
        cout << "List is empty." << endl;
    } else {
        int max = head->data;
        Node *temp = head;
        while (temp != NULL) {
            if (temp->data > max) {
                max = temp->data;
            }
            temp = temp->next;
        }
        cout << "Maximum value is: " << max << endl;
    }
}

int main()
{
    DoublyLinkedList dll;
    int choice, x;

    cout << "Enter number of elements you want in your list: ";
    cin >> x;
    dll.createList(x);

    do {
        cout << "\nMenu:\n";
        cout << "1. Display List\n";
        cout << "2. Insert at Beginning\n";
        cout << "3. Insert at End\n";
        cout << "4. Insert at Specific Position\n";
        cout << "5. Delete Head\n";
        cout << "6. Delete Tail\n";
        cout << "7. Delete Specific Element\n";
        cout << "8. Search Element\n";
        cout << "9. Find Minimum\n";
        cout << "10. Find Maximum\n";
        cout << "11. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                dll.display();
                break;

            case 2:
                dll.insertAtBeg();
                break;

            case 3:
                dll.insertAtEnd();
                break;

            case 4:
                dll.insertAtAny();
                break;

            case 5:
                dll.delHead();
                break;

            case 6:
                dll.delTail();
                break;

            case 7:
                dll.delAny();
                break;

            case 8:
                dll.search();
                break;

            case 9:
                dll.Min();
                break;

            case 10:
                dll.Max();
                break;

            case 11:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice, please try again.\n";
        }

    } while (choice != 11);

    return 0;
}
