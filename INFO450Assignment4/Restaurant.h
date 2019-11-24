#pragma once
#include <iostream>
#include <string>
using namespace std;

class Restaurant
{
public:
	string location;
	int rating;
	string favItem;
	double favPrice;
	string name;

	// Constructors
	Restaurant();
	Restaurant(string n, string l, int r, string i, double p);

	// Gathers input
	void getRestaurant();

	// Getters
	string getName();
	string getLocation();
	int getRating();
	string getFavItem();
	double getFavPrice();

	// Setters
	void setName(string n);
	void setLocation(string l);
	void setRating(int r);
	void setFavItem(string f);
	void setFavPrice(double p);

	// Overloaded operators
	friend ostream& operator<<(ostream &output, Restaurant &r);
	friend bool operator==(Restaurant &a, Restaurant &b);
};