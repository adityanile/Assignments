#include<iostream>
#include"Queue.h"
using namespace std;
struct AdjListNode
{
    int dest;
    struct AdjListNode* next;
};

struct AdjList
{
    struct AdjListNode *head;
};

class Graph{
private:
    int V;
    struct AdjList* total; //this will hold the head pointers of all the linked lists. vertices number of linked lists
    int* visited_array;
public:
    Graph(int no_of_vertices){
        V = no_of_vertices;
        total = (AdjList*)malloc(V * sizeof(AdjList));
        visited_array = (int*)malloc(V * sizeof(int));
        for(int i=0;i<V; i++){
            total[i].head = NULL;
            visited_array[i]=0;
        }
    }
    void addEdge(int src, int dest){
        struct AdjListNode* new_node = new AdjListNode;
        new_node->dest=dest;
        new_node->next = NULL;

        struct AdjListNode* temp = total[src].head;
        if(temp==NULL)
            total[src].head = new_node;
        else{
            while(temp->next !=NULL)
                temp = temp->next;
            temp->next = new_node; 
        }

        struct AdjListNode* nn2 = new AdjListNode;
        nn2->dest=src;
        nn2->next = NULL;
        temp = total[dest].head;
        if(temp==NULL)
            total[dest].head = nn2;
        else{
            while(temp->next !=NULL)
                temp = temp->next;
            temp->next = nn2;
        }
    }

    void printAdjList(){
        cout<<"printing";
        for(int i=0;i<V;i++){
            AdjListNode* temp = total[i].head; 
            while(temp!=NULL){
                cout<<" ->"<<temp->dest;
                temp=temp->next;
            }
            cout<<endl;
        }
    }

    void bfs(int start){
        Queue Q;
        int visited[V]={0};
        Q.enQueue(start);
        visited[start] = 1;
        while(!Q.isEmpty()){
                int printVertex = Q.deQueue();
                cout<<printVertex<<endl;
                AdjListNode* temp = total[printVertex].head;
                while(temp!=NULL){
                    if(visited[temp->dest]==0){
                        Q.enQueue(temp->dest);
                        visited[temp->dest] = 1;
                    }
                    temp=temp->next;

                }

        }
    }
    void dfs(int v){
        cout<<v<<endl;
        visited_array[v] = 1;
        AdjListNode* temp = total[v].head;
        while(temp!=NULL){
            if(visited_array[temp->dest] == 0)
                dfs(temp->dest);
            temp=temp->next;
        }

    }

};


int main(){
    cout<<"Graph representation using adjacency list.."<<endl;
    Graph g(6);
    g.printAdjList();
    cout<<"Adding edge"<<endl;
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(0,3);
    g.addEdge(1,4);
    g.addEdge(1,5);
    g.printAdjList();
    cout<<"BFS..."<<endl;
    g.bfs(1);
    cout<<"DFS..."<<endl;
    g.dfs(3);
    cout<<"Done";
    return 0;
}
