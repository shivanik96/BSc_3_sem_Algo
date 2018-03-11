#include<iostream> #include<fstream> #include<stdlib.h> #include<vector> #include<string> #include<time.h> 
using namespace std; 
class input { int size; vector<int> ar; int ctr; public: input() { ctr=0; size=rand()%1000; input_file(); } void input_file(); void getdata(); void build_max_heap(vector<int>,int); void max_heapify(vector<int>,int,int); void heap_sort(vector<int>,int); int returnsize(); int returnctr(); }; 
void input :: input_file() { ofstream out; out.open("input.txt", ios::trunc); for (int j =0;j<size;j++) out<<rand()%15<<' '; out<<'\n'; out.close(); } 
void input :: getdata() { ifstream in; in.open("input.txt", ios::in); int x; ar.clear(); while(!in.eof()) { in>>x; ar.push_back(x); } 
heap_sort(ar,ar.size()); in.close(); 
} 
void input :: max_heapify(vector<int> a, int i, int n) { int l = 2*i; int r = 2*i+1; int largest=0; int temp=0; 
if (l<n) ctr+=1; 
if (r<n) ctr+=1; 
if ((l<=n)&&(a[l]>a[i])) largest = l; else largest = i; 
if ((r<=n)&&(a[r]>a[largest])) largest = r; 
if (largest != i) { temp = a[i]; a[i] = a[largest]; a[largest] = temp; max_heapify(a,largest,n); } 
} 
void input :: build_max_heap(vector<int> arr, int n) { int limit; limit = n/2-1; for (int i=limit;i>=0;i--) { max_heapify(arr,i,n); } } 
void input :: heap_sort(vector<int> heap, int n) { build_max_heap(heap,n); int temp = 0; for (int k=n-1;k>=0;k--) { temp = heap[k]; heap[k] = heap[0]; 
heap[0] = temp; max_heapify(heap,0,k-1); 
} 
} 
int input :: returnsize() { return size; } 
int input :: returnctr() { return ctr; } 
int main() { srand(time(NULL)); int size=20; cout<<"Size of array"<<"\t"<<"Comparisions"<<"\n"; for (int i=0;i<size;i++) { input obj; obj.getdata(); cout<<"\t"<<obj.returnsize()<<"\t\t"<<obj.returnctr()<<"\n"; } return 0; }