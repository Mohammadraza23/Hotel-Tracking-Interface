#ifndef ROOM_H
#define ROOM_H
#include "Reservation.h"
#include "defs.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;


//Room class
class Room
{
	//private data members
private:
	int roomNumber;
	string bedType;
	int capacity;
	bool hasFridge;
	Reservation* reservations[MAX_RES];
	int numReservations;

	//public functions
public:
	//constructor
	Room(int roomNum, string bedtp, int cap, bool fridge);
	
	//destructor
	~Room();
	
	int getRoomNumber();
	bool isMatch(string bt, int cap, bool f);
	bool lessThan(Room& r);
	bool addReservation(string name, Date& d, int duration);
	void print();
	void printReservations();
	void updateReservations(Date& currentDate);
};

#endif