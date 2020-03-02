#pragma once
// Name:Mitchell Culligan
// Seneca Student ID: 161293170
// Seneca email: mculligan@myseneca.ca
// Date of completion: DEC 1st 2019
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include"Item.h"
#include "CustomerOrder.h"
#include<deque>
#ifndef TASK_H
#define TASK_H

class Task:public Item
{
	std::deque<CustomerOrder> m_orders;
	Task* m_pNextTask;
public:
	Task(const std::string&);
	Task(const Task&) = delete;
	Task(Task&&) = delete;
	Task& operator=(const Task&) = delete;
	Task& operator=(Task&&) = delete;
	void runProcess(std::ostream&);
	bool moveTask();
	void setNextTask(Task&);
	bool getCompleted(CustomerOrder&&);
	void validate(std::ostream&);
	Task* NextTask()const;
	Task& operator+=(CustomerOrder&&);
};
#endif