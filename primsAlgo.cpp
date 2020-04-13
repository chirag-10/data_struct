//============================================================================
// Name        : Prims.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include <iostream>
#define MAX 20
#define INF 999
using namespace std;

class Prims
{
public:
	int v,e;
	int G[MAX][MAX];
	void init();
	void primsfunc();
};

void Prims::init()
{
	int m,n,cost;
	cout<<"\nEnter number of  vertices ";
	cin>>v;
	for(int i=1;i<=v;i++)
		for(int j=1;j<=v;j++)
			G[i][j]=INF;

	cout<<"\nEnter number of  edges ";
	cin>>e;
	for(int i=0;i<e;i++)
	{
		cout<<"\nEnter start and end vertex and its cost ";
		cin>>m>>n>>cost;
		G[m][n]=cost;
		G[n][m]=cost;
	}
}

void Prims::primsfunc()
{
	int i,min,k,lowcost[MAX],from[MAX],visited[MAX];

	cout<<"\nMinimum spanning tree \n";
	int mincost=0;
	for(int i=1;i<=v;i++)
	{
		lowcost[i]=G[1][i];
		from[i]=1;
		visited[i]=0;
	}
	visited[1]=1;
	for(int i=1;i<v;i++)
	{
		int vertex;
		min=INF;
		for(int j=2;j<=v;j++)
		{
			if(!visited[j] && (min>lowcost[j]))
			{
				min=lowcost[j];
				vertex=j;
			}
		}
		cout<<"\nEdge : "<<from[vertex]<<" "<<vertex<<"\n";
		mincost=mincost+lowcost[vertex];
		visited[vertex]=1;
		for(int j=1;j<=v;j++)
		{
			if(!visited[j] && G[vertex][j]<lowcost[j])
			{
				lowcost[j]=G[vertex][j];
				from[j]=vertex;
			}
		}
	}
	cout<<"\nCost of MST : "<<mincost<<endl;
}

int main()
{
	Prims obj;
	int ch=1;
	while(ch=1)
	{
		obj.init();
		obj.primsfunc();
		cout<<"\nEnter 1 t0 continue ";
		cin>>ch;
	}
	return 0;
}
