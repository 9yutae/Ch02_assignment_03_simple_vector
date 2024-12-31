#pragma once

// #define DEBUG

#include <iostream>
#include <cassert>
using namespace std;

template <typename T>
class SimpleVector {
public:
	SimpleVector() : currentSize(0), currentCapacity(10) {
		data = new T[currentCapacity];
		cout << "Created SimpleVector!" << endl;
	}

	SimpleVector(int capacity) : currentSize(0), currentCapacity(capacity) {
		data = new T[currentCapacity];
		cout << "Created SimpleVector!" << endl;
	}

	~SimpleVector() {
		delete[] data;
		cout << "Destroyed SimpleVector!" << endl;
	}

	void push_back(const T& value) {
		if (currentSize < currentCapacity) {
			data[currentSize++] = value;
		}
		else cout << "SimpleVector is already full!" << endl;
	}

	void pop_back() {
		if (currentSize > 0) {
			currentSize--;
		}
		else cout << "SimpleVector is empty!" << endl;
	}

	int size() const { return currentSize; }
	int capacity() const { return currentCapacity; }

#ifdef DEBUG
	T& operator[](int idx) {
		//assert(idx >= 0 && idx < size);
		return data[idx];
	}
#endif

private:
	T* data;
	int currentSize;
	int currentCapacity;
};
