#include "Employee.h"

//Constructors
Employee::Employee() = default;
Employee::Employee(int size, std::string tempFirstName, std::string tempLastName, std::string tempExpertise){
	createID(size);
	setFirstName(tempFirstName);
	setLastName(tempLastName);
	setExpertise(tempExpertise);
	determineRate();
}
Employee::Employee(int tempID, std::string tempFirstName, std::string tempLastName, std::string tempExpertise, double tempRate){
	setID(tempID);
	setFirstName(tempFirstName);
	setLastName(tempLastName);
	setExpertise(tempExpertise);
	setRate(tempRate);
}
//Mutators
void Employee::setID(int tempID){ID = tempID;}
void Employee::setFirstName(std::string tempFirstName){firstName = tempFirstName;}
void Employee::setLastName(std::string tempLastName){lastName = tempLastName;}
void Employee::setExpertise(std::string tempExpertise){expertise = tempExpertise;}
void Employee::setRate(double tempRate){rate = tempRate;}
//Accessors
int Employee::getID() const {return ID;}
std::string Employee::getFirstName() const {return firstName;}
std::string Employee::getLastName() const {return lastName;}
std::string Employee::getExpertise() const {return expertise;}
double Employee::getRate() const {return rate;}
//Other functions
void Employee::createID(int tempPreviousID){
	int tempID = tempPreviousID + 1;
	setID(tempID);
}
void Employee::determineRate(){
	if(expertise == "Novice"){
		rate = 100;
	}
	else if(expertise == "Adept"){
		rate = 150;
	}
	else if(expertise == "Expert"){
		rate = 200;
	}
	else if(expertise == "Master"){
		rate = 250;
	}
	else{
		std::cout << "ERROR.This should be impossible.\n";
	}
}
void Employee::display(){
	std::cout << "Name: " << firstName << " " << lastName << " ID: " << std::setw(3) << std::setfill('0') << ID << " Expertise: " << expertise << " Rate: " << rate << std::endl;
}
