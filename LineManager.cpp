// Name:Mitchell Culligan
// Seneca Student ID: 161293170
// Seneca email: mculligan@myseneca.ca
// Date of completion: DEC 1st 2019
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include "LineManager.h"

LineManager::LineManager(const std::string& fileName, std::vector<Task*>& tasks, std::vector<CustomerOrder>& toFillOrders):
nodeStart(nullptr){
	std::ifstream fin(fileName);
	std::string line;
	bool more;
	bool flag;
	size_t pos;
	Utilities util;
	std::string token;
	std::vector<Task*>::iterator curr , next;
	auto findPos = [&token](Task* task){
	    return token == task->getName();
	};

	    Utilities::setDelimiter('|');
		if (fin.is_open()) {

			while (std::getline(fin, line, '\n')) {
				more = true;
				pos = 0;
				flag = false;
              // curr = std::end(tasks);
				if (fin) {

                        token = util.extractToken(line, pos, more);
                    curr  = std::find_if(std::begin(tasks), std::end(tasks), findPos);
                    if(!this->nodeStart) this->nodeStart= *curr;

                        if (curr!=std::end(tasks)) {
                          next  = std::find_if(std::begin(tasks), std::end(tasks), findPos);
                            if (next != std::end(tasks)) {
                                (*curr)->setNextTask(*(*next));
                                curr=std::move(next);
                            }
                        }



				}
					
			}

			for (auto itr = toFillOrders.begin(); itr != toFillOrders.end(); itr++)
				this->ToBeFilled.push_front(std::move(*itr));

			this->AssemblyLine = tasks;
			this->m_cntCustomerOrder = this->ToBeFilled.size();
		}
		else
			throw "Error";
	

	
	
}


bool LineManager::run(std::ostream& os) {
	bool done = false;
	Task* found = nullptr;
	CustomerOrder order;
	
	
	if (!this->ToBeFilled.empty()) {

		// while (node != nullptr && !flag) {
			// if (this->ToBeFilled.back().getItemFillState(node->getName()))
			// {
		*this->nodeStart += std::move(this->ToBeFilled.back());
		this->ToBeFilled.pop_back();
	
		// }
		//else
		 //node = node->getNextTask();
	 }

		for (auto itr = this->AssemblyLine.begin(); itr != this->AssemblyLine.end(); itr++)
			(*itr)->runProcess(os);

		for (auto itr = this->AssemblyLine.begin(); itr != this->AssemblyLine.end(); itr++) {
           if (!(*itr)->moveTask()){
               if ((*itr)->getCompleted(std::move(order))) {
                   this->Completed.push_back(std::move(order));
               }
           }
        }



		//for (auto itr = this->AssemblyLine.begin();itr != this->AssemblyLine.end(); itr++) {

	//	}

	

		done = this->Completed.size() == this->m_cntCustomerOrder;//if all customers have been filled
		
	

	return done;
}
void LineManager::displayCompleted(std::ostream& os)const {

	for (auto itr = this->Completed.begin(); itr != this->Completed.end(); itr++)
			itr->display(os);
}
void LineManager::validateTasks()const {

	for (auto itr = this->AssemblyLine.begin(); itr != this->AssemblyLine.end(); itr++)
		(*itr)->validate(std::cout);
}