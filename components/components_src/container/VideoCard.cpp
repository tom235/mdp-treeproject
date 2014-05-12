#include "VideoCard.h"


VideoCard::VideoCard()
{
}

VideoCard::VideoCard(std::string name, std::string producer, std::string chipset, int ram)
{
	this->name = name;
	this->producer = producer;
	this->chipset = chipset;
	this->ram = ram;
}

std::string VideoCard::getName()
{
	return name;
}
std::string VideoCard::getProducer()
{
	return producer;
}
std::string VideoCard::getChipset()
{
	return chipset;
}
int VideoCard::getRam()
{
	return ram;
}

void VideoCard::setName(std::string name)
{
	this->name = name;
}
void VideoCard::setProducer(std::string producer)
{
	this->producer = producer;
}
void VideoCard::setChipset(std::string chipset)
{
	this->chipset = chipset;
}
void VideoCard::setRam(int ram)
{
	this->ram = ram;
}

std::ostream& operator<<(std::ostream& os, const VideoCard& vc)
{
    os << "Видеокарта[название:" << vc.name << ",производитель:" << vc.producer << ",чипсет:" << vc.chipset<< ",объем памяти:" << vc.ram << "]";
	return os;
}



VideoCard::~VideoCard()
{
}
