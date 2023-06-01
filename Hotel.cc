#include "Hotel.h"

//default constructor
Hotel::Hotel()
{
	numRooms = 0;
}


//destructor to deallocate dynamic memory
Hotel::~Hotel()
{
	for (int i = 0; i < numRooms; i++)
	{
		delete rooms[i];
	}
}

//function to add room to a hotel
bool Hotel::addRoom(int roomNumber, string bedType, int capacity, bool fr)
{
	//check if there is still space to add a room, if not return false
	if (numRooms == MAX_ROOMS)
		return false;

	//check if there is already a room with same room number, if found returen false
	bool roomFound = false;
	for (int i = 0; i < numRooms; i++)
	{
		if (rooms[i]->getRoomNumber() == roomNumber)
			roomFound = true;
	}

	if (roomFound)
		return false;

	//or else add room in sorted order of room number and return true
	Room obj(roomNumber, bedType, capacity, fr);

	int i;
	for (i = numRooms - 1; (i >= 0 && obj.lessThan(*rooms[i])); i--) {
		rooms[i + 1] = rooms[i];
	}

	Room* newRoom = new Room(roomNumber, bedType, capacity, fr);
	rooms[i + 1] = newRoom;

	numRooms++;
	return true;
}

//this function removes a room with the room number from hotel rooms
bool Hotel::deleteRoom(int roomNumber)
{
	//find the index of room with the room number
	int index = -1;
	for (int i = 0; i < numRooms; i++)
	{
		if (rooms[i]->getRoomNumber() == roomNumber)
		{
			delete rooms[i];
			index = i;
		}
	}

	//if index is -1 that means no room is found so return false
	if (index == -1)
		return false;

	//else move all the rooms one index behind and return true
	for (int i = index; i < numRooms; i++)
	{
		rooms[i] = rooms[i + 1];
	}
	numRooms--;
	return true;
}

//this function returns true or false if a room is found with roomNumber
bool Hotel::getRoom(int roomNumber, Room** room)
{
	int index = -1;
	for (int i = 0; i < numRooms; i++)
	{
		if (rooms[i]->getRoomNumber() == roomNumber)
		{
			*room = rooms[i];
			index = i;
		}
	}

	if (index == -1)
		return false;
	return true;
}

//this function adds a reservation to a specific room of hotel
bool Hotel::addReservation(string customer, string bedType, int capacity, bool fr, Date& date, int duration)
{
	//Loop to find room with specific bedtype capacity and fridge
	int index = -1;
	for (int i = 0; i < numRooms; i++)
	{
		if (rooms[i]->isMatch(bedType, capacity, fr))
		{
			//if room is found add reservation to it
			index = i;
			bool check = rooms[i]->addReservation(customer, date, duration);
			return check;
		}
	}

	if (index == -1)
		return false;
}

//simple print function to print room data
void Hotel::print()
{
	for (int i = 0; i < numRooms; i++)
	{
		rooms[i]->print();
		cout << endl;
	}
}

//simple print function to print rooms data with every rooms specifications
void Hotel::printReservations()
{
	for (int i = 0; i < numRooms; i++)
	{
		rooms[i]->printReservations();
		cout << endl;
	}
}

//An update function that updates all the reservations of every room present
void Hotel::updateReservations(Date& currentDate)
{
	for (int i = 0; i < numRooms; i++)
	{
		rooms[i]->updateReservations(currentDate);
	}
}