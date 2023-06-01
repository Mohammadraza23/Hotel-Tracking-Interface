#ifndef RESERVATION_H
#define RESERVATION_H
#include"Date.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

//Class reservation
class Reservation
{
	//private data members of class
private:
	string customerName;
	Date checkIn;
	int duration;

public:
	//Parameterized constructor
	Reservation(string name, Date& date, int dur);

	//function that checks if dates overlap
	bool overlaps(Reservation& r);

	//functions that returns true if current reservation is less than the paramters 
	bool lessThan(Reservation& res);
	bool lessThan(Date& d);
	void print();
};

#endif