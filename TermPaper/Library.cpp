#include "Library.h"
Library::Library() 
{ 
	array = nullptr;
	size = 0; 
}
int Library::getcount()
{
	return size;
}
Book* Library::getlibrary()
{
	return array;
}
Iterator Library::begin()// метод для отримання першого елемента в массиві
{
	return Iterator(array);
}
Iterator Library::end()// метод для отримання останнього елемента в массиві
{
	return Iterator(array+size);
}
void Library::setlibrary(Book* arr, int sizel)
{
    arr = array;
    sizel = size;
}
void Library::setcount(int n)
{
    size = n;
    array = new Book[size];
}
Library::Library(const Library& other) //конструктор копіювання
{
    size = other.size;
    array = new Book[other.size];
    for (int i = 0; i < other.size; i++)
    {
        array[i] = other.array[i];
    }
}
Library& Library::operator=(const Library& other)//перевантажений метод присвоєння
{
    if (this!=&other)
    {
        delete[]array;
        array = new Book[size = other.size];
        for (int i = 0; i < other.size; i++)
        {
            array[i] = other.array[i];
        }
    }
    return *this;
}
void Library::CreateALibrary()//створення масиву
{
    int count; 
    cout << "Введіть яку саме кількість книг, Ви хочете додати до бібліотеки ";
    cin >> count;
    while (cin.fail() || count<=0)
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Пробачте, але вводити можна лише більше за 0 та цілочисельнні значення." << endl;
        cout << "Будь ласка, введіть знову кількість книг, яку хочете занести до бібілотеки " << endl;
        cin >> count;
    }
    if (size == 0)
    {
        size = count;
        array = new Book[size]; 
        for (int i = 0; i < size; i++)
        {
            Book tmp;
            cout << "Будь ласка введіть дані про книгу " << endl;
            cin >> tmp;
            array[i] = tmp;
            cout << "*****************" << endl;

        }
    }
    else
    {
        Book* mas = new Book[size];   
        int sizel = size + count;
        for (int i = 0; i < size; i++)
        {
            mas[i] = array[i];
        }
        array = new Book[sizel]; 
        for (int i = 0; i < size; i++)
        {
            array[i] = mas[i];
        }        
        for (int i = size; i < sizel; i++)
        {
            Book tmp;
            cout << "Будь ласка введіть дані про книгу " << endl;
            cin >> tmp;
            array[i] = tmp;
            cout << "*****************" << endl;
        }
        size = sizel;
        delete[] mas;
    }
    
}
void Library::DisplayWork()//виведення інформації на консоль
{
    if (size == 0)
    {
        cout << "На жаль, зараз немає книг у бібліотеці." << endl;
    }
    else {
        for (Iterator i = begin(); i != end(); i++)
        {
            cout <<*i << endl;
        }
        
    }
}
void Library::ReadFile()//читання з файлу
{
    ifstream reading;
    reading.open("D:\\перший курс\\курсовая\\Library.txt");
    char c = reading.get();
    try
    {
        if (reading)
        {
            while (!reading.eof())
            {
                if (c == ';')
                {
                    size++;
                }
                c = reading.get();
            }
        }
        else 
        {
            throw exception("Помилка при відкритті файлу \n");
        }
        reading.close();
    }
    catch (const std::exception& a)
    {
        cout << a.what();
    }
    
    ifstream file;
    array = new Book[size];
    file.open("D:\\перший курс\\курсовая\\Library.txt");
    try
    {
        char* ch;
        char line[500];
        if (file)
        {
            for (int i = 0; i < size; i++)
            {
                file.getline(line, 500, ';');
                ch = strtok(line, ",");
                if (strlen(ch) > 1)
                {
                    file.ignore(1);
                    array[i].setname(ch);
                    ch = strtok(NULL, ",");
                    array[i].setauthor(ch);
                    ch = strtok(NULL, ",");
                    array[i].setpublishing_house(ch);
                    char* temp = strtok(NULL, ",");
                    array[i].setpages(atoi(temp));
                    temp = strtok(NULL, ",");
                    array[i].setpublishing_year(atoi(temp));
                    temp = strtok(NULL, ",");
                    array[i].setday(atoi(temp));
                    temp = strtok(NULL, ",");
                    array[i].setmonth(atoi(temp));
                    temp = strtok(NULL, ",");
                    array[i].setyear(atoi(temp));
                }
            }
        }
        else
        {
            throw exception("Помилка при відкритті файлу \n");
        }
        file.close();
    }
    catch (const std::exception& a)
    {
        cout << a.what();
    }
}
void Library::WritingToFile()//запис у файл
{
    ofstream file("Library.txt", ios::app);
    if (!file.is_open())
    {
        cout << "Помилка! Неможливо відкрити файл!" << endl;
    }
    else {
        for (int i = 0; i < size; i++)
        {
            file << "Назва книги: " << array[i].getname() << endl;
            file << "Прізвище автора: " << array[i].getauthor() << endl;
            file << "Назва видавництва: " << array[i].getpublishing_house() << endl;
            file << "Рік видання: " << array[i].getpublishing_year() << endl;
            file << "Кількість сторінок: " << array[i].getpages() << endl;
            file << "Дата: " << array[i].getday() << "." << array[i].getmounth() << "." << array[i].getyear() << endl;
            file << "*******************************************************************************" << endl;
        }
    }    
	file.close();
    cout << "Всі данні про книги записано у файл." << endl;
}
void Library::SortByName() //  метод сортування книг за назвою книги
{
    Book tmp;
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (array[i].getname() > array[j].getname())
            {
                tmp = array[i];
                array[i] = array[j];
                array[j] = tmp;
            }
        }
    }
}
void Library::SortByAuthor() //  метод сортування книг за прізвищем автора 
{
    Book tmp;
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (array[i].getauthor() > array[j].getauthor())
            {
                tmp = array[i];
                array[i] = array[j];
                array[j] = tmp;
            }
        }
    }
}
void Library::SearchForName()// метод знаходження книги за назвою
{
    cout << "Введіть назву книги яку шукаєте\n";
    Print printer;
    int counter=0;
    string temp;
    cin.ignore();
    getline(cin,temp);
    for (Iterator i = begin(); i != end(); i++)
    {
        if (temp == (*i).getname())
        {
           
            cout << *i;
            counter++;
            
        }
    }
    if (counter==0)
    {
        cout << "На жаль, книгу з такою назвою ще немає в нашій бібліотеці\n";
    }
}
void Library::SearchByAuthor()// метод знаходження книги за прізвищем автора
{
    cout << "Введіть прізвище автора, за яким будете шукати книгу\n";
    int counter = 0;
    string temp;
    cin.ignore();
    getline(cin, temp);
    for (Iterator i = begin(); i != end(); i++)
    {
        if (temp == (*i).getauthor())
        {
            
            cout << *i;
            counter++;
            
        }
    }
    if (counter == 0)
    {
        cout << "На жаль, такого автора не має в нашій бібліотеці\n";
    }
}
void Library::SearchForAPublisher()// метод знаходження книги за видавництвом
{
    cout << "Введіть видавництво, за яким будете шукати книгу\n";
    int counter = 0;
    string temp;
    cin.ignore();
    getline(cin, temp);
    for (Iterator i = begin(); i != end(); i++)
    {
        if (temp == (*i).getpublishing_house())
        {
            
            cout << *i;
            counter++;
            
        }
    }
    if (counter == 0)
    {
        cout << "На жаль,такого видавництва не має в нашій бібліотеці\n";
    }
}
void Library::SearchByYear()// метод знаходження книги за роком видання
{
    cout << "Введіть рік видання, за яким будете шукати книгу\n";
    int counter = 0;
    int temp;
    cin >> temp;
    while (cin.fail() || temp < 1675)
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Пробачте, але вводити можна лише роки більші за 1675." << endl;
        cout << "Будь ласка, введіть знову  ";
        cin >> temp;
    }
    for (Iterator i = begin(); i != end(); i++)
    {
        if (temp == (*i).getpublishing_year())
        {
            
            cout << *i;
            counter++;
            
        }
    }
    if (counter == 0)
    {
        cout << "На жаль,такого року видавництва не має в нашій бібліотеці\n";
    }
}
void Library::MissingBook()// метод демонстрації пізнього зв'язування та поліморфічного кластеру
{
    Print p;
    Date *n1;
    Book delet("Музей покинутих секретів", "Забужко", "Комора", 2010,835,14,11,2013);
    n1 = &delet;
    cout <<"На жаль,цієї книги деякий час не буде в нашій бібліотеці " << endl;
    p.printer(n1);
}
void Library::DeletingBook()// метод видалення елемента з масива
{
    int number;
    cout << "Наразі у бібіотеці знаходиться ( " << size << " ) книг." << endl;
    cout << "Будь ласка оберіть номер тієї книги, яку хочете видалить "; cin >> number;
    Book* arr = new Book[size]; 
    for (int i = 0; i < size; i++)
    {
        arr[i] = array[i];
    }
    int n = 0;
    size--;
    array = new Book[size];
    for (int i = 0; i <= size; i++)
    {
        if (i != number - 1)
        {
            array[n] = arr[i];
            n++;
        }
    }
    delete[] arr;
}
Library::~Library()
{
    delete[] array;
}