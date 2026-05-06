// Write your code here
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class CircularQueue {
    private:
    vector<int> arr;
    int front;
    int rear;
    int capacity;
    int currentSize;
    public:
    CircularQueue(int size) {
        capacity = size;
        arr.resize(capacity);
        front = 0;
        rear = -1;
        currentSize = 0;
    }
    void enqueue(int x) {
        if (currentSize == capacity) {
            cout << "Full!" << endl;
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = x;
        currentSize++;
    }
    void dequeue() {
        if (currentSize == 0) {
            cout << "Empty!" << endl;
            return;
        }
        front = (front + 1) % capacity;
        currentSize--;
    }
    void display() {
        if (currentSize == 0) {
            cout << "Empty" << endl;
            return;
        }
        for (int i = 0; i < currentSize; i++) {
            cout << arr[(front + i) % capacity] << (i == currentSize - 1 ? "" : " ");
        }
        cout << endl;
    }
    void peek() {
        if (currentSize == 0) {
            cout << -1 << endl;
        } else {
            cout << arr[front] << endl;
        }
    }
    void isEmpty() {
        if (currentSize == 0) {
            cout << "true" << endl;
        } else {
            cout << "false" << endl;
        }
    }
};
int main() {
    int Q;
    if (!(cin >> Q)) return 0;
    CircularQueue cq(5);
    while (Q--) {
        string command;
        cin >> command;
        if (command == "ENQUEUE") {
            int val;
            cin >> val;
            cq.enqueue(val);
        } else if (command == "DEQUEUE") {
            cq.dequeue();
        } else if (command == "DISPLAY") {
            cq.display();
        } else if (command == "PEEK") {
            cq.peek();
        } else if (command == "ISEMPTY") {
            cq.isEmpty();
        }
    }
    return 0;
}
     