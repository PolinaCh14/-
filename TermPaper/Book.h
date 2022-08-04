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
	Book(const Book& other);// ����������� ���������
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
	Book& operator= (const Book& other);// �������������� ��������� ��������� 
	Book& operator()(string name, string author,string publishing_house,int publishing_year,int pages,int day, int month, int year);//�������������� ��������� ����� �����
	friend ostream& operator<< (ostream& out,  Book& other);// �������������� �������� ������ << 
	friend istream& operator>> (istream& in, Book& other);// �������������� �������� ����� >>  
	 void Output()override; //�������������� ����� ������ ����������
	 ~Book();
};

