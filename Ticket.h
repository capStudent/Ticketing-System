//Ticket.h
#include <iostream>
#include "TimeStamp.h"
#include "Employee.h"

using namespace std;

#ifndef TICKET_H
#define TICKET_H

//Has equipment name and owner
class Equipment{
	public:
		Equipment();
		Equipment(string, string);
		
		string getEquipName();
		string getOwner();
		
		void setEquipName(string);
		void setOwner(string);
	private:
		string equipName;
		string owner;
};

//Has Employee and hours
class Repairs{
	public:
		Repairs();
		Repairs(Employee, double);
		
		Employee getEmployee();
		double getHours();
		
		void setEmployee(Employee);
		void setHours(double);
	private:
		Employee emp;
		double hours;
};

//Has Timestamp and string for name
class Parts{
	public:
		Parts();
		Parts(string, TimeStamp, double);
		
		string getPartName();
		TimeStamp getTimeStamp();
		double getCost();
		
		void setPartName(string);
		void setTimeStamp(TimeStamp);
		void setCost(double);
	private:
		TimeStamp stamp;
		string partName;
		double cost;
};

//Status: 1 = Pending, 2 = In Progress, 3 = Complete
class Ticket{
	public:
		Ticket();
		Ticket(string, string, TimeStamp);
		
		Equipment getEquipment();
		void getStartStamp();
		void getEndStamp();
		void geStatus();
		bool getCompletion();
		
		void setEquipment(string, string);
		void setStatus();
		void setCompletion(TimeStamp);
		void addPart(string, TimeStamp, double);
		void logRepairs(Employee, double);
		
		//Shows List of Parts
		void showParts();
		//Shows list of Repairs
		void showRepairs();
		//Calculates current costs
		void showInvoice();
	private:
		Equipment equip;
		Repairs repairLog[100];
		Parts partLog[100];
		
		bool completion;
		int status;
		TimeStamp startStamp;
		TimeStamp endStamp;
		int partCount;
		int logCount;
};
#endif
