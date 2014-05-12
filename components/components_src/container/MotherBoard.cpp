#include "MotherBoard.h"


MotherBoard::MotherBoard()
{
}

MotherBoard::MotherBoard(std::string name, std::string producer, std::string ramType, int maxAmountMemory)
{
	this->name = name;
	this->producer = producer;
	this->ramType = ramType;
	this->maxAmountMemory = maxAmountMemory;
}

std::string MotherBoard::getName()
{
	return name;
}

std::string MotherBoard::getProducer()
{
	return producer;
}
std::string MotherBoard::getRamType()
{
	return ramType;
}
int MotherBoard::getMaxAmountMemory()
{
	return maxAmountMemory;
}

void MotherBoard::setProducer(std::string producer)
{
	this->producer = producer;
}
void MotherBoard::setMaxAmountMemory(int maxAmountMemory)
{
	this->maxAmountMemory = maxAmountMemory;
}

void MotherBoard::setRamType(std::string ramType)
{
	this->ramType = ramType;
}

std::ostream& operator<<(std::ostream& os, const MotherBoard& mb)
{
    os << "Материнская плата[название:" << mb.name << ",производитель:" << mb.producer << ",тип памяти:" << mb.ramType << ",максимальный объем памяти:" << mb.maxAmountMemory << "]";
	return os;
}


MotherBoard::~MotherBoard()
{
}
