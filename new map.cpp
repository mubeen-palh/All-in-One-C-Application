#include<iostream>
#include<unistd.h>
using namespace std;

class node;
class countrymap;
class citymap;


		//storing data in a list
class linklist{
	public:
		int weight;
		node *data;
		linklist *next;
		
};

class linking{
							//creating link between two nodes
	public:
		linklist *head;
		linklist *tail; 
		linking()
		{
			head=NULL;
			tail=NULL;
		}
		void push(node *a,int b)
		{
			linklist *t=new linklist();
			t->data=a;
			if(head==NULL)
			{
				head=t;
			}
			if (tail==NULL)
			{
				tail=t;
			}
			else
			{
				tail->next=t;	
			}
			t->next=NULL;
			tail=t;	
			t->weight=b;
		}
};



	//to store name of city or locations with in city
class node{
	public:
		string name;
		linking list;
		node(string a,int v)		//name of the city or place
		{
			name=a;
		}
		
};


class citymap{
	linklist *head;
	linklist *tail;
		node *s=new node("Sadar",4);
		node *d=new node("Defence",3);
		node *p=new node("Port",3);
		node *dr=new node("Drigh Road",6);
		node *f=new node("FAst",3);
		node *h=new node("Highway",3); 
		node *qa=new node("Quetta Airport",3);
		node *qf=new node ("Fatima Jinnah Park",3);
		node *ql=new node ("Liaqat Park",3);
		node *ld=new node ("Lahore defence",3);
		node *lb=new node ("Badshahi Mosque",3);
		node *lg=new node ("Shalimar Garden",3);
		node *ib=new node ("Bani Gala",3);
		node *ip=new node ("Rawal Pindi",3);
		node *iff=new node ("Shah Faisal Mosque",3);
		node *hs=new node ("Hyderabad Station",3);
		node *hm=new node ("Sindh Museum",3);
		node *hb=new node ("Hyderabad bazar",3);
		node *pz=new node ("Peshawar Zoo",3);
		node *pt=new node ("Tartara Park",3);
		node *pd=new node ("Defence",3);					
	void kar()
	{
		//building karachi	
		s->list.push(d,1);
		s->list.push(p,2);
		s->list.push(dr,3);
		d->list.push(s,1);
		d->list.push(dr,2);
		p->list.push(s,2);
		p->list.push(dr,3);
		dr->list.push(d,2);
		dr->list.push(s,3);
		dr->list.push(p,3);
		dr->list.push(f,2);	
		dr->list.push(h,3);	
		h->list.push(dr,2);
		f->list.push(h,1);
		h->list.push(dr,3);
		h->list.push(f,1);
		
	}

	void que()
	{
		//building quetta
		qa->list.push(qf,6);
		qa->list.push(ql,7);
		qf->list.push(ql,1);
		qf->list.push(qa,6);
		ql->list.push(qa,7);
		ql->list.push(qf,1);
		
	}

	void lah()
	{
		//building lahore
		ld->list.push(lb,4);
		ld->list.push(lg,8);
		lg->list.push(ld,8);
		lg->list.push(lb,3);
		lb->list.push(ld,4);
		lb->list.push(lg,3);
			
	}

	void isl()
	{
		//building islamabad
		ib->list.push(ip,4);
		ib->list.push(iff,8);
		ip->list.push(ib,8);
		ip->list.push(iff,4);
		iff->list.push(ip,4);
		iff->list.push(ib,8);
	}
	
	void hyd()
	{
		//building hydrabad
		hs->list.push(hb,4);
		hs->list.push(hm,8);
		hm->list.push(hs,8);
		hm->list.push(hb,4);
		hb->list.push(hm,4);
		hb->list.push(hs,4);
	}
	
	void pes()
	{
		//building peshawar
		pz->list.push(pt,4);
		pz->list.push(pd,8);
		pt->list.push(pz,4);
		pt->list.push(pd,8);
		pd->list.push(pt,8);
		pd->list.push(pz,4);
	}
	public:

		void buildcity()
		{
			kar();
			isl();
			lah();
			hyd();
			pes();
			que();	
		}
		
		
		bool searching(node *source,node *destination)
		{
			if(source == destination)
			{
			//	cout<<destination->name;
				return true;
			}
			else
			{
				linklist *trav=source->list.head;
				while(trav!=NULL)
				{
					if(trav->data==destination)
					{
						cout<<destination->name;
						cout<<"<-"<<source->name;
						return true;
					}
					trav=trav->next;
				}
					
				linklist *trav1=source->list.head;
				while(trav1!=NULL)
				{
					if (searching2(trav1->data,destination))
					{
						cout<<"<-"<<source->name;
						return true;
					}
					trav1=trav1->next;
				}
			}
				return false;
			
		}
		
		bool searching2(node *source,node *destination)
		{
			if(source == destination)
			{
			//	cout<<destination->name;
				return true;
			}
			else
			{
				linklist *trav=source->list.head;
				while(trav!=NULL)
				{
					if(trav->data == destination)
					{
						cout<<destination->name;
						cout<<"<-"<<source->name;
						return true;
					}
					trav=trav->next;
				}
				return false;
			}
			
		}
		
		
			//landmark for karachi
		void landk()
		{
			int a;
			string nam;
			cout<<"Enter the no. of adjacent location to your landmark:";
			cin>>a;
			cout<<"Enter the Name of Landmark:";
			cin>>nam;
			int loca[a];
			start16:
			cout<<"Select the adjacent locations:"<<endl;
			cout<<"1-Sadar \n2- Defence \n3- Port \n4- Drigh Road \n5- FAst \n6- Highway "<<endl;
				for(int i=0;i<a;i++)
				{
					cin>>loca[i];
					if (loca[i]<1 && loca[i]>6)
					{
						cout<<"Wrong input \n Select Again"<<endl;
						cin>>loca[i];
						break;
					}		
				}
			node *n1=new node(nam,a);
				for(int i=0;i<a;i++)
				{
					switch(loca[i])
					{
						case '1':
							s->list.push(n1,4);
							n1->list.push(s,4);
							break;
						case '2':
							d->list.push(n1,4);
							n1->list.push(d,4);
						
							break;	
						case '3':
							p->list.push(n1,4);
							n1->list.push(p,4);
							break;
						case '4':
							dr->list.push(n1,4);
							n1->list.push(dr,4);
							break;
						case '5':
							f->list.push(n1,4);
							n1->list.push(f,4);	
							break;
						case '6':
							h->list.push(n1,4);
							n1->list.push(h,4);
							break;					
					}
				}
		}
		
			//landmark for quetta
		void landq()
		{
			int a;
			string nam;
			cout<<"Enter the no. of adjacent location to your landmark:";
			cin>>a;
			cout<<"Enter the Name of Landmark:";
			cin>>nam;
			int loca[a];
			start18:
			cout<<"Select the adjacent locations:"<<endl;
			cout<<"1-Quetta Airport \n2- Fatima Jinnah Park \n3-Liaqat Park "<<endl;
				for(int i=0;i<a;i++)
				{
					cin>>loca[i];
					if (loca[i]<1 && loca[i]>3)
					{
						cout<<"Wrong input \n Select Again"<<endl;
						cin>>loca[i];
						break;
					}
				}
			node *n1=new node(nam,a);
				for(int i=0;i<a;i++)
				{
					switch(loca[i])
					{
						case '1':
							qa->list.push(n1,4);
							n1->list.push(qa,4);
							break;
						case '2':
							qf->list.push(n1,4);
							n1->list.push(qf,4);
							break;	
						case '3':
							ql->list.push(n1,4);
							n1->list.push(ql,4);
							break;					
					}
				}
		}
		
			//landmark for hyderabad
		void landh()
		{
			int a;
			string nam;
			cout<<"Enter the no. of adjacent location to your landmark:";
			cin>>a;
			cout<<"Enter the Name of Landmark:";
			cin>>nam;
			int loca[a];
			start20:
			cout<<"Select the adjacent locations:"<<endl;
			cout<<"1-Hyderabad Station \n2- Sindh Museum \n3-Hyderabad bazar "<<endl;
				for(int i=0;i<a;i++)
				{
					cin>>loca[i];
					if (loca[i]<1 && loca[i]>3)
					{
						cout<<"Wrong input \n Select Again"<<endl;
						cin>>loca[i];
						break;
					}
				}
			node *n1=new node(nam,a);
				for(int i=0;i<a;i++)
				{
					switch(loca[i])
					{
						case '1':
							hs->list.push(n1,4);
							n1->list.push(hs,4);
							break;
						case '2':
							hm->list.push(n1,4);
							n1->list.push(hm,4);
							break;	
						case '3':
							hb->list.push(n1,4);
							n1->list.push(hb,4);
						
							break;					
					}
				}
		}
		
			//landmark for peshawar
		void landp()
		{
			int a;
			string nam;
			cout<<"Enter the no. of adjacent location to your landmark:";
			cin>>a;
			cout<<"Enter the Name of Landmark:";
			cin>>nam;
			int loca[a];
			start21:
			cout<<"Select the adjacent locations:"<<endl;
			cout<<"1-Peshawar Zoo \n2- Tartara Park \n3-Defence "<<endl;
				for(int i=0;i<a;i++)
				{
					cin>>loca[i];
					if (loca[i]<1 && loca[i]>3)
					{
						cout<<"Wrong input \n Select Again"<<endl;
						cin>>loca[i];
						break;
					}
				}
			node *n1=new node(nam,a);
				for(int i=0;i<a;i++)
				{
					switch(loca[i])
					{
						case '1':
							pz->list.push(n1,4);
							n1->list.push(pz,4);
							break;
						case '2':
							pt->list.push(n1,4);
							n1->list.push(pt,4);
							
							break;	
						case '3':
							pd->list.push(n1,4);
							n1->list.push(pd,4);
							
							break;					
					}
				}
		}
		
			//landmark for lahore
		void landl()
		{
			int a;
			string nam;
			cout<<"Enter the no. of adjacent location to your landmark:";
			cin>>a;
			cout<<"Enter the Name of Landmark:";
			cin>>nam;
			int loca[a];
			start22:
			cout<<"Select the adjacent locations:"<<endl;
			cout<<"1-Lahore defence\n2- Badshahi Mosque \n3-Shalimar Garden"<<endl;
				for(int i=0;i<a;i++)
				{
					cin>>loca[i];
					if (loca[i]<1 && loca[i]>3)
					{
						cout<<"Wrong input \n Select Again"<<endl;
						cin>>loca[i];
						break;
					}
				}
			node *n1=new node(nam,a);
				for(int i=0;i<a;i++)
				{
					switch(loca[i])
					{
						case '1':
							ld->list.push(n1,4);
							n1->list.push(ld,4);
							
							break;
						case '2':
							lb->list.push(n1,4);
							n1->list.push(lb,4);
							
							break;	
						case '3':
							lg->list.push(n1,4);
							n1->list.push(lg,4);
							
							break;					
					}
				}
		}
		
			//landmark for islamad
		void landi()
		{
			int a;
			string nam;
			cout<<"Enter the no. of adjacent location to your landmark:";
			cin>>a;
			cout<<"Enter the Name of Landmark:";
			cin>>nam;
			int loca[a];
			start23:
			cout<<"Select the adjacent locations:"<<endl;
			cout<<"1-Bani Gala\n2- Rawal Pindi \n3-Shah Faisal Mosque"<<endl;
				for(int i=0;i<a;i++)
				{
					cin>>loca[i];
					if (loca[i]<1 && loca[i]>3)
					{
						cout<<"Wrong input \n Select Again"<<endl;
						cin>>loca[i];
						break;
					}
				}
			node *n1=new node(nam,a);
				for(int i=0;i<a;i++)
				{
					switch(loca[i])
					{
						case '1':
							ib->list.push(n1,4);
							n1->list.push(ib,4);
							
							break;
						case '2':
							ip->list.push(n1,4);
							n1->list.push(ip,4);
							
							break;	
						case '3':
							iff->list.push(n1,4);
							n1->list.push(iff,4);
							
							break;					
					}
				}
		}
		
			//selecting city for landmark
		void insert()
		{
			start15:
			char op;
			system("cls");
			cout<<"Select the city where you want to add a landmark"<<endl;
			cout<<"1- Karachi\n2- Lahore\n3-Islamabad\n4- Peshawar\n5- Hyderabad \n6- Quetta"<<endl;
			cin>>op;
			
			switch (op)
			{
				case '1':
					landk();
					break;
				case '2':
					landl();
					break;
				case '3':
					landi();
					break;
				case '4':
					landp();
					break;
				case '5':
					landh();
					break;
				case '6':
					landq();
					break;
				default:
					cout<<"wrong option selected"<<endl;
					goto start15;	
					
			}
			cout<<"Your landmark is added Successfully"<<endl;
			sleep(1);
			system("cls");
		}
		
		
			//for searching within karachi
	void searchroutek()
		{
			start6:
			char city2,city1;
			node *destination;
			cout<<"1- Sadar\n2-Port\n3-Defence\n4-DrighRoad\n5-Fast\n6-Highway"<<endl;
			cout<<"From:";
			cin>>city1;
			cout<<"Destination:";
			cin>>city2;
			if (city2=='1')
			{
				destination=s;
			}
			else if(city2=='2')
			{
				destination=p;
			}
			else if(city2=='3')
			{
				destination=d;
			}
			else if(city2=='4')
			{
				destination=dr;
			}
			else if(city2=='5')
			{
				destination=f;
			}
			else if(city2=='6')
			{
				destination=h;
			}
			else
			{
				cout<<"wrong option selected";
				system("pause");
				system("cls");
				goto start6;
			}
			switch (city1)
			{
				case '1':
					searching(s,destination);
					sleep(2);
					system("cls");	
					break;	
				case '2':
					searching(p,destination);
					sleep(2);
					system("cls");	
					break;
				case '3':
					searching(d,destination);
					sleep(2);
					system("cls");	
					break;	
				case '4':
					searching(dr,destination);
					sleep(2);
					system("cls");	
					break;	
				case '5':
					searching(f,destination);
					sleep(2);	
					system("cls");	
					break;
				case '6':
					searching(h,destination);
					sleep(2);
					system("cls");
					break;	
				default:
					cout<<"Wrong option selected";
					system("pause");
					system("cls");
					goto start6;
					break;		
			}
		}
		
		void searchrouteq()
		{
			start7:
			char city2,city1;
			node *destination;
			cout<<"1- Quetta Airport\n2-Fatima Jinnah Park\n3-Liaqat Park"<<endl;
			cout<<"From:";
			cin>>city1;
			cout<<"Destination:";
			cin>>city2;
			sleep(2);
			if (city2=='1')
			{
				destination=qa;
			}
			else if(city2=='2')
			{
				destination=qf;
			}
			else if(city2=='3')
			{
				destination=ql;
			}
			else
			{
				cout<<"wrong option selected";
				system("pause");
				system("cls");
				goto start7;
			}
			switch (city1)
			{
				case '1':
					searching(qa,destination);
					sleep(2);
					system("cls");	
					break;	
				case '2':
					searching(qf,destination);
					sleep(2);
					system("cls");	
					break;
				case '3':
					searching(ql,destination);
					sleep(2);
					system("cls");	
					break;	
				default:
					cout<<"Wrong option selected";
					system("pause");
					system("cls");
					goto start7;
					break;		
			}
		}
		
		void searchroutep()
		{
			start8:
			char city2,city1;
			node *destination;
			cout<<"1- Peshawar Zoo\n2-Tartara Park\n3-Defence"<<endl;
			cout<<"From:";
			cin>>city1;
			cout<<"Destination:";
			cin>>city2;
			sleep(2);
			if (city2=='1')
			{
				destination=pz;
			}
			else if(city2=='2')
			{
				destination=pt;
			}
			else if(city2=='3')
			{
				destination=pd;
			}
			else
			{
				cout<<"wrong option selected";
				system("pause");
				system("cls");
				goto start8;
			}
			switch (city1)
			{
				case '1':
					searching(pz,destination);
					sleep(2);
					system("cls");	
					break;	
				case '2':
					searching(pt,destination);
					sleep(2);
					system("cls");	
					break;
				case '3':
					searching(pd,destination);
					sleep(2);
					system("cls");		
					break;	
				default:
					cout<<"Wrong option selected";
					system("pause");
					system("cls");
					goto start8;
					break;		
			}
		}
		
		void searchrouteh()
		{
			start9:
			char city2,city1;
			node *destination;
			cout<<"1- Hyderabad Station\n2-Sindh Museum\n3-Hyderabad bazar"<<endl;
			cout<<"From:";
			cin>>city1;
			cout<<"Destination:";
			cin>>city2;
			sleep(2);
			if (city2=='1')
			{
				destination=hs;
			}
			else if(city2=='2')
			{
				destination=hm;
			}
			else if(city2=='3')
			{
				destination=hb;
			}
			else
			{
				cout<<"wrong option selected";
				system("pause");
				system("cls");
				goto start9;
			}
			switch (city1)
			{
				case '1':
					searching(hs,destination);
					sleep(2);
					system("cls");	
					break;	
				case '2':
					searching(hm,destination);
					sleep(2);
					system("cls");	
					break;
				case '3':
					searching(hb,destination);
					sleep(2);
					system("cls");		
					break;	
				default:
					cout<<"Wrong option selected";
					system("pause");
					system("cls");
					goto start9;
					break;		
			}
		}
		
		
		void searchroutei()
		{
			start10:
			char city2,city1;
			node *destination;
			cout<<"1- Bani Gala\n2-Rawal Pindi\n3-Shah Faisal Mosque"<<endl;
			cout<<"From:";
			cin>>city1;
			cout<<"Destination:";
			cin>>city2;
			sleep(2);
			if (city2=='1')
			{
				destination=ib;
			}
			else if(city2=='2')
			{
				destination=ip;
			}
			else if(city2=='3')
			{
				destination=iff;
			}
			else
			{
				cout<<"wrong option selected";
				system("pause");
				system("cls");
				goto start10;
			}
			switch (city1)
			{
				case '1':
					searching(ib,destination);
					sleep(2);
					system("cls");	
					break;	
				case '2':
					searching(ip,destination);
					sleep(2);
					system("cls");	
					break;
				case '3':
					searching(iff,destination);
					sleep(2);
					system("cls");	
					break;	
				default:
					cout<<"Wrong option selected";
					system("pause");
					system("cls");
					goto start10;
					break;		
			}
		}
		
		void searchroutel()
		{
			start11:
			char city2,city1;
			node *destination;
			cout<<"1- Lahore defence\n2-Badshahi Mosque\n3-Shalimar Garden"<<endl;
			cout<<"From:";
			cin>>city1;
			cout<<"Destination:";
			cin>>city2;
			sleep(2);
			if (city2=='1')
			{
				destination=ld;
			}
			else if(city2=='2')
			{
				destination=lb;
			}
			else if(city2=='3')
			{
				destination=lg;
			}
			else
			{
				cout<<"wrong option selected";
				system("pause");
				system("cls");
				goto start11;
			}
			switch (city1)
			{
				case '1':
					searching(ld,destination);
					sleep(2);
					system("cls");	
					break;	
				case '2':
					searching(lb,destination);
					sleep(2);
					system("cls");	
					break;
				case '3':
					searching(lg,destination);
					sleep(2);
					system("cls");	
					break;	
				default:
					cout<<"Wrong option selected";
					system("pause");
					system("cls");
					goto start11;
					break;		
			}
		}
		
		void select()
		{
			start4:
			char a;
			cout<<"Select the city"<<endl;
			cout<<"1- Karachi\n2-Quetta\n3-Peshawar\n4-Islamabad\n5-Lahore\n6-Hyderabad\n7-Exit"<<endl;
			cin>>a;
			sleep(2);
			system("cls");
			switch(a)
			{
				case '1':
					searchroutek();
					goto start4;
					break;
				case '2':
					searchrouteq();
					goto start4;
					break;
				case '3':
					searchroutep();
					goto start4;
					break;
				case '4':
					searchroutei();
					goto start4;
					break;
				case '5':
					searchroutel();
					goto start4;
					break;
				case '6':
					searchrouteh();
					goto start4;
					break;
				case '7':
					//exit
					break;						
			}
		}
		
		void options()
		{
			start3:
			char a;
			system("cls");
			cout<<"----CITY MAP----"<<endl;
			cout<<"1- Search Route"<<endl;
			cout<<"2- Insert Landmark"<<endl;
			cout<<"3- Exit"<<endl;
			cout<<"Press the option:";
			cin>>a;
			sleep(2);
			system("cls");
			switch (a)
			{
				case '1':
					select();	//call to search route
					goto start3;	
					break;
				case '2':
					insert();		//insert landmark
					goto start3;
					break;
				case '3':
					system("cls");
					break;
				default:
					cout<<"Wrong Option Selected"<<endl;
					goto start3;				
			}
		}
};


	//only for country
class countrymap{
	linklist *head;
	linklist *tail;
			node *k=new node("Karachi",3);
			node *q=new node ("Quetta",3);
			node *h=new node("Hyderabad",2);
			node *l=new node("Lahore",3);
			node *i=new node("Islamabad",3);
			node *p=new node("Peshawar",2);

	public:
		void buildcountry()
		{
			k->list.push(h,3);
			k->list.push(q,7);
			k->list.push(l,8);
			q->list.push(k,7);
			q->list.push(p,6);
			q->list.push(i,8);
			h->list.push(k,3);
			h->list.push(l,7);
			l->list.push(h,7);
			l->list.push(i,2);
			l->list.push(k,8);	
			i->list.push(l,2);
			i->list.push(p,4);
			i->list.push(q,8);
			p->list.push(i,4);
			p->list.push(q,6);
		}

		bool searching(node *source,node *destination)
		{
			if(source == destination)
			{
			//	cout<<destination->name;
				return true;
			}
			else
			{
				linklist *trav=source->list.head;
				while(trav->next!=NULL)
				{
					if(trav->data==destination)
					{
						cout<<destination->name;
						cout<<"<-"<<source->name;
						return true;
					}
					trav=trav->next;
				}
					
				linklist *trav1=source->list.head;
				while(trav1->next!=NULL)
				{
					if (searching2(trav1->data,destination))
					{
						cout<<"<-"<<source->name;
						return true;
					}
					trav1=trav1->next;
				}
			}
				return false;
			
		}
		
		bool searching2(node *source,node *destination)
		{
			if(source == destination)
			{
			//	cout<<destination->name;
				return true;
			}
			else
			{
				linklist *trav=source->list.head;
				while(trav->next!=NULL)
				{
					if(trav->data==destination)
					{
						cout<<destination->name;
						cout<<"<-"<<source->name;
						return true;
					}
					trav=trav->next;
				}
				return false;
			}
			
		}
		

			//asking for roots to be searched
		void searchroute()
		{	
			start2:
			char city2,city1;
			node *destination;
			cout<<"Press the given number to select the city "<<endl;
			cout<<"1- Karachi\n2-Quetta\n3-Peshawar\n4-Islamabad\n5-Lahore\n6-Hyderabad"<<endl;
			cout<<"From:";
			cin>>city1;
			cout<<"Destination:";
			cin>>city2;
			if (city2=='1')
			{
				destination=k;
			}
			else if(city2=='2')
			{
				destination=q;
			}
			else if(city2=='3')
			{
				destination=p;
			}
			else if(city2=='4')
			{
				destination=i;
			}
			else if(city2=='5')
			{
				destination=l;
			}
			else if(city2=='6')
			{
				destination=h;
			}
			else
			{
				cout<<"wrong option selected";
				system("pause");
				system("cls");
				goto start2;
			}
			switch (city1)
			{
				case '1':
					searching(k,destination);
					sleep(2);
					break;	
				case '2':
					searching(q,destination);
					sleep(2);
					break;
				case '3':
					searching(p,destination);
					sleep(2);	
					break;	
				case '4':
					searching(i,destination);
					sleep(2);
					break;	
				case '5':
					searching(l,destination);
					sleep(2);	
					break;
				case '6':
					searching(h,destination);
					sleep(2);
					break;	
				default:
					cout<<"Wrong option selected";
					system("pause");
					system("cls");
					goto start2;
					break;		
			}
		}
		
		
		void options()
		{
			start1:
			char a;
			system("cls");
			cout<<"----Country MAP---- "<<endl<<endl;
			cout<<"1- Search Route"<<endl;
			cout<<"2- City Map"<<endl;
			cout<<"3- Exit"<<endl;
			cout<<"Press the option:";
			cin>> a;
			
			switch (a)
			{
				case '1':
					{
					searchroute();	//call to search route
					sleep(1);
					system("cls");
					goto start1;	
					break;
				}
				case '2':
					{
					citymap c;
					c.buildcity();
					c.options();
					sleep(1);
					system("cls");
					goto start1;
					break;
				}
				case '3':
					{
					system("cls");
					break;
				}
				default:
					cout<<"Wrong Option Selected"<<endl;
					goto start1;				
			}
		}
					
};

	void cityorcountry()		//selecting if a person want to see map of country or city
	{
	
		start:
		char a;
			cout<<"1- Country Map"<<endl;
			cout<<"2- City Map"<<endl;
			cout<<"3- Exit"<<endl;
			cout<<"Press the option:";
			cin>> a;
				
			switch(a)
			{
				case '1':
					{
					countrymap m1;
					m1.buildcountry();
					m1.options();
					sleep(1);
					system("cls");
					goto start;
					break;
				}
				case '2':
					{
					
					citymap cm;
					cm.buildcity();
					cm.options();
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
					
					cout<<"Wrong Option Selected"<<endl;
					goto start;	
				}
			}
	}	

int main(){
	cityorcountry();
	
}
