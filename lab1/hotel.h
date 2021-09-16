#include<string>

namespace hotelSystem {

	class Hotel {
	public:
		Hotel(int code, std::string name, std::string country, std::string city, std::string address, int stars);
		

		int getCode() { return code; }
		void setCode(int code) { this->code = code; }

	private:
		int code;
		std::string name;
		std::string country, city, address;
		int stars;
		std::string contactName, contactPatronymic, contactSurname, contactPhone;

	};

}
