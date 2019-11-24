#include <iostream>
#include <string>
#include "Restaurant.h"
using namespace std;

// Constructors
Restaurant::Restaurant()
{
	name = "";
	location = "";
	rating = 0;
	favItem = "";
	favPrice = 0.00;
}

Restaurant::Restaurant(string n, string l, int r, string i, double p)
{
	name = n;
	location = l;
	rating = r;
	favItem = i;
	favPrice = p;
}

// Gathers input
void Restaurant::getRestaurant()
{
	const int maxRate = 5, minRate = 1;

	cout << "\nEnter the restaurant's name: ";
	getline(cin, name);

	cout << "Enter the restaurant's location : ";
	getline(cin, location);
	while (rating > maxRate || rating < minRate) // Loops until the user chooses a rating 1-5
	{
		cout << "How would you rate this restaurant 1 - 5? ";
		cin >> rating;
		cin.ignore();

		if (rating > maxRate || rating < minRate)
			cout << "(Rating must be on a scale of 1 - 5!)" << endl;
	}
	cout << "Enter your favorite item from the menu: ";
	getline(cin, favItem);
	cout << "Enter the price of your favorite Item: $";
	cin >> favPrice;
	cin.ignore();
}

// Getters
string Restaurant::getName()
{
	return name;
}

string Restaurant::getLocation()
{
	return location;
}

int Restaurant::getRating()
{
	return rating;
}

string Restaurant::getFavItem()
{
	return favItem;
}

double Restaurant::getFavPrice()
{
	return favPrice;
}

// Setters
void Restaurant::setName(string n)
{
	name = n;
}

void Restaurant::setLocation(string l)
{
	location = l;
}

void Restaurant::setRating(int r)
{
	rating = r;
}
void Restaurant::setFavItem(string i)
{
	favItem = i;
}
void Restaurant::setFavPrice(double p)
{
	favPrice = p;
}

// Output operator for each restaurant object
ostream& operator<<(ostream &output, Restaurant &r)
{
	output << "\n********** Restaurant **********" << endl;
	output << "Name: " << r.name << endl;
	output << "Location: " << r.location << endl;
	output << "Rating: " << r.rating << endl;
	output << "Favorite Menu Item: " << r.favItem << endl;
	output << "Favorite Menu Item Price: $" << r.favPrice << endl;
	output << endl;

	return output;
}

// Comparison operator for 2 restaurant objects
bool operator==(Restaurant &a, Restaurant &b)
{
	if (a.name == b.name)
		return true;
	else
		return false;
}