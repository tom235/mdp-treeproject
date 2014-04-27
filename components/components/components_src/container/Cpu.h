#ifndef CPU_H
#define CPU_H

#include<string>
#include <iostream> 


class Cpu
{
private:
	std::string name;
	std::string producer;
	float frequence;
	int coreAmount;


public:
	Cpu();
	Cpu(std::string name, std::string produce, float frequence, int coreAmount);


	int getCoreAmount();
	void setCoreAmount(int);

	std::string getName();
	float getFrequnce();
	void setFrequnce(float);

	std::string getProducer();
	void setProducer(std::string);
	friend std::ostream& operator<<(std::ostream& os, const Cpu& dt);

	~Cpu();
};

#endif
