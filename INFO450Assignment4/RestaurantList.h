#pragma once
#include <iostream>
#include <string>
#include "Restaurant.h"
using namespace std;

class RestaurantList
{
public:
	Restaurant **restaurants = new Restaurant*[100]; // Extra Credit
	int numRestaurants;
	RestaurantList();
	void AddRestaurant();
	void deleteRestaurant(string unwanted);
	void showRestaurants();
	int readFromFile(string filename);
	int writeToFile(string filename);
	bool isValidName(string n);
};