#include "etudiant.h"
#include "main.h"
#include<iostream>
using namespace std;
void Member::add()
{
    getchar();
    cout<<"Enter personal id: ";
    cin.getline(id,10);
    cout<<"Enter speciality name: ";
    cin.getline(spec,20);
    cout<<"Enter member name: ";
    cin.getline(name,20);
    cout<<"Enter address: ";
    cin.getline(address,20);
    cout<<"Enter phone no.: ";
    cin.getline(phone,20);
    cout<<"Enter member id: ";
    cin.getline(m_id,10);
    noOfBook=0;
    fstream f;
    f.open(m_id,ios::out);
    f.write((char*)this,sizeof(Member));
    f.close();
}
void Member::delet()
{
    cout<<"enter member id:";
    getchar();
    string i;getline(cin,i);
    if(!remove(i.c_str()))cout<<"Member deleted\n";
    else cout<<"Member not found\n";
}
void Member::info()
{
    cout<<"Member id: ";
    getchar();
    string i;getline(cin,i);
    fstream f;
    f.open(i,ios::in);
    if(!f){cout<<"member not found\n";return;}
    f.read((char*)this,sizeof(Member));
    cout<< *this;
    Main ob;
    for(int i=0;i<noOfBook;i++){

        f.read((char*)&ob,sizeof(Main));
        cout<<ob;
    }
    f.close();
}
void Member::modify()
{
    getchar();
    cout<<"Member id: ";
    string s;getline(cin,s);
    ifstream f(s);
    if(!f)
    {
        cout<<"Book not found\n";
        return;
    }
    f.read((char*)this,sizeof(Member));
    string c;
    cout<<"Member id: "<<m_id;
    cout<<"\nchange (y/n)? ";
    getline(cin,c);
    if(c=="y")
    {
        cout<<"Enter new id: ";
        cin>>m_id;
    }
    cout<<"Student id: "<<id;
    cout<<"\nchange (y/n)? ";
    getline(cin,c);
    if(c=="y")
    {
        cout<<"Enter new id: ";
        cin>>id;
    }
    cout<<"speciality name: "<<spec;
    cout<<"\nchange (y/n)? ";
    getline(cin,c);
    if(c=="y")
    {
        cout<<"Enter new department name: ";
        cin.getline(spec,20);
    }
    cout<<"Member name: "<<name;
    cout<<"\nchange (y/n)? ";
    getline(cin,c);
    if(c=="y")
    {
        cout<<"Enter new name: ";
        cin.getline(name,20);
    }
    cout<<"Address: "<<address;
    cout<<"\nchange (y/n)? ";
    getline(cin,c);
    if(c=="y")
    {
        cout<<"Enter new address: ";
        cin.getline(address,20);
    }
    cout<<"Phone no.: "<<phone;
    cout<<"\nchange (y/n)? ";
    getline(cin,c);
    if(c=="y")
    {
        cout<<"Enter new phone no.: ";
        cin.getline(phone,20);
    }
    ofstream t("temp");
    t.write((char*)this,sizeof(Member));
    f.close();
    t.close();
    remove(s.c_str());
    rename("temp",s.c_str());
}
bool Member::nib(string i)
{
    ifstream f(i);
    f.read((char*)this,sizeof(Member));
    f.close();
    return (noOfBook<3);
}
void Member::nib_change(string s,string b,int j)
{
    ifstream f(s);
    f.read((char*)this,sizeof(Member));
    Main ob;
    ofstream t("temp");
    if(j){

        noOfBook++;
        t.write((char*)this,sizeof(Member));
        while(f.read((char*)&ob,sizeof(Main)))
            t.write((char*)&ob,sizeof(Main));

    }
    else
    {
        noOfBook--;
        t.write((char*)this,sizeof(Member));
        while(f.read((char*)&ob,sizeof(Main))) {
            if(b==ob.get_id())continue;
            t.write((char*)&ob,sizeof(Main));
        }
    }
    f.close();
    t.close();
    remove(s.c_str());
    rename("temp",s.c_str());
}
ostream &operator<<(ostream &stream,Member ob)
{
    stream<<"Member id: "<<ob.m_id<<'\n';
    stream<<"Personal id: "<<ob.id<<'\n';
    stream<<"speciality: "<<ob.spec<<'\n';
    stream<<"Name: "<<ob.name<<'\n';
    stream<<"Address: "<<ob.address<<'\n';
    stream<<"Phone no.: "<<ob.phone<<'\n';
    stream<<"No. of books issued: "<<ob.noOfBook<<'\n';
    return stream;
}
