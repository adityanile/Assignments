#include<iostream>
#define infinity 9999
using namespace std;
class spt{

    int vertex;
    int Edges;

    int adj[100][100];
    int sp[100][100];
    int minCost;

public:
    spt(int V){
        vertex = V;
        for(int i=0;i<V;i++)
        for(int j=0;j<V;j++){
            adj[i][j]=0;
            sp[i][j]=0;
        }

    }
    int getMinCost(){
        return this->minCost;
    }
    void createGraph(){
        int source, destination, weight;
        char choice='y';
        cout<< "Enter the details of edges (source, destination and weight)"<<endl;
        do{
            cout<<"Enter edge - source, destination, weight"<<endl;
            cin>>source>>destination>>weight;
            adj[source][destination] = weight;
            adj[destination][source] = weight;

            cout<<"Do you want to enter another edge? (Y-yes and N-No)"<<endl;
            cin>>choice;
        }while(choice=='y' || choice=='Y');
    }
    void printGraph();
    void printSpanningTree();
    void mst();
};
void spt::printGraph(){
    for(int i=0;i<vertex;i++){
        for(int j=0;j<vertex;j++)
            cout<<" "<<adj[i][j];
        cout<<endl;
    }
}

void spt::printSpanningTree(){
    for(int i=0;i<vertex;i++){
        for(int j=0;j<vertex;j++)
            cout<<" "<<sp[i][j];
        cout<<endl;
    }
}

void spt::mst(){
    int cost[vertex][vertex]={0};
    int visited[10]={0};

    int distance[vertex] = {infinity};
    int source[vertex] = {0};

    int minDist=0;

    //Building Cost Matrix
    for(int i=0;i<vertex;i++)
        for(int j=0;j<vertex;j++)
            if(adj[i][j]==0)
                cost[i][j] = infinity;
            else
                cost[i][j] = adj[i][j];

    //Start from vertex 0;
    distance[0]=0;
    visited[0] = 1;
    int source_vertex, dest_vertex=0;

    //Calculate distance of all vertices from 0 and make their source as 0
    for(int i=0;i<vertex;i++){
        distance[i] = cost[0][i];
        source[i] = 0;
    }

    minCost=0;
    Edges=vertex-1;
    while(Edges>0){
        minDist = infinity;
        /*Find edge with minimum weight from the distance array. The destination vertex will be the index position with minimum value*/
		for(int i=0;i<vertex;i++)
		{
			if(visited[i]==0 && distance[i]< minDist)
			{
				minDist= distance[i];
				dest_vertex= i;
			}
		}

		/*Need to add an edge from source_vertex to dest_vertex in the spanning tree and update the minCost. The source vertex will be obtained from source array*/

		source_vertex=source[dest_vertex];
		sp[source_vertex][dest_vertex] = sp[dest_vertex][source_vertex] = distance[dest_vertex];
		cout<<"Added ("<<source_vertex<<","<<dest_vertex<<")"<<endl;
		visited[dest_vertex] = 1;
		minCost+=cost[source_vertex][dest_vertex];
		Edges--;

		//Now a node has been added, need to check the minimum distance of all other nodes from this newly added dest_vertex. If some cost is less than the existing distance, the distance vector should be updated.

		for(int i=0;i<vertex; i++)
		{
			if(visited[i]==0 && cost[dest_vertex][i]< distance[i])
			{
				distance[i]= cost[dest_vertex][i];
				source[i]=dest_vertex;
			}
		}

    }



}
int main(){
    spt spObj(7);
    spObj.createGraph();
    spObj.printGraph();
    spObj.mst();
    cout<<"Done"<<endl;
    spObj.printSpanningTree();
    cout<<"The cost of minimum spanning tree is: "<<spObj.getMinCost();
    return 0;
}
