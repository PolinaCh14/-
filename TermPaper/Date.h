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
	Date(const Date& other);//����������� ���������
	void setday(int day);
	void setmonth(int month);
	void setyear(int day);
	int getday();
	int getmounth();
	int getyear();
	virtual void Output(); // ����� ��������� ����������  
	Date& operator= (const Date& other);//�������������� �������� ���������
    Date& operator()(int day, int month, int year);//�������������� �������� ����� �����
	friend ostream& operator<< (ostream& out, const Date& other);// �������������� �������� ������ << 
	friend istream& operator>> (istream& in, Date& other);// �������������� �������� ����� >>   
	virtual ~Date();
};

