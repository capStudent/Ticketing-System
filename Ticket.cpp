#include "Ticket.h"

//Constructors
Equipment::Equipment() = default;
Equipment::Equipment(std::string tempOwnerFirstName, std::string tempOwnerLastName, std::string tempEquipmentName){
	setOwnerFirstName(tempOwnerFirstName);
	setOwnerLastName(tempOwnerLastName);
	setEquipmentName(tempEquipmentName);
}
//Mutators
void Equipment::setOwnerFirstName(std::string tempOwnerFirstName){ownerFirstName = tempOwnerFirstName;}
void Equipment::setOwnerLastName(std::string tempOwnerLastName){ownerLastName = tempOwnerLastName;}
void Equipment::setEquipmentName(std::string tempEquipmentName){equipmentName = tempEquipmentName;}
//Accessors
std::string Equipment::getOwnerFirstName() const {return ownerFirstName;}
std::string Equipment::getOwnerLastName() const {return ownerLastName;}
std::string Equipment::getEquipmentName() const {return equipmentName;}

//Constructors
Repairs::Repairs() = default;
Repairs::Repairs(Employee tempEmployee, double tempHours){
	setEmployee(tempEmployee);
	setHours(tempHours);
}
//Mutators
void Repairs::setEmployee(Employee tempEmployee){employee = tempEmployee;}
void Repairs::setHours(double tempHours){hours = tempHours;}
//Accessors
Employee Repairs::getEmployee() const {return employee;}
double Repairs::getHours() const {return hours;}

//Constructors
Parts::Parts() = default;
Parts::Parts(std::string tempPartName, TimeStamp tempTimeStamp, double tempPartCost){
	setPartName(tempPartName);
	setTimeStamp(tempTimeStamp);
	setPartCost(tempPartCost);
}
//Mutators
void Parts::setPartName(std::string tempPartName){partName = tempPartName;}
void Parts::setTimeStamp(TimeStamp tempTimeStamp){timeStamp = tempTimeStamp;}
void Parts::setPartCost(double tempPartCost){partCost = tempPartCost;}
//Accessors
std::string Parts::getPartName() const {return partName;}
TimeStamp Parts::getTimeStamp() const {return timeStamp;}
double Parts::getPartCost() const {return partCost;}

//Constructors
Ticket::Ticket() = default;
Ticket::Ticket(std::string tempOwnerFirstName, std::string tempOwnerLastName, std::string tempEquipmentName, TimeStamp tempStamp){
	equip = Equipment(tempOwnerFirstName, tempOwnerLastName, tempEquipmentName);
	startStamp = tempStamp;
	invoiced = false;
	status = 1;
	partCount = 0;
	logCount = 0;
}
Ticket::Ticket(Equipment tempEquipment, std::vector<Repairs> tempRepairLog, std::vector<Parts> tempPartLog, bool tempInvoiced, int tempStatus, TimeStamp tempStartStamp, TimeStamp tempEndStamp, int tempPartCount, int tempLogCount){
	equip = tempEquipment;
	repairLog = tempRepairLog;
	partLog = tempPartLog;
	invoiced = tempInvoiced;
	status = tempStatus;
	startStamp = tempStartStamp;
	endStamp = tempEndStamp;
	partCount = tempPartCount;
	logCount = tempLogCount;
	
}
//Accessors
Equipment Ticket::getEquipment() const {return equip;}
std::vector<Repairs> Ticket::getRepairLog() const {return repairLog;}
std::vector<Parts> Ticket::getPartLog() const {return partLog;}
bool Ticket::getInvoiced() const {return invoiced;}
int Ticket::getStatus() const {return status;}
TimeStamp Ticket::getStartTimeStamp() const {return startStamp;}
TimeStamp Ticket::getEndTimeStamp() const {return endStamp;}
int Ticket::getPartCount() const {return partCount;}
int Ticket::getLogCount() const {return logCount;}

double Ticket::getHoursWorked(){
	double labor;
	
	for(int i = 0; i < logCount; i++)
	{
		labor += repairLog[i].getHours();
	}
	
	return labor;
}


//Ticket Mutators
void Ticket::showStatus(){
	switch (status)
	{
		case 1: std::cout <<"Status: Pending\n";
				break;
		case 2: std::cout <<"Status: In Progress\n";
				break;
		case 3: std::cout <<"Status: Complete\n"
					 <<"Date Completed: ";
				endStamp.display();
				break;
	}
}
void Ticket::setEquipment(std::string tempEquipmentName, std::string tempOwnerFirstName, std::string tempOwnerLastName){
	equip = Equipment(tempOwnerFirstName, tempOwnerLastName, tempEquipmentName);
}
void Ticket::setStatus(TimeStamp tempStamp)
{
	std::cout << "Enter a number to set the status of the Ticket.\n"
		 << "1. Pending\n"
		 << "2. In Progress\n"
		 << "3. Certified Complete\n"
		 << "Enter Number: ";
	std::cin >> status;
	
	if (status == 3)
		endStamp = tempStamp;
}
//Only called to switch from false completion status to true completion status
void Ticket::setInvoiced()
{
	invoiced = true;
}
void Ticket::addPart(std::string tempName, TimeStamp tempStamp, double tempCost)
{
	partLog.push_back(Parts(tempName, tempStamp, tempCost));
	partCount++;
	
	if (status == 1)
		status = 2;
}
void Ticket::logRepairs(Employee tempEmp, double tempHours)
{
	repairLog.push_back(Repairs(tempEmp, tempHours));
	logCount++;
	
	if (status == 1)
		status = 2;
}

//Ticket Other
void Ticket::showStartStamp(){startStamp.display();}
void Ticket::showEndStamp()
{
	if (status != 3)
		std::cout << "Repairs not complete.\n";
	else
		endStamp.display();
}
void Ticket::showParts()
{
	for(int i = 0; i < partCount; i++)
	{
		std::cout << "Part #"<<i+1<<"\n"
			 << "Name: "<<partLog[i].getPartName()<<"\n"
			 << "Time Installed: ";
		partLog[i].getTimeStamp().display();
		std::cout << "\n"
			 << "Cost: "<< partLog[i].getPartCost() << "\n";
	}
}

void Ticket::showRepairs()
{
	for(int i = 0; i < logCount; i++)
	{
		std::cout <<"Repair #"<<i+1<<"\n";
		repairLog[i].getEmployee().display();
		std::cout <<"\nHours Worked: "<<repairLog[i].getHours()<<"\n";
	}
}

void Ticket::showSummary()
{
	std::cout << "Ticket for " << equip.getEquipmentName() << " Owned by: " << equip.getOwnerFirstName() << " " << equip.getOwnerLastName() << std::endl
			  << "Start Time\n";
	startStamp.display();
	switch (status)
	{
		case 1: std::cout <<"Status: Pending\n";
				break;
		case 2: std::cout <<"Status: In Progress\n";
				break;
		case 3: std::cout <<"Status: Complete\n"
					 <<"End Time: ";
				endStamp.display();
				break;
	}
}

void Ticket::showInvoice()
{
	double totalCost, partCost, workCost;
	
	std::cout << "Ticket for " << equip.getEquipmentName() << " Owned by: " << equip.getOwnerFirstName() << " " << equip.getOwnerLastName() << std::endl
		 <<"Start Time\n";
	startStamp.display();
	switch (status)
	{
		case 1: std::cout <<"Status: Pending\n";
				break;
		case 2: std::cout <<"Status: In Progress\n";
				break;
		case 3: std::cout <<"Status: Complete\n"
					 <<"End Time: ";
				endStamp.display();
				break;
	}
	
	std::cout <<"Part Log\n";
	std::cout <<"----------------------------\n";
	if (partCount == 0)
		std::cout <<"None";
	else
	{
		for(int i = 0; i < partCount; i++)
		{
			partCost += partLog[i].getPartCost();
			std::cout << "Part #"<<i+1<<"\n"
				 << "Name: "<<partLog[i].getPartName()<<"\n"
				 << "Time Installed: ";
			partLog[i].getTimeStamp().display();
			std::cout << "\n"
				 << "Cost: "<<partLog[i].getPartCost()<<"\n";
		}
	}
	
	std::cout <<"Repair Log\n";
	std::cout <<"----------------------------\n";
	if (logCount == 0)
		std::cout <<"None";
	else
	{
		for(int i = 0; i < logCount; i++)
		{
			//workCost +=(repairLog[i].getHours() * repairLog[i].getEmployee().getRate());
			std::cout <<"Repair #"<<i+1<<"\n";
			repairLog[i].getEmployee().display();
			std::cout <<"\nHours Worked: "<<repairLog[i].getHours()<<"\n";
		}
	
	showParts();
	showRepairs();
	totalCost = partCost + workCost;
	
	std::cout <"---------------------------------------------\n";
	std::cout << "Cost of Parts: "<<partCost<<"\n"
		 << "Cost of Labor: "<<workCost<<"\n"
		 << "Total Cost: "<<totalCost<<"\n";
	}
}