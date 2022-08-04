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
	Book* array; // масив полів класу Book  
	int size;// кількість елементів масиву 
public:
	
	Library(); // конструктор за замовчуванням 
	Book* getlibrary();
	int getcount();
	void setlibrary(Book* arr, int size);
	void setcount(int n);
	Library(const Library& other);//конструктор копіювання
	Library& operator=(const Library& other);//конструктор присвоєння
	Iterator begin(); // метод для отримання першого елемента в массиві
	Iterator end(); // метод для отримання останньог елемента в массиві
	
	void CreateALibrary();//метод створення масиву
	void DisplayWork();//метод виводу на інформації на екран
	void ReadFile();//метод читання з файлу
	void WritingToFile();//метод запису у файл
	void SearchForName();//метод знаходження книги за назвою
	void SearchByAuthor();//метод знаходження книги за прізвищем автора
	void SearchForAPublisher();//метод знаходження книги за видавництвом
	void SearchByYear();//метод знаходження книги за роком видання
	void SortByName();//метод сортування за назвою книги
	void SortByAuthor();//метод сортування за прізвищем автора
	void MissingBook();//метод демонстрації пізнього зв'язування та поліморфічного кластеру
	void DeletingBook();//метод видалення елементу з масива
	~Library(); // дестурктор 
};

