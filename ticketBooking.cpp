#include<iostream>
using namespace std;
struct node
{
	int col,row;
	string status,name;
	struct node *next ,*prev;
}
*head[10];

class ticket
{
	public:
	ticket()
	{
		for(int j=0 ; j<10 ; j++)
		{
			head[j]=NULL;
			struct node* temp;
			for(int i=1 ; i<=7 ; i++)
			{
					temp=new(struct node);
					temp->col=i;
					temp->row=j+1;
					temp->status="A";
					temp->next=NULL;
					temp->prev=NULL;

				if(head[j]==NULL)
				{
					head[j]=temp;
					head[j]->next=NULL;
				}
				else
				{
					temp->next=head[j];
					head[j]->prev=temp;
					head[j]=temp;
				}
			}
		}
	}

void book()
{
	int x,y;
	cout<<"\nEnter Row:";
	cin>>x;
	cout<<"\nEnter Seat No:";
	cin>>y;
	struct node* temp;
	temp=head[x-1];
	for(int i=0 ; i<7 ; i++)
	{
		if(temp->col==y)
		{
			if(temp->status=="A")
			{
				temp->status="B";
				cout<<"Enter Name: ";
				cin>>temp->name;
				break;
			}
			else
			{
				cout<<"\nAlready booked!!\n";
			}
		}
		temp=temp->next;
	}
	display();
}

void cancel()
{
	int x,y;
	cout<<"\nEnter row and column to cancel booking : ";
	cin>>x>>y;
	struct node* temp;
	temp=head[x-1];
	for(int i=0 ; i<7 ; i++)
	{
		if(temp->col==y)
		{
			if(temp->status=="B")
			{
				temp->status="A";
			}
			else
			{
				cout<<"\nAlready Unbooked!!\n";
			}
		}
		temp=temp->next;
	}
	display();
}

void display()
{
	struct node* temp;
	for(int j=0 ; j<10 ; j++)
	{
		temp=head[j];
		for(int i=0 ; i<7 ; i++)
		{
			cout<<temp->status<<"\t";
			temp=temp->next;
		}
		cout<<"\n";
	}
}
void Info()
{
	int x,y;
		cout<<"\nEnter row and column";
		cin>>x>>y;
		struct node* temp;
		temp=head[x-1];
		for(int i=0 ; i<7 ; i++)
		{
			if(temp->col==y)
			{
				if(temp->status=="B")
				cout<<"Name: "<<temp->name<<endl;
				else
					cout<<"\nEMPTY\n";
			}
			temp=temp->next;
		}
}
};

int main()
{
	ticket t;
	int ch;
	t.display();
	do{
		cout<<"\nFor Book Ticket: 1 \nFor Cancel Booking: 2 \nFor Info: 3\nEXIT: 4\n";
		cin>>ch;
		switch(ch)
		{
			case 1:t.book();
				break;
			case 2:t.cancel();
				break;
			case 3:t.Info();
				break;
		}
}while(ch!=4);

return 0;
}
