//No Comments in Exercise Plan since it is exactly the same as Diet Plan
// Only Exercise Plan has steps as opposed to DietPlan
#pragma once
#include <iostream>
#include <fstream>
#include <string>

using std::string;
using std::fstream;
using std::ostream;
using std::ios;
using std::cin;
using std::cout;
using std::endl;

class ExcercisePlan
{
public:
	ExcercisePlan(int newgoalsteps = 0, string newplanname = "", string newdate = "");
	ExcercisePlan(const ExcercisePlan&copy); // copy
	~ExcercisePlan();
	ExcercisePlan & EditGoal();
	ExcercisePlan & EditDate();

	void DisplayExcercisPlan();
	void SetGoalSteps(const int &newgoalsteps);
	void SetName(const string &newplanname);
	void SetDate(const string &newdata);

	int GetGoalSteps()const;
	string GetName()const;
	string GetDate()const;

private:
	int GoalSteps;
	string Name;
	string Date;
};
fstream &operator >> (fstream &lhs, ExcercisePlan &rhs);
ostream &operator << (ostream &lhs, const ExcercisePlan &rhs);
fstream &operator <<(fstream &lhs, const ExcercisePlan &rhs);

