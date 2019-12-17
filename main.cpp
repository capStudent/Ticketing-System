#include <iostream>
#include <fstream>
#include <iomanip>
#include "TimeStamp.h"
#include "Employee.h"
#include "Ticket.h"
#include "Sanitization.h"
using namespace std;

Date setCurrentDate(){
	Date currentDate;
	bool settingDate = true;
	int month, day, year;
	char input;
	
	while(settingDate){
		system("CLS");
		monthCheck("Enter the month (in number form):", &month);
		dayCheck("Enter the day (in number form):", &day);
		yearCheck("Enter year (in four digit number form):", &year);
		
		currentDate = Date(month, day, year);
		
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
	return currentDate;
}

void decryptFileData(string *linePTR, char key){
	for(auto i = 0;i < linePTR -> size();i++){
			linePTR -> at(i) = linePTR -> at(i)^key;
	}
}
Date readInDate(string line){
	int month, day, year;
	string del = ".";
	size_t pos = 0;
	
	decryptFileData(&line, 'D');
	
	pos = line.find(del);
	month = stoi(line.substr(0, pos));
	line.erase(0, pos + del.length());
	pos = line.find(del);
	day = stoi(line.substr(0, pos));
	line.erase(0, pos + del.length());
	pos = line.find(del);
	year = stoi(line.substr(0, pos));
	line.erase(0, pos + del.length());
	
	return Date(month, day, year);
}
vector<Employee> readInEmployees(string line){
	string firstName, lastName, expertise, del = ".";
	size_t pos = 0;
	double rate;
	int ID;
	
	decryptFileData(&line, 'E');
	
	pos = line.find(del);
	ID = stoi(line.substr(0, pos));
	line.erase(0, pos + del.length());
	pos = line.find(del);
	firstName = line.substr(0, pos);
	line.erase(0, pos + del.length());
	pos = line.find(del);
	lastName = line.substr(0, pos);
	line.erase(0, pos + del.length());
	pos = line.find(del);
	expertise = line.substr(0, pos);
	line.erase(0, pos + del.length());
	pos = line.find(del);
	rate = stoi(line.substr(0, pos));
	line.erase(0, pos + del.length());
}
vector<Ticket> readInTickets(string line){
	
}

void encryptFileData(string *linePTR, char key){
	for(auto i = 0;i < linePTR -> size();i++){
			linePTR -> at(i) = linePTR -> at(i)^key;
	}
}
void writeOutDate(Date currentDate){
	string line = "";
	line += to_string(currentDate.getMonth());
	line.push_back('.');
	line += to_string(currentDate.getDay());
	line.push_back('.');
	line += to_string(currentDate.getYear());
	line.push_back('.');
	encryptFileData(&line, 'D');
	ofstream dateFile("currentdate.txt", ios::trunc);
	dateFile << line;
	dateFile.close();
}
void writeOutEmployees(vector<Employee> employees){
	string line = "";
	for(auto i = 0;i < employees.size();i++){
		line += to_string(employees.at(i).getID());
		line.push_back('.');
		line += employees.at(i).getFirstName();
		line.push_back('.');
		line += employees.at(i).getLastName();
		line.push_back('.');
		line += employees.at(i).getExpertise();
		line.push_back('.');
		line += to_string(employees.at(i).getRate());
		line.push_back('.');
	}
	encryptFileData(&line, 'E');
	ofstream employeesFile("employees.txt", ios::trunc);
	employeesFile << line;
	employeesFile.close();
}
void writeOutTickets(vector<Ticket> tickets){
	string line = "";
	for(auto i = 0;i < tickets.size();i++){
		//write all ticket info to a line
	}
	encryptFileData(&line, 'T');
	ofstream ticketsFile("tickets.txt", ios::trunc);
	ticketsFile << line;
	ticketsFile.close();
}
void writeOutRecords(vector<Ticket> records){
	string line = "";
	for(auto i = 0;i < records.size();i++){
		//write all ticket info to a line
	}
	encryptFileData(&line, 'T');
	ofstream recordsFile("records.txt", ios::trunc);
	recordsFile << line;
	recordsFile.close();
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
	cout << "7. View Equipment Tickets\n";
	cout << "8: Reporting Phase\n";
	cout << "9: Save and Shut Down\n";
	cout << "-------------------------\n";
	intOptionsCheck("Select an option based on its number.", 9, option);
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
	intOptionsCheck("Enter the number next to the Employee to delete it.", employeesPTR -> size(), &option);
	option = option - 1;
	employeesPTR -> erase(employeesPTR -> begin() + option);
}

TimeStamp createTimeStamp(Date tempDate){
	int tempHour, tempMin;
	
	militaryHourCheck("Enter hour (in military time):", &tempHour);
	minCheck("Enter minutes:", &tempMin);
	
	Time tempTime(tempHour, tempMin);
	
	TimeStamp tempTimeStamp(tempDate, tempTime);
	
	return tempTimeStamp;
}

void equipmentDropOff(vector<Ticket> *ticketPTR, Date currentDate){
	TimeStamp tempTimeStamp;
	string tempCustomerFirstName, tempCustomerLastName, tempEquipmentName;
	cout << "Enter customer's first name:\n";
	cin >> tempCustomerFirstName;
	cout << "Enter customer's last name:\n";
	cin >> tempCustomerLastName;
	cout << "Enter equipment name:\n";
	cin >> tempEquipmentName;
	
	tempTimeStamp = createTimeStamp(currentDate);
	
	ticketPTR -> push_back(Ticket(tempCustomerFirstName, tempCustomerLastName, tempEquipmentName, tempTimeStamp));
}

void viewTickets(vector<Ticket> tempTicket)
{
	for(int i = 0;i < tempTicket.size();i++){
		cout << i + 1 << " - ";
		tempTicket.at(i).showSummary();
	}
}

void logRepairWork(vector<Ticket> *ticketPTR, int ticketOption, Employee tempEmp)
{
	double hours;
	cout << "Enter the hours to be logged on the ticket: ";
	cin >> hours;
	
	ticketPTR->logRepairs(tempEmp, hours);
	//tickets.at(ticketOption).logRepairs(employees.at(empOption), hours);
}

int main(){
	vector<Employee> employees;
	vector<Ticket> tickets;
	vector<Ticket> records;
	Date currentDate;
	bool creatingEmployees, deletingEmployees;
	string line;
	int option;
	char input;
	
	ifstream dateFile("currentdate.txt");
	dateFile >> line;
	
	if(line.size() == 0){
		cout << "Welcome to your ticketing software.\n";
		currentDate = setCurrentDate();
		system("PAUSE");
	}
	else if(line.size() > 0){
		currentDate = readInDate(line);
		line.clear();
		
		ifstream employeeFile("employees.txt");
		employeeFile >> line;
		if(line.size() > 0){
			employees = readInEmployees(line);
		}
		employeeFile.close();
		line.clear();
		
		ifstream ticketFile("tickets.txt");
		ticketFile >> line;
		if(line.size() > 0){
			tickets = readInTickets(line);
		}
		ticketFile.close();
		
		cout << "Welcome back to your ticketing software.\n";
		cout << "Today's date is ";
		currentDate.display();
		system("PAUSE");
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
				if(employees.size() == 0){
					cout << "There are no employees to view.\nSelect option 1 to create employees.\n";
				}
				else if(employees.size() > 0){
					equipmentDropOff(&tickets, currentDate);
				}
				else{
					cout << "ERROR.This shouldn't be possible.\n";
				}
				break;
			}
			case 5:{//Log Work on Ticket
				if(employees.size() == 0){
					cout << "There are no employees to view.\nSelect option 1 to create employees.\n";
				}
				else if (tickets.size() == 0)
					cout << "There are no tickets.\n";
				else
				{
					int empOption, ticketOption;
					viewEmployees(employees);
					intOptionsCheck("Enter a number to log work for that Employee: ", employees.size(), &empOption);
					empOption = empOption - 1;
	
					viewTickets(tickets);
					intOptionsCheck("Enter a number next to log work for that Ticket: ", tickets.size(), &ticketOption);
					ticketOption = ticketOption - 1;
					logRepairWork(&tickets, ticketOption, employees.at(empOption));
				}
				break;
			}
			case 6:{//equipment picked up, moved to record keeping file
				break;
			}
			case 7:{//Viewing all Tickets
				if(tickets.size() == 0)
					cout << "There are no tickets.\n";
				else
					viewTickets(tickets);
				break;
			}
			case 8:{//reporting phase, the day progresses forward
				break;
			}
			case 9:{
				ynCheck("Would you like to save your data?(y or n)", &input);
				
				if(input == 'y'){
					writeOutDate(currentDate);
					writeOutEmployees(employees);
					writeOutTickets(tickets);
					writeOutRecords(records);
				}
				else if(input == 'n'){//clears all data so that when the program starts again, its a freash start
					ofstream dateFile("currentdate.txt", ios::trunc);
					dateFile.close();
					ofstream employeesFile("employees.txt", ios::trunc);
					employeesFile.close();
					ofstream ticketsFile("tickets.txt", ios::trunc);
					ticketsFile.close();
					ofstream recordsFile("records.txt", ios::trunc);
					recordsFile.close();
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
