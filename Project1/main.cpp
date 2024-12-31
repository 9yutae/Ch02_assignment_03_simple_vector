#include "SimpleVector.h"
#include <iostream>
#include <string>

int main() {
	SimpleVector<int> vec;
	vec.push_back(10);

	cout << "Size: " << vec.size() << ", Capacity: " << vec.capacity() << endl;

	SimpleVector<string> str;
	str.push_back("Hello,");
	str.push_back("World!");

	cout << "Size: " << str.size() << ", Capacity: " << str.capacity() << endl;

#ifdef DEBUG
	cout << "Input 10 numbers seperated by space : ";

	for (int i = 0, num;i < 10;i++) {
		cin >> num;
		vec.push_back(num);
	}

	cout << "\After push_back()" << endl;
	for (int i = 0;i < vec.size();i++) {
		cout << i + 1 << ": " << vec[i] << "\t";
	}

	vec.sortData();
	cout << "After sortData()" << endl;
	for (int i = 0;i < vec.size();i++) {
		cout << i + 1 << ": " << vec[i] << "\t";
	}

	vec.pop_back();
	cout << "\n\nAfter pop_back()" << endl;
	cout << "Size: " << vec.size() << ", Capacity: " << vec.capacity() << endl;

	for (int i = 0;i < vec.size();i++) {
		cout << i + 1 << ": " << vec[i] << "\t";
	}


	cout << "\n\n";

	for (int i = 0;i < 10;i++) {
		cout << i << " pop_back()" << endl;
		vec.pop_back();
	}

	cout << "Size: " << vec.size() << ", Capacity: " << vec.capacity() << endl;

#endif

	return 0;
}
