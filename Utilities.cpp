// Name:Mitchell Culligan
// Seneca Student ID: 161293170
// Seneca email: mculligan@myseneca.ca
// Date of completion: Nov 17th 2019
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include"Utilities.h"

char Utilities::m_delimiter;

void Utilities::setFieldWidth(size_t fieldWidth) {
	this->m_widthField = fieldWidth;
}

size_t Utilities::getFieldWidth()const {
	return this->m_widthField;
}

 void Utilities::setDelimiter(const char delim) {
	 m_delimiter = delim;
}

 const char Utilities::getDelimiter()const {
	 return m_delimiter;
 }

 const std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more) {
	
	 std::string token;
	 size_t end_pos;
	 if (next_pos < str.size() ) {
		 token = str.substr(next_pos);
		 end_pos = token.find(this->m_delimiter);
		 if (size_t(end_pos) != std::string::npos) {//maybe err
			 token.erase(end_pos);
			 next_pos += end_pos + 1;
			 more = true;
		 }
		 else {
			 more = false;
			 next_pos += token.size();
		 }

	 }
	 if (token.empty() && more) {
		 more = false;
		 throw "Bad Token";
	 }


	 if (this->m_widthField < token.length())
		 setFieldWidth(token.length());
	 return token;
 }