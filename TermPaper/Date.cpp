#include "Date.h"
Date::Date() : day(0), month(0), year(0){}
Date::Date(int day, int month, int year)
{
	this->day = day;
	this->month = month;
	this->year = year;
}
Date::Date(const Date& other)//конструктор копіювання 
{
	day = other.day;
	month = other.month;
	year = other.year;
}
void Date::setday(int day)
{
	this->day = day;
}
void Date::setmonth(int month)
{
	this->month = month;
}
void Date::setyear(int year)
{
	this->year = year;
}
int Date::getday()
{
	return day;
}
int Date::getmounth()
{
	return month;
}
int Date::getyear()
{
	
	return year;
}
Date& Date::operator()(int day, int month, int year)// перевантаження оператора круглі дужки
{
	this->day = day;
	this->month = month;
	this->year = year;
	return *this;
}
ostream& operator<< (ostream& out, const Date& other)  // перевантаження операції виводу <<
{
	cout << "Повна дата запису книги в реєстр " << other.day << "." << other.month << "." << other.year << endl;
	return out;
}
Date& Date::operator=(const Date& other)//перевантаження оператора присвоєння
{
	this->day = other.day;
	this->month = other.month;
	this->year = other.year;
	return *this;
}
istream& operator>> (istream& in, Date& other)// перевантаження операції вводу >>
{
	cout << "Введіть день "; in >> other.day;
	while (cin.fail() || other.day <= 0 || other.day > 31)
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Пробачте, але вводити можна лише більше за 0 та менше за 31." << endl;
		cout << "Будь ласка, введіть знову  ";
		in >> other.day;
	}
	cout << "Введіть місяць "; in >> other.month;
	while (cin.fail() || other.month <= 0 || other.month > 12)
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Пробачте, але вводити можна лише більше за 0 та менше за 12." << endl;
		cout << "Будь ласка, введіть знову  ";
		in >> other.month;
	}
	cout << "Введіть рік "; in >> other.year;
	while (cin.fail() || other.year < 1675)
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Пробачте, але вводити можна лише роки більші за 1675." << endl;
		cout << "Будь ласка, введіть знову  ";
		in >> other.year;
	}
	return in;
}
void Date::Output()// метод виведення інформації
{
	cout << "Повна дата запису книги в реєстр " << day << "." << month << "." << year << endl;
}

Date::~Date()
{

}
