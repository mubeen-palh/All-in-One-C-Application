#include<iostream>
#include<string.h>
#include<fstream>
#include<sstream>
using namespace std;

class FoodMart{
	public:
		int *time;
		int count;
		int capacity;
		string *items;
		int* price;
	
	FoodMart(int n){
		count=0;
		capacity=n;
		time= new int[n];
		items= new string[n];
		price= new int[n];
	}
	
	void insert(int data, string name, int pr){
		
		count++;
		int i=count-1;
		
		if(count > capacity){
			
			count--;
			return;
		}
		
		while(i > 0 && data < time[(i-1)/2]){
			
			time[i]=time[(i-1)/2];
			items[i]=items[(i-1)/2];
			price[i]=price[(i-1)/2];
			i=(i-1)/2;
		}
		time[i]=data;
		items[i]=name;
		price[i]=pr;
	}
	
	void ShowAllOrders(){
		 
		 cout<<"\n===============================================\n";
		 for(int i=0;i<count;i++){
		 	cout<<"\tORDER NUMBER "<<i+1<<endl;
		 	cout<<"\t-------------\t"<<endl;
		 	cout<<"   Item: "<<items[0]<<" Price: "<<price[0]<<" Cooking Time: "<<time[0]<<endl;
		 	cout<<"\n===============================================\n";
		 }
		 
	 		
	}
	
	void delete_first_order(){
		
 	     removeMin();
	}
	
	
	
	
	
	void siftDown(int nodeIndex) {

      int leftChildIndex, rightChildIndex, minIndex, tmp;

      leftChildIndex = (2*nodeIndex)+1;

      rightChildIndex = (2*nodeIndex)+2;

      if (rightChildIndex >= count) {

            if (leftChildIndex >= count)

                  return;

            else

                  minIndex = leftChildIndex;

      } else {

            if (time[leftChildIndex] <= time[rightChildIndex])

                  minIndex = leftChildIndex;

            else

                  minIndex = rightChildIndex;

      }

      if (time[nodeIndex] > time[minIndex]) {
      	
			swap(time[minIndex], time[nodeIndex]);
			items[minIndex].swap(items[nodeIndex]);
			swap(price[minIndex], price[nodeIndex]);
            siftDown(minIndex);

      	}
 
		}
	
	 void removeMin() {

      if (count==0){
      	   cout<<"Heap is empty";
	  }


      else {

            time[0]=time[count-1];
			items[0]=items[count-1];
			price[0]=price[count-1];

            count--;

            if (count > 0)

                  siftDown(0);

      }
  }
	
	
	void  show_menu(){
		
	cout<<"\n\t\t======WELCOME TO FOODMART==========\n";
	cout<<"\t1-SHOW ALL ORDERS"<<endl;
	cout<<"\t2-PLACE ORDER"<<endl;
	cout<<"\t3-Find Minimum Cooking Time Food"<<endl;
	cout<<"\t4-Exit"<<endl;
	
    }
	void get_min(){
		
		cout<<"The Following food need minimum time to get ready: ";
		
		cout<<"Item: "<<items[0]<<" Price: "<<price[0]<<" Cooking Time: "<<time[0]<<endl;
	
	}
	
	
	

};




	void insert_file_data(string filename){
		fstream file;
	   string word;
	   string items[100]; 
	   int time[100];
	   int price[100];
	   int i=0,count=0;
	   file.open(filename.c_str());
	   
	   while(file >> word) { 
      
      
	      	items[i]=word;
		  	file>>word;
			stringstream(word) >> time[i]; 
		  	file>>word;
		  	stringstream(word) >> price[i];			   
		  	i++;
		  	count++;
  	    }
	 
	
	 
	 file.close();
	 
	  FoodMart H(100);
	 
	 i=0;
	 while (i != count){
	 
	 	H.insert(time[i],items[i], price[i]);
	 	i++;
	 	
	 }
	 
	 
	 int end=0;
	 char choice;
	 start:
	 while(end!=-1){
	 	
	 	system("cls");
	 	H.show_menu();
	 	cin>>choice;
	 	string it;
	 	int tim, pr;
	 	
	 	 switch(choice){
	 	
		 	case '1':
		 		system("cls");
		 	 	H.ShowAllOrders();
		 	 	 s:
				 int press;
				 cout<<"Press 1 if  Order 1 is ready : "<<endl;
				 cin>>press;
				 
				 if(press){
				 	H.delete_first_order();
				 }
				 else{
				 	cout<<"Please enter a valid digit"<<endl;
				 	goto s;
				 }
				 
		 		system("PAUSE");
		 		break;
		 		
		 	case '2':
		 		system("cls");
		 		cout<<"\nEnter the item:  ";
		 		cin>>it;
		 		cout<<"\n\nEnter the Cooking time: ";
		 		cin>>tim;
		 		cout<<"\n\nEnter the Price: ";
		 		cin>>pr;
		 		H.insert(tim, it, pr);
			 	system("PAUSE");
			 	break;
			 	
			case '3':
				system("cls");
				H.get_min();
			 	system("PAUSE");
			 	break;
			 	
			case '4':
                
                 system("cls");
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

//int main(){
//   
//   
//   insert_file_data("Food.txt");
//	
//}
