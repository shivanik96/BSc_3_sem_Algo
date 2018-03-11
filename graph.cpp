#include<iostream> 
using namespace std; 
int t; 
class node { public: int key; node* next; node() { key=0; next=NULL; } node(int val) { key=val; next=NULL; } }; 
class queue { public: node* front; queue() { front=NULL; } void insert(int); int del(); bool isempty(); }; 
void queue :: insert(int value) { node* nn = new node(value); if (front==NULL) front=nn; else { node* ptr = front; while(ptr->next!=NULL) ptr=ptr->next; ptr->next=nn; } } 
int queue :: del() 
{ 
if (front==NULL) { cout<<"Empty List!\n"; return 0; } node* ptr = front; front = front->next; return ptr->key; 
} 
bool queue :: isempty() { if (front==NULL) return true; else return false; } 
class graph { int v[5]; int adj[5][5]; int d[5]; char color[5]; int start[5]; int finish[5]; public: graph() { cout<<"Enter the vertices =>\n"; for (int i=1;i<=5;i++) cin>>v[i]; cout<<"\nEnter the adjacency matrix\n"; 
for (int j=1;j<=5;j++) for (int k=1;k<=5;k++) { cout<<"\nValue for ( "<<j<<" , "<<k<<" ) : "; cin>>adj[j][k]; } for (int l=1;l<=5;l++) d[l]=999; 
} void BFS(int); void BFSaux(); void DFS(); void DFS_visit(int u); 
}; 
void graph :: BFSaux() { 
int val; cout<<"Enter the value to perform BFS on : "; cin>>val; for (int i=1;i<=5;i++) { if (val==v[i]) { return (BFS(v[i])); } } cout<<"The node not present!\n"; 
} 
void graph :: BFS(int s) { int u; d[s]=0; queue q; q.insert(s); while(!q.isempty()) { u=q.del(); cout<<u<<" "; for (int v=1;v<=5;v++) { if ((adj[u][v]==1) && (d[v]==999)) { d[v]=d[u]+1; q.insert(v); } } } } 
void graph :: DFS() { int u; for (u=1;u<=5;u++) { color[u]='w'; } t=0; for (u=1;u<=5;u++) { if (color[u]=='w') DFS_visit(u); } } 
void graph :: DFS_visit(int u) { color[u]='g'; 
cout<<u<<" "; t=t+1; start[u]=t; int v; for (v=1;v<=5;v++) { if ((adj[u][v]==1) && (color[v]=='w')) { DFS_visit(v); } } color[u]='b'; t=t+1; finish[u]=t; 
} 
int main() { graph g; cout<<"\n***BFS***\n"; g.BFSaux(); cout<<endl; cout<<"\n***DFS***\n"; g.DFS(); cout<<endl; return 0; }
