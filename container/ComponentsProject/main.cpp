
#include"OATree.h"
#include<string>
#include <iostream>
#include <fstream>

using namespace std;


bool isNumeric(const std::string& s)
{
	std::string::const_iterator it = s.begin();
	while (it != s.end() && isdigit(*it)) 
		++it;
	return !s.empty() && it == s.end();
}


int main()
{
	string str , tmp;

	string typeStart = "!";
	string propertyStart = "OR[";
	
	ifstream myfile("file.txt");

	if (myfile.is_open())
	{
		unsigned position = 0;
		while (getline(myfile, str))
		{
			position = str.find(typeStart);
			if (position >= 0 && position < str.length()){
     			string typeName = str.substr(position + 1);
				cout << "typeName-" << typeName << "\n";
			}
			position = str.find(propertyStart);
			if (position >= 0 && position < str.length()){
				string prop = str.substr(position + 3,str.length() - 4);
				cout << "property-" << prop << "\n";
				continue;
			}
			if (isNumeric(str))
			{
				int num = stoi(str);
				cout << num << "\n";
			}
			else
			{
				cout << str << "\n";
			}
		}
		myfile.close();
	}
	
	system("PAUSE");

	
	return 0;
}


