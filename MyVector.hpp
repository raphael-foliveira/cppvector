#include <iostream>
#include <cstring>
using namespace std;


template <typename T>
class MyVector {
    T* arr;
    int size;
    int capacity;

    void increaseCapacity() {
        capacity *= 2;
        T* newArr = new T[capacity];

        for (int i = 0; i < size; i++) {
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
    }

public:
    MyVector() {
        capacity = 5;
        size = 0;
        arr = new T[capacity];
    }

    ~MyVector() {
        delete[] arr;
    }

    T* get(int index) {
        if (index >= size) {
            cout << "Index out of bounds" << endl;
            return NULL;
        }
        return &arr[index];
    }

    void push(T value) {
        if (size == capacity) {
            increaseCapacity();
        }
        arr[size] = value;
        size++;
    }

    T* pop() {
        if (size == 0) {
            return NULL;
        }
        int* value = arr[size - 1];
        size--;
        return value;
    }

    T length() {
        return size;
    }

    int getCapacity() {
        return capacity;
    }

    void reverse() {
        for (int i = 0; i < size / 2; i++) {
            T temp = arr[i];
            arr[i] = arr[size - i - 1];
            arr[size - i - 1] = temp;
        }
    }

    string toString() {
        string str;
        str += "[";

        for (int i = 0; i < size; ++i) {
            str += to_string(arr[i]);
            if (i < size - 1) {
                str += ", ";
            }
        }

        str += "]";
        return str;
    }
};