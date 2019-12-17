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
	completion = false;
	status = 1;
	partCount = 0;
	logCount = 0;
}
//Accessors
Equipment Ticket::getEquipment() const {return equip;}
void Ticket::getStartStamp(){startStamp.display();}
void Ticket::getEndStamp()
{
	if (status != 3)
		std::cout << "Repairs not complete.\n";
	else
		endStamp.display();
}
void Ticket::getStatus()
{
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
bool Ticket::getCompletion() const {return completion;}

//Ticket Mutators
void Ticket::setEquipment(std::string tempEquipmentName, std::string tempOwnerFirstName, std::string tempOwnerLastName){
	equip = Equipment(tempOwnerFirstName, tempOwnerLastName, tempEquipmentName);
}
void Ticket::setStatus()
{
	std::cout << "Enter a number to set the status of the Ticket.\n"
		 << "1. Pending\n"
		 << "2. In Progress\n"
		 << "3. Certified Complete\n"
		 << "Enter Number: ";
	std::cin >> status;
}
//Only called to switch from false completion status to true completion status
void Ticket::setCompletion(TimeStamp tempStamp)
{
	completion = true;
	endStamp = tempStamp;
}
void Ticket::addPart(std::string tempName, TimeStamp tempStamp, double tempCost)
{
	partLog[partCount] = Parts(tempName, tempStamp, tempCost);
	partCount++;
}
void Ticket::logRepairs(Employee tempEmp, double tempHours)
{
	repairLog[logCount] = Repairs(tempEmp, tempHours);
	logCount++;
	
	if (status == 1)
		status = 2;
}

//Ticket Other
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
