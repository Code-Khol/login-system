#include <iostream>
#include <fstream>
#include <conio.h>
#include <time.h>
#include <stdlib.h>

using namespace std;

int sec_num = 0 , User_num = 0 ;

int main()
{
	system("color 2");

	void menu();
	void _register();
	void login();

	menu();

	switch(getch())
	{
		case '2' : system("cls"); _register(); break;
		case '1' : system("cls"); login(); break;
	}


}

//----------functions----------//

void menu()
{
	cout<<"--=Menu=--"<<endl;
	cout<<" 1.login "<<endl;
	cout<<" 2.register"<<endl;
}

void _register()
{
	int secur();
	fstream file_User , file_Pass , file_Info;
	string User , Pass_1 , Pass_2 ,
			Name , Email , Age ,
			Phone_Number ,
			Region;

	cout<<"select User Name: "; cin>>User; //set Username
	cout<<"select Pass Word: "; cin>>Pass_1;	//set Pass word
	cout<<"Write your Pass Word again: "; cin>>Pass_2;

	if(Pass_1 == Pass_2)
	{
		file_User.open(User + "_User.doc" , ios :: out); //creat file
		file_User<<User<<endl;
		file_Pass.open(User + "_Pass.doc" , ios :: out); //creat file
		file_Pass<<Pass_1<<endl;

		system("cls");

		file_Info.open(User + "_info.doc" , ios :: out); //creat file

		cout<<"Name: "; cin>>Name;
		file_Info<<Name<<endl;
		cout<<"Age: "; cin>>Age;
		file_Info<<Age<<endl;
		cout<<"E-mail: "; cin>>Email;
		file_Info<<Email<<endl;
		cout<<"Phone Number: "; cin>>Phone_Number;
		file_Info<<Phone_Number<<endl;
		cout<<"Region: "; cin>>Region;
		file_Info<<Region<<endl;

		system("cls");
		secur();
		if(sec_num == User_num)
		{
			cout<<"account created successfully!"<<endl;
		}
		else
			cout<<"ERROR!"<<endl;
	}
	else
		cout<<"Pass Word not match!"<<endl;
}

int secur()
{	//creat random number to increase security
	srand(time(0));
	for(int i=0 ; i<=500 ; i++)
	{
		sec_num += (rand()%10)*18;
	}
	cout<<"please write this number below: "<<sec_num<<endl;
	cin>>User_num;
}

void login()
{
	fstream file_Pass;
	string User , Pass_1 , Pass_2 ;

	cout<<"user Name: "; cin>>User;
	cout<<"Pass Word: "; cin>>Pass_1;

	file_Pass.open(User + "_Pass.doc" , ios :: in);
	file_Pass>>Pass_2;

	if(Pass_1 == Pass_2)
	{
		system("cls");
		cout<<"Wellcome"<<endl;
	}
	else
		cout<<"ERROR!"<<endl;

}
