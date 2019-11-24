#include <iostream>
#include "TimeStamp.h"
using namespace std;

TimeStamp createTimeStamp(Date tempDate){
	int tempHour, tempMin;
	
	militaryHourCheck("Enter hour", &tempHour);
	minCheck("Enter min", &tempMin);
	
	Time tempTime(tempHour, tempMin);
	
	TimeStamp tempTimeStamp(tempDate, tempTime);
	
	return tempTimeStamp;
}

void mainMenu(int *option){
	cout << "\tMain Menu\n";
	cout << "-------------------------\n";
	cout << "1: \n";
	cout << "2: \n";
	cout << "3: \n";
	cout << "4: \n";
	cout << "5: \n";
	cout << "6: \n";
	cout << "7: \n";
	cout << "-------------------------\n";
	cout << "Select an option based on its number.";
	cin >> *option;
	intOptionsCheck("Select an option based on its number.", 7, option);
}

int main(){
	int month, day, option;
	monthCheck("Enter month (in number form):", &month);
	dayCheck("Enter day (the number of the day):", &day);
	
	Date runDate(month, day, 19);
	
	do
	{
		system("CLS");
		//mainMenu(&option);
		
		switch(option)
		{
			case 1: //
				
				break;
			case 2: //
				
				break;
			case 3: //
				
				break;
			case 4: //
				
				break;
			case 5: //
				
				break;
			case 6: //
				
				break;
			case 7: cout <<"Closing Program...";
					break;
			default: cout << "Invalid choice.\n";
					break;
		}
		system("PAUSE");
	}while(option != 7);
	return 0;
}
