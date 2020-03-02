// Name:Mitchell Culligan
// Seneca Student ID: 161293170
// Seneca email: mculligan@myseneca.ca
// Date of completion: DEC 1st 2019
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include"Task.h"

Task::Task(const std::string& str) : Item(str), m_pNextTask(nullptr) {}

void Task::runProcess(std::ostream& os) {
	
	if (!this->m_orders.empty()) 
		if (!this->m_orders.back().getItemFillState(Item::getName())) 
			this->m_orders.back().fillItem(*this, os);
		
	
}

bool Task::moveTask() {
	bool full = false;

	if (this->NextTask()!=nullptr&&!this->m_orders.empty()&&this->m_orders.back().getItemFillState(Item::getName())) {
		full = true;
		*this->NextTask() += std::move(this->m_orders.back());
		this->m_orders.pop_back();
		
	}
	return full;

}

void Task::setNextTask(Task& task) {
	this->m_pNextTask = &task;
}

bool Task::getCompleted(CustomerOrder&& order) {
	bool full = false;
	if (!this->m_orders.empty()&& 
		this->m_orders.back().getOrderFillState()) 
	{
		full = true;
		order = std::move(this->m_orders.back());
		this->m_orders.pop_back();
	}
	return full;
}

void Task::validate(std::ostream& os) {
	os << Item::getName()<<"-->"<< (this->m_pNextTask == nullptr ?
		"END OF LINE" : this->m_pNextTask->getName()) << std::endl;
	

}
Task& Task::operator+=(CustomerOrder&& order) {
	this->m_orders.push_front(std::move(order));
	return *this;
}


Task* Task::NextTask()const{
	return this->m_pNextTask;
}