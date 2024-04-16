#include<iostream>
#include<fstream>
using namespace std;

class node{
	public:
		
		string first_name;
		string last_name;
		string contact;
		string email;
		node* left;
		node* right;
		int height;
		
};

class AVL{
	public:
		node* root;
		
	int height(node* N){
		
		if(N==NULL){
			return 0;
		}
		
		return N->height;
		
	}
	
	int get_balance_factor(node* N){
		
		if(N==NULL){
			return 0;
		}
		  return height(N->left)- height(N->right);
	}
	
	int max (int a, int b){
		return (a > b )? a:b;
	}
	
	node* right_rotation(node* n){
		node* X= n->left;
		node* T2=X->right;
		
		X->right=n;
		n->left=T2;
		
		n->height= max(height(n->left), height(n->right) + 1);
		X->height= max(height(X->left), height(X->right) + 1);
		return X;
		
	}
	
	 node* left_rotation(node* n){
		node* Y= n->right;
		node* T2=Y->left;
		
		Y->left=n;
		n->right=T2;
		
		n->height= max(height(n->left), height(n->right) + 1);
		Y->height= max(height(Y->left), height(Y->right) + 1);
		return Y;
		
	}
	
	
	node* newNode(string na, string la, string cont, string mail)
	{
	    node* n = new node();
	    n->first_name = na;
	    n->last_name = la;
	    n->contact=cont;
	    n->email=mail;
	    n->left = NULL;
	    n->right = NULL;
	    n->height = 1; 
	    
	    return(n);
	}
	
	
	node* insert(node* n , string na, string la, string cont, string mail){
		
		if(n==NULL){
			return newNode(na, la, cont, mail);
		}
		
		else if (na < n->first_name){
			n->left=insert(n->left, na,la, cont, mail);
		}
		
		else if (na > n->first_name){
			n->right=insert(n->right, na, la, cont, mail);
		}
		
		else{
			cout<<"\n\nNo duplicate nodes are allowed!"<<endl;
		}
		
		n->height = 1 + max(height(n->left),
                        height(n->right));
 
		
		int balance_fact=get_balance_factor(n);
		
		if(balance_fact > 1 && na < n->left->first_name){
			return right_rotation(n);
		}
		
	    if(balance_fact < -1 && na > n->right->first_name){
			return left_rotation(n);
		}
		
		if(balance_fact > 1 && na > n->left->first_name){
			n->left=left_rotation(n->left);
			return right_rotation(n);
		}
		
	    if(balance_fact < -1 && na < n->right->first_name){
			n->right=right_rotation(n->right);
			return left_rotation(n);
		}
		
		return n;
		
	}		
		
	node* add_contact(node* n){
		
		string name1,name2, contact, mail;
		
		cout<<"Enter the first name: ";
		cin>>name1;
		
		cout<<"\n\nEnter the last name: ";
		cin>>name2;
		
		cout<<"\n\nEnter the Contact Number: ";
		cin>>contact;
		
		cout<<"\n\nEnter Email: ";
		cin>>mail;
		
		insert(n, name1, name2, contact, mail);

		
	}
	
	
	
	
	
		
	void showAscending(node* root){
		
		if(root != NULL){

			showAscending(root->left);
			cout<<"|Name : "<<root->first_name<<" "<<root->last_name<<" \t"<<"|Contact No : "<<root->contact<<"\t"<<"|Email : "<<root->email<<endl;
			showAscending(root->right);
			
		}
		
	}
	
	
	void showDescending(node *root)
	{
		
   	 if(root != NULL)
      {
	   	  showDescending(root->right);
	      cout<<"|Name : "<<root->first_name<<" "<<root->last_name<<" \t"<<"|Contact No : "<<root->contact<<"\t"<<"|Email : "<<root->email<<endl;
	      showDescending(root->left);
   	 }
   	 
	}
	
	void search_from_phonebook(node* root, string name){
		
		if(root ==  NULL){
		
			cout<<"Sorry! No Record found"<<endl;
			return;
			
		}
		
		
		if(root->first_name == name){
			
		   cout<<" Found!!"<<endl;	
		   cout<<"|Name : "<<root->first_name<<" "<<root->last_name<<" \t"<<"|Contact No : "<<root->contact<<"\t"<<"|Email : "<<root->email<<endl;
			
		}
		
		
		if(name < root->first_name){
			
			search_from_phonebook(root->left, name);
			
		}
		
		if(name > root->first_name){
			
			search_from_phonebook(root->right, name);
			
		}
		
		
		
		
	 		
	 }
	 
	 node* find_min(node* root){
		if(root==NULL){
			return NULL;
		}
		
		if(root->left == NULL){
			return root;
		}
		
		else{
			find_min(root->left);
			
		}
	 }	
	 
	  node* delete_contact(node* n, string nam){
		 
		 if(n== NULL){
			return n;
		  }
		
		if(n->first_name == nam){
			
			if(n->left == NULL && n->right==NULL){
				delete n;
				return NULL;
			}
		
			if(n->left==NULL && n->right!=NULL){
				node* temp=n->right;
				delete n;
				return temp;
			}
			
			if(n->left!=NULL && n->right==NULL){
				node* temp=n->left;
				delete n;
				return temp;
			}
		
			if(n->left!=NULL && n->right!=NULL){
				node* min=find_min(n->left);
				n->first_name=min->first_name;
				n->last_name=min->last_name;
				n->contact=min->contact;
				n->email=min->email;
				n->left=delete_contact(n->right, min->first_name);
			}
			
			
		}
		
		else if(nam > n->first_name){
			n->right=delete_contact(n->right,nam);
			return n;
		}
		
		else{
			n->left=delete_contact(n->left,nam);
			return n;
		}
		
		
		 n->height = 1 + max(height(n->left),
                        height(n->right));
 
		
		int balance_fact=get_balance_factor(n);
		
		if(balance_fact > 1 && nam < n->left->first_name){
			return right_rotation(n);
		}
		
	    if(balance_fact < -1 && nam > n->right->first_name){
			return left_rotation(n);
		}
		
		if(balance_fact > 1 && nam > n->left->first_name){
			n->left=left_rotation(n->left);
			return right_rotation(n);
		}
		
	    if(balance_fact < -1 && nam < n->right->first_name){
			n->right=right_rotation(n->right);
			return left_rotation(n);
		}
		
		return n;
	 			
	  }
	  
	  
	  void update(node* n , string name){
	  	
	  	
	  	
	  	if(n->first_name ==  name){
	  		
	  		string contact_no;
	  		 cout<<"\nEnter the new contact number:";
	  	   	cin>>contact_no; 
			 n->contact=contact_no;
			 cout<<"\n\nContact has been updated"<<endl;
	  		
		  }
		 
		   if(name < root->first_name){
		
		    update(root->left, name);
				
			}
			
			if(name > root->first_name){
				
			 update(root->right, name);
				
			}  
  	
	  }
	  
	  
	  void display_menu(){
	  	
	  	
	  	  cout<<"==================================";
		  cout<<"\n\tPhone Directory\t\t";
		  cout<<"\n==================================\n";
		  
		  cout<<"1-Add contacts"<<endl;
		  cout<<"2-Show Contacts in Ascending Order"<<endl;
		  cout<<"3-Show Contacts in Descending Order"<<endl;
		  cout<<"4-Search Contact"<<endl;
		  cout<<"5-Delete Contact From Phonebook"<<endl;
		  cout<<"6-Update Contact"<<endl;
		  cout<<"7-Go back"<<endl;
	  	  	
	  }
	
	
		
};

   node* insertion_from_file(string filename){
		
	   fstream file;
	   string word;
	   string name1[100], name2[100], contact[100], email[100];
	   int i=0,count=0;
	   file.open(filename.c_str());
	   
	   while(file >> word) { 
      
      
	      	name1[i]=word;
		  	file>>word; 
		  	name2[i]=word;
		  	file>>word;
	      	contact[i]=word;
		   	file>>word;
	      	email[i]=word;
	      	
	      	i++;
	      	count++;
  	 }
	 
	 
	 file.close();   
	 AVL L;
	 L.root=NULL;   
	  
	    
	 for(int i=0;i<count;i++){
	    		L.root=L.insert(L.root, name1[i], name2[i], contact[i], email[i]);
		}
		
	int end=0; 
	 
	 start:
	 	
	 while(end != -1){	
	 system("cls");
	 char choice;	
	 L.display_menu();
	 cin>>choice;	
	 string name;
	 
	 switch(choice){
	 	
		 	case '1':
		 		system("cls");
		 		L.add_contact(L.root);
		 		system("PAUSE");
		 		break;
		 		
		 	case '2':
		 		system("cls");
		 		cout<<"\n\n";
			 	L.showAscending(L.root);
			 	system("PAUSE");
			 	break;
			 	
			case '3':
				system("cls");
				cout<<"\n\n";
			 	L.showDescending(L.root);
			 	system("PAUSE");
			 	break;
			 	
			case '4': 
			    
			    system("cls");
				cout<<"Enter the First Name to Search:";
				cin>>name;
				cout<<"\n\n";
			 	L.search_from_phonebook(L.root, name);
			 	system("PAUSE");
			 	break;
			case '5':
                
                system("cls");
			    cout<<"Enter the First name to Delete from PhoneBook:";
			    cin>>name;
			 	L.delete_contact(L.root, name);
			 	cout<<"\n\nRecord succesfully Deleted"<<endl;
			 	system("PAUSE");
			 	break;
			 	
			case '6':
		        
		        system("cls");
				cout<<"Enter the First name to Update from PhoneBook:";
				cin>>name;
			 	L.update(L.root, name);
			 	system("PAUSE");
			 	break;
			 	
			case '7':
				
			   end=-1;
			   exit(0);
			   break; 	
			   
			default:
				system("cls");
				cout<<"\n\nEnter a Correct Choice"<<endl;
				system("PAUSE");
					
		 	}
	 
		}
	 
	 
		
		
}		

int main(){
    
    
    insertion_from_file("phonedata.txt");
    
	return 0;
	
	
	
	
	
}
