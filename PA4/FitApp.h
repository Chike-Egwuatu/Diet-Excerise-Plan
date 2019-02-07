#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "DietPlan.h"
#include "ExercisePlan.h"

using std::string;
using std::fstream;
using std::ostream;
using std::ios;
using std::cin;
using std::cout;
using std::endl;


class FittnessAppWrapper
{
public:
	FittnessAppWrapper(); 
	FittnessAppWrapper(DietPlan NewWeeklyDP[], ExcercisePlan NewWeeklyEP[]);
	~FittnessAppWrapper();
	void setWeeklyDp(const DietPlan NewDietPlan, int day); // set the weekly Diet Plan
	void setWeeklyEP(const ExcercisePlan NewExcercisePlan, int day);

	void loadDailyPlan(fstream &file, DietPlan &plan); // Load the Daily Plan
	void loadDailyPlan(fstream &file, ExcercisePlan &plan);

	void loadWeeklyPlan(fstream &file, DietPlan weeklyPlan[]); // Load weekly Plan
	void loadWeeklyPlan(fstream &file, ExcercisePlan weeklyPlan[]);

	void DisplayDailyDietPlan(const DietPlan &dp); // Display Certain Plan
	void DisplayDailyExerciseplan(const ExcercisePlan &ep);

	//void displayDailyPlan(ostream &cout, const DietPlan &dp);
	//void displayDailyPlan(ostream &cout, const ExcercisePlan &ep);

	void displayWeeklyPlan(const DietPlan weeklyDP[]); // display weekly plan
	void displayWeeklyPlan(const ExcercisePlan weeklyEP[]);

	void storeDailyPlan(fstream &output, const DietPlan &dp); //store certain plan
	void storeDailyPlan(fstream &output, const ExcercisePlan &ep);

	void storeWeeklyPlan(fstream &output, const DietPlan WeeklyDP[]); // store weekly plans
	void storeWeeklyPlan(fstream &output, const ExcercisePlan WeeklyEP[]);

	int displayMenu(); // display the menu for user
	void runApp(void); // run the fitness app

private:
	DietPlan WeeklyDietplan[7];
	ExcercisePlan WeeklyExcercisePlan[7];

};