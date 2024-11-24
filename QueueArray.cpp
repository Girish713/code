#include <iostream>
using namespace std;

class QueueArray {
private:
    int front, rear, size;
    int* queueArray;

public:
    QueueArray(int s) {
        front = -1;
        rear = -1;
        size = s;
        queueArray = new int[size];
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full! Cannot enqueue " << value << endl;
            return;
        }
        if (front == -1) {
            front = 0;
        }
        rear++;
        queueArray[rear] = value;
        cout << value << " enqueued to queue" << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty! Cannot dequeue" << endl;
            return;
        }
        cout << queueArray[front] << " dequeued from queue" << endl;
        front++;
        if (front > rear) {
            front = -1;
            rear = -1;
        }
    }

    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty! No front element" << endl;
            return -1;
        }
        return queueArray[front];
    }

    bool isEmpty() {
        if (front == -1) {
            return true;
        } else {
            return false;
        }
    }

    bool isFull() {
        if (rear == size - 1) {
            return true;
        } else {
            return false;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << queueArray[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int queueSize;
    cout << "Enter the size of the queue: ";
    cin >> queueSize;

    QueueArray q(queueSize);

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
