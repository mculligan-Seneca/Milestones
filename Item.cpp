// Name:Mitchell Culligan
// Seneca Student ID: 161293170
// Seneca email: mculligan@myseneca.ca
// Date of completion: Nov 17th 2019
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include"Item.h"

size_t Item::m_widthField{ 1 };

Item::Item(const std::string& str) {
	Utilities util;
	size_t pos = 0;
	bool flag;
	
		this->m_name = util.extractToken(str, pos, flag);
		this->m_serialNumber = std::stoi(util.extractToken(str, pos, flag));
		this->m_quantity = std::stoi(util.extractToken(str, pos, flag));
		this->m_description = util.extractToken(str, pos, flag);
		Item::m_widthField = Item::m_widthField > this->m_name.length() ?
			Item::m_widthField : this->m_name.length();

}



const std::string& Item::getName()const { return this->m_name; }

const unsigned int Item::getSerialNumber() {
	return ++this->m_serialNumber;
}


const unsigned int Item::getQuantity() const {
	return this->m_quantity;
}

void Item::updateQuantity() {
	if (this->m_quantity > 0)
		this->m_quantity--;
}

void Item::display(std::ostream& os, bool full)const {
	
	os << std::left<<std::setfill(' ')<<std::setw(this->m_widthField) << this->m_name;
	
		os<<" ["<<std::right<<std::setw(6)<<std::setfill('0')
	    <<this->m_serialNumber<<"] ";
		
	
	if (full) {
		os << "Quantity: " << std::setw(Item::m_widthField) << std::setfill(' ')
			<<std::left<< this->m_quantity;
		os.clear();
		os<< " Description: " << this->m_description;
	}
	
	os << std::endl;
	
}