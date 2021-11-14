#include <iostream>
#include <vector>
#include <string>
#include "menu/menu.h"
#include "hotel/hotel.h"

using namespace std;
using namespace hotelSystem;

void loadHotels(vector<Hotel>& hotels);

int main() {
	vector<Hotel> hotels;

	loadHotels(hotels);


	Menu::Item items[] = {
            Menu::Item("Add a hotel", [&hotels]() {
                
            }),
            Menu::Item("Raise a hotel's rating", [&hotels]() {
                
            }),
	    Menu::Item("Lower a hotel's rating", [&hotels]() {
                
            }),
	    Menu::Item("Remove a hotel", [&hotels]() {
                
            }),
	    Menu::Item("Get hotel info", [&hotels]() {
                cout << "Input hotel name: ";
		string name;
		cin >> name;
		
            }),
	    Menu::Item("List all hotels", [&hotels]() {
                for (auto &hotel : hotels) 
		{  
   			cout << hotel.getName() << endl;
		}
            }),
            Menu::Item("Exit", []() {}, true)
    };
    Menu menu(items, 7);
    menu.showItems();
    menu.askForSelection();
}

void loadHotels(vector<Hotel>& hotels) {
	Hotel hotel(1, "Intercontinental", "Ukraine", "Kyiv", "Poshtova Sqr", 5);
	hotel.setContactName("Sabina");
	hotel.setContactSurname("Carpenter");
	hotel.setContactPhone("+380444206969");
	hotels.push_back(hotel);

	
	Hotel hotel2(2, "Beach View", "USA", "Miami", "Taras Shevchenko Str", 4);
	hotel2.setContactName("Sheev");
	hotel2.setContactSurname("Palpatine");
	hotel2.setContactPhone("+187644507623");
	hotels.push_back(hotel2);
}
