#pragma once
#include <string>
#include <iostream>
#include <windows.h>
using namespace std;

class Date
{
protected:
	int day;
	int month;
	int year;
public:
	
	Date();
	Date(int day, int month, int year);
	Date(const Date& other);//конструктор копіювання
	void setday(int day);
	void setmonth(int month);
	void setyear(int day);
	int getday();
	int getmounth();
	int getyear();
	virtual void Output(); // метод виведення інформації  
	Date& operator= (const Date& other);//перевантаження операції присвоєння
    Date& operator()(int day, int month, int year);//перевантаження операції круглі дужки
	friend ostream& operator<< (ostream& out, const Date& other);// перевантаження операції виводу << 
	friend istream& operator>> (istream& in, Date& other);// перевантаження операції вводу >>   
	virtual ~Date();
};

