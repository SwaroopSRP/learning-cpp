#include <iostream>

using namespace std;

template <typename T>
class DynArr {
    T *arr;
    int capacity{};
    int size{};

    public:
        DynArr() {
            arr = nullptr;
        }

        DynArr(const T arr[], const int size) {
            this->size = size;
            capacity = 3 * size / 2;
            this->arr = new T[capacity];
            for (int i = 0; i < size; i++) {
                this->arr[i] = arr[i];
            }
        }

        void reserve(const int n) {
            capacity += n;
            T *temp = new T[capacity];
            for (int i = 0; i < size; i++) {
                temp[i] = arr[i];
            }
            delete[] arr;
            arr = temp;
        }

        void shrink() {
            if (size <= capacity / 2) {
                capacity = capacity == 0 ? 1 : 3 * size / 2;
                T *temp = new T[capacity];
                for (int i = 0; i < size; i++) {
                    temp[i] = arr[i];
                }
                delete[] arr;
                arr = temp;
            }
        }

        void clear() {
            size = 0;
            delete[] arr;
            arr = new T[capacity];
        }

        T get(const int index) {
            if (index >= 0 && index < size) {
                return arr[index];
            }
            cout << "Index out of range!" << endl;
            return T();
        }

        void set(const int index, const T value) {
            if (index >= 0 && index < size) {
                arr[index] = value;
                return;
            }
            cout << "Index out of range!" << endl;
        }

        [[nodiscard]] int getSize() const {
            return size;
        }

        [[nodiscard]] int getCap() const {
            return capacity;
        }

        void append(const T elem) {
            if (size == capacity) {
                capacity = capacity == 0 ? 1 : 3 * capacity / 2;
                T *temp = new T[capacity];
                for (int i = 0; i < size; i++) {
                    temp[i] = arr[i];
                }
                delete[] arr;
                arr = temp;
            }
            arr[size++] = elem;
        }

        void insert(const int index, const T value) {
            if (index >= 0 && index <= size) {
                if (size == capacity) {
                    capacity = capacity == 0? 1 : 3 * capacity / 2 + 1;
                    T *temp = new T[capacity];
                    for (int i = 0; i < size; i++) {
                        temp[i] = arr[i];
                    }
                    delete[] arr;
                    arr = temp;
                }
                for (int i = size; i > index; i--) {
                    arr[i] = arr[i - 1];
                }
                arr[index] = value;
                size++;
                return;
            }
            cout << "Index out of range!" << endl;
        }

        T pop() {
            if (size > 0) {
                T temp = arr[size - 1];
                size--;
                shrink();
                return temp;
            }
            cout << "Array is empty!" << endl;
            return T();
        }

        T pop(const int index) {
            if (index >= 0 && index < size) {
                T temp = arr[index];
                for (int i = index; i < size - 1; i++) {
                    arr[i] = arr[i + 1];
                }
                size--;
                return temp;
            }
            cout << "Index out of range!" << endl;
            return T();
        }

    void remove(const T elem) {
            bool found = false;
            for (int i = 0, shift_idx = 0; i < size; i++) {
                if (arr[i] == elem) {
                    found = true;
                    continue;
                }
                arr[shift_idx++] = arr[i];
            }

            if (found) {
                size--;
            } else {
                cout << "Element not found in array!" << endl;
            }
        }


        void print() const {
            if (size == 0) {
                cout << "Array is empty!" << endl;
                return;
            }
            cout << "{";
            int i;
            for (i = 0; i < size - 1; i++) {
                cout << arr[i] << ", ";
            }
            cout << arr[i] << "}" << endl;
        }

        ~DynArr() {
            delete[] arr;
        }
};
