#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>
#include "menu/menu.h"
#include "hotel/hotel.h"

using namespace std;
using namespace hotelSystem;

void loadHotels(vector <Hotel> &hotels);
string inputHotelName();
Hotel *findHotelByName(vector<Hotel> &hotels, string &name);
Hotel inputHotelData(unsigned nextCode);
string inputWithPrompt(const string& prompt);

void raiseHotelRating(vector<Hotel> &hotels);
void lowerHotelRating(vector<Hotel> &hotels);
void removeHotel(vector<Hotel> &hotels);

int main() {
    vector <Hotel> hotels;

    loadHotels(hotels);

    Menu::Item items[] = {
        Menu::Item("Add a hotel", [&hotels]() {
            hotels.push_back(inputHotelData(hotels.size() + 1));
            cout << "A hotel was successfully added" << endl;
        }),
        Menu::Item("Raise a hotel's rating", [&hotels]() {
            raiseHotelRating(hotels);
        }),
        Menu::Item("Lower a hotel's rating", [&hotels]() {
            lowerHotelRating(hotels);
        }),
        Menu::Item("Remove a hotel", [&hotels]() {
            removeHotel(hotels);
        }),
        Menu::Item("Get hotel info", [&hotels]() {
            string name = inputHotelName();
            Hotel *hotel = findHotelByName(hotels, name);
            if (hotel) printHotel(*hotel);
        }),
        Menu::Item("List all hotels", [&hotels]() {
            for (auto &hotel: hotels) {
                cout << hotel.getName() << endl;
            }
        }),
        Menu::Item("Exit", []() {}, true)
    };
    Menu menu(items, 7);
    menu.showItems();
    menu.askForSelection();
}

void loadHotels(vector <Hotel> &hotels) {
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

string inputHotelName() {
    return inputWithPrompt("Input hotel name: ");
}

string inputWithPrompt(const string& prompt) {
    cout << prompt;
    string data;
    getline(cin, data);
    return data;
}

Hotel *findHotelByName(vector<Hotel> &hotels, string &name) {
    for (auto &hotel: hotels) {
        if (hotel.getName() == name) {
           return &hotel;
        }
    }
    cout << "Couldn't find that hotel" << endl;
    return nullptr;
}

Hotel inputHotelData(unsigned nextCode) {
    string name = inputHotelName();
    string city = inputWithPrompt("City: ");
    string country = inputWithPrompt("Country: ");
    string address = inputWithPrompt("Address: ");
    int stars = stoi(inputWithPrompt("Stars: "));

    Hotel hotel(nextCode, name, country, city, address, stars);
    return hotel;
}

void raiseHotelRating(vector<Hotel> &hotels) {
    string name = inputHotelName();
    Hotel *hotel = findHotelByName(hotels, name);
    if (hotel) {
        if (hotel->getStars() == 5) {
            cout << "This hotel is already rated 5 stars" << endl;
        } else {
            hotel->setStars(hotel->getStars() + 1);
            cout << hotel->getName() + " is now rated " << hotel->getStars() << " stars" << endl;
        }
    }
}

void lowerHotelRating(vector<Hotel> &hotels) {
    string name = inputHotelName();
    Hotel *hotel = findHotelByName(hotels, name);
    if (hotel) {
        if (hotel->getStars() == 1) {
            cout << "This hotel is already rated 1 star" << endl;
        } else {
            hotel->setStars(hotel->getStars() - 1);
            cout << hotel->getName() + " is now rated " << hotel->getStars() << " stars" << endl;
        }
    }
}

void removeHotel(vector<Hotel> &hotels) {
    string name = inputHotelName();
    bool deleted = false;
    for (auto hotelItr = hotels.begin(); hotelItr != hotels.end(); hotelItr++) {;
        if (hotelItr->getName() == name) {
            hotels.erase(hotelItr);
            deleted = true;
            cout << name << " has been obliterated" << endl;
            break;
        }
    }
    if (!deleted) cout << "Could not find such hotel" << endl;
}