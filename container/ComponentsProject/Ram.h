#pragma once

#include<string>
#include <iostream> 

class Ram
{
private:
	std::string name;
	std::string producer;
	std::string type;
	float frequence;
public:
	Ram();

	Ram(std::string name, std::string producer, std::string type, float frequence);


	std::string getName();
	std::string getProducer();
	std::string getType();
	float getFrequnce();


	void setName(std::string name);
	void setProducer(std::string producer);
	void setType(std::string);
	void setFrequnce(float);

	friend std::ostream& operator<<(std::ostream& os, const Ram& ram);

	~Ram();
};

