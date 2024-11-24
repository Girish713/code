#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node *next;

    Node(int d)
    {
        data = d;
        next = NULL;
    }
};

class LinkedList
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

// Create the list
void LinkedList::createList(int val)
{
    Node *temp, *newNode;
    int d;
    cout << "Enter the elements of the list:" << endl;
    
    for (int i = 0; i < val; i++) {
        cin >> d;
        newNode = new Node(d);  // Create a new node for each element
        
        if (head == NULL) {  
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;  
            temp = temp->next;     
        }
    }
    cout << endl;
}

// Display the list
void LinkedList::display()
{
    Node *temp = head;
    if (temp == NULL) {
        cout << "List is empty." << endl;
        return;
    }
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Insert at the beginning
void LinkedList::insertAtBeg()
{
    Node *newNode;
    int d;
    cout << "Enter value to insert at beginning: ";
    cin >> d;
    newNode = new Node(d);
    newNode->next = head;
    head = newNode;
}

// Insert at the end
void LinkedList::insertAtEnd()
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
    }
}

// Insert at any position
void LinkedList::insertAtAny()
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
    for (int i = 2; i < pos && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        cout << "Position out of bounds." << endl;
    } else {
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

// Delete the head node
void LinkedList::delHead()
{
    if (head == NULL) {
        cout << "List is empty." << endl;
    } else {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}

// Delete the last node
void LinkedList::delTail()
{
    if (head == NULL) {
        cout << "List is empty." << endl;
    } else if (head->next == NULL) {
        delete head;
        head = NULL;
    } 
    else {
        Node *temp = head;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
}

// Delete any node (by value)
void LinkedList::delAny()
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
        while (temp->next != NULL && temp->next->data != d) {
            temp = temp->next;
        }
        if (temp->next == NULL) {
            cout << "Element not found." << endl;
        } else {
            Node *toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
        }
    }
}

// Search for an element
void LinkedList::search()
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
void LinkedList::Min()
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
void LinkedList::Max()
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
    LinkedList ll;
    int choice, x;

    cout << "Enter number of elements you want in your list: ";
    cin >> x;
    ll.createList(x);

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
                ll.display();
                break;

            case 2:
                ll.insertAtBeg();
                break;

            case 3:
                ll.insertAtEnd();
                break;

            case 4:
                ll.insertAtAny();
                break;

            case 5:
                ll.delHead();
                break;

            case 6:
                ll.delTail();
                break;

            case 7:
                ll.delAny();
                break;

            case 8:
                ll.search();
                break;

            case 9:
                ll.Min();
                break;

            case 10:
                ll.Max();
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
