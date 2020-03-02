#pragma once
// Name:Mitchell Culligan
// Seneca Student ID: 161293170
// Seneca email: mculligan@myseneca.ca
// Date of completion: DEC 1st 2019
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include"Task.h"
#include<vector>
#include<fstream>
#include<algorithm>
#ifndef LINE_MANAGER_H
#define LINE_MANAGER_H
class LineManager {
	std::vector<Task*> AssemblyLine;
	std::deque<CustomerOrder> ToBeFilled;
	std::deque<CustomerOrder> Completed;
	unsigned int m_cntCustomerOrder;
	Task* nodeStart;
public:
	LineManager(const std::string&, std::vector<Task*>&, std::vector<CustomerOrder>&);
	bool run(std::ostream&);
	void displayCompleted(std::ostream&)const;
	void validateTasks()const;

};
#endif