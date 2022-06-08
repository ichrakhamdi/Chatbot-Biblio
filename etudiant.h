#ifndef ETUDIANT_H_INCLUDED
#define ETUDIANT_H_INCLUDED
#include<bits/stdc++.h>
#include<string>
#include<iostream>
using namespace std;
class Member
{
protected:
    int noOfBook;
    char m_id[10],name[20],address[20],phone[20];
    char id[10];
    char spec[20];
public:
    Member(){};
    virtual ~Member(){};
    bool nib(string);
    void info();
    void add();
    void modify();
    void delet();
    void nib_change(string,string,int);
    friend ostream &operator<<(ostream&,Member);
};



#endif // ETUDIANT_H_INCLUDED
