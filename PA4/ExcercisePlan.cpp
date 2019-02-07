#include "ExercisePlan.h"

ExcercisePlan::ExcercisePlan(int newgoalsteps, string newplanname, string newdate)
{
	GoalSteps = newgoalsteps;
	Name = newplanname;
	Date = newdate;
}

ExcercisePlan:: ExcercisePlan(const ExcercisePlan&copy)
{
	this->GoalSteps = copy.GetGoalSteps();
	this->Name = copy.GetName();
	this->Date = copy.GetDate();
}

ExcercisePlan::~ExcercisePlan()
{

}

void ExcercisePlan::SetGoalSteps(const int &newgoalsteps)
{
	this->GoalSteps = newgoalsteps;
}

void ExcercisePlan::SetName(const string &newplanname)
{
	this->Name = newplanname;
}

void ExcercisePlan::SetDate(const string &newdata)
{
	this->Date = newdata;
}

int ExcercisePlan::GetGoalSteps()const
{
	return this->GoalSteps;
}

string ExcercisePlan::GetName()const
{
	return this->Name;
}

string ExcercisePlan::GetDate()const
{
	return this->Date;
}

ostream &operator << (ostream &lhs, const ExcercisePlan &rhs)
{
	lhs << rhs.GetName() << endl << rhs.GetDate() << endl << rhs.GetGoalSteps() << endl;
	return lhs;
}

fstream &operator <<(fstream &lhs, const ExcercisePlan &rhs)
{
	lhs << rhs.GetName() << endl << rhs.GetDate() << endl << rhs.GetGoalSteps() << endl <<endl;
	return lhs;
}

fstream &operator >> (fstream &lhs, ExcercisePlan &rhs)
{
	char name[100], date[100], whitespace[2];
	int goalsteps;

	lhs.getline(name, 100);
	rhs.SetName(name);
	

	lhs.getline(date, 100);
	rhs.SetDate(date);

	lhs >> goalsteps;
	rhs.SetGoalSteps(goalsteps);
	lhs.getline(whitespace, 2);

	//lhs.getline(date, 100);
	lhs.getline(whitespace, 2);
	return lhs;

}

ExcercisePlan & ExcercisePlan::EditGoal()
{
	cout << endl << "Current Excercise Plan:" << endl << *this;
	int NewGoalSteps = 0;
	cout << "Enter the New Goal Steps for your exercise Plan: ";
	cin >> NewGoalSteps;
	this->GoalSteps = NewGoalSteps;
	cout << "Updated Excercise Plan:" << endl << *this;
	return *this;
}

ExcercisePlan & ExcercisePlan::EditDate()
{
	cout << endl << "Current Excercise Plan:" << endl << *this;
	string NewDate;
	cout << "Enter the New Date for your exercise Plan: ";
	cin >> NewDate;
	this->Date = NewDate;
	cout << "Updated Excercise Plan:" << endl << *this;
	return *this;
}

void ExcercisePlan::DisplayExcercisPlan()
{
	cout << "Excercise Plan" << *this;
}