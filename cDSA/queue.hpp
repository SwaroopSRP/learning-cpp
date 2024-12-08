#ifndef QUEUE_HPP
#define QUEUE_HPP
#endif

#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class StaticQueue {
    T *arr;
    int front, rear, size;

public:
    StaticQueue() {
        arr = new T[0];
        front = rear = -1;
        size = 1;
    }

    explicit StaticQueue(const int capacity) {
        arr = new T[capacity];
        size = capacity;
        front = rear = -1;
    }

    ~StaticQueue() {
        delete[] arr;
        arr = nullptr;
    }

    [[nodiscard]] bool isEmpty() const {
        return front == -1 || front > rear;
    }

    [[nodiscard]] bool isFull() const {
        return rear == size - 1;
    }

    [[nodiscard]] int len() const {
        if (isEmpty()) {
            return 0;
        }
        return rear - front + 1;
    }

    void enqueue(const T elem) {
        if (!isFull()) {
            arr[++rear] = elem;
            if (front == -1) {
                front = 0;
            }
            return;
        }
        cout << "The queue is full!" << endl;
    }

    T dequeue() {
        if (isEmpty()) {
            cout << "The queue is empty" << endl;
            return T();
        }
        if (front == rear) {
            T elem = arr[front];
            front = rear = -1;
            return elem;
        }
        return arr[front++];
    }

    T peek(bool at_rear=false) const {
        if (isEmpty()) {
            cout << "The queue is empty" << endl;
            return T();
        }
        return at_rear ? arr[rear] : arr[front];
    }

    friend ostream &operator<<(ostream &ost, const StaticQueue &sq_obj) {
        if (sq_obj.isEmpty()) {
            ost << "The queue is empty!";
        } else {
            ost << "[";
            for (int i = sq_obj.front; i < sq_obj.rear; ++i) {
                ost << sq_obj.arr[i] << ", ";
            }
            ost << sq_obj.arr[sq_obj.rear] << "]";
        }
        return ost;
    }
};

template <typename T>
class DynQueue {
    vector<T> qvec;

public:
    [[nodiscard]] bool isEmpty() const {
        return qvec.empty();
    }

    [[nodiscard]] int size() const {
        return qvec.size();
    }

    void enqueue(T elem) {
        qvec.push_back(elem);
    }

    T dequeue() {
        if (isEmpty()) {
            cout << "The queue is empty!" << endl;
            return T();
        }
        T elem = qvec.front();
        qvec.erase(qvec.begin());
        return elem;
    }

    [[nodiscard]] T peek(const bool at_rear=false) const {
        if (isEmpty()) {
            cout << "The queue is empty!" << endl;
            return T();
        }
        if (at_rear == true) {
            return qvec.back();
        }
        return qvec.front();
    }

    friend ostream &operator<<(ostream &ost, const DynQueue &dq_obj) {
        if (dq_obj.isEmpty()) {
            ost << "The queue is empty!";
        } else {
            ost << "[";
            for (size_t i = 0; i < dq_obj.qvec.size() - 1; ++i) {
                ost << dq_obj.qvec[i] << ", ";
            }
            ost << dq_obj.qvec.back() << "]";
        }
        return ost;
    }

};
