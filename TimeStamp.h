#include <iostream>
#include "Sanitization.h"

#ifndef TIMESTAMP_H
#define TIMESTAMP_H

class Date{
	private:
		int month;
		int day;
		int year;
	public:
		//Constructors
		Date();
		Date(int tempMonth, int tempDay, int tempYear);
		//Mutators
		void setMonth(int tempMonth);
		void setDay(int tempDay);
		void setYear(int tempYear);
		//Accessors
		int getMonth() const;
		int getDay() const;
		int getYear() const;
		//Other Functions
		void display();
};

class Time{
	private:
		int hour;
		int min;
	public:
		//Constructors
		Time();
		Time(int tempHour, int tempMin);
		//Mutators
		void setHour(int tempHour);
		void setMin(int tempMin);
		//Accessors
		int getHour() const;
		int getMin() const;
		//Other Functions
		void display();
};

class TimeStamp{
	private:
		Date date;
		Time time;
	public:
		//Constructors
		TimeStamp();
		TimeStamp(Date tempDate, Time tempTime);
		//Mutators
		void setDate(Date tempDate);
		void setTime(Time tempTime);
		//Accessors
		Date getDate() const;
		Time getTime() const;
		//Other Functions
		void display();
};
#endif
