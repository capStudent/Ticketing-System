#include "Sanitization.h"

void cinIntCheck(std::string message, int *optionPTR){//make sure a user enters an int when ask
	while(std::cin.fail()){//runs when cin has failed
		std::cin.clear();//clears the error flag on cin
		std::cin.ignore(256,'\n');//ignores 256 characters and stops when it encounters a newline
		std::cout << "ERROR\nYou must enter a number.\nTry again.\n";//cout an error message
		std::cout << message << std::endl;//cout the original prompt
		std::cin >> *optionPTR;//accepts the users input
	}//continues until the users has entered an int
}

void cinDoubleCheck(std::string message, double *optionPTR){//make sure a user enters an double when ask
	while(std::cin.fail()){//runs when cin has failed
		std::cin.clear();//clears the error flag on cin
		std::cin.ignore(256,'\n');//ignores 256 characters and stops when it encounters a newline
		std::cout << "ERROR\nYou must enter a number.\nTry again.\n";//cout an error message
		std::cout << message << std::endl;//cout the original prompt
		std::cin >> *optionPTR;//accepts the users input
	}//continues until the users has entered a double
}

void possitiveIntCheck(std::string message, int *inputPTR){//makes sure the user enterd is a possitive int
	std::cout << message << std::endl;//cout the prompt for the user
	std::cin >> *inputPTR;//accepts the users input
	
	cinIntCheck(message, inputPTR);//checks to make sure the cin didn't fail
    
    if(*inputPTR < 0){//checks to see if the input is possitive
		std::cout << "ERROR\nThe number enterd must be possitive.\n";//cout an error message
		possitiveIntCheck(message, inputPTR);
	}//continues until the users has entered a possitive int
}

void possitiveDoubleCheck(std::string message, double *inputPTR){//makes sure the user enterd is a possitive double
	std::cout << message << std::endl;//cout the prompt for the user
	std::cin >> *inputPTR;//accepts the users input
	
	cinDoubleCheck(message, inputPTR);//checks to make sure the cin didn't fail
	
    if(*inputPTR < 0){//checks to see if the input is possitive
		std::cout << "ERROR\nThe number enterd must be possitive.\n";//cout an error message
		possitiveDoubleCheck(message, inputPTR);
	}//continues until the users has entered a possitive double
}

void intOptionsCheck(std::string message, int numOfOptions, int *optionPTR){//makes sure the user selected one of the menu options
	std::cout << message << std::endl;//cout the prompt for the user
	std::cin >> *optionPTR;//accepts the users input
	
	cinIntCheck(message, optionPTR);//checks to make sure the cin didn't fail
	
    if(*optionPTR < 1 || *optionPTR > numOfOptions){//checks to see if the user selected a valid option
    	std::cout << "ERROR\nMust select a valid option\nEnter ";//cout an error message and starts a prompt of the possible options
		for(auto i = 1;i < numOfOptions;i++){//loops until i equals numOfOptions
			std::cout << i << " or ";//cout "i or "
		}//creates a message giving the users almost every possible option for them to enterd
		std::cout << numOfOptions << ".\nTry again.\n";//cout the last possible option for the user to enter
		intOptionsCheck(message, numOfOptions, optionPTR);
	}
}

void militaryHourCheck(std::string message, int *hourPTR){
	std::cout << message << std::endl;//cout the prompt for the user
	std::cin >> *hourPTR;//accepts the users input
	
	cinIntCheck(message, hourPTR);//checks to make sure the cin didn't fail
    
    if(*hourPTR > 24 || *hourPTR < 0){//checks to see if a possible hour has been entered
		std::cout << "ERROR\nThe number enterd must be between 0 and 24.\n";//cout an error message
		militaryHourCheck(message, hourPTR);
	}//continues until the users has entered a possitive int
}
void minCheck(std::string message, int *minPTR){
	std::cout << message << std::endl;//cout the prompt for the user
	std::cin >> *minPTR;//accepts the users input
	
	cinIntCheck(message, minPTR);//checks to make sure the cin didn't fail
    
    if(*minPTR > 59 || *minPTR < 0){//checks to see if a possible hour has been entered
		std::cout << "ERROR\nThe number enterd must be between 0 and 59.\n";//cout an error message
		minCheck(message, minPTR);
	}//continues until the users has entered a possitive int
}
void monthCheck(std::string message, int *monthPTR){
	std::cout << message << std::endl;//cout the prompt for the user
	std::cin >> *monthPTR;//accepts the users input
	
	cinIntCheck(message, monthPTR);//checks to make sure the cin didn't fail
    
    if(*monthPTR > 12 || *monthPTR < 1){//checks to see if a possible hour has been entered
		std::cout << "ERROR\nThe number enterd must be between 1 and 12.\n";//cout an error message
		monthCheck(message, monthPTR);
	}//continues until the users has entered a possitive int
}
void dayCheck(std::string message, int *dayPTR){
	std::cout << message << std::endl;//cout the prompt for the user
	std::cin >> *dayPTR;//accepts the users input
	
	cinIntCheck(message, dayPTR);//checks to make sure the cin didn't fail
    
    if(*dayPTR > 31 || *dayPTR < 1){//checks to see if a possible hour has been entered
		std::cout << "ERROR\nThe number enterd must be between 1 and 31.\n";//cout an error message
		dayCheck(message, dayPTR);
	}//continues until the users has entered a possitive int
}
void yearCheck(std::string message, int *yearPTR){
	std::cout << message << std::endl;//cout the prompt for the user
	std::cin >> *yearPTR;//accepts the users input
	
	cinIntCheck(message, yearPTR);//checks to make sure the cin didn't fail
    
    if(*yearPTR > 9999 || *yearPTR < 1000){//checks to see if the number is a four digit number
		std::cout << "ERROR\nThe number enterd must be a four digit number.\n";//cout an error message
		yearCheck(message, yearPTR);
	}//continues until the users has entered a possitive four digit int
}

void ynCheck(std::string message, char *inputPTR){//makes sure the user enters either y or n
	std::cout << message << std::endl;//cout the prompt for the user
	std::cin >> *inputPTR;//accepts the users input
	
	tolower(*inputPTR);//changes input to be lowercase
	
	if(*inputPTR != 'y' && *inputPTR != 'n'){//checks if input is either a y or a n
		//if input is not a y or a n
		std::cout << "ERROR\nEnter either y or n.\nTry again.\n";//cout an error message
		ynCheck(message, inputPTR);//recursively calls itself
	}
}

void configName(std::string message, std::string *namePTR){//configures a name to common upper and lowercase form
	std::cout << message << std::endl;//cout the prompt for the user
	std::cin >> *namePTR;//accepts the users input
	
	char fLetter = namePTR -> at(0);//saves the first character of name to fLetter
	//changes the string so that the whole things is lowercase, then makes the first letter uppercase
	transform(namePTR -> begin(), namePTR -> end(), namePTR -> begin(), ::tolower);
	toupper(fLetter);
	namePTR -> at(0) = fLetter;
}
