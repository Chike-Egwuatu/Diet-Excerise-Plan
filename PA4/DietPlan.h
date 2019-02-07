#pragma once
#include <iostream>
#include <fstream>
#include <string>

using std::string; // use std so that string isnt mixed up in the libray same with fstream
using std::fstream;
using std::ostream;
using std::ios;
using std::cin;
using std::cout;
using std::endl;

class DietPlan // initialize class
{
public:
	DietPlan(int newgoalcalories = 0, string newplanname = "", string newdate = ""); // constructor
	DietPlan(const DietPlan &copy); // copy constructor
	~DietPlan(); // deconstruct
	DietPlan & EditGoal(); // edit specific goal
	DietPlan & EditDate(); // edit date

	void DisplayDietPlan(); // display the diet plan
	void SetGoalCalories(const int &newgoalcalories); // set goal calories
	void SetName(const string &newplanname); // set the name
	void SetDate(const string &newdata); // set the date

 	int GetGoalCalories()const; // return pointer goal calories
	string GetName()const; // return pointer name
	string GetDate()const; // return pointer date

private: // data that cannot be accessed must stay the same throughout
	int GoalCalories;
	string Name;
	string Date;
};
fstream &operator >> (fstream &lhs, DietPlan &rhs); // read in the txt file of the data
ostream &operator << (ostream &lhs, const DietPlan &rhs); // print out the data into the terminal
fstream &operator <<(fstream &lhs, const DietPlan &rhs); // print out the data into the File
