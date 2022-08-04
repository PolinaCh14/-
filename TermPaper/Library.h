#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS
#include "Book.h"
#include"Iterator.h"
#include "Print.h"
#include<fstream>
#include<cstring>
#include<string>
#include<string.h>


class Library: public Book
{
protected:
	Book* array; // ����� ���� ����� Book  
	int size;// ������� �������� ������ 
public:
	
	Library(); // ����������� �� ������������� 
	Book* getlibrary();
	int getcount();
	void setlibrary(Book* arr, int size);
	void setcount(int n);
	Library(const Library& other);//����������� ���������
	Library& operator=(const Library& other);//����������� ���������
	Iterator begin(); // ����� ��� ��������� ������� �������� � ������
	Iterator end(); // ����� ��� ��������� ��������� �������� � ������
	
	void CreateALibrary();//����� ��������� ������
	void DisplayWork();//����� ������ �� ���������� �� �����
	void ReadFile();//����� ������� � �����
	void WritingToFile();//����� ������ � ����
	void SearchForName();//����� ����������� ����� �� ������
	void SearchByAuthor();//����� ����������� ����� �� �������� ������
	void SearchForAPublisher();//����� ����������� ����� �� ������������
	void SearchByYear();//����� ����������� ����� �� ����� �������
	void SortByName();//����� ���������� �� ������ �����
	void SortByAuthor();//����� ���������� �� �������� ������
	void MissingBook();//����� ������������ ������� ��'�������� �� ������������� ��������
	void DeletingBook();//����� ��������� �������� � ������
	~Library(); // ���������� 
};

