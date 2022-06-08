#include<iostream>
#include<fstream>
#include <string>
#include "book.h"
using namespace std;
void Book::add()
{
    getchar();
    cout<<"Enter Book id: ";
    cin>>id;
    cout<<"Enter Book name: ";
    cin.getline(name,20);
    cin>>name;
    cout<<"Enter Book author: ";
    cin.getline(author,20);
    cin>>author;
    cout<<"Enter Book theme: ";
    cin.getline(theme,20);
    cin>>theme;
    available=1;
    fstream f;
    f.open(id,ios::out);
    f.write((char*)this,sizeof(Book));
    f.close();
}
void Book::info()
{
    cout<<"Book id: ";
    getchar();
    string i;getline(cin,i);
    fstream f;
    f.open(i,ios::in);
    if(!f){cout<<"book not found\n";return;}
    f.read((char*)this,sizeof(Book));
    cout<<*this;
    f.close();
}
void Book::delet()
{
    cout<<"enter book id:";
    getchar();
    string i;getline(cin,i);
    if(!remove(i.c_str()))cout<<"Book deleted\n";
    else cout<<"Book not found\n";
}


bool Book::avail(string bk_id)
{
    ifstream f(bk_id);
    f.read((char*)this,sizeof(Book));
    f.close();
    return available;
}
void Book::avail_change(string bk_id,int i=0)
{
    ifstream f(bk_id);
    f.read((char*)this,sizeof(Book));
    if(i)available=0;
    else available=1;
    ofstream t("temp");
    t.write((char*)this,sizeof(Book));
    f.close();
    t.close();
    remove(bk_id.c_str());
    rename("temp",bk_id.c_str());
}
void Book::modify()
{
    getchar();
    cout<<"Book id: ";
    string s;getline(cin,s);
    ifstream f(s);
    if(!f)
    {
        cout<<"Book not found\n";
        return;
    }
    f.read((char*)this,sizeof(Book));
    string c;
    cout<<"Book id: "<<id;
    cout<<"\nchange (y/n)? ";
    getline(cin,c);
    if(c=="y")
    {
        cout<<"Enter new id: ";
        cin>>id;
    }
    cout<<"Book name: "<<name;
    cout<<"\nchange (y/n)? ";
    getline(cin,c);
    if(c=="y")
    {
        cout<<"Enter new name: ";
        cin.getline(name,20);
    }
    cout<<"Author name: "<<author;
    cout<<"\nchange (y/n)? ";
    getline(cin,c);
    if(c=="y")
    {
        cout<<"Enter new Author name: ";
        cin.getline(author,20);
    }
    cout<<"book theme: "<<theme;
    cout<<"\nchange (y/n)? ";
    getline(cin,c);
    if(c=="y")
    {
        cout<<"Enter new theme: ";
        cin>>theme;
    }
    ofstream t("temp");
    t.write((char*)this,sizeof(Book));
    f.close();
    t.close();
    remove(s.c_str());
    rename("temp",s.c_str());
}
ostream &operator<<(ostream &stream,Book ob)
{
    stream<<"Book id: "<<ob.id<<'\n';
    stream<<"Name: "<<ob.name<<'\n';
    stream<<"Author name: "<<ob.author<<'\n';
    stream<<"Available: ";(ob.available)?stream<<"yes\n":stream<<"no\n";
    stream<<"theme: "<<ob.theme<<'\n';
    return stream;
}
