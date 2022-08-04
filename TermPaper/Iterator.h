#pragma once
#include"Book.h"
class Iterator
{
protected:
    Book* i;
public:
    explicit Iterator(Book* i1 = 0) : i(i1) {} // конструктор ініціалізації 
    Iterator(const Iterator& x) : i(x.i) {} // конструктор копіювання 
    // перевантажені операції 
    Iterator& operator=(const Iterator& x)
    {
        i = x.i;
        return *this;
    }
    Book& operator*() const { return *i; }
    Iterator& operator++ () { ++i; return *this; }
    Iterator& operator-- () { --i; return *this; }
    Iterator& operator++ (int) { i++; return *this; }
    Iterator& operator-- (int) { i--; return *this; }
    Iterator operator+ (int n) { return Iterator(i + n); }
    Iterator operator- (int n) { return Iterator(i - n); }
    bool operator==(const Iterator& x)const { return i == x.i; }
    bool operator!=(const Iterator& x)const { return i != x.i; }
    bool operator<(const Iterator& x)const { return i < x.i; }
    bool operator>(const Iterator& x)const { return i > x.i; }
    
    friend int operator-(const Iterator& x, const Iterator& y)
    {
        return x.i - y.i;
    }
};

