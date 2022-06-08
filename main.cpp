#include "main.h"
#include "etudiant.h"
#include<string>
#include <iostream>
using namespace std;
void Main::issue_book()
{
    getchar();
    string t_bookid,t_mid;
    cout<<"Enter member id: ";
    getline(cin,t_mid);
    cout<<"Enter book id: ";
    getline(cin,t_bookid);
    ifstream f1(t_mid),f2(t_bookid);
    if(!f1)
        cout<<"Member not found\n";
    if(!f2)
        cout<<"Book not found\n";
    if(!f1 || !f2)
    {
        cout<<"Can not change\n";
        return;
    }
    f1.close();
    f2.close();
    bool flag1,flag2;
    flag1=avail(t_bookid);
    if(!flag1)
        cout<<"Book is not available\n";
    flag2=nib(t_mid);
    if(!flag2)
        cout<<"You can not issue more than 3 books\n";
    if(!flag1||!flag2)
    {
        cout<<"operation failed\n";
            return;
    }
    avail_change(t_bookid,1);
    nib_change(t_mid,t_bookid,1);
    cout<<"Enter current date(d-m-y): ";
    get_date();
    fstream f(t_mid,ios::app);
    f.write((char*)this,sizeof(Main));
    f.close();

}
void Main::return_book()
{
    getchar();
    string t_bookid,t_mid;
    cout<<"Enter member id: ";
    getline(cin,t_mid);
    cout<<"Enter book id: ";
    getline(cin,t_bookid);
    ifstream f1(t_mid),f2(t_bookid);
    if(!f1)
        cout<<"Member not found\n";
    if(!f2)
        cout<<"Book not found\n";
    if(!f1 || !f2)
    {
        cout<<"Can not return\n";
        return;
    }
    f2.close();
    bool flag=avail(t_bookid);
    if(flag)
    {
        cout<<"Book is not issued\n";
        return;
    }
    f1.read((char*)this,sizeof(Member));
    while(f1.read((char*)this,sizeof(Main)))
    {
        if(t_bookid==this->Book::id)flag=1;
    }
    if(!flag)
    {
        cout<<"you have not issued this book\n";
        return;
    }
    f1.close();
    flag=test();
    if(flag){
        avail_change(t_bookid,0);
        nib_change(t_mid,t_bookid,0);
        cout<<"Book returned\n";
    }
    else
    {
        cout<<"Book not returned\n";
    }
}
bool Main::test()
{
    int d=diff();
    if(d>20)
    {
        //double f=(double)(d-20)/2;
        cout<<"You have to return the book "<<endl;
        while(1){
        cout<<"Ready to return the book ?(y/n): "<<endl;
        string c;
        cin>>c;
        if(c=="y")
        {
            cout<<"Ok great you will return the book "<<endl;

        }
        else
            return 0;
        }
    }
    return 1;
}
int Main::diff()
{
    cout<<"Enter current date(d-m-y): ";
    int d2,m2,y2;
    cin>>d2>>m2>>y2;
    int d1=d,m1=m,y1=y;
	const int month[] = {31,29,31,30,31,30,31,31,30,31,30,31} ;

	long int n1 = y1*365 + d1;
    for (int i=0; i<m1 - 1; i++)
        n1 += month[i];

    long int n2 = y2*365 + d2;
    for (int i=0; i<m2 - 1; i++)
        n2 += month[i];

    return n1 - n2;
}
ostream &operator<<(ostream &stream,Main ob)
{
    stream<<"Book id: "<<ob.Book::id<<'\n';
    stream<<"Name: "<<ob.Book::name<<'\n';
    stream<<"Date of issue: "<<ob.d<<'-'<<ob.m<<'-'<<ob.y<<'\n';
    return stream;
}

