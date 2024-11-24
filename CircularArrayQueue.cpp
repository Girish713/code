#include <iostream>
using namespace std;

class CircularQueue {
private:
    int front, rear, size;
    int* queueArray;

public:
    // Constructor to initialize the queue
    CircularQueue(int s) {
        front = -1;
        rear = -1;
        size = s;
        queueArray = new int[size];
    }

    // Destructor to free memory
    ~CircularQueue() {
        delete[] queueArray;
    }

    // Function to add an element to the queue (Enqueue)
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full! Cannot enqueue " << value << endl;
            return;
        }
        if (isEmpty()) front = 0;
        rear = (rear + 1) % size;
        queueArray[rear] = value;
        cout << value << " enqueued to queue" << endl;
    }

    // Function to remove an element from the queue (Dequeue)
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty! Cannot dequeue" << endl;
            return;
        }
        cout << queueArray[front] << " dequeued from queue" << endl;
        if (front == rear) {
            front = rear = -1;  // Reset the queue if it becomes empty
        } else {
            front = (front + 1) % size;
        }
    }

    // Function to get the front of the queue
    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty! No front element" << endl;
            return -1;
        }
        return queueArray[front];
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return (front == -1);
    }

    // Function to check if the queue is full
    bool isFull() {
        return ((rear + 1) % size == front);
    }

    // Function to display the queue elements
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Queue elements: ";
        int i = front;
        while (true) {
            cout << queueArray[i] << " ";
            if (i == rear) break;
            i = (i + 1) % size;
        }
        cout << endl;
    }
};

// Main function to demonstrate circular queue operations
int main() {
    int queueSize;
    cout << "Enter the size of the queue: ";
    cin >> queueSize;

    CircularQueue q(queueSize);

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

    q.enqueue(60);  // Attempt to enqueue in a full queue
    q.dequeue();
    q.enqueue(60);  // Successfully enqueue after dequeue
    q.display();

    return 0;
}
