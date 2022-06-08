#include<fstream>
#include<string.h>
#include<iostream>
#include"main.h"
int adminmenu()
{
      int n;
       do {

        cout<<"\t\t [1]add book\n";
        cout<<"\t\t [2]view book\n";
        cout<<"\t\t [3]remove book\n";
        cout<<"\t\t [4]modify book\n";
        cout<<"\t\t [5]add Member\n";
        cout<<"\t\t [6]view Member\n";
        cout<<"\t\t [7]remove Member\n";
        cout<<"\t\t [8]modify Member\n";
        cout<<"\t\t [9]issue book\n";
        cout<<"\t\t[10]return book\n";
        cout<<"\t\t[11]exit\n";
        cout<<"Enter your choice: ";
        cin>>n;
        system("cls");
        if(n==1){Book b;b.add();cin.ignore();}
        else if(n==2){Book b;b.info();cin.ignore(); }
        else if(n==3){Book b;b.delet();cin.ignore(); }
        else if(n==4){Book b;b.modify();cin.ignore(); }
        else if(n==5){Member b;b.add();cin.ignore();}
        else if(n==6){Member b;b.info();cin.ignore(); }
        else if(n==7){Member b;b.delet();cin.ignore(); }
        else if(n==8){Member b;b.modify();cin.ignore(); }
        else if(n==9){Main b;b.issue_book();cin.ignore(); }
        else if(n==10){Main b;b.return_book();cin.ignore(); }
        else cout<<"invalid choice\n";
        system("cls");
    }while(n!=11);
    return 0;
}

int etudiantmenu(){
bool retour;
int jour,mois,annee;
string books[10];
string author[10];
int n;
string name ;
string f =" hi guys";
string question ="";
string reponse="";
string theme[10];
//char dic;
books[0]="learn c++";
books[1]="c++ vs c ";
books[2]="Java";
books[3]="google";
books[4]="RH for your life";
books[5]="soft skills";
books[6]="Java script , php";
books[7]="machine learning";
books[8]="python and IA";
books[9]="data science";

author[0]="Mark Twain";
author[1]="Lewis Carrol";
author[2]="Kazi Nasrul Islam";
author[3]="Coleridge";
author[4]="George Orwell";
author[5]="John singh";
author[6]="xxxx";
author[7]="yyyy";
author[8]="zzzz";
author[9]="wwww";

theme[0]="programmation c++";
theme[1]="programmation c++ and c";
theme[2]="programmation java";
theme[3]="Biographie";
theme[4]="soft skills";
theme[5]="";
theme[6]="";
theme[7]="";
theme[8]="projet d'un robot intelligent ";
theme[9]="gerer et manipuler les donnees de base de donnee";

cout<<"what's your name !?"<<endl;
 cin >> name;
//start:
do{
        retour=false;
 cout << " hi " << name <<" ! how can i help you? ";
 cin>>question;
// questions starts
do{
  if (question=="i want a book"|| question=="book"){
        cout<< "ok , I give you our list of our books exist !"<<endl;
        for(int i=0;i<=9;i++){
            cout<<i<<"-"<<books[i]<<endl;}

        cout<<"choose the numero "<<endl;
        cin>>n;
        if (n<=10){cout<<"good choice ... I will show more information about the book "<< endl;
         break ;}
         else{cout<<"this book was not found ..sorry "<<endl;
                return 0;}

        }

  else {
 	cout <<" This thing is not in my database ,as i am still learning i didnt know it \n i will improve it in my next update . \n\nSuggest your questions at Email : ensi_admin@ensi-uma.tn \n\n";
 	   return 0;}



}while(true);
 cout<<endl;
 cout<<"what's your question: theme,author,date_limit,return,reservation,thanks,good-bye"<<endl;  // end_date:The day the book is returned

for(int i=0;i<=6;i++){
    cin>>question;
    if(question=="theme"){cout<<theme[n]<<endl;}
    if(question=="author"){cout<<author[n]<<endl;}
    if(question=="date_limit"){cout<<"What day you take the book?"<<endl;
                                                      cout <<"jour:";
                                                      cin>>jour;
                                                       cout <<"mois:";
                                                       cin>>mois;
                                                       cout <<"annee:";
                                                       cin>>annee;
                                                       if (mois==12){mois=1;
                                                                    annee+=1;}
                                                        else{mois+=1;}
                                                        cout<<endl;
                                                        cout<<jour<<"/"<<mois<<"/"<<annee<<" Is that okay??"<<endl;}
   if(question=="good-bye"){cout<<"good bye"<<endl;
                            return 0;}
   if(question=="thanks"){cout<<"you're welcome 🙂 🙂 "<<endl;}
   if(question=="reservation"){cout<<"you want to reserve this book"<<endl;
                                cin>>reponse;
                                if(reponse=="yes"){cout<<"this book is reserved for you"<<endl;
                                                    cout<<"What day you take the book?"<<endl;
                                                      cout <<"jour:";
                                                      cin>>jour;
                                                       cout <<"mois:";
                                                       cin>>mois;
                                                       cout <<"annee:";
                                                       cin>>annee;
                                                       cout<<"good,Well we met on that day"<<jour<<"/"<<mois<<"/"<<annee<<endl;}
                                else{
                                    if(reponse=="no"){cout<<"okey"<<endl;}
                                    else{cout<<"your answer is not clear"<<endl;}}
                                    }
   if(question=="return"){cout<<"Do you want to go back to the beginning?"<<endl;
                            cin>>reponse;
                            if(reponse=="yes"){i=6;
                                                retour=true;
                                                break;}
                            else {break;}
                            }
   }
}while(retour==true);
    return 0;
}




int main()
{


	int opt;
	cout<<"ENSI Library Management System \n\n";
	cout<<"Main Menu \n\n";
	cout<<"1. Administrator menu"<<endl;
	cout<<"2. STUDENT menu"<<endl;
	cout<<"3. EXIT"<<endl;
	cout<<"Enter your choice  ";
	cin>>opt;
	system("cls");
	switch(opt)
	{
		case 1: adminmenu();
               break;

		case 2: etudiantmenu();
			break;
        case 3 :
            cout << " This Project made by Ichrak Hamdi, Hammam Ben Younes et Ghaith Farhat "<<endl;
            cout<<" THANKS FOR USING THIS PROJECT \n "; // end


}

}
