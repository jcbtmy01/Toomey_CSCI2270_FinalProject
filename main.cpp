#include <iostream>
#include <vector>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include "holderStruct.h"
#include "organizer.h"


using namespace std;

void DisplayMenu();
void loadOrganizer(organizer* current, string filename);

int main(int argc, char* argv[])
{
	bool quit = false;
	organizer* allStructures = new organizer;

	int user_input;

	while (!quit)
	{
		DisplayMenu();
		cin >> user_input;

		cin.clear();
		cin.ignore(10000, '\n');

		switch (user_input)
		{
			case 1:
				cout << "\n" << "------Loading Sample.txt------- " << "\n" << endl;
				loadOrganizer(allStructures, "Sample.txt");
				break;

			case 2:
                {
				string theirFile;
				cout << "Enter file name:" << endl;
				cin >> theirFile;
				loadOrganizer(allStructures, theirFile);
				break;
				}

			case 3:
			{
				int searchValue;
				cout << "Enter a search value:" << endl;
				cin >> searchValue;
				allStructures->callSearch(searchValue);
				allStructures->getSearches();
				allStructures->sort();

				vector<dataHolder*>* returnedSearches = allStructures->getSorted();

				for (int i = 0; i < returnedSearches->size(); i++)
				{
					cout << "\n" << returnedSearches->at(i)->searchType << " ----- Search Time: " << returnedSearches->at(i)->timeE * 1000 << " sec" <<"\n" << endl;

				}
				break;
			}
			case 4:
				int enterValue;
				cout << "Enter an Integer: " << endl;
				cin >> enterValue;
				allStructures->addAll(enterValue);

				cout << enterValue << " has been added." << endl;
				break;
			case 5:

				cout << "Goodbye!" << endl;
				quit = true;
				break;



		}

	}


	return 0;
}


void DisplayMenu()
{
	cout << "1. Preload File" << endl;
	cout << "2. UserLoaded File(file of proper format)" << endl;
	cout << "3. Search for value" << endl;
	cout << "4. Add data" << endl;
	cout << "5. Quit" << endl;
}

void loadOrganizer(organizer* current, string filename)
{

	fstream inFile;

	inFile.open(filename.c_str());

	if(!inFile)
	{
		cout << "File could not open" << endl;
		return;
	}

	string num;

	while (!inFile.eof())
	{
		getline(inFile, num);

		if (num != "")
		{
			int insertvalue = atoi(num.c_str());
			current->addAll(insertvalue);
		}
	}

}
