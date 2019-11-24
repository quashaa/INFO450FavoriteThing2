#include <iostream>
#include <string>
#include "Restaurant.h"
#include"RestaurantList.h"

using namespace std;

int main()
{
	// Intro
	cout << "*** ********************* ***" << endl;
	cout << "***                       ***" << endl;
	cout << "***       Welcome To      ***" << endl;
	cout << "***  Restaurant Tracker!  ***" << endl;
	cout << "***                       ***" << endl;
	cout << "***   This app will show  ***" << endl;
	cout << "***   you a list of all   ***" << endl;
	cout << "***   of your favorite    ***" << endl;
	cout << "***     restaurants!      ***" << endl;
	cout << "***                       ***" << endl;
	cout << "***  Each restaurant will ***" << endl;
	cout << "***  need the following:  ***" << endl;
	cout << "***     - Name            ***" << endl;
	cout << "***     - Location        ***" << endl;
	cout << "***     - Rating          ***" << endl;
	cout << "***     - Favorite Item   ***" << endl;
	cout << "***     - Item Price      ***" << endl;
	cout << "***                       ***" << endl;
	cout << "*** ********************* ***" << endl;
	cout << endl;

	system("pause");
	system("CLS");

	int option = 0;
	RestaurantList *favRestaurants = new RestaurantList;

	// Loops until user exits
	while (option != 6)
	{
		cout << "\n***   Please choose one of the menu options below by entering the correspnding number  ***" << endl;
		cout << "1. Upload" << endl;
		cout << "2. Add" << endl;
		cout << "3. Delete" << endl;
		cout << "4. Show" << endl;
		cout << "5. Save" << endl;
		cout << "6. Exit\n" << endl;
		cin >> option;
		cin.ignore();

		// Upload
		if (option == 1)
		{
			string readFile;

			cout << "\n(File Format: C:\\users\\path\\file.txt)" << endl;
			cout << "Please enter the full path of the file to read from: ";
			getline(cin, readFile, '\n');

			favRestaurants->readFromFile(readFile);
		}

		// Add
		if (option == 2)
		{
			char addItem = 'y';

			// Loops to gather multiple restaurants
			while (addItem == 'y' || addItem == 'Y')
			{
				favRestaurants->AddRestaurant();

				cout << "\nWould you like to add another favorite restaurant? ";
				cin >> addItem;
				cin.ignore();
			}
		}

		//Delete
		if (option == 3)
		{
			char deleteItem = 'y';

			// No restaurant condition
			if (favRestaurants->numRestaurants != 0)
			{
				// Gets name of the Restaurant to be deleted
				// Loops until user has no more unwanted restaurants OR no more restaurants exist
				while ((deleteItem == 'y' || deleteItem == 'Y') && favRestaurants->numRestaurants != 0)
				{
					string unwanted = "";

					cout << "\nPlease Enter name of the restaurant you would like to delete: ";
					getline(cin, unwanted);

					favRestaurants->deleteRestaurant(unwanted);


					cout << "\nWould you like to delete another restaurant from your list? ";
					cin >> deleteItem;
					cin.ignore();
				}
				if (favRestaurants->numRestaurants == 0)
				{
					cout << "\n[ERROR: There are no restaurants in memory]" << endl;

				}

			}
			else
			{
				cout << "\n[ERROR: There are no restaurants in memory]" << endl;
			}
		
		}
		
		// Show
		if (option == 4)
		{
			// No restaurant condition
			if (favRestaurants->numRestaurants != 0)
			{
			cout << "\nYour list of favorite restaurants is below:\n" << endl;
			favRestaurants->showRestaurants();
			}
			else 
			{
				cout << "\n[ERROR: There are no restaurants in memory]" << endl;
			}
		}

		// Save
		if (option == 5)
		{
			// No restaurant condition
			if (favRestaurants->numRestaurants != 0)
			{

				string outputFile;

				cout << "\n(File Format: C:\\users\\path\\file.txt)" << endl;
				cout << "Please enter the full path of the file to save to: ";
				getline(cin, outputFile, '\n');

				favRestaurants->writeToFile(outputFile);
			}
			else
			{
				cout << "\n[ERROR: There are no restaurants in memory]" << endl;
			}
		}
	}

	// Garbage collection
	for (int i = 0; i < favRestaurants->numRestaurants; i++)
	{
		delete favRestaurants->restaurants[i];
	}
	delete [] favRestaurants->restaurants;
	delete favRestaurants;

	// Exit
	cout << "\n\n*** ********************* ***" << endl;
	cout << "***                       ***" << endl;
	cout << "***       GOOD BYE        ***" << endl;
	cout << "***                       ***" << endl;
	cout << "*** ********************* ***\n\n" << endl;

	system("pause");
	return 0;
}