#include "Book.h"
#include <string>
#include "Date.h"
using namespace std;
Book::Book()
{
	author = "Невідомо ";
	name = "Невідомо ";
	publishing_house = "Невідомо ";
	publishing_year = 0;
	pages = 0;
}
Book::Book(string name, string author, string publishing_house, int publishing_year, int pages, int day, int month, int year) : Date(day, month, year)
{
	this->name = name;
	this->author = author;
	this->publishing_house = publishing_house;
	this->publishing_year = publishing_year;
	this->pages = pages;
}
Book::Book(const Book& other):Date(other)// конструктор копіювання
{
	this->name = other.name;
	this->author = other.author;
	this->publishing_house = other.publishing_house;
	this->publishing_year = other.publishing_year;
	this->pages = other.pages;
}
Book& Book::operator()( string name, string author, string publishing_house, int publishing_year, int pages, int day, int month, int year)//перевантаження оператора круглі дужки
{
	this->name = name;
	this->author = author;
	this->publishing_house = publishing_house;
	this->publishing_year = publishing_year;
	this->pages = pages;
	this->Date::operator()(day, month, year);
	return *this;
}
Book& Book::operator= (const Book& other) //перевантаження оператора присвоєння 
{
	this->name = other.name;
	this->author = other.author;
	this->publishing_house = other.publishing_house;
	this->publishing_year = other.publishing_year;
	this->pages = other.pages;
	this->Date::operator=(other);
	return *this;
}

string Book::getauthor()
{
	return author;
}
string Book::getname()
{
	return name;
}
string Book::getpublishing_house()
{
	return publishing_house;
}
int Book::getpublishing_year()
{
	return publishing_year;
}
int Book::getpages()
{
	return pages;
}
void Book::setauthor(string author)
{
	this->author = author;
}
void Book::setname(string  name)
{
	this->name = name;
}
void Book::setpublishing_house(string publishing_house)
{
	this->publishing_house = publishing_house;
}
void Book::setpublishing_year(int publishing_year)
{
	this->publishing_year = publishing_year;
}
void Book::setpages(int pages)
{
	this->pages = pages;
}
void Book::Output()//перевизначений метод виводу інформації
{
	cout << "*****************" << endl;
	cout << "Назва книги " << name << endl;
	cout << "Автор книги " << author << endl;
	cout << "Рік видання " << publishing_year << endl;
	cout << "Кількість сторінок " << pages << endl;
	cout << "Видавничий дім " << publishing_house << endl;
	cout << "Повна дата запису книги в реєстр " << day << "." << month << "." << year << endl;
	cout << "*****************" << endl;
}
ostream& operator<< (ostream& out,  Book& other)//перевантажений оператор виводу
{
	out << "*****************" << endl;
	out << "Назва книги " << other.name << endl;
	out << "Автор книги " << other.author << endl;
	out << "Рік видання " << other.publishing_year << endl;
	out << "Кількість сторінок " << other.pages << endl;
	out << "Видавничий дім " << other.publishing_house << endl;
	other.Date::Output();
	out << "*****************" << endl;
	return out;
}

istream& operator>> (istream& in, Book& other)//перевантажений оператор вводу
{
	in.ignore();
	cout << "Введіть назву книги "; getline(in, other.name);
	cout << "Введіть призвище авотора "; getline(in, other.author);
	cout << "Введіть рік видання "; in >> other.publishing_year; 
	while (cin.fail() || other.publishing_year < 1675)
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Пробачте, але вводити можна лише більше за 0 та цілочисельнні значення." << endl;
		cout << "Будь ласка, введіть знову  ";
		in >> other.publishing_year;
	}
	in.get();
	cout << "Введіть видавничий дім "; getline(in, other.publishing_house);
	cout << "Введіть кількість сторінок "; in >> other.pages; 
	while (cin.fail() || other.pages <= 0)
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Пробачте, але вводити можна лише більше за 0 та цілочисельнні значення." << endl;
		cout << "Будь ласка, введіть знову  ";
		in >> other.pages;
	}
	cout << "Введіть день "; in >> other.day;
	while (cin.fail() || other.day <= 0|| other.day>31)
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Пробачте, але вводити можна лише більше за 0 та менше за 31." << endl;
		cout << "Будь ласка, введіть знову  ";
		in >> other.day;
	}
	cout << "Введіть місяць "; in >> other.month; 
	while (cin.fail() || other.month <= 0|| other.month>12)
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

Book::~Book()
{

}