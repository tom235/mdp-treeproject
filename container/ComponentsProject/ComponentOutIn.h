#pragma once

#include <vector>
#include <string>
#include "Cpu.h"
#include "MotherBoard.h"
#include"VideoCard.h"
#include "Ram.h"

#include <iostream>
#include <fstream>


class ComponentOutIn
{
public:
	
	static void writeComponents(std::vector<Ram> rams, std::vector<VideoCard> videoCards, std::vector<MotherBoard> mrBorads, std::vector<Cpu> cpus, std::string fileName);
	static void readComponents(std::vector<Ram>& rams, std::vector<VideoCard>& videoCards, std::vector<MotherBoard>& mrBorads, std::vector<Cpu>& cpus, std::string fileName);

};

void ComponentOutIn::readComponents(std::vector<Ram>& rams, std::vector<VideoCard>& videoCards, std::vector<MotherBoard>& mrBorads, std::vector<Cpu>& cpus, std::string fileName)
{
	std::string vcStr = "VideoCard";
	std::string cpuStr = "CPU";
	std::string motherStr = "MotherBoard";
	std::string ramStr = "RAM";

	std::ifstream myfile(fileName);

	if (myfile.is_open())
	{
		std::string str;
		while (std::getline(myfile,str))
		{
			unsigned position = str.find(vcStr);
			if (position >= 0 && position < str.length())
			{
				int start = str.find(":");
				int end = str.find(",");
				int back = (end - 2) - start + 1;
				std::string name = str.substr(start + 1, back);
				start = str.find(":", end + 1);
				end = str.find(",", end + 1);
				back = (end - 2) - start + 1;
				std::string producer = str.substr(start + 1, back);
				start = str.find(":", end + 1);
				end = str.find(",", end + 1);
				back = (end - 2) - start + 1;
				std::string chipset = str.substr(start + 1, back);
				start = str.find(":", end + 1);
				end = str.find(",", end + 1);
				back = (end - 2) - start + 1;
				std::string ramStr = str.substr(start + 1, back);
				int ramAbount = atof(ramStr.c_str());

				VideoCard video(name, producer, chipset, ramAbount);
				videoCards.push_back(video);

				continue;
			}
			position = str.find(cpuStr);
			if (position >= 0 && position < str.length())
			{
				int start = str.find(":");
				int end = str.find(",");
				int back = (end - 2) - start + 1;
				std::string name = str.substr(start + 1, back);
				start = str.find(":", end + 1);
				end = str.find(",", end + 1);
				back = (end - 2) - start + 1;
				std::string producer = str.substr(start + 1, back);
				start = str.find(":", end + 1);
				end = str.find(",", end + 1);
				back = (end - 2) - start + 1;
				std::string coreStr = str.substr(start + 1, back);
				int coreAmount = atof(coreStr.c_str());
				start = str.find(":", end + 1);
				end = str.find(",", end + 1);
				back = (end - 2) - start + 1;
				std::string freqStr = str.substr(start + 1, back);
				float frequency = atof(freqStr.c_str());

				Cpu cp(name, producer, frequency, coreAmount);
				cpus.push_back(cp);
				
				continue;
			}
			position = str.find(motherStr);
			if (position >= 0 && position < str.length())
			{
				int start = str.find(":");
				int end = str.find(",");
				int back = (end - 2) - start + 1;
				std::string name = str.substr(start + 1, back);
				start = str.find(":", end + 1);
				end = str.find(",", end + 1);
				back = (end - 2) - start + 1;
				std::string producer = str.substr(start + 1, back);
				start = str.find(":", end + 1);
				end = str.find(",", end + 1);
				back = (end - 2) - start + 1;
				std::string ramType = str.substr(start + 1, back);
				start = str.find(":", end + 1);
				end = str.find(",", end + 1);
				back = (end - 2) - start + 1;
				std::string maxAmountStr = str.substr(start + 1, back);
				int maxAmount = atof(maxAmountStr.c_str());

				MotherBoard mother(name, producer, ramType, maxAmount);
				mrBorads.push_back(mother);
				continue;
		
			}
			position = str.find(ramStr);
			if (position >= 0 && position < str.length())
			{
				int start = str.find(":");
				int end = str.find(",");
				int back = (end - 2) - start + 1;
				std::string name = str.substr(start + 1, back);
				start = str.find(":",end + 1);
				end = str.find(",", end + 1);
				back = (end - 2) - start + 1;
				std::string producer = str.substr(start + 1, back);
				start = str.find(":", end + 1);
				end = str.find(",", end + 1);
				back = (end - 2) - start + 1;
				std::string type = str.substr(start + 1, back);
				start = str.find(":", end + 1);
				end = str.find(",", end + 1);
				back = (end - 2) - start + 1;
				std::string freqStr = str.substr(start + 1, back);
				float frequency = atof(freqStr.c_str());

				Ram ram(name, producer, type, frequency);
				rams.push_back(ram);
				continue;
			}
		}
	}
	myfile.close();


}

void ComponentOutIn::writeComponents(std::vector<Ram> rams, std::vector<VideoCard> videoCards, std::vector<MotherBoard> mrBorads, std::vector<Cpu> cpus, std::string fileName)
{

	std::ofstream out(fileName);

	for (int i = 0; i < rams.size(); i++)
	{
		//std::cout << rams[i] << std::endl;
		out << rams[i] << std::endl;

	}
	for (int i = 0; i < videoCards.size(); i++)
	{
		//std::cout << videoCards[i] << std::endl;
		out << videoCards[i] << std::endl;
	}
	for (int i = 0; i < mrBorads.size(); i++)
	{
		//std::cout << mrBorads[i] << std::endl;
		out << mrBorads[i] << std::endl;
	}
	for (int i = 0; i < cpus.size(); i++)
	{
		//std::cout << cpus[i] << std::endl;
		out << cpus[i] << std::endl;
	}
	out.close();

}


