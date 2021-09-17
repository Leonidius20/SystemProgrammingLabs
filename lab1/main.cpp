#include "hotel.h"
#include <iostream>

using namespace hotelSystem;
using namespace std;

void printHotel(Hotel *hotel) {
	cout << "Hotel " << hotel->getName() << " " << hotel->getStars() << " stars" << endl;
	cout << "Location: " << hotel->getAddress() << ", " << hotel->getCity() << ", " << hotel->getCountry() << endl;
	cout << "Contact: " << hotel->getContactName() << " " << hotel->getContactPatronymic() << " " << hotel->getContactSurname() 
		<< ", phone: " << hotel->getContactPhone() << endl;
	cout << endl;
}

int main() {
	Hotel hotel(1, "Intercontinental", "Ukraine", "Kyiv", "Poshtova Sqr", 5);
	hotel.setContactName("Sabina");
	hotel.setContactSurname("Carpenter");
	hotel.setContactPhone("+380444206969");
	printHotel(&hotel);

	
	Hotel *hotel2 = new Hotel(2, "Beach View", "USA", "Miami", "Taras Shevchenko Str", 4);
	hotel2->setContactName("Sheev");
	hotel2->setContactSurname("Palpatine");
	hotel2->setContactPhone("+187644507623");
	printHotel(hotel2);

	int result = hotel.compareWith(hotel2);
	if (result == 0) cout << "Hotels are equivalent" << endl;
	if (result == -1) cout << hotel2->getName() << " is the superiour hotel" << endl;
	if (result == 1) cout << hotel.getName() << " is the superiour hotel" << endl;

	delete hotel2;
}
