#include "Room.h"

//parameterized constructor of room class
Room::Room(int roomNum, string bedtp, int cap, bool fridge)
{
	numReservations = 0;
	roomNumber = roomNum;
	bedType = bedtp;
	capacity = cap;
	hasFridge = fridge;
}


//destructor to delete any dynamic allocated memory
Room::~Room()
{
	for (int i = 0; i < numReservations; i++)
		delete reservations[i];
}

//function to return room number
int Room::getRoomNumber()
{
	return roomNumber;
}

//function that return true or false after matching room types,capacity and fridge
bool Room::isMatch(string bt, int cap, bool f)
{
	if (bedType == bt && capacity >= cap)
	{
		if (f == true && hasFridge == false)
			return false;
		else
			return true;
	}

	return false;
}

//this function returns true if current room number is less than parameter's room number
bool Room::lessThan(Room& r)
{
	if (this->roomNumber < r.roomNumber)
		return true;
	else
		return false;
}

//this function add a reservation to the room
bool Room::addReservation(string name, Date& d, int duration)
{
	//check if room have capacity to add reservation otherwise return false
	if (MAX_RES == numReservations)
		return false;

	bool checkoverlap = false;
	Reservation obj(name, d, duration);
	//loop to check if the date of reservation overlaps with any previous reservation for room
	for (int i = 0; i < numReservations; i++)
	{
		if (reservations[i]->overlaps(obj))
		{
			checkoverlap = true;
		}
	}

	//if there is overlap return false;
	if (checkoverlap)
		return false;

	//otherwise add the reservation in sorted manner by date and return true
	int i;
	for (i = numReservations - 1; (i >= 0 && obj.lessThan(*reservations[i])); i--) {
		reservations[i + 1] = reservations[i];
	}

	Reservation* newReservation = new Reservation(name, d, duration);
	reservations[i + 1] = newReservation;


	numReservations++;
	return true;
}

//A simple function to print room data on console
void Room::print()
{
	cout << "Room Number: " << roomNumber << "\nBed Type: " << bedType << "\n"
		<< "Capacity: " << capacity << "\n";
	if (hasFridge)
		cout << "Fridge: Yes\n";
	else
		cout << "Fridge: No\n";
}

//A simple function to print room data on console with reservations
void Room::printReservations()
{
	cout << "Room Number: " << roomNumber << "\nBed Type: " << bedType << "\n"
		<< "Capacity: " << capacity << "\n";
	if (hasFridge)
		cout << "Fridge: Yes\n";
	else
		cout << "Fridge: No\n";

	cout << "Reservations:\n";
	for (int i = 0; i < numReservations; i++)
		reservations[i]->print();
}

//this function removes all the reservations that are less than currentDate
void Room::updateReservations(Date& currentDate)
{
	for (int i = 0; i < numReservations; i++)
	{
		//if the reservation is less than current date
		if (reservations[i]->lessThan(currentDate))
		{
			//delete it and move the next reservations one index behind each other
			delete reservations[i];
			for (int j = i; j < (numReservations - 1); j++)
				reservations[j] = reservations[j + 1];
			
			i--;
			numReservations--;
		}
	}
}