// Name:Mitchell Culligan
// Seneca Student ID: 161293170
// Seneca email: mculligan@myseneca.ca
// Date of completion: Nov 17th 2019
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#pragma once
#include"Utilities.h"
#include<iostream>
#include<iomanip>
#ifndef ITEM_H
#define ITEM_H

class Item {
	std::string m_name;
	std::string m_description;
	size_t m_serialNumber;
	size_t m_quantity;
	static  size_t m_widthField;
public:

	Item(const std::string&);
	const std::string& getName() const;
	const unsigned int getSerialNumber();
	const unsigned int getQuantity()const;
	void updateQuantity();
	void display(std::ostream&, bool)const;
};
#endif