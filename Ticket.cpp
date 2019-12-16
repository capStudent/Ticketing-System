//Ticket.cpp

#include "Ticket.h"

//Equipment Constructors
Equipment::Equipment(){};

Equipment::Equipment(string tempName, string tempOwner)
{
	equipName = tempName;
	owner = tempOwner;
}

//Equipment Accessors
string Equipment::getEquipName(){return equipName;}
string Equipment::getOwner(){return owner;}

//Equipment Mutators
void Equipment::setEquipName(string tempName)
{
	equipName = tempName;
}

void Equipment::setOwner(string tempOwner)
{
	owner = tempOwner;
}

//Repair Constructors
Repairs::Repairs(){};

Repairs::Repairs(Employee emp, double tempHours)
{
	emp = emp;
	hours = tempHours;
}

//Repairs Accessors
Employee Repairs::getEmployee(){return emp;}
double Repairs::getHours(){return hours;}

//Repairs Mutators
void Repairs::setEmployee(Employee emp)
{
	emp = emp;
}

void Repairs::setHours(double tempHours)
{
	hours = tempHours;
}

//Parts Constructors
Parts::Parts(){};

Parts::Parts(string tempName, TimeStamp tempStamp, double tempCost)
{
	partName = tempName;
	stamp = tempStamp;
	cost = tempCost;
}

//Parts Accessors
string Parts::getPartName(){return partName;}
TimeStamp Parts::getTimeStamp(){return stamp;}
double Parts::getCost(){return cost;}

//Parts Mutators
void Parts::setPartName(string tempName)
{
	partName = tempName;
}

void Parts::setTimeStamp(TimeStamp tempStamp)
{
	stamp = tempStamp;
}
void Parts::setCost(double tempCost)
{
	cost = tempCost;
}

//Ticket Constructors
Ticket::Ticket(){};

Ticket::Ticket(string eqpName, string ownName, TimeStamp tempStamp)
{
	equip = Equipment(eqpName, ownName);
	startStamp = tempStamp;
	completion = false;
	status = 1;
	partCount = 0;
	logCount = 0;
}

//Ticket Accessors
Equipment Ticket::getEquipment(){return equip;}
void Ticket::getStartStamp(){startStamp.display();}
void Ticket::getEndStamp()
{
	if (status != 3)
		cout << "Repairs not complete.\n";
	else
		endStamp.display();
}
void Ticket::geStatus()
{
	switch (status)
	{
		case 1: cout <<"Status: Pending\n";
				break;
		case 2: cout <<"Status: In Progress\n";
				break;
		case 3: cout <<"Status: Complete\n"
					 <<"Date Completed: ";
				endStamp.display();
				break;
	}
}
bool Ticket::getCompletion(){return completion;}

//Ticket Mutators
void Ticket::setEquipment(string tempName, string tempOwner)
{
	equip = Equipment(tempName, tempOwner);
}
void Ticket::setStatus()
{
	cout << "Enter a number to set the status of the Ticket.\n"
		 << "1. Pending\n"
		 << "2. In Progress\n"
		 << "3. Certified Complete\n"
		 << "Enter Number: ";
	cin >> status;
}
//Only called to switch from false completion status to true completion status
void Ticket::setCompletion(TimeStamp tempStamp)
{
	completion = true;
	endStamp = tempStamp;
}
void Ticket::addPart(string tempName, TimeStamp tempStamp, double tempCost)
{
	partLog[partCount] = Parts(tempName, tempStamp, tempCost);
	partCount++;
}
void Ticket::logRepairs(Employee tempEmp, double tempHours)
{
	repairLog[logCount] = Repairs(tempEmp, tempHours);
	logCount++;
}

//Ticket Other
void Ticket::showParts()
{
	for(int i = 0; i < partCount; i++)
	{
		cout << "Part #"<<i+1<<"\n"
			 << "Name: "<<partLog[i].getPartName()<<"\n"
			 << "Time Installed: ";
		partLog[i].getTimeStamp().display();
		cout << "\n"
			 << "Cost: "<<partLog[i].getCost()<<"\n";
	}
}

void Ticket::showRepairs()
{
	for(int i = 0; i < logCount; i++)
	{
		cout <<"Repair #"<<i+1<<"\n";
		repairLog[i].getEmployee().display();
		cout <<"\nHours Worked: "<<repairLog[i].getHours()<<"\n";
	}
}

void Ticket::showInvoice()
{
	double totalCost, partCost, workCost;
	
	cout <<"Ticket for "<<equip.getEquipName()<<" Owned by: "<<equip.getOwner()<<"\n"
		 <<"Start Time\n";
	startStamp.display();
	switch (status)
	{
		case 1: cout <<"Status: Pending\n";
				break;
		case 2: cout <<"Status: In Progress\n";
				break;
		case 3: cout <<"Status: Complete\n"
					 <<"End Time: ";
				endStamp.display();
				break;
	}
	
	cout <<"Part Log\n";
	for(int i = 0; i < partCount; i++)
	{
		partCost += partLog[i].getCost();
		cout << "Part #"<<i+1<<"\n"
			 << "Name: "<<partLog[i].getPartName()<<"\n"
			 << "Time Installed: ";
		partLog[i].getTimeStamp().display();
		cout << "\n"
			 << "Cost: "<<partLog[i].getCost()<<"\n";
	}
	
	cout <<"Repair Log\n";
	for(int i = 0; i < logCount; i++)
	{
		workCost +=(repairLog[i].getHours() * repairLog[i].getEmployee().getRate());
		cout <<"Repair #"<<i+1<<"\n";
		repairLog[i].getEmployee().display();
		cout <<"\nHours Worked: "<<repairLog[i].getHours()<<"\n";
	}
	
	showParts();
	showRepairs();
	totalCost = partCost + workCost;
	
	cout <"---------------------------------------------\n";
	cout << "Cost of Parts: "<<partCost<<"\n"
		 << "Cost of Labor: "<<workCost<<"\n"
		 << "Total Cost: "<<totalCost<<"\n";
}














