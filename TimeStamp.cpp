#include "TimeStamp.h"

//Constructors
Date::Date() = default;
Date::Date(int tempMonth, int tempDay, int tempYear){
	setMonth(tempMonth);
	setDay(tempDay);
	setYear(tempYear);
}
//Mutators
void Date::setMonth(int tempMonth){month = tempMonth;}
void Date::setDay(int tempDay){day = tempDay;}
void Date::setYear(int tempYear){year = tempYear;}
//Accessors
int Date::getMonth() const {return month;}
int Date::getDay() const {return day;}
int Date::getYear() const {return year;}
//Other Functions
void Date::display(){
	std::cout << month << "/" << day << "/" << year << std::endl;
}

//Constructors
Time::Time() = default;
Time::Time(int tempHour, int tempMin){
	setHour(tempHour);
	setMin(tempMin);
}
//Mutators
void Time::setHour(int tempHour){hour = tempHour;}
void Time::setMin(int tempMin){min = tempMin;}
//Accessors
int Time::getHour() const {return hour;}
int Time::getMin() const {return min;}
//Other Functions
void Time::display(){
	std::cout << hour << ":" << min << std::endl;
}

//Constructors
TimeStamp::TimeStamp() = default;
TimeStamp::TimeStamp(Date tempDate, Time tempTime){
	setDate(tempDate);
	setTime(tempTime);
}
//Mutators
void TimeStamp::setDate(Date tempDate){date = tempDate;}
void TimeStamp::setTime(Time tempTime){time = tempTime;}
//Accessors
Date TimeStamp::getDate() const {return date;}
Time TimeStamp::getTime() const {return time;}
//Other Functions
void TimeStamp::display(){
	date.display();
	time.display();
}
