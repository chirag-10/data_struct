#include<iostream>
#define MAX 20
#define INF 999
using namespace std;

class prims
{
        public:
        int V,E;
        int G[MAX][MAX];

        void init()
        {
                it m,n,cost;
                cout<<"\nEnter number of vertices :";
                cin>>V;
                
                for(int i=1;i<=V;i++)
                {
                        for(int j=1;j<=V;j++)
                        {
                                G[i][j]=INF;
                        }
                }
                
                cout<<"\nEnter number of edges :";
                cin>>E;
                
                for(int i=0;i<E;i++)
                {
                        int m,n;
                        cout<<"\nEnter start,end vertex and cost :;
                        cin>>m>>n>>cost;
                        G[m][n]=cost;
                        G[n][m]=cost;
                }
        }
        void primfunc()
        {
                int i,min,k;
                int lowcost[MAX];
                int from[MAX];
                int visited[MAX];
                
                cout<<"\nMinimum Spanning tree :";
                
                int mincost=0;
                
                for(int i=1;i<=V;i++)
                {
                        lowcost[i]=G[1][i];
                        from[i]=1;
                        visited[i]=0;
                }
                visited[i]=1;
                
                for(int i=1;i<V;i++)
                {
                        int Vertex;
                        min=INF;
                        for(int j=2;j<=V;j++)
                        {
                                if(min>lowcost[j])
                                {
                                        min=lowcost[j];
                                        Vertex=j;
                                }
                        }
                        
                        cout<<"\nEdge :"<<from[Vertex]<<" "<<Vertex<<"\n";
                        mincost=mincost+lowcost[Vertex];
                        
                        visited[Vertex]=1;
                        lowcost[Vertex]=INF;
                        
                        for(int j=1;j<=V;j++)
                        {
                                if(!visited[j] && G[Vertex][j]<lowcost[j])
                                {
                                        lowcost[j]=G[Vertex][j];
                                        from[j]=Vertex;
                                }
                        }
                }
                cout<<"\nCost of MST :"<<mincost<<endl;
        }
};
int main()
{
        prims obj;
        obj.init();
        obj.primfunc();
        return 0;
}
