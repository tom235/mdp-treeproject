#include "Cpu.h"


Cpu::Cpu()
{
}


Cpu::Cpu(std::string name, std::string produce, float frequence, int coreAmount)
{
	this->name = name;
	this->producer = produce;
	this->frequence = frequence;
	this->coreAmount = coreAmount;
}

std::string Cpu::getName()
{
	return name;
}

int Cpu::getCoreAmount()
{
	return coreAmount;
}
void Cpu::setCoreAmount(int amount)
{
	this->coreAmount = amount;
}

float Cpu::getFrequnce()
{
	return frequence;
}
void Cpu::setFrequnce(float frequence)
{
	this->frequence = frequence;
}

std::string Cpu::getProducer()
{
	return producer;
}
void Cpu::setProducer(std::string producer)
{
	this->producer = producer;
}

std::ostream& operator<<(std::ostream& os, const Cpu& cp)
{
	os << "CPU[name:" << cp.name <<",producer:" << cp.producer << ",coreAmount:" << cp.coreAmount << ",frequence:" << cp.frequence << "]";
	return os;
}


Cpu::~Cpu()
{
}
