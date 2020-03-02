// Name:Mitchell Culligan
// Seneca Student ID: 161293170
// Seneca email: mculligan@myseneca.ca
// Date of completion: Nov 24th 2019
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include"CustomerOrder.h"

size_t CustomerOrder::m_widthField;

CustomerOrder::CustomerOrder(): m_name(""), m_product(""),
m_cntItem(0), m_lstItem(nullptr){}

CustomerOrder::CustomerOrder(const std::string& str): m_cntItem(0),
m_lstItem(nullptr){
	std::queue<std::unique_ptr<ItemInfo>> items;//in case of exception unique_ptr
	size_t pos = 0;
	Utilities util;
	bool more = true;
	this->m_name = util.extractToken(str, pos, more);
	this->m_product = util.extractToken(str, pos, more);
	while (more) {
		items.push(std::make_unique<ItemInfo>(util.extractToken(str, pos, more)));
	}		
	this->m_cntItem = items.size();
	this->m_lstItem = new ItemInfo*[this->m_cntItem];
	for (int i = 0; i < m_cntItem; i++) {
		this->m_lstItem[i] = items.front().release();
		items.pop();
	}
	CustomerOrder::m_widthField = CustomerOrder::m_widthField > util.getFieldWidth() ?
			CustomerOrder::m_widthField : util.getFieldWidth();
	
}
CustomerOrder::CustomerOrder(const CustomerOrder& src) {
	throw std::exception();
}

CustomerOrder& CustomerOrder::operator=(CustomerOrder&& src) {
	if (this != &src) {
		delete[] this->m_lstItem;
		this->m_name = src.m_name;
		this->m_product = src.m_product;
		this->m_lstItem = src.m_lstItem;
		this->m_cntItem = src.m_cntItem;
		src.m_name = "";
		src.m_product = "";
		src.m_lstItem = nullptr;
		src.m_cntItem = 0;
	}

	return *this;
}

CustomerOrder::CustomerOrder(CustomerOrder&& src)noexcept{
	this->m_lstItem = nullptr;
	*this = std::move(src);
}

CustomerOrder::~CustomerOrder() {
	for(int i=0; i<this->m_cntItem;i++)
		delete this->m_lstItem[i];
	delete[] this->m_lstItem;
	this->m_lstItem = nullptr;
	this->m_cntItem = 0;
}

bool CustomerOrder::getItemFillState(const std::string item)const {
	bool full = true;
	for (int i = 0; i < this->m_cntItem; i++)
		if(this->m_lstItem[i]->m_itemName == item) {
            full = this->m_lstItem[i]->m_fillState;
                    break;
        }
	return full;
}

bool CustomerOrder::getOrderFillState()const {
	bool full = true;
	for (int i = 0; i < this->m_cntItem && full; i++) {
		full = getItemFillState(this->m_lstItem[i]->m_itemName);
	}
	return full;
}


void CustomerOrder::fillItem(Item& item, std::ostream& os) {
	bool full = false;
	const char* messages[] { "Unable to fill","Filled" };
	for (int i = 0; i < this->m_cntItem; i++) {
		if (this->m_lstItem[i]->m_itemName == item.getName()) {
			if (item.getQuantity() > 0) {
				item.updateQuantity();
				this->m_lstItem[i]->m_serialNumber = item.getSerialNumber();
				this->m_lstItem[i]->m_fillState = true;
				full = true;
			}
			else
				full = false;
			
			os << messages[full ? 1 : 0]
				<< " " << this->m_name << ", " << this->m_product << "["
				<< item.getName() << "]" << std::endl;
		}
	}
}

void CustomerOrder::display(std::ostream& os)const {
	
	os << this->m_name << " - " << this->m_product << std::endl;
	for (int i = 0; i < this->m_cntItem; i++) {
		os << "[" <<std::right<< std::setw(6) << std::setfill('0')
			<< this->m_lstItem[i]->m_serialNumber << "]"
			<< " " << std::left << std::setfill(' ') << std::setw(this->m_widthField)
			<< this->m_lstItem[i]->m_itemName
			<< " - " << (this->m_lstItem[i]->m_fillState ? "FILLED" : "MISSING")
			<< std::endl;
	}
}