#include "Reader.h"
#include <iostream>
#include <fstream>
using namespace std;





OATree<string>* Reader::readTree(char* fileName){
	OATree<string> *tree  = 0;
	string str, tmp;
	string typeStart = "!";
	string propertyOr = "OR[";
	string propertyAnd = "AND[";
    ifstream myfile(fileName);

	if (myfile.is_open())
	{
		unsigned position = 0;
        List<OATree<string> > *list = 0;
        List<OATree<string> > *sublist = 0;
		while (getline(myfile, str))
		{
			position = str.find(typeStart);

			if (position >= 0 && position < str.length()){
				string typeName = str.substr(position + 1);
                list = new List<OATree<string> >();
				tree = new OATree<string>(typeName,false, list);
			
				cout << "ТипName-" << typeName << endl;
				continue;
			}
			position = str.find(propertyOr);
			if (position >= 0 && position < str.length()){
				string prop = str.substr(position + 3, str.length() - 4);
				cout << "property-" << prop << endl;
                sublist = new List<OATree<string> >();
				list->addElem(OATree<string>(prop, true, sublist));
				continue;
			}
			position = str.find(propertyAnd);
			if (position >= 0 && position < str.length()){
				string prop = str.substr(position + 4, str.length() - 5);
				
				cout << "property-" << prop << endl;
                sublist = new List<OATree<string> >();
				list->addElem(OATree<string>(prop, false, sublist));
				continue;
			}
			cout << str << endl;
			sublist->addElem(OATree<string>(str, false, 0));



		}
		myfile.close();
	}
	return tree;
}

