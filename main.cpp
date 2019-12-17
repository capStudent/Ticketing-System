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

Date readInDate(string line){
	int month, day, year;
	string del = ".";
	size_t pos = 0;
	
	pos = line.find(del);
	cout << "1a\n";
	month = stoi(line.substr(0, pos).c_str());
	line.erase(0, pos + del.length());
	pos = line.find(del);
	cout << "2a\n";
	day = stoi(line.substr(0, pos).c_str());
	line.erase(0, pos + del.length());
	pos = line.find(del);
	cout << "3a\n";
	year = stoi(line.substr(0, pos).c_str());
	line.erase(0, pos + del.length());
	
	return Date(month, day, year);
}
vector<Employee> readInEmployees(string line){
	vector<Employee> tempEmployees;
	string firstName, lastName, expertise, del = ".";
	size_t pos = 0;
	int size, ID;
	
	pos = line.find(del);
	cout << "1b\n";
	size = stoi(line.substr(0, pos).c_str());
	line.erase(0, pos + del.length());
	for(auto i = 0;i < size;i++){
		pos = line.find(del);
		cout << "2b\n";
		ID = stoi(line.substr(0, pos).c_str());
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
		
		tempEmployees.push_back(Employee(ID-1, firstName, lastName, expertise));
	}
	
	return tempEmployees;
}
vector<Ticket> readInTickets(string line){
	
}

void writeOutDate(Date currentDate){
	string line = "";
	line += to_string(currentDate.getMonth());
	line += ".";
	line += to_string(currentDate.getDay());
	line += ".";
	line += to_string(currentDate.getYear());
	line += ".";
	ofstream dateFile("currentdate.txt", ios::trunc);
	dateFile << line;
	dateFile.close();
}
void writeOutEmployees(vector<Employee> employees){
	string line = "";
	line += to_string(employees.size());
	line += ".";
	for(auto i = 0;i < employees.size();i++){
		line += to_string(employees.at(i).getID());
		line += ".";
		line += employees.at(i).getFirstName();
		line += ".";
		line += employees.at(i).getLastName();
		line += ".";
		line += employees.at(i).getExpertise();
		line += ".";
	}
	ofstream employeesFile("employees.txt", ios::trunc);
	employeesFile << line;
	employeesFile.close();
}
void writeOutTickets(vector<Ticket> tickets){
	string line = "";
	for(auto i = 0;i < tickets.size();i++){
		//write all ticket info to a line
	}
	ofstream ticketsFile("tickets.txt", ios::trunc);
	ticketsFile << line;
	ticketsFile.close();
}
void writeOutRecords(vector<Ticket> records){
	string line = "";
	for(auto i = 0;i < records.size();i++){
		//write all record info to a line
	}
	ofstream recordsFile("records.txt", ios::trunc);
	recordsFile << line;
	recordsFile.close();
}

void mainMenu(int *option, Date currentDate){
	cout << "    Main Menu ";
	currentDate.display();
	cout << "--------------------------\n";
	cout << "1: Create Employees\n";
	cout << "2: View Employees\n";
	cout << "3: Delete Employees\n";
	cout << "4: Equipment Drop Off\n";
	cout << "5: Equipment Repair\n";
	cout << "6. Order Part\n";
	cout << "7: Equipment Picked Up\n";
	cout << "8. View Equipment Tickets\n";
	cout << "9: Reporting Phase\n";
	cout << "10: Save and Shut Down\n";
	cout << "--------------------------\n";
	intOptionsCheck("Select an option based on its number.", 10, option);
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
	
	ticketPTR -> at(ticketOption).logRepairs(tempEmp, hours);
}

void completeOrder(vector<Ticket> *ticketPTR,int ticketOption, Date currentDate)
{
	TimeStamp tempTimeStamp;
	tempTimeStamp = createTimeStamp(currentDate);
	
	ticketPTR -> at(ticketOption).setStatus(tempTimeStamp);
}

void orderParts(vector<Ticket> *ticketPTR, int ticketOption, Date currentDate)
{
	double cost;
	string name;
	TimeStamp tempTimeStamp;
	
	cout <<"Enter the name of the part: ";
	cin >> name;
	cout <<"Enter the cost of the part: ";
	cin >> cost;
	tempTimeStamp = createTimeStamp(currentDate);
	
	ticketPTR -> at(ticketOption).addPart(name, tempTimeStamp, cost);
}

int endOfDayMenu()
{
	int option, subchoice;
	cout <<"End of Day Menu\n"
		 <<"1. Tickets to be Invoiced\n"
		 <<"2. Incomplete Repairs\n"
		 <<"3. Flagged Tickets\n"
		 <<"Enter choice: ";
	cin >> option;
	
	if (option == 1)
		return option;
	else if (option == 2)
	{
		cout <<"Incomplete Repairs\n"
			 <<"1. Pending Tickets\n"
			 <<"2. In Progress Tickets\n"
			 <<"Enter choice: ";
		cin >> subchoice;
		if (subchoice == 1)
			return 2;
		else
			return 3;
	} else
	{
		cout <<"Flagged Tickets\n"
			 <<"1. Complete Tickets\n"
			 <<"2. Pending Tickets\n";
		cin >> subchoice;
		if (subchoice == 1)
			return 4;
		else
			return 5;
	}
}

void endOfDay(vector<Ticket> *ticketPTR)
{
	int choice, ticketCount;
	choice = endOfDayMenu();
	ticketCount = ticketPTR ->size();
	
	switch(choice)
	{
		case 1:{//Tickets to be Invoiced
			for(int i = 0; i < ticketCount; i++)
			{
				if (ticketPTR -> at(i).getStatus() == 3 && ticketPTR -> at(i).getInvoiced() == false)
					ticketPTR -> at(i).showInvoice();
			}
			break;
		}
		case 2:{//Pending Tickets
			for(int i = 0; i< ticketCount; i++)
			{
				if (ticketPTR -> at(i).getStatus() == 1)
					ticketPTR -> at(i).showInvoice();
			}
			break;
		}
		case 3:{//In Progress Tickets
			for(int i = 0; i< ticketCount; i++)
			{
				if (ticketPTR -> at(i).getStatus() == 2)
					ticketPTR -> at(i).showInvoice();
			}
			break;
		}
		case 4:{//Completed Flagged Tickets
			for(int i = 0; i< ticketCount; i++)
			{
				if (ticketPTR -> at(i).getStatus() == 3 && ticketPTR -> at(i).getHoursWorked() > 4)
					ticketPTR -> at(i).showInvoice();
			}
			break;
		}
		case 5:{//In Progress Flagged Tickets
		for(int i = 0; i< ticketCount; i++)
			{
				if (ticketPTR -> at(i).getStatus() == 2 && ticketPTR -> at(i).getHoursWorked() > 4)
					ticketPTR -> at(i).showInvoice();
			}
			break;
		}
	}

	for(int i = 0; i < ticketCount; i++)
	{
		if (ticketPTR -> at(i).getStatus() == 3 && ticketPTR -> at(i).getInvoiced() == false)
			ticketPTR -> at(i).setInvoiced();
	}
	
}

int main(){
	vector<Employee> employees;
	vector<Ticket> tickets;
	vector<Ticket> records;
	Date currentDate;
	bool creatingEmployees, deletingEmployees;
	int option, empOption, ticketOption;
	string line;
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
		mainMenu(&option, currentDate);
		
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
					viewEmployees(employees);
					intOptionsCheck("Enter a number to log work for that Employee: ", employees.size(), &empOption);
					empOption = empOption - 1;
	
					viewTickets(tickets);
					intOptionsCheck("Enter a number next to log work for that Ticket: ", tickets.size(), &ticketOption);
					ticketOption = ticketOption -1;
					logRepairWork(&tickets, ticketOption, employees.at(empOption));
				}
				break;
			}
			case 6:{//Ordering a part for a ticket
				if(employees.size() == 0){
					cout << "There are no employees to view.\nSelect option 1 to create employees.\n";
				}
				else if (tickets.size() == 0)
					cout << "There are no tickets.\n";
				else
				{
					viewTickets(tickets);
					intOptionsCheck("Enter a number next to log work for that Ticket: ", tickets.size(), &ticketOption);
					ticketOption = ticketOption -1;
					orderParts(&tickets, ticketOption, currentDate);
				}
				break;
			}
			case 7:{//equipment picked up, moved to record keeping file
				if (tickets.size() == 0)
					cout << "There are no tickets.\n";
				else
				{
					viewTickets(tickets);
					intOptionsCheck("Enter a number next to log work for that Ticket: ", tickets.size(), &ticketOption);
					ticketOption = ticketOption -1;
					completeOrder(&tickets, ticketOption, currentDate);
				}
				break;
			}
			case 8:{//Viewing all Tickets
				if(tickets.size() == 0)
					cout << "There are no tickets.\n";
				else
					viewTickets(tickets);
				break;
			}
			case 9:{//reporting phase, the day progresses forward
				endOfDay(&tickets);
				currentDate.setDay(currentDate.getDay()+1);
				break;
			}
			case 10:{
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
	}while(option != 10);
	return 0;
}
