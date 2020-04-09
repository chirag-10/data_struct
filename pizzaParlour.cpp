#include<iostream>
using namespace std;
#define size 100
class dominos
{
	struct pizza
	{
		int order_no[size];
        int front,rear;
        string pname,cname;
        float bill=0;
	}p;
public:
	dominos()
	{
		p.front=-1;
		p.rear=-1;
	}
	int qfull()
	{
		if(p.front==(p.rear+1)%size)
			return 1;
		else
			return 0;
	}
	int qempty()
	{
		if(p.front==-1)
			return 1;
		else
			return 0;
	}
	int place_order(int a)
	{
		cout<<"\n Enter your name:";
		cin>>p.cname;
		int ch;
		if(qfull())
			cout<<"\n Further orders are not accepted";
		else if(qempty())
			p.front=p.rear=0;
		else
			p.rear=(p.rear+1)%size;
		cout<<"\n 1)Veg pizza Cost:300 \n 2)Non-veg pizza Cost:400 \n 3)Veg combo offer Cost:350 \n It includes 200ml Coke and a pizza of your choice \n 4)Non-Veg combo offer Cost:450 \n It includes 200ml Coke and a pizza of your choice";
		cout<<"\nEnter your choice of pizza ";
		cin>>ch;
		if(ch==1)
		{
			p.bill=300;
			p.pname="\nVeg pizza";
		}
		else if(ch==2)
		{
			p.bill=400;
			p.pname="\nNon-veg pizza";
		}
		else if(ch==3)
		{
			p.bill=350;
			p.pname="\nVeg pizza with a chilled glass of Coca-Cola";
		}
		else
		{
			p.bill=450;
			p.pname="Non-veg pizza with a chilled glass of Coca-Cola";
		}
		p.order_no[p.rear]=a;
		return p.rear;
	}
	int remove_order()
	{
		cout<<"\n The order number :"<<p.order_no[p.front]<<" is ready.";
		cout<<"\n Enjoy your pizza...";
		if(p.front==p.rear)
		{
			p.front=p.rear=-1;
			return 0;
		}
		else
		{	p.front=(p.front+1)%size;
			return 1;
		}
	}
	void display()
	{
		int i;
		i=p.front;
		do
		{
			cout<<"\nName of the customer is: "<<p.cname;
			cout<<"\nOrder is"<<p.pname;
			cout<<"\nBill amount is :"<<p.bill;
			cout<<"\nOrder number is :"<<p.order_no[i];
			i=(i+1)%size;
		 }while(i!=p.rear+1);
	}
};
int main()
{
	int choice,item;
	dominos obj;
	do
	{
		cout<<"\n WELCOME TO DOMINOS \n 1)Place an order. \n 2)Pizza's that are ready. \n 3)Display the pending orders";
		cout<<"\n Enter your choice :";
		cin>>choice;
		switch(choice)
		{
		case 1:if(obj.qfull())
					cout<<"\n Cannot accept order";
				else
				{
					cout<<"\n Enter order number :";
					cin>>item;
					obj.place_order(item);
				}
				break;
		case 2:if(obj.qempty())
					cout<<"\n None of the orders are ready.";
				else
					obj.remove_order();
				break;
		case 3:if(obj.qempty())
					cout<<"\n Order queue is empty.";
				else
					obj.display();
				break;
		default:
				cout<<"\n Wrong choice";
		}
	}while(choice<=3);
	return 0;
}
