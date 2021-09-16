#include"hotel.h"
#include<string>

namespace hotelSystem {
	
	Hotel::Hotel(int code, std::string name, std::string country, std::string city, std::string address, int stars) {
		this->code = code;
		this->name = name;
		this->country = country;
		this->city = city;
		this->address = address;
		this->stars = stars;
	}
	
}
