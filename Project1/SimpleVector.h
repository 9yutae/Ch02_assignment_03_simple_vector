#pragma once

#define DEBUG

#include <iostream>
#include <algorithm>
#ifdef DEBUG
#include <cassert>
#endif

using namespace std;

template <typename T>
class SimpleVector {
private:
	T* data;
	int currentSize;
	int currentCapacity;

public:
	SimpleVector();		// Default Constructor
	SimpleVector(int capacity); // Constructor Overloading
	SimpleVector(const SimpleVector& other) noexcept; // Copy Constructor
	~SimpleVector();	// Destructor

	void push_back(const T& value);
	void pop_back();
	void sortData();
	void resize(int newCapacity);

	int size() const { return currentSize; }
	int capacity() const { return currentCapacity; }


#ifdef DEBUG
	T& operator[](int idx);
#endif

};

// Code Implement
// Default Constructor
template <typename T>
SimpleVector<T>::SimpleVector() : currentSize(0), currentCapacity(10) {
	data = new T[currentCapacity];
	cout << "Created SimpleVector!" << endl;
}

// Constructor Overloading
template <typename T>
SimpleVector<T>::SimpleVector(int capacity) : currentSize(0), currentCapacity(capacity) {
	data = new T[currentCapacity];
	cout << "Created SimpleVector! Capacity of Vector is " << currentCapacity << endl;
}

// Copy Constructor
template <typename T>
SimpleVector<T>::SimpleVector(const SimpleVector& other) noexcept
		:data(new T[other.currentCapacity]),
		currentSize(other.currentSize),
		currentCapacity(other.currentCapacity) {
	copy(other.data, other.data + currentSize, data);
	cout << "Vector Successfully Copied" << endl;
}

// Destructor
template <typename T>
SimpleVector<T>::~SimpleVector() {
	delete[] data;
	cout << "Destroyed SimpleVector!" << endl;
}

// push_back()
template <typename T>
void SimpleVector<T>::push_back(const T& value) {
	if (currentSize >= currentCapacity) {
		this->resize(currentCapacity + 5);
	}
	data[currentSize++] = value;
}

// pop_back()
template <typename T>
void SimpleVector<T>::pop_back() {
	if (currentSize > 0) {
		currentSize--;
	}
	else cout << "SimpleVector is empty!" << endl;
}

// sortData()
template <typename T>
void SimpleVector<T>::sortData() {
	sort(data, data + currentSize);
	cout << "Sort completed!" << endl;
}

// resize()
template <typename T>
void SimpleVector<T>::resize(int newCapacity) {
	if (newCapacity > currentCapacity) {
		T* newVector = new T[newCapacity];
		std::copy(data, data + currentSize, newVector);

		delete[] data;

		data = newVector;
		currentCapacity = newCapacity;
	}

	cout << "[Resize] currentSize : " << currentSize << ", currentCapacity : " << currentCapacity << endl;
}

#ifdef DEBUG
// operator [] overloading
template <typename T>
T& SimpleVector<T>::operator[](int idx) {
	assert(idx >= 0 && idx < currentSize);
	return data[idx];
}
#endif
