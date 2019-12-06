#include <iostream>
#include <iomanip>
#include "TimeStamp.h"
#include "Sanitization.h"
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
	cout << "1: Create Employees\n";
	cout << "2: Delete Employees\n";
	cout << "3: View Employees\n";
	cout << "4: Equipment Drop Off\n";
	cout << "5: Equipment Repair\n";
	cout << "6: Equipment Complete\n";
	cout << "7: Equipment Picked Up\n";
	cout << "8: Reporting Phase\n";
	cout << "9: Save and Shut Down\n";
	cout << "-------------------------\n";
	intOptionsCheck("Select an option based on its number.", 9, option);
}

int main(){
	bool settingDate = true;
	int month, day, option;
	char input;
	
	cout << "Welcome to your ticketing software\n";
	
	//check file to decide if the date needs to be set
	while(settingDate){
		monthCheck("Enter month (in number form):", &month);
		dayCheck("Enter day (the number of the day):", &day);
		Date runDate(month, day, 19);
		
		runDate.display();
		
		ynCheck("Is that the correct date?(y or n)", &input);
		
		if(input == 'y'){
			settingDate = false;
		}
		else if(input == 'n'){
			cout << "Try again\n";
		}
		else{
			cout << "ERROR.This should never happen\n";
		}
	}
	
	do
	{
		system("CLS");
		mainMenu(&option);
		
		switch(option)
		{
			case 1:{
				break;
			}
			case 2:{
				break;
			}
			case 3:{
				break;
			}
			case 4:{
				break;
			}
			case 5:{
				break;
			}
			case 6:{
				break;
			}
			case 7:{
				break;
			}
			case 8:{
				break;
			}
			case 9:{
				cout << "Closing Program...\n";
				break;
			}
			default:{
				cout << "Invalid choice.\n";
				break;
			}
		}
		system("PAUSE");
	}while(option != 9);
	return 0;
}
