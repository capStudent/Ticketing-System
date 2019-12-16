#include "Employee.h"

//Constructors
Employee::Employee() = default;
Employee::Employee(int size, std::string tempFirstName, std::string tempLastName, std::string tempExpertise){
	createID(size);
	setFirstName(tempFirstName);
	setLastName(tempLastName);
	setExpertise(tempExpertise);
}
Employee::Employee(std::string tempFirstName, std::string tempLastName, int tempID, std::string tempExpertise){
	setID(tempID);
	setFirstName(tempFirstName);
	setLastName(tempLastName);
	setExpertise(tempExpertise);
}
//Mutators
void Employee::setID(int tempID){ID = tempID;}
void Employee::setFirstName(std::string tempFirstName){firstName = tempFirstName;}
void Employee::setLastName(std::string tempLastName){lastName = tempLastName;}
void Employee::setExpertise(std::string tempExpertise)
{
	expertise = tempExpertise;
	if (expertise == "Novice")
		rate = 15.00;
	else if (expertise == "Adept")
		rate == 20.00;
	else if (expertise == "Expert")
		rate == 30.00;
	else
		rate = 50.00;
}
//Accessors
int Employee::getID() const {return ID;}
std::string Employee::getFirstName() const {return firstName;}
std::string Employee::getLastName() const {return lastName;}
std::string Employee::getExpertise() const {return expertise;}
double Employee::getRate(){return rate;}
//Other functions
void Employee::createID(int tempPreviousID){
	int tempID = tempPreviousID + 1;
	setID(tempID);
}
void Employee::display(){
	std::cout << "Name: " << firstName << " " << lastName << " ID: " << std::setw(3) << std::setfill('0')
	          << ID << " Expertise: " << expertise << std::endl
	          << "Rate: "<<rate<<"\n";
}
