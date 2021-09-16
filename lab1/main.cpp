#include "hotel.h"
#include <iostream>

using namespace hotelSystem;
using namespace std;

int main() {
	Hotel hotel(1, "Intercontinental", "Ukraine", "Kyiv", "Poshtova Sqr", 5);
	cout << hotel.getCode() << endl;
}
