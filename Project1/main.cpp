#include "SimpleVector.h"
// #define DEBUG_02

template <typename T>
void printVector(SimpleVector<T>& vec);

int main() {
	SimpleVector<int> vec;
	vec.push_back(10);

	cout << "Size: " << vec.size() << ", Capacity: " << vec.capacity() << endl;

	SimpleVector<string> str;
	str.push_back("Hello,");
	str.push_back("World!");

	cout << "Size: " << str.size() << ", Capacity: " << str.capacity() << endl;

	SimpleVector<string> str1(str);
	str1.push_back("Hello,");
	str1.push_back("World!");

	cout << "Size: " << str.size() << ", Capacity: " << str.capacity() << endl;

#ifdef DEBUG

	int _size;
	cout << "\nEnter the size of Vector: ";
	cin >> _size;
	vec.resize(_size);

	cout << "\nEnter " << _size << " numbers sepertated by space: ";
	for (int i = 0, num;i < _size;i++) {
		cin >> num;
		vec.push_back(num);
	}

	cout << "\nAfter push_back()" << endl;
	printVector(vec);

#ifdef DEBUG_02
	cout << "\nEnter " << _size << " numbers sepertated by space: ";
	for (int i = 0, num;i < _size;i++) {
		cin >> num;
		vec.push_back(num);
	}

	cout << "\nAfter push_back()" << endl;
	printVector(vec);
#endif

	vec.sortData();
	cout << "After sortData()" << endl;
	printVector(vec);

	vec.pop_back();
	cout << "After pop_back()" << endl;
	printVector(vec);

#ifdef DEBUG_02
	for (int i = 0;i < _size;i++) {
		vec.pop_back();
	}
#endif

	for (int i = 0;i <= _size;i++) {
		vec.pop_back();
	}
	cout << "After pop_back()" << endl;
	cout << "Size: " << vec.size() << ", Capacity: " << vec.capacity() << "\n\n";

#endif

	return 0;
}

template <typename T>
void printVector(SimpleVector<T>& vec) {
	for (int i = 0;i < vec.size();i++) {
		cout << i + 1 << ": " << vec[i] << "\t";
	}
	cout << "\nSize: " << vec.size() << ", Capacity: " << vec.capacity() << "\n\n";
}
