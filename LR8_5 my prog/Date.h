#pragma once
#include <iostream>
using namespace std;

class Date {
	friend ostream& operator<<(ostream&, const Date&);
public:
	// ...
private:
	int month, day, year;
};

