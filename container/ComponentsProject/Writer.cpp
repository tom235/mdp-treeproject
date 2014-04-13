#include "Writer.h"
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;





void Writer::writeTree(string fileName,OATree<string>* tree){
	ofstream outFile(fileName);

	vector<OATree<string>> rootStack;
	rootStack.push_back(*tree);
	int i = 0;
	while (!rootStack.empty())
	{
		OATree<string> root = rootStack.at(0);
		rootStack.erase(rootStack.begin());
		List<OATree<string>> *childs = root.getElems();
		if (i == 0)
		{

			outFile << "!" << root.getValue() << endl;
		}
		else
		{
			if (childs == 0)
			{
				outFile << root.getValue() << endl;
			}
			else{
				outFile << (root.isOr() ? "OR" : "AND") << "[" << root.getValue() << "]" << endl;
			}
		}
			
			if (childs != 0)
			{

				Elem<OATree<string>>* iterator = childs->getHead();
				vector<OATree<string>> tempV;
				while (iterator != 0)
				{
					tempV.insert(tempV.begin(),iterator->getValue());
					
					iterator = iterator->getNext();
				}
				while (!tempV.empty())
				{
					rootStack.insert(rootStack.begin(),tempV.at(0));
					tempV.erase(tempV.begin());
				}
				iterator = 0;
			}
			childs = 0;
			
			i++;
	}
	outFile.close();
}