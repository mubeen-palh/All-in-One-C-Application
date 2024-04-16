#include<iostream>
#include<Windows.h> 
#include <unistd.h>
#include<fstream>
using namespace std;

class node{
	public:
		//data	
			string que;
			node *left;
			node *right;
		//constructor 
			node (string a)
			{
				que=a;
				left=NULL;
				right=NULL;		
			}
};
	//GLOBAL FUNCTION FOR INSTRUCTIONS AND choosiong an animal	
		void list()
		{
			for(int j=5;j>0;j--)
			{
				string a[17]={"LION","PANDA","RABBIT","DUCK","OSTRICH","HAWK","SPARROW","CROCODILE","SNAKE","GOLDFISH","SALMON","FROG","ANT","COCKROACH","SCORPION","EARTHWORM","FLUKE WORM"};
				cout<<"--------------------------------GUESS THE ANIMAL-----------------------------"<<endl<<endl;
				cout<<"CHOOSE THE ANIMAL FROM THE LIST AND COMPUTER WILL GUESS ANIMAL USING HINTS"<<endl<<endl;		
				//printing the list
				cout<<"-------------------------------------------------------------------------------"<<endl<<endl;
				cout<<"LIST OF ANIMALS:"<<endl;
				for(int i=0;i<16;i++)
				{
					cout<<a[i]<<",";	
				}	
				cout<<a[16]<<endl<<endl;;
				cout<<"----------------------------GAME WILL START IN --------------------------------"<<endl;
				cout<<"------------------------------------"<<j<<"------------------------------------------"<<endl;
				sleep(2);
				system("cls");
			}	
		}
class animaltree{
	node *root;
	int win;
	int lose;
	int total;
		//Function to build the tree of questions for guessing the animal
		void buildtree()
		{
			node *q1=new node("Is Animal A Vertebrate? :");
			root=q1;				
			node *q2=new node("Is Animal A Warm Blooded? :");
			q1->left=q2;			//q1 right tree left//	
			node *q3=new node("Is Animal A Mammal? :");	//spelling of mammal
			q2->left=q3;			//q2 right tree left//
			node *q4=new node("Is Animal A Carnivore? :");
			q3->left=q4;			//q3 right tree left//
			node *q5=new node("LION");
			q4->left=q5;
			node *q6=new node("Does it like Bamboo to eat? :");
			q4->right=q6;
			node *q7=new node("Panda");
			q6->left=q7;
			node *q8=new node("Rabbit");
			q6->right=q8;
			node *q9=new node("Can that Animal Fly? :");
			q3->right=q9;
			node *q10=new node("Is it A Predator? :");
			q9->left=q10;		//q9 right tree left//
			node *q11=new node("HAWK");
			node *q12=new node("Sparrow");
			q10->left=q11;
			q10->right=q12;
			node *q13=new node("Does it Like to Swim? :");
			q9->right=q13;
			node *q14=new node("DUCK");
			node *q15=new node("Ostritch"); //speeling of Ostritch
			q13->left=q14;
			q13->right=q15;
			node *q16=new node("Is Animal A Reptile? :");
			q2->right=q16;
			node *q17=new node("Does it have Legs? :");
			q16->left=q17;			//q16 right tree left//
			node *q18=new node("CROCODILE");
			node *q19=new node("SNAKE");
			q17->left=q18;
			q17->right=q19;
			node *q20=new node("Does it always live in Water? :");
			q16->right=q20;
			node *q21=new node("Does the Name of Animal starts with Gold? :");
			q20->left=q21;			//q20 right tree left//
			node *q22=new node("GOLD FISH");
			node *q23=new node("SALMON");
			q21->left=q22;
			q21->right=q23;
			node *q24=new node("FROG");
			q20->right=q24;
			node *q25=new node("Is it with Joint Legs? :");
			q1->right=q25;
			node *q26=new node("Does Animal have 3 Pair of Legs? :");
			q25->left=q26;			//q25 right tree left
			node *q27=new node("Does Name start with an A? :");
			q26->left=q27;        //q26 right tree left//
			node *q28=new node("ANT");
			node *q29=new node("COCKROACH");
			q27->left=q28;
			q27->right=q29;
			node *q30=new node("SCORPION");
			q26->right=q30;
			node *q31=new node("Is it Worm like? :");
			q25->right=q31;
			node *q32=new node("Earthworm");
			node *q33=new node("Fluke Worm");
			q31->left=q32;
			q31->right=q33;
			
		}
		//guessing animal using hints
		void guessanima(node *root)
		{
			char option; //for yes or no
			if (root->left==NULL && root->right==NULL)
			{
				cout<<endl<<root->que<<" is the Guess"<<endl;
				cout<<"Is the GUESS correct?";
				xy:
				cin>>option;
				if(option=='Y'||option=='y')
				{
					total++;
					win++;
					cout<<"Total Wins: "<<win<<endl;
					ofstream out("guess game.dat");
					out<<total<<endl;
					out<<win<<endl;
					out<<lose<<endl;
					out.close();
				}
				else if(option=='N'||option=='n')
				{
					total++;
					lose++;
					cout<<"OOPS! Wrong Guess"<<endl;
					ofstream out("guess game.dat");
					out<<total<<endl;
					out<<win<<endl;
					out<<lose<<endl;
					out.close();
				}
				else
				{
					cout<<"Wrong Option Selected!!"<<endl;
					goto xy;
				}
			}
			else
			{
				//using recursion to find animal
			 fy:	
				cout<<root->que;
				cin>>option;
				if(option=='Y'||option=='y')	//if yes than left sub tree
				{
					guessanima(root->left);
				}
				else if(option=='N'||option=='n')		//if no than right sub tree
				{
					guessanima(root->right);
				}	
				else
				{	
					cout<<"Wrong Option Selected!!"<<endl;
					goto fy;
				}
			}
		}
	public:

		void guesstheanimal()
		{
			buildtree();
			list();
			ifstream in("guess game.dat");
			in>>total;
			in>>win;
			in>>lose;
			in.close();
			guessanima(root);
		}
		
		void select()
		{
			start:
			char press;
			cout<<"1- Play the Game"<<endl;
			cout<<"2- Show Stats of Game"<<endl;
			cout<<"3- Exit"<<endl;
			cout<<"Press the Option:";
			cin>>press;
			system("cls");
			switch (press)
			{
				case '1':
					{
						guesstheanimal();
						sleep(1);
						system("cls");
						goto start;
						break;
					}
				case '2':
					{
						ifstream in("guess game.dat");
						in>>total;
						in>>win;
						in>>lose;
						in.close();
						
						cout<<"Total Game:"<<total<<"\tGame Won:"<<win<<"\tGame Lost:"<<lose<<endl;
						sleep(1);
						system("cls");
						goto start;
						break;
					}
				case '3':
					//exit	
					break;
				default:
					{
						cout<<"Wrong Option selected !!"<<endl;
						cout<<"Press again"<<endl;
						sleep(1);
						system("cls");	
						goto start;
						break;
					}
			}
		}
		
};

int main(){
	animaltree guess;
	guess.select();
}
