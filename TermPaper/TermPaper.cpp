#include <iostream>
#include "Date.h"
#include"Book.h"
#include "Print.h"
#include "Library.h"
#include<Windows.h>

int main()
{
    SetConsoleCP( 1251);
    SetConsoleOutputCP(1251);
    Library library;
    library.ReadFile();
    int choice = -1;
    cout << "Доброго дня! Вас вітає бібілотека 'Барвінок' " << endl;;
    library.MissingBook();
    do
    {
        cout << "Оберіть, що саме ви хочете зробити\n";
        cout << "(1) Додати книги до бібліотеки\n";
        cout << "(2) Переглянути всі книги бібліотеки\n";
        cout << "(3) Відсортувати книги за назвою \n";
        cout << "(4) Відсортувати книги за прізвищем письменника \n";
        cout << "(5) Знайти книгу за назвою\n";
        cout << "(6) Знайти книгу за прізвищем автора\n";
        cout << "(7) Знайти книгу за видавництвом\n";
        cout << "(8) Знайти книгу за роком видання\n";
        cout << "(9) Видалити книгу з бібліотеки\n";
        cout << "(10) Записати у файл вміст бібліотеки\n";
        cout << "(0) Завершити роботу\n";
        cout << "Введіть ваш вибір тут "; cin >> choice;
        system("cls");
        switch(choice)
        {    
case 1:
{
    library.CreateALibrary();
    break;
}
case 2:
{
    library.DisplayWork();
    break;
}
case 3:
{
    library.SortByName();
    break;
}
case 4:
{
    library.SortByAuthor();
    break;
}
case 5:
{
    library.SearchForName();
    break;
}
case 6:
{
    library.SearchByAuthor();
    break;
}
case 7:
{
    library.SearchForAPublisher();
    break;
}
case 8:
{
    library.SearchByYear();
    break;
}
case 9:
{
    library.DeletingBook();
    
    break;
}
case 10:
{
    library.WritingToFile();
    break;
}
    }
    } while (choice!=0);
    
    system("pause");
    return 0;
}
   

  