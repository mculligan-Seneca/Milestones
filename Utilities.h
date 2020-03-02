#pragma once
// Name:Mitchell Culligan
// Seneca Student ID: 161293170
// Seneca email: mculligan@myseneca.ca
// Date of completion: Nov 17th 2019
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include<string>


#ifndef UTIL_H
#define UTIL_H
class Utilities {
	size_t m_widthField{ 1 };
	static char m_delimiter;
public:
	void setFieldWidth(size_t);
	size_t getFieldWidth()const;
	const std::string extractToken(const std::string& str, size_t& pos, bool& more);
	static void setDelimiter(const char);
	const char getDelimiter()const;
};

#endif