#pragma once
#include <string>
#include "Date.h"
#include<fstream> 

using namespace std;
class Book: public Date
{
protected:
	string name;
	string author;
	string publishing_house;
	int publishing_year;
	int pages;
public:
	
	Book();
	Book(string name, string author, string publishing_house, int publishing_year, int pages, int day, int month, int year);
	Book(const Book& other);// конструктор копіювання
	string getauthor();
	string getname();
	string getpublishing_house();
	int getpublishing_year();
	int getpages();
	void setauthor(string author);
	void setname(string  name);
	void setpublishing_house(string publishing_house);
	void setpublishing_year(int publishing_year);
	void setpages(int pages);
	Book& operator= (const Book& other);// перевантаження оператора присвоєння 
	Book& operator()(string name, string author,string publishing_house,int publishing_year,int pages,int day, int month, int year);//перевантаження оператора круглі дужки
	friend ostream& operator<< (ostream& out,  Book& other);// перевантаження операції виводу << 
	friend istream& operator>> (istream& in, Book& other);// перевантаження операції вводу >>  
	 void Output()override; //перевантажений метод виводу інформації
	 ~Book();
};

