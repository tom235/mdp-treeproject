#ifndef COIN_H
#define COIN_H
#include <vector>
#include <string>
#include "Cpu.h"
#include "MotherBoard.h"

#include"VideoCard.h"
#include "Ram.h"
#include <stdlib.h>

#include "QRegExp"
#include <iostream>
#include <fstream>
#include"exception/FileFormatException.h"

class ComponentOutIn
{
public:

    static void writeComponents(std::vector<Ram> rams, std::vector<VideoCard> videoCards, std::vector<MotherBoard> mrBorads, std::vector<Cpu> cpus, const char* fileName);
    static void readComponents(std::vector<Ram>& rams, std::vector<VideoCard>& videoCards, std::vector<MotherBoard>& mrBorads, std::vector<Cpu>& cpus, const char* fileName) throw(FileFormatException) ;

};

void ComponentOutIn::readComponents(std::vector<Ram>& rams, std::vector<VideoCard>& videoCards, std::vector<MotherBoard>& mrBorads, std::vector<Cpu>& cpus,const char* fileName) throw(FileFormatException)
{
    QRegExp motherRegex("Материнская плата\\[название:(\\w+|\\d+),производитель:(\\w+|\\d+),тип памяти:(\\w+|\\d+),максимальный объем памяти:(\\d+)\\]");
    QRegExp ramRegex("Оперативная память\\[название:(\\w+|\\d+),производитель:(\\w+|\\d+),тип:(\\w+|\\d+),частота:([0-9]*(\\.[0-9]+)?)\\]");
    QRegExp cpuRegex("Процессор\\[название:(\\w+|\\d+),производитель:(\\w+|\\d+),Количество ядер:(\\d+),частота:([0-9]*(\\.[0-9]+)?)\\]");
    QRegExp vcRegex("Видеокарта\\[название:(\\w+|\\d+),производитель:(\\w+|\\d+),чипсет:(\\w+),объем памяти:(\\d+)\\]");


    std::ifstream myfile(fileName);

    if (myfile.is_open())
    {
        std::string str;
        int lineCounter=0;
        while (std::getline(myfile,str))
        {
            int pos = motherRegex.indexIn(QString::fromStdString(str));
            if(pos == 0){
                QString name = motherRegex.cap(1).trimmed();
                QString pr = motherRegex.cap(2).trimmed();
                QString type = motherRegex.cap(3).trimmed();
                int amount = motherRegex.cap(4).toInt();
                std::cout << name.toStdString() << "\n";
                std::cout << pr.toStdString() << "\n";
                std::cout << type.toStdString() << "\n";
                std::cout <<  amount<< "\n";
                MotherBoard mother(name.toStdString(),pr.toStdString(),type.toStdString(),amount);
                lineCounter++;
                mrBorads.push_back(mother);
                continue;
            }
            pos = ramRegex.indexIn(QString::fromStdString(str));
            if(pos == 0){
                QString name = ramRegex.cap(1).trimmed();
                QString pr = ramRegex.cap(2).trimmed();
                QString type = ramRegex.cap(3).trimmed();
                float freq = ramRegex.cap(4).toFloat();
                std::cout << name.toStdString() << "\n";
                std::cout << pr.toStdString() << "\n";
                std::cout << type.toStdString() << "\n";
                std::cout <<  ramRegex.cap(4).toFloat()<< "\n";

                Ram ram(name.toStdString(),pr.toStdString(),type.toStdString(),freq);
                lineCounter++;
                rams.push_back(ram);
                continue;
            }
            pos = vcRegex.indexIn(QString::fromStdString(str));
            if(pos == 0){
                QString name = vcRegex.cap(1).trimmed();
                QString pr = vcRegex.cap(2).trimmed();
                QString chipset = vcRegex.cap(3);
                int ram = vcRegex.cap(4).toFloat();
                std::cout << name.toStdString() << "\n";
                std::cout << pr.toStdString() << "\n";
                std::cout << chipset.toStdString() << "\n";
                std::cout <<  ram<< "\n";

                VideoCard vc(name.toStdString(),pr.toStdString(),chipset.toStdString(),ram);
                lineCounter++;
                videoCards.push_back(vc);
                continue;
            }
            pos = cpuRegex.indexIn(QString::fromStdString(str));
            if(pos == 0){
                QString name = cpuRegex.cap(1).trimmed();
                QString pr = cpuRegex.cap(2).trimmed();
                int coreAmount = cpuRegex.cap(3).toInt();
                float freq = cpuRegex.cap(4).toFloat();
                std::cout << name.toStdString() << "\n";
                std::cout << pr.toStdString() << "\n";
                std::cout << coreAmount << "\n";
                std::cout <<  freq<< "\n";

                Cpu cpu(name.toStdString(),pr.toStdString(),coreAmount,freq);
                lineCounter++;
                cpus.push_back(cpu);
                continue;
            }
            throw FileFormatException(QString::number(lineCounter));
        }
    }
    myfile.close();


}

void ComponentOutIn::writeComponents(std::vector<Ram> rams, std::vector<VideoCard> videoCards, std::vector<MotherBoard> mrBorads, std::vector<Cpu> cpus,const char* fileName)
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

#endif
