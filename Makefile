all: out

out: main.o Hotel.o Room.o Reservation.o Date.o
		g++ -o out main.o Hotel.o Room.o Reservation.o Date.o
Hotel.o: Hotel.h Hotel.cc
		g++ -c Hotel.cc
Room.o: Room.h Room.cc
		g++ -c Room.cc
Reservation.o: Reservation.h Reservation.cc
		g++ -c Reservation.cc
Date.o: Date.h Date.cc
		g++ -c Date.cc
main.o: main.cc
		g++ -c main.cc

clean:
		rm -f main.o Hotel.o Room.o Reservation.o Date.o out