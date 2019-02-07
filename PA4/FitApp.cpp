#include "FitApp.h"

FittnessAppWrapper::FittnessAppWrapper() // constructor that points to weeklyplan and sets int
{
	DietPlan dp;
	ExcercisePlan ep;

	for (int i = 0; i < 7; i++)
	{
		this->WeeklyDietplan[i] = dp;
	}
	for (int i = 0; i < 7; i++)
	{
		this->WeeklyExcercisePlan[i] = ep;
	}

}

FittnessAppWrapper::~FittnessAppWrapper() // deconstructor
{

}

void FittnessAppWrapper::setWeeklyDp(const DietPlan NewDietPlan, int day) // set the weekly plan and it is -1 because it goes 0-6
{
	this->WeeklyDietplan[day - 1] = NewDietPlan;
}

void FittnessAppWrapper::setWeeklyEP(const ExcercisePlan NewExcercisePlan, int day)// set the weekly plan and it is -1 because it goes 0-6
{
	this->WeeklyExcercisePlan[day - 1] = NewExcercisePlan;
}

void FittnessAppWrapper::loadDailyPlan(fstream &file, DietPlan &plan) // points to Diet Plan txt
{
	file >> plan;
}

void FittnessAppWrapper::loadDailyPlan(fstream &file, ExcercisePlan &plan)// points to Exercise plan txt
{
	file >> plan;
}

void FittnessAppWrapper::loadWeeklyPlan(fstream &file, DietPlan weeklyPlan[]) // load and read from txt
{
	file.open("dietplans.txt", ios::in);
	for (int i = 0; i < 7; i++)
	{
		loadDailyPlan(file, weeklyPlan[i]);
	}
	file.close();
	cout << "Weekly Diet Plan is Loaded" << endl;
}

void FittnessAppWrapper::loadWeeklyPlan(fstream &file, ExcercisePlan weeklyPlan[]) // load and read from txt
{
	file.open("Excerciseplan.txt", ios::in);
	for (int i = 0; i < 7; i++)
	{
		loadDailyPlan(file, weeklyPlan[i]);
	}
	file.close();
	cout << "Weekly Excerise Plan is Loaded" << endl;
}

void FittnessAppWrapper::DisplayDailyDietPlan(const DietPlan &dp)
{
	cout << dp << endl;
}

void FittnessAppWrapper::DisplayDailyExerciseplan(const ExcercisePlan &ep)
{
	cout << ep << endl;
}

void FittnessAppWrapper::displayWeeklyPlan(const DietPlan weeklyDP[])
{
	for (int i = 0; i < 7; i++)
	{
		DisplayDailyDietPlan(weeklyDP[i]);
	}
}

void FittnessAppWrapper::displayWeeklyPlan(const ExcercisePlan weeklyEP[])
{
	for (int i = 0; i < 7; i++)
	{
		DisplayDailyExerciseplan(weeklyEP[i]);
	}
}

void FittnessAppWrapper::storeDailyPlan(fstream &output, const DietPlan &dp) 
{
	output << dp;
}

void FittnessAppWrapper::storeDailyPlan(fstream &output, const ExcercisePlan &ep)
{
	output << ep;
}

void FittnessAppWrapper::storeWeeklyPlan(fstream &output, const DietPlan WeeklyDP[]) // read in and store weekly plan
{
	output.open("dietplans.txt", ios::out);
	for (int i = 0; i < 7; i++)
	{
		storeDailyPlan(output, WeeklyDP[i]);
	}
	output.close();
	cout << "Weekly Diet Plan has been stored" << endl;
}

void FittnessAppWrapper::storeWeeklyPlan(fstream &output, const ExcercisePlan WeeklyEP[])// read in and store weekly plan
{
	output.open("Excerciseplan.txt", ios::out);
	for (int i = 0; i < 7; i++)
	{
		storeDailyPlan(output, WeeklyEP[i]);
	}
	output.close();
	cout << "Weekly Excerise Plan Has been Stored" << endl;
}

int FittnessAppWrapper::displayMenu() //display menu
{
	int choice = 0;
	cout << "PA4" << endl << endl;
	cout << "Make Sure to Load Diet and Exercise plan Everytime or else the txt will not load" << endl << endl;
	cout << "Menu" << endl;
	cout << "1. Load weekly diet plan from file." << endl;
	cout << "2. Load weekly exercise plan from file." << endl;
	cout << "3. Store weekly diet plan to file." << endl;
	cout << "4. Store weekly exercise plan to file." << endl;
	cout << "5. Display weekly diet plan to screen." << endl;
	cout << "6. Display weekly exercise plan to screen." << endl;
	cout << "7. Edit daily diet plan." << endl;
	cout << "8. Edit daily exercise plan." << endl;
	cout << "9. Exit." << endl;
	cout << endl << "Menu Option: ";
	cin >> choice;
	return choice;
}

void FittnessAppWrapper::runApp(void) // function to run app with different cases like load week, or store .
{
	fstream DP,EP;
	int dailyplandp, dailyplanep, optionDP, optionEP;
	int choice = 0;
	while (choice != 9)
	{
		choice = displayMenu();
		switch (choice)
		
		{
		case 1: //load weekly plan
			this->loadWeeklyPlan(DP, this->WeeklyDietplan);
			system("pause");
			system("cls");
			break;
		case 2:
			this->loadWeeklyPlan(EP, this->WeeklyExcercisePlan);
			system("pause");
			system("cls");
			break;
		case 3: // store weekly plans
			this->storeWeeklyPlan(DP, this->WeeklyDietplan);
			system("pause");
			system("cls");
			break;
		case 4:
			this->storeWeeklyPlan(EP, this->WeeklyExcercisePlan);
			system("pause");
			system("cls");
			break;
		case 5: // display weekly plans
			this->displayWeeklyPlan(this->WeeklyDietplan);
			system("pause");
			system("cls");
			break;
		case 6:
			this->displayWeeklyPlan(this->WeeklyExcercisePlan);
			system("pause");
			system("cls");
			break;
		case 7: // edit Diet Plan
			cout << endl << "Enter the day you wish to edit(1-7)(Monday-Sunday): ";
			cin >> dailyplandp;
			cout << "Choose what you wish to edit" << endl;
			cout << "1.Edit Goal Calories" << endl;
			cout << "2.Edit Date." << endl;
			cout << "Option 1 or 2:" << endl;
			cin >> optionDP;
			switch (optionDP)
			{
			case 1:
				this->WeeklyDietplan[dailyplandp - 1].EditGoal();
				break;
			case 2 :
				this->WeeklyDietplan[dailyplandp - 1].EditDate();
				break;
			}
			system("pause");
			system("cls");
			break;
		case 8: // Edit Excerise Plan
			cout << endl << "Enter the day you wish to edit(1-7)(Monday-Sunday): ";
			cin >> dailyplanep;
			cout << "Choose what you wish to edit" << endl;
			cout << "1.Edit Goal Steps" << endl;
			cout << "2.Edit Date." << endl;
			cout << "Option 1 or 2:" << endl;
			cin >> optionEP;
			switch (optionEP)
			{
			case 1:
				this->WeeklyExcercisePlan[dailyplanep - 1].EditGoal();
				break;
			case 2:
				this->WeeklyExcercisePlan[dailyplanep - 1].EditDate();
				break;
			}
			system("pause");
			system("cls");
			break;
		case 9: // Exit and Store everything that has been changed.
			this->storeWeeklyPlan(DP, this->WeeklyDietplan);
			this->storeWeeklyPlan(EP, this->WeeklyExcercisePlan);
			break;
			}
		}
}