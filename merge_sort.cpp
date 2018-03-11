#include<iostream> #include<fstream> #include<stdlib.h> #include<vector> #include<string> #include<time.h> 
using namespace std; 
class input { int size; vector<int> vec; int ctr; public: input() { size=rand()%1000; input_file(); ctr=0; } void input_file(); void getdata(); void merge(int,int,int); void merge_sort(int,int); int returnsize(); int returnctr(); }; 
void input :: input_file() { ofstream out; out.open("input.txt", ios::trunc); for (int j =0;j<size;j++) out<<rand()%150<<' '; out<<'\n'; out.close(); } 
void input :: getdata() { ifstream in; in.open("input.txt", ios::in); int x; while(!in.eof()) { in>>x; vec.push_back(x); } merge_sort(0,size-1); in.close(); 
} 
void input :: merge_sort(int low, int high) { int mid; if(low<high) { mid=(low+high)/2; merge_sort(low,mid); merge_sort(mid+1,high); merge(low,mid,high); } } 
void input :: merge(int low1, int mid1, int high1) { vector<int> a; vector<int> b; int n1, n2, i, j, k; n1=(mid1-low1)+1; n2=high1-mid1; 
for (i=0;i<n1;i++) { a.push_back(vec[low1+i]); } for (j=0;j<n2;j++) { b.push_back(vec[mid1+j+1]); } i=0; j=0; k=low1; while(i!=n1&&j!=n2) { ctr++; if (a[i]<b[j]) { vec[k]=a[i]; k++; i++; } else { vec[k]=b[j]; k++; j++; } } while(i!=n1) { vec[k]=a[i]; 
k++; i++; 
} while(j!=n2) { vec[k]=b[j]; k++; j++; } 
} 
int input :: returnsize() { return size; } 
int input :: returnctr() { return ctr; } int main() { srand(time(NULL)); int size=20; cout<<"Size of array"<<"\t"<<"Comparisions"<<"\n"; for (int i=0;i<size;i++) { input obj; obj.getdata(); cout<<"\t"<<obj.returnsize()<<"\t\t"<<obj.returnctr()<<"\n"; } return 0; }