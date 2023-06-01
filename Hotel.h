#ifndef HOTEL_H
#define HOTEL_H

#include "Room.h"
#include "defs.h"
#include <iostream>
#include <string>
#include <iomanip>

//Hotel Class
class Hotel
{
	//Private date members
private:
	Room* rooms[MAX_ROOMS];
	int numRooms;

	//public member functions for this class
public:
	Hotel();
	~Hotel();
	bool addRoom(int roomNumber, string bedType, int capacity, bool fr);
	bool deleteRoom(int roomNumber);
	bool getRoom(int roomNumber, Room** room);
	bool addReservation(string customer, string bedType, int capacity, bool fr, Date& date, int duration);
	void print();
	void printReservations();
	void updateReservations(Date& currentDate);
};

#endif
