#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED
#include"book.h"
#include "etudiant.h"
class Main:public Book,public Member
{
    int d,m,y;
public:
    Main(): Book(),Member(){};
    ~Main(){};
    void get_date(){cin>>d>>m>>y;}
    void issue_book();
    void return_book();
    bool test();
    int diff();
    friend ostream &operator<<(ostream&,Main);
};


#endif // MAIN_H_INCLUDED
