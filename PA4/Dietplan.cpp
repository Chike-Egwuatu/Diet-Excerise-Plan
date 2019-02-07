#include "DietPlan.h"


DietPlan::DietPlan(int newgoalcalories, string newplanname, string newdate) // constructor
{
	GoalCalories = newgoalcalories;
	Name = newplanname;
	Date = newdate;
}

DietPlan::DietPlan(const DietPlan &copy) // copy constructor
{
	this->GoalCalories = copy.GetGoalCalories();
	this->Name = copy.GetName();
	this->Date = copy.GetDate();
}

DietPlan::~DietPlan() // deconstruct
{

}

void DietPlan::SetGoalCalories(const int &newgoalcalories) // set goal calories
{
	this->GoalCalories = newgoalcalories;
}

void DietPlan::SetName(const string &newplanname) // set the name
{
	this->Name = newplanname;
}

void DietPlan::SetDate(const string &newdata) // set the date
{
	this->Date = newdata;
}

int DietPlan::GetGoalCalories()const // return pointer goal calories
{
	return this->GoalCalories;
}

string DietPlan::GetName()const // return pointer name
{
	return this->Name;
}

string DietPlan::GetDate()const // return pointer date
{
	return this->Date;
}

ostream &operator << (ostream &lhs, const DietPlan &rhs) // print out the data into the terminal
{
	lhs << rhs.GetName() << endl << rhs.GetDate() << endl << rhs.GetGoalCalories() << endl;
	return lhs;
}

fstream &operator <<(fstream &lhs, const DietPlan &rhs)// print out the data into the File
{
	lhs << rhs.GetName() << endl << rhs.GetDate() << endl << rhs.GetGoalCalories() << endl << endl;
	return lhs;
}

fstream &operator >> (fstream &lhs, DietPlan &rhs) // read in the txt file of the data
{
	char name[100], date[100],whitespace[2];
	int goalcalories;

	lhs.getline(name, 100);
	rhs.SetName(name);

	lhs.getline(date, 100);
	rhs.SetDate(date);

	lhs >> goalcalories;
	rhs.SetGoalCalories(goalcalories);
	lhs.getline(whitespace, 2);

//	lhs.getline(whitespace, 2);
	//lhs.getline(date, 100);
	lhs.getline(whitespace, 2);
	return lhs;

}

DietPlan & DietPlan::EditGoal()
{
	cout << endl << "Current Diet Plan:" << endl << *this;
	int NewGoalCalories = 0;
	cout << "Enter the New Goal Calories for your Diet Plan: ";
	cin >> NewGoalCalories;
	this->GoalCalories = NewGoalCalories;
	cout << "Updated Diet Plan:" << endl << *this;
	return *this;
}

DietPlan & DietPlan::EditDate()
{
	cout << endl << "Current Diet Plan:" << endl << *this;
	string NewDate;
	cout << "Enter the New Date for your exercise Plan: ";
	cin >> NewDate;
	this->Date = NewDate;
	cout << "Updated Diet Plan:" << endl << *this;
	return *this;
}

void DietPlan::DisplayDietPlan()
{
	cout << "Diet Plan" << *this;
}