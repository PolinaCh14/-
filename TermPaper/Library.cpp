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
Iterator Library::begin()// ����� ��� ��������� ������� �������� � ������
{
	return Iterator(array);
}
Iterator Library::end()// ����� ��� ��������� ���������� �������� � ������
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
Library::Library(const Library& other) //����������� ���������
{
    size = other.size;
    array = new Book[other.size];
    for (int i = 0; i < other.size; i++)
    {
        array[i] = other.array[i];
    }
}
Library& Library::operator=(const Library& other)//�������������� ����� ���������
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
void Library::CreateALibrary()//��������� ������
{
    int count; 
    cout << "������ ��� ���� ������� ����, �� ������ ������ �� �������� ";
    cin >> count;
    while (cin.fail() || count<=0)
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "��������, ��� ������� ����� ���� ����� �� 0 �� ������������ ��������." << endl;
        cout << "���� �����, ������ ����� ������� ����, ��� ������ ������� �� �������� " << endl;
        cin >> count;
    }
    if (size == 0)
    {
        size = count;
        array = new Book[size]; 
        for (int i = 0; i < size; i++)
        {
            Book tmp;
            cout << "���� ����� ������ ��� ��� ����� " << endl;
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
            cout << "���� ����� ������ ��� ��� ����� " << endl;
            cin >> tmp;
            array[i] = tmp;
            cout << "*****************" << endl;
        }
        size = sizel;
        delete[] mas;
    }
    
}
void Library::DisplayWork()//��������� ���������� �� �������
{
    if (size == 0)
    {
        cout << "�� ����, ����� ���� ���� � ��������." << endl;
    }
    else {
        for (Iterator i = begin(); i != end(); i++)
        {
            cout <<*i << endl;
        }
        
    }
}
void Library::ReadFile()//������� � �����
{
    ifstream reading;
    reading.open("D:\\������ ����\\��������\\Library.txt");
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
            throw exception("������� ��� ������� ����� \n");
        }
        reading.close();
    }
    catch (const std::exception& a)
    {
        cout << a.what();
    }
    
    ifstream file;
    array = new Book[size];
    file.open("D:\\������ ����\\��������\\Library.txt");
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
            throw exception("������� ��� ������� ����� \n");
        }
        file.close();
    }
    catch (const std::exception& a)
    {
        cout << a.what();
    }
}
void Library::WritingToFile()//����� � ����
{
    ofstream file("Library.txt", ios::app);
    if (!file.is_open())
    {
        cout << "�������! ��������� ������� ����!" << endl;
    }
    else {
        for (int i = 0; i < size; i++)
        {
            file << "����� �����: " << array[i].getname() << endl;
            file << "������� ������: " << array[i].getauthor() << endl;
            file << "����� �����������: " << array[i].getpublishing_house() << endl;
            file << "г� �������: " << array[i].getpublishing_year() << endl;
            file << "ʳ������ �������: " << array[i].getpages() << endl;
            file << "����: " << array[i].getday() << "." << array[i].getmounth() << "." << array[i].getyear() << endl;
            file << "*******************************************************************************" << endl;
        }
    }    
	file.close();
    cout << "�� ���� ��� ����� �������� � ����." << endl;
}
void Library::SortByName() //  ����� ���������� ���� �� ������ �����
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
void Library::SortByAuthor() //  ����� ���������� ���� �� �������� ������ 
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
void Library::SearchForName()// ����� ����������� ����� �� ������
{
    cout << "������ ����� ����� ��� ������\n";
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
        cout << "�� ����, ����� � ����� ������ �� ���� � ����� ��������\n";
    }
}
void Library::SearchByAuthor()// ����� ����������� ����� �� �������� ������
{
    cout << "������ ������� ������, �� ���� ������ ������ �����\n";
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
        cout << "�� ����, ������ ������ �� �� � ����� ��������\n";
    }
}
void Library::SearchForAPublisher()// ����� ����������� ����� �� ������������
{
    cout << "������ �����������, �� ���� ������ ������ �����\n";
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
        cout << "�� ����,������ ����������� �� �� � ����� ��������\n";
    }
}
void Library::SearchByYear()// ����� ����������� ����� �� ����� �������
{
    cout << "������ �� �������, �� ���� ������ ������ �����\n";
    int counter = 0;
    int temp;
    cin >> temp;
    while (cin.fail() || temp < 1675)
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "��������, ��� ������� ����� ���� ���� ����� �� 1675." << endl;
        cout << "���� �����, ������ �����  ";
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
        cout << "�� ����,������ ���� ����������� �� �� � ����� ��������\n";
    }
}
void Library::MissingBook()// ����� ������������ ������� ��'�������� �� ������������� ��������
{
    Print p;
    Date *n1;
    Book delet("����� ��������� �������", "�������", "������", 2010,835,14,11,2013);
    n1 = &delet;
    cout <<"�� ����,���� ����� ������ ��� �� ���� � ����� �������� " << endl;
    p.printer(n1);
}
void Library::DeletingBook()// ����� ��������� �������� � ������
{
    int number;
    cout << "����� � ������� ����������� ( " << size << " ) ����." << endl;
    cout << "���� ����� ������ ����� 򳺿 �����, ��� ������ �������� "; cin >> number;
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