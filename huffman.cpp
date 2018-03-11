#include <iostream> #include<stdlib.h> #include<vector> #include<string> #include<fstream> 
using namespace std; 
class node { public: node * left; node * right; int freq; char ch; string code; node(int a,char c) { freq=a; ch=c; left=NULL; right=NULL; code=" "; 
} 
}; 
class Huffman { vector<node *> arr; int size; public: void input(); void build_heap(int n); void min_heapify(int i,int n); void swap(int i,int j); node* min_extract(); node* build_tree(); void display(); void cdisplay(node*); void assigncode(node*,string c); }; 
void Huffman :: input() { int n,f; char ch; node * temp; cout<<"Enter the no. of elements : "; cin>>n; for(int i=0;i<n;i++) { cout<<"\nEnter the character : "; cin>>ch; cout<<"Enter the frequency : "; cin>>f; temp=new node(f,ch); arr.push_back(temp); } build_heap(n); } 
void Huffman :: build_heap(int size) { int i; for(i=(size-1)/2;i>=0;i--) { min_heapify(i,size); } } 
void Huffman :: min_heapify(int i,int n) { int left = 2*i+1; int right = 2*i+2; int min; if(left  <= n-1 && arr[left]->freq < arr[i]->freq ) min=left; else 
min=i; if(right <=n-1 && arr[right]->freq < arr[min]->freq) { min= right; } if(min != i) { swap(i,min); min_heapify(min,n); } 
} 
void Huffman ::swap(int i,int j) { node* temp; temp=arr[i]; arr[i]=arr[j]; arr[j]=temp; } 
node* Huffman :: min_extract() { node* temp; temp=arr[0]; arr.erase(arr.begin()+0); build_heap(arr.size()); return temp; } 
node* Huffman :: build_tree() { while(arr.size()>1) { node* n1=min_extract(); node* n2=min_extract(); int n=n1->freq+n2->freq; node* z=new node(n,' '); z->left=n1; z->right=n2; arr.push_back(z); build_heap(arr.size()); } return arr[0]; } 
void Huffman :: display() { node *root=build_tree(); root->code=" ";   cdisplay(root); } 
void Huffman :: cdisplay(node *q) 
{ 
if(q) { 
if(q->left) { assigncode(q->left,q->code+"0"); cdisplay(q->left); } if(q->right) { assigncode(q->right,q->code+"1"); cdisplay(q->right); } 
} 
} 
void Huffman :: assigncode(node* q,string code) { q->code=code; if(q->ch!=' ') cout<<q->ch<<"\t"<<q->code<<"\n"; } 
int main() { Huffman h ; h.input(); cout<<"\nThe Huffman Code generated is :\n"; h.display(); return 0; }
