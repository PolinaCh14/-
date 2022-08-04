#include "Book.h"
#include <string>
#include "Date.h"
using namespace std;
Book::Book()
{
	author = "������� ";
	name = "������� ";
	publishing_house = "������� ";
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
Book::Book(const Book& other):Date(other)// ����������� ���������
{
	this->name = other.name;
	this->author = other.author;
	this->publishing_house = other.publishing_house;
	this->publishing_year = other.publishing_year;
	this->pages = other.pages;
}
Book& Book::operator()( string name, string author, string publishing_house, int publishing_year, int pages, int day, int month, int year)//�������������� ��������� ����� �����
{
	this->name = name;
	this->author = author;
	this->publishing_house = publishing_house;
	this->publishing_year = publishing_year;
	this->pages = pages;
	this->Date::operator()(day, month, year);
	return *this;
}
Book& Book::operator= (const Book& other) //�������������� ��������� ��������� 
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
void Book::Output()//�������������� ����� ������ ����������
{
	cout << "*****************" << endl;
	cout << "����� ����� " << name << endl;
	cout << "����� ����� " << author << endl;
	cout << "г� ������� " << publishing_year << endl;
	cout << "ʳ������ ������� " << pages << endl;
	cout << "���������� �� " << publishing_house << endl;
	cout << "����� ���� ������ ����� � ����� " << day << "." << month << "." << year << endl;
	cout << "*****************" << endl;
}
ostream& operator<< (ostream& out,  Book& other)//�������������� �������� ������
{
	out << "*****************" << endl;
	out << "����� ����� " << other.name << endl;
	out << "����� ����� " << other.author << endl;
	out << "г� ������� " << other.publishing_year << endl;
	out << "ʳ������ ������� " << other.pages << endl;
	out << "���������� �� " << other.publishing_house << endl;
	other.Date::Output();
	out << "*****************" << endl;
	return out;
}

istream& operator>> (istream& in, Book& other)//�������������� �������� �����
{
	in.ignore();
	cout << "������ ����� ����� "; getline(in, other.name);
	cout << "������ �������� ������� "; getline(in, other.author);
	cout << "������ �� ������� "; in >> other.publishing_year; 
	while (cin.fail() || other.publishing_year < 1675)
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "��������, ��� ������� ����� ���� ����� �� 0 �� ������������ ��������." << endl;
		cout << "���� �����, ������ �����  ";
		in >> other.publishing_year;
	}
	in.get();
	cout << "������ ���������� �� "; getline(in, other.publishing_house);
	cout << "������ ������� ������� "; in >> other.pages; 
	while (cin.fail() || other.pages <= 0)
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "��������, ��� ������� ����� ���� ����� �� 0 �� ������������ ��������." << endl;
		cout << "���� �����, ������ �����  ";
		in >> other.pages;
	}
	cout << "������ ���� "; in >> other.day;
	while (cin.fail() || other.day <= 0|| other.day>31)
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "��������, ��� ������� ����� ���� ����� �� 0 �� ����� �� 31." << endl;
		cout << "���� �����, ������ �����  ";
		in >> other.day;
	}
	cout << "������ ����� "; in >> other.month; 
	while (cin.fail() || other.month <= 0|| other.month>12)
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "��������, ��� ������� ����� ���� ����� �� 0 �� ����� �� 12." << endl;
		cout << "���� �����, ������ �����  ";
		in >> other.month;
	}
	cout << "������ �� "; in >> other.year; 
	while (cin.fail() || other.year < 1675)
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "��������, ��� ������� ����� ���� ���� ����� �� 1675." << endl;
		cout << "���� �����, ������ �����  ";
		in >> other.year;
	}
	return in;
}

Book::~Book()
{

}