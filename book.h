#ifndef BOOK_H_INCLUDED
#define BOOK_H_INCLUDED
#include <string>
#include<iostream>
using namespace std;
class Book
{
protected:
    char id[10];
    bool available;
    char name[30],author[30];
    char theme[50];
public:
    Book(){};
    virtual ~Book(){};
    void info();
    bool avail(string);
    void avail_change(string,int);
    string get_id(){return id;}
    void add();
    void modify();
    void delet();
    friend ostream &operator<<(ostream &,Book);
};

#endif // BOOK_H_INCLUDED
