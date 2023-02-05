#include<iostream>
using namespace std;
class node
{
	node*next,*prev;
	char data;
	public:
	node(char y)
	{
		next=prev=NULL;
		data=y;
	}
	friend class ticket;
};
class ticket
{
	node*head[9],*rear[9];
	public:
	ticket()
	{
		for(int i=0;i<9;i++)
		{
			head[i]=NULL;
		}
	
	}
	void creat();
	void show();
	void booking();
	void available();
	void booked();
	void show1();
	void cancelbooking();
};
void ticket::creat()
{
	node*p;
	for(int x=0;x<9;x++)
	{ 
		head[x]=new node('-');
		head[x]->next=head[x];
		head[x]->prev=head[x];
		p=head[x];
		rear[x]=p;
		for(int j=0;j<7;j++)
		{
			p->next=new node('-');
			p->next->prev=p;
			p=p->next;
			head[x]->prev=p;
			p->next=head[x];
			rear[x]=p;
			
		}
				
	}
}
void ticket::show()
{
    cout<<"  1 2 3 4 5 6 7 8"<<endl;
	node*p;
	for(int x=0;x<9;x++)
	{    
	p=head[x];
	cout<<x+1<<" ";
	do
	{
		cout<<p->data<<" ";
		p=p->next;
	}while(p!=head[x]);
	cout<<"\n";
	}
}
void ticket::booking()
{
	int x,y,t;node*p;
	cout<<"enter total no of tickets that do u want to book"<<endl;
	cin>>t;
	while(t>0)
	{
	
		cout<<"enter row no in which do u want to book"<<endl;
		cin>>x;
		cout<<"enter seat no in that row"<<endl;
		cin>>y;
		if(x>0 && x<11 && y>0 && y<8)
		{
	
			p=head[x-1];
			for(int i=0;i<y-1;i++)
			{
				p=p->next;
			}
			p->data='X';
            cout<<x<<y<<" seat is booked"<<endl;
			t--;
		}
		else
		{
			cout<<"enter valid data"<<endl;
		}
	}
    show();
}
void ticket::available()
{
	node*p;
    cout<<"Available seats are "<<endl;
	for(int i=0;i<9;i++)
	{ 
		p=head[i];
		for(int j=0;j<7;j++)
		{
			
			if(p->data=='-')
			{
				cout<<i+1<<j+1<<" ";
			}
			p=p->next;
        
		}
        cout<<endl;
	}
	cout<<endl;
}
void ticket::booked()
{
		node*p;
        cout<<"Booked seats are "<<endl;
	for(int i=0;i<9;i++)
	{
		p=head[i];
		for(int j=0;j<7;j++)
		{
			
			if(p->data=='X')
			{
				cout<<i+1<<j+1<<" ";
			}
			p=p->next;
		 }
	}
    cout<<endl;
}
void ticket::cancelbooking()
{
	node*p;
    int x,y,t;
	cout<<"enter total no of seats that u want to cancel"<<endl;
	cin>>t;
	while(t>0)
	{
	
	cout<<"enter row no and seat no that do u want to cancel"<<endl;
	cin>>x>>y;
		p=head[x-1];
		for(int j=0;j<y-1;j++)
		{
		
			p=p->next;
		}
				
			if(p->data=='X')
			{
				p->data='-';
                cout<<x<<y<<" seat is cancelled"<<endl;
			}
			else
			{
				cout<<"this ticket is not already booked"<<endl;
			}
			t--;
	}
    show();
}

int main()
{
    cout<<"--------------------------------------------------------------------------------------------------"<<endl;
    cout<<"                                       MOVIE THEATRE                                             "<<endl;
    cout<<"-------------------------------------------------------------------------------------------------"<<endl;
	ticket obj;
    int ch;
    int flag=1;
	obj.creat();
	while(flag==1)
	{
        cout<<"-------------------------"<<endl;
        cout<<"OUR SERVICES"<<endl;
		cout<<"1)Available seats "<<endl;
		cout<<"2)Book seats "<<endl;
		cout<<"3)Cancel seat"<<endl;
		cout<<"4)Exit"<<endl;
        cout<<"-------------------------"<<endl;
		cout<<endl<<"Enter your choice"<<endl;
		cin>>ch;
		switch(ch)
		{
			case 1:
                cout<<"-----------------------"<<endl;
                obj.show();
			    break;
			case 2:
                cout<<"-----------------------"<<endl;
                obj.available();
                obj.booking();
			    break;
            case 3:
                cout<<"-----------------------"<<endl;
                obj.booked();
                obj.cancelbooking();
			    break;
			case 4:
                cout<<"-----------------------"<<endl;
                cout<<"Thank You!";
                flag=0;
                break;
		}
	}
	
}