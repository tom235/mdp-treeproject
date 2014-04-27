#ifndef VCARD_H
#define VCARD_H

#include<string>
#include <iostream> 

class VideoCard
{
private:
    std::string name;
    std::string producer;
    std::string chipset;
	int ram;

public:
	VideoCard();
    VideoCard(std::string name, std::string producer, std::string chipset, int ram);
    std::string getName();
    std::string getProducer();
    std::string getChipset();
	int getRam();

    void setName(std::string name);
    void setProducer(std::string producer);
    void setChipset(std::string chipset);
	void setRam(int ram);

	friend std::ostream& operator<<(std::ostream& os, const VideoCard& vc);

	~VideoCard();
};

#endif
