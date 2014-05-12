#include "Ram.h"


Ram::Ram()
{
}
Ram::Ram(std::string name, std::string producer, std::string type, float frequence)
{
	this->name = name;
	this->producer = producer;
	this->type = type;
	this->frequence = frequence;
}



std::string Ram::getName(){return name;}
std::string Ram::getProducer(){return producer;}
std::string Ram::getType(){ return type; }
float Ram::getFrequnce(){ return frequence; }


void Ram::setName(std::string name){ this->name = name; }
void Ram::setProducer(std::string producer){ this->producer = producer; }
void Ram::setType(std::string type){ this->type = type; }
void Ram::setFrequnce(float frequence){ this->frequence = frequence; }

std::ostream& operator<<(std::ostream& os, const Ram& ram)
{
    os << "Оперативная память[название:" << ram.name << ",производитель:" << ram.producer << ",тип:" << ram.type<< ",частота:" << ram.frequence << "]";
	return os;
}


Ram::~Ram()
{
}
