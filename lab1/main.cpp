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

	
	Hotel *hotel2 = new Hotel(2, "Beach View", "USA", "Miami", "Taras Shevchenko Str", 5);
	hotel2->setContactName("Sheev");
	hotel2->setContactSurname("Palpatine");
	hotel2->setContactPhone("+187644507623");
	printHotel(hotel2);
	delete hotel2;
}
