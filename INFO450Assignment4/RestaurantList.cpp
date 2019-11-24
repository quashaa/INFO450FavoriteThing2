#include <iostream>
#include <string>
#include <fstream>
#include "Restaurant.h"
#include "RestaurantList.h"
using namespace std;

// Constructor
RestaurantList::RestaurantList()
{
	numRestaurants = 0;
}

// Gets restaurants and validates it's not a duplcate
void RestaurantList::AddRestaurant()
{
	bool duplicate = true;
	
	// Allocates new object for the next restaurant
	restaurants[numRestaurants] = new Restaurant();

	// Gathers input
	restaurants[numRestaurants]->getRestaurant(); 

	//Validates restaurant is not a duplicate
	while (duplicate)
	{
		// Skips duplicate check on first restaurant
		if (numRestaurants == 0)
		{
			break;
		}

		// Compares new restaurant name with existing restaurants in list
		for (int i = 0; i < numRestaurants; i++)
		{
			// No match condition
			if (restaurants[i]->name != restaurants[numRestaurants]->name)
			{
				duplicate = false;
			}
			else
			{
				cout << "\n[ERROR: You have already added a restaurant with this name!]" << endl;
				delete restaurants[i];
				numRestaurants--;
				break;
			}
		}
	}
	numRestaurants++;
}

// Verifies unwanted restaurants exists in array
bool RestaurantList::isValidName(string n)
{
	// Compares new restaurant name with existing restaurants in list
	for (int i = 0; i < numRestaurants; i++)
	{
		bool check = (restaurants[i]->name == n);

		if (check == true)
		{
			return true;
		}
		else if (i == (numRestaurants - 1))
		{
			return false;
		}
	}
	return false;
}

// Checks to see if the unwanted restaurant is in the list; then deletes
void RestaurantList::deleteRestaurant(string unwanted)
{
	char answer = 'y';
	int index = 0, length = 0;

	// Valid restaurant check
	if (isValidName(unwanted))
	{
		// Compares unwanted restaurant name with existing restaurants in list
		for (int i = 0; i < numRestaurants; i++)
		{
			// Finds unwanted index and deletes
			if (restaurants[i]->name == unwanted)
			{
				int deleteIndex = i;

				length = numRestaurants - 1;

				// Loops through array to delete and adjust
				for (index = 0; index < length; index++)
				{
					if (index == deleteIndex)
					{
						delete restaurants[index];
					}

					if (index >= deleteIndex)
					{
						restaurants[index] = restaurants[index + 1];
					}
				}

				cout << "\nYour restaurant has been deleted!" << endl;
				break;
			}
		}

		numRestaurants--;
	}
	else
	{
		cout << "\n[ERROR: This restaurant is not on your list]" << endl;
	}
}

// Displays restaurant list
void RestaurantList::showRestaurants()
{
	int i;

	for (i = 0; i < numRestaurants; i++)
	{
		cout << *restaurants[i];
	}
}

// Truncates file with new favorite restaurant list
int RestaurantList::writeToFile(string filename)
{
	char answer = 'n';
	int i;
	ofstream outputFile;

	outputFile.open(filename, ios::trunc);

	// Good file condition 
	// (if filename doesn't exist it will create a new file with specified path or in sln folder)
	if (!outputFile)
	{
		cout << "\n[ERROR: File Open Failed!]" << endl;
		return -1;
	}
	
	cout << "\n[Warning: Saving will overwrite existing file]" << endl;
	cout << "Are you sure you want to save? [Y/N]: ";
	cin >> answer;
	cin.ignore();

	// User verification condition
	if (answer == 'y' || answer == 'Y')
	{
		for (i = 0; i < numRestaurants; i++)
		{
			outputFile << "\n********** Restaurant **********" << endl;
			outputFile << "Name: " << restaurants[i]->getName() << endl;
			outputFile << "Location: " << restaurants[i]->getLocation() << endl;
			outputFile << "Rating: " << restaurants[i]->getRating() << endl;
			outputFile << "Favorite Menu Item: " << restaurants[i]->getFavItem() << endl;
			outputFile << "Favorite Menu Item Price: $" << restaurants[i]->getFavPrice() << endl;
		}
		outputFile.close();

		cout << "\nYour file has been saved!" << endl;
	}
	return 0;
}

// Reads from file to add new restaurants
int RestaurantList::readFromFile(string filename)
{
	int count = 0;
	ifstream inputFile;

	inputFile.open(filename, ios::in);

	if (!inputFile)
	{
		cout << "\n[ERROR: File Open Failed!]" << endl;
		return -1;
	}

	// Temp holders
	string header;
	string label;
	string name;
	string location;
	int rating;
	string favItem;
	double favPrice;
	string istring;

	// Loops until eond of file
	while (!inputFile.eof())
	{
		// Reads from the file
		getline(inputFile, header, '\n');
		if (header.length() >= 1)
		{
			getline(inputFile, label, ' ');
			getline(inputFile, name, '\n');

			getline(inputFile, label, ' ');
			getline(inputFile, location, '\n');

			getline(inputFile, label, ' ');
			getline(inputFile, istring, '\n');
			rating = stoi(istring);

			getline(inputFile, label, ':');
			getline(inputFile, label, ' ');
			getline(inputFile, favItem, '\n');

			getline(inputFile, label, '$');
			getline(inputFile, istring, '\n');
			favPrice = stod(istring);

			restaurants[numRestaurants] = new Restaurant();

			// Adds data to objects in list if the restaurant doesn't exist
			if (!isValidName(name))
			{
				restaurants[numRestaurants]->setName(name);
				restaurants[numRestaurants]->setLocation(location);
				restaurants[numRestaurants]->setRating(rating);
				restaurants[numRestaurants]->setFavItem(favItem);
				restaurants[numRestaurants]->setFavPrice(favPrice);
				
				numRestaurants++;
				count++;
			}
			else
			{
				cout << "\n[ERROR: The restaurant " << name << " has already been entered in the list. This restaurant will not be added.]" << endl;
			}
		}
	}

	cout << "\n" << count << " restaurants were added to the list!" << endl;

	return 0;
}