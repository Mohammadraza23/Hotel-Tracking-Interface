#include "Reservation.h"

//Parameterized constructor
Reservation::Reservation(string name, Date& date, int dur)
{
	customerName = name;
	checkIn = date;
	duration = dur;
}

//function to check if 2 reservations overlap with time
bool Reservation::overlaps(Reservation& r)
{
	Date date1(this->checkIn);
	Date date2(r.checkIn);

	//if dates of both reservations are equal then we return true as they overlap
	if (date1.equals(date2))
		return true;

	
	if (date1.lessThan(date2))
	{
		//if current date is less then add duration days to it
		date1.addDays(duration);
		//if current date is less than or equal to date2 then it does not overlap
		if (date1.lessThan(date2) || date1.equals(date2))
			return false;
		else
			return true;
	}
	else
	{
		//if date2 is less then add duration days to it
		date2.addDays(r.duration);
		//if date2 is less than or equal to current date then it does not overlap
		if (date2.lessThan(date1) || date2.equals(date1))
			return false;
		else
			return true;
	}

}

bool Reservation::lessThan(Reservation& res)
{
	//if both dates overlaps then this one is not less that the other so return false
	if (overlaps(res))
		return false;

	Date date1(this->checkIn);
	Date date2(res.checkIn);
	//if this date is less than the other date, add the duration and check
	//if it is still less of equal to other date, if so return true
	if (date1.lessThan(date2))
	{
		date1.addDays(duration);
		if (date1.lessThan(date2) || date1.equals(date2))
			return true;
		else
			return false;
	}

	return false;
}

bool Reservation::lessThan(Date& d)
{
	Date date1(this->checkIn);
	//if this date is less than the other date, add the duration and check
	//if it is still less of equal to other date, if so return true
	if (date1.lessThan(d))
	{
		date1.addDays(duration);
		if (date1.lessThan(d) || date1.equals(d))
			return true;
		else
			return false;
	}

	return false;
}

void Reservation::print()
{
	cout << "Reservation for " << customerName << " on " << checkIn.getMonthName() <<
		" " << checkIn.getDay() << ", " << checkIn.getYear() << " for " << duration << " days." << endl;;
}