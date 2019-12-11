#include <iostream>
#include <fstream>
#include <iomanip>
#include "TimeStamp.h"
#include "Equipment.h"
#include "Sanitization.h"
#include "Employee.h"

using namespace std;

TimeStamp createTimeStamp(Date tempDate){
	int tempHour, tempMin;
	
	militaryHourCheck("Enter hour (in military time):", &tempHour);
	minCheck("Enter minutes:", &tempMin);
	
	Time tempTime(tempHour, tempMin);
	
	TimeStamp tempTimeStamp(tempDate, tempTime);
	
	return tempTimeStamp;
}

void encryptFileData(string *linePTR, char key){
	for(auto i = 0;i < linePTR -> size();i++){
			linePTR -> at(i) = linePTR -> at(i)^key;
	}
}

void decryptFileData(string *linePTR, char key){
	for(auto i = 0;i < linePTR -> size();i++){
			linePTR -> at(i) = linePTR -> at(i)^key;
	}
}

void mainMenu(int *option){
	cout << "\tMain Menu\n";
	cout << "-------------------------\n";
	cout << "1: Create Employees\n";
	cout << "2: View Employees\n";
	cout << "3: Delete Employees\n";
	cout << "4: Equipment Drop Off\n";
	cout << "5: Equipment Repair\n";
	cout << "6: Equipment Picked Up\n";
	cout << "7: Reporting Phase\n";
	cout << "8: Save and Shut Down\n";
	cout << "-------------------------\n";
	intOptionsCheck("Select an option based on its number.", 8, option);
}

void createEmployees(vector<Employee> *employeesPTR){
	string tempFirstName, tempLastName, tempExpertise;
	int option;
	
	configName("Enter Employee's First Name:", &tempFirstName);
	configName("Enter Employee's Last Name:", &tempLastName);
	
	cout << "What is the employee's expertise?\n";
	cout << "1: Novice\n";
	cout << "2: Adept\n";
	cout << "3: Expert\n";
	cout << "4: Master\n";
	intOptionsCheck("Select an expertise based on its number.", 4, &option);
	
	if(option == 1){
		tempExpertise = "Novice";
	}
	else if(option == 2){
		tempExpertise = "Adept";
	}
	else if(option == 3){
		tempExpertise = "Expert";
	}
	else if(option == 4){
		tempExpertise = "Master";
	}
	else{
		cout << "ERROR. This shouldn't be possible.\n";
	}
	
	employeesPTR -> push_back(Employee(employeesPTR -> size(), tempFirstName, tempLastName, tempExpertise));
}

void viewEmployees(vector<Employee> tempEmployees){
	for(int i = 0;i < tempEmployees.size();i++){
		cout << i + 1 << " - ";
		tempEmployees.at(i).display();
	}
}

void deleteEmployees(vector<Employee> *employeesPTR){
	int option;
	viewEmployees(*employeesPTR);
	intOptionsCheck("Enter the number next to the Client to delete it.", employeesPTR -> size(), &option);
	option = option - 1;
	employeesPTR -> erase(employeesPTR -> begin() + option);
}

int main(){
	vector<Employee> employees;
	bool settingDate, creatingEmployees, deletingEmployees;
	int month, day, year, option;
	string line, del = ".";
	size_t pos = 0;
	char input, dateKey = 'D';
	
	ifstream dateFile("currentdate.txt");
	dateFile >> line;
	
	if(line.size() == 0){
		cout << "Welcome to your ticketing software.\n";
		system("PAUSE");
		settingDate = true;
		while(settingDate){
			system("CLS");
			monthCheck("Enter the month (in number form):", &month);
			dayCheck("Enter the day (in number form):", &day);
			yearCheck("Enter year (in four digit number form):", &year);
			Date currentDate(month, day, year);
			
			currentDate.display();
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
	}
	else if(line.size() > 0){
		decryptFileData(&line, dateKey);
		
		pos = line.find(del);
		month = stoi(line.substr(0, pos));
		line.erase(0, pos + del.length());
		pos = line.find(del);
		day = stoi(line.substr(0, pos));
		line.erase(0, pos + del.length());
		pos = line.find(del);
		year = stoi(line.substr(0, pos));
		line.erase(0, pos + del.length());
		
		Date currentDate(month, day, year);
		
		//read in the data from the other files here
		
		cout << "Welcome back to your ticketing software.\n";
		cout << "Today's date is ";
		currentDate.display();
		system("PAUSE");
		system("CLS");
	}
	else{
		cout << "ERROR.This shouldn't be possible.\n";
	}
	dateFile.close();
	
	do
	{
		system("CLS");
		mainMenu(&option);
		
		switch(option)
		{
			case 1:{
				creatingEmployees = true;
				while(creatingEmployees){
					createEmployees(&employees);
					
					ynCheck("Would you like to create another employee?(y or n)", &input);
					
					if(input == 'n'){
						creatingEmployees = false;
					}
					system("CLS");
				}
				break;
			}
			case 2:{
				if(employees.size() == 0){
					cout << "There are no employees to view.\nSelect option 1 to create employees.\n";
				}
				else if(employees.size() > 0){
					viewEmployees(employees);
				}
				else{
					cout << "ERROR.This shouldn't be possible.\n";
				}
				break;
			}
			case 3:{
				deletingEmployees = true;
				while(deletingEmployees){
					if(employees.size() == 0){
						cout << "There are no employees to be deleted.\nSelect option 1 to create employees.\n";
						deletingEmployees = false;
					}
					else if(employees.size() > 0){
						deleteEmployees(&employees);
						
						ynCheck("Would you like to delete another employee?(y or n)", &input);
						
						if(input == 'n'){
							deletingEmployees = false;
						}
					}
					else{
						cout << "ERROR.This shouldn't be possible.\n";
					}
				}
				break;
			}
			case 4:{//equipment drop off, create ticket
				break;
			}
			case 5:{//equipment repair, work being done, option to finish it
				break;
			}
			case 6:{//equipment picked up, moved to record keeping file
				break;
			}
			case 7:{//reporting phase, the day progresses forward
				break;
			}
			case 8:{
				ynCheck("Would you like to save your data?(y or n)", &input);
				
				if(input == 'y'){
					ofstream dateFile("currentdate.txt", ios::trunc);
					line = to_string(month);
					line.push_back('.');
					line += to_string(day);
					line.push_back('.');
					line += to_string(year);
					line.push_back('.');
					encryptFileData(&line, dateKey);
					dateFile << line;
					dateFile.close();
					
					//write out the data to the other files here
				}
				else if(input == 'n'){//clears all data so that when the program starts again, its a freash start
					ofstream dateFile("currentdate.txt", ios::trunc);
					dateFile.close();
					
					//clear out the date from the other files here
				}
				else{
					cout << "ERROR. This shouldn't be possible.\n";
				}
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
