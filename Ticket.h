#include <iostream>
#include <vector>
#include "TimeStamp.h"
#include "Employee.h"

#ifndef TICKET_H
#define TICKET_H

//Has equipment name and owner
class Equipment{
	private:
		std::string ownerFirstName;
		std::string ownerLastName;
		std::string equipmentName;
	public:
		//Constructors
		Equipment();
		Equipment(std::string tempOwnerFirstName, std::string tempOwnerLastName, std::string tempEquipmentName);
		//Mutators
		void setOwnerFirstName(std::string tempOwnerFirstName);
		void setOwnerLastName(std::string tempOwnerLastName);
		void setEquipmentName(std::string tempEquipmentName);
		//Accessors
		std::string getOwnerFirstName() const;
		std::string getOwnerLastName() const;
		std::string getEquipmentName() const;
};

//Has Employee and hours
class Repairs{
	private:
		Employee employee;
		double hours;
	public:
		//Constructors
		Repairs();
		Repairs(Employee tempEmployee, double tempHours);
		//Mutators
		void setEmployee(Employee tempEmployee);
		void setHours(double tempHours);
		//Accessors
		Employee getEmployee() const;
		double getHours() const;
};

//Has Timestamp and string for name
class Parts{
	private:
		std::string partName;
		TimeStamp timeStamp;
		double partCost;
	public:
		//Constructors
		Parts();
		Parts(std::string tempPartName, TimeStamp tempTimeStamp, double tempPartCost);
		//Mutators
		void setPartName(std::string tempPartName);
		void setTimeStamp(TimeStamp tempTimeStamp);
		void setPartCost(double tempPartCost);
		//Accessors
		std::string getPartName() const;
		TimeStamp getTimeStamp() const;
		double getPartCost() const;
};

//Status: 1 = Pending, 2 = In Progress, 3 = Complete
class Ticket{
	private:
		Equipment equip;
		std::vector<Repairs> repairLog;
		std::vector<Parts> partLog;
		bool completion;
		int status;
		TimeStamp startStamp;
		TimeStamp endStamp;
		int partCount;
		int logCount;
	public:
		//Constructors
		Ticket();
		Ticket(std::string tempOwnerFirstName, std::string tempOwnerLastName, std::string tempEquipmentName, TimeStamp tempStamp);
		//Mutators
		void setEquipment(std::string tempEquipmentName, std::string tempOwnerFirstName, std::string tempOwnerLastName);
		void setStatus();
		void setCompletion(TimeStamp);
		void addPart(std::string, TimeStamp, double);
		void logRepairs(Employee, double);
		//Accessors
		Equipment getEquipment() const;
		void getStartStamp();
		void getEndStamp();
		void getStatus();
		bool getCompletion() const;
		
		//Shows List of Parts
		void showParts();
		//Shows list of Repairs
		void showRepairs();
		//Calculates current costs
		void showInvoice();
};
#endif
