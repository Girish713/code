#include <iostream>
using namespace std;

// Node class for linked list
class Node {
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

// Queue class using linked list
class QueueLinkedList {
private:
    Node* front;
    Node* rear;

public:
    QueueLinkedList() : front(nullptr), rear(nullptr) {}

    ~QueueLinkedList() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        cout << value << " enqueued to queue" << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty! Cannot dequeue" << endl;
            return;
        }
        Node* temp = front;
        cout << front->data << " dequeued from queue" << endl;
        front = front->next;
        if (front == nullptr) rear = nullptr;
        delete temp;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty! No front element" << endl;
            return -1;
        }
        return front->data;
    }

    bool isEmpty() {
        return (front == nullptr);
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        Node* temp = front;
        cout << "Queue elements: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    QueueLinkedList q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();

    cout << "Front element: " << q.peek() << endl;

    q.dequeue();
    q.display();

    q.enqueue(40);
    q.enqueue(50);
    q.display();

    return 0;
}
