#include<iostream>
#include<unistd.h>
#include "guess game.h"
#include "new map.h"
#include "PhoneBook.h"
#include "FoodMart.h"
#include "sudoku.h"
#include "Nayapay.h"
using namespace std;


int main(){
	
	initial:
	char choice;
	cout<<"---WElCOME TO MINI SMARTPHONE---"<<endl;
	cout<<"1- GOOGLE MAPS"<<endl;
	cout<<"2- AKINATOR"<<endl;
	cout<<"3- PHONEBOOK"<<endl;
	cout<<"4- Food Mart"<<endl;
	cout<<"5- SODUKU"<<endl;
	cout<<"6- Nayapay"<<endl;	
	cout<<"Select the Option:";
	cin>>choice;
	
	system("cls");
	switch(choice)
	{
		case '1':
			cityorcountry();
			sleep(1);
			system("cls");
			goto initial;
			break;
		case '2':
			animaltree guess;
			guess.select();
			system("cls");
			goto initial;
			break;
		case '3':
			insertion_from_file("phonedata.txt");
			system("cls");
			goto initial;
			break;
		case '4':
			insert_file_data("Food.txt");
			system("cls");
			goto initial;
			break;
		case '5':
			start_program();
			system("cls");
			goto initial;
			break;
		case '6':
			start_nayapay_app();
			system("cls");
			goto initial;
		break;			
		case '7':
			exit(0);
			break;
		default:
			
			cout<<"Wrong Option Selected! Select Again"<<endl;
			goto initial;				
	}

}
