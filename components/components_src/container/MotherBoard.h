#ifndef MB_H
#define MB_H

#include<string>
#include <iostream>

class MotherBoard
{
private:
    std::string name;
    std::string producer;
    std::string ramType;
	int maxAmountMemory;
public:
	MotherBoard();

    MotherBoard(std::string name, std::string producer, std::string ramType, int maxAmountMemory);

    std::string getProducer();
    std::string getRamType();
	int getMaxAmountMemory();

    void setProducer(std::string);
	void setMaxAmountMemory(int);
    void setRamType(std::string);
    std::string getName();

	friend std::ostream& operator<<(std::ostream& os, const MotherBoard& dt);

	~MotherBoard();
};
#endif
