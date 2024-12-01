#ifndef ARRSTACK_HPP
#define ARRSTACK_HPP
#endif //ARRSTACK_HPP
#include <iostream>
#include <climits>

using namespace std;

template <typename dtype>
class Stack {
    dtype *arr;
    int size;
    int top;
    public:
        Stack() { // Default Constructor, equiv to: // Stack() : arr(nullptr), top(-1), size(0) {}
            arr = nullptr;
            top = -1;
            size = 0;
        }
    
        explicit Stack(int size) {
            if (size <= 0 || size > INT_MAX) {
                cout << "Invalid stack size!" << endl;
                return;
            }
            this->size = size;
            arr = new dtype[size]; // new is used for dyn-memalloc, returning address of loc
            top = -1;
        }
    
        void push(dtype elem) {
            if (top == size - 1) {
                cout << "Stack Overflow!" << endl;
                return;
            }
            arr[++top] = elem;
        }
    
        dtype pop() {
            if (top == -1) {
                cout << "Stack Underflow!" << endl;
                return dtype{};
            }
            return arr[top--];
        }
    
        dtype peek() const {
            if (top == -1) {
                cout << "Stack is empty!" << endl;
                return dtype{};
            }
            return arr[top];
        }
    
        [[nodiscard]] bool isEmpty() const { // nodisc allows warning for not catching return on declaration
            return top == -1;
        }
    
        [[nodiscard]] bool isFull() const{
            return top == size -1;
        }

        int size() const {
            return size;
    
        void display() {
            if (top == -1) {
                cout << "Stack is empty!" << endl;
                return;
            }
            cout << "Stack Elements: ";
            for (int i = 0; i <= top; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    
        ~Stack() {
            delete[] arr;
        }
};
