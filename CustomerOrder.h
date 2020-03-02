// Name:Mitchell Culligan
// Seneca Student ID: 161293170
// Seneca email: mculligan@myseneca.ca
// Date of completion: Nov 24th 2019
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#pragma once

#include"Item.h"
#include<string>
#include<queue>
#include<memory>
#include<iostream>
#ifndef  CUSTOM_ORDER_H
#define CUSTOM_ORDER_H
struct ItemInfo
{
	std::string m_itemName;
	unsigned int m_serialNumber = 0;
	bool m_fillState = false;

	ItemInfo(std::string src) : m_itemName(src) {};
};
class CustomerOrder {
	std::string m_name;
	std::string m_product;
	unsigned int m_cntItem;
	ItemInfo** m_lstItem;
	static size_t m_widthField;
public:
	CustomerOrder();
	CustomerOrder(const std::string&);
	CustomerOrder(const CustomerOrder&);
	CustomerOrder& operator=(const CustomerOrder&) = delete;
	CustomerOrder& operator=(CustomerOrder&&);
	CustomerOrder(CustomerOrder&&)noexcept;
	~CustomerOrder();
	bool getItemFillState(const std::string)const;
	bool getOrderFillState()const;
	void fillItem(Item&, std::ostream&);
	void display(std::ostream&)const;
};
#endif // ! CUSTUMOR_ORDER_H
