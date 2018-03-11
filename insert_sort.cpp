#include<iostream> #include<fstream> #include<stdlib.h> #include<vector> #include<string> 
using namespace std; 
class input { int size; public: input() { size=rand()%1000; } int input_file(); int getdata(); int insertsort(vector<int>); }; 
int input :: input_file() { ofstream out; out.open("input.txt", ios::trunc); for (int j =0;j<size;j++) out<<rand()%150<<' '; out<<'\n'; out.close(); return size; } 
int input :: getdata() { ifstream in; in.open("input.txt", ios::in); int x; vector<int> vec; while(!in.eof()) { in>>x; vec.push_back(x); } int noc=insertsort(vec); in.close(); return noc; } 
int input :: insertsort(vector<int> data) { int temp=0; 
int ctr=0; for (int i=0;i<data.size();i++) { for (int j=i;j>0;j--) { if (data[j]<data[j-1]) { temp=data[j]; data[j]=data[j-1]; data[j-1]=temp; ctr++; } else break; } } return ctr; 
} 
int main() { int size=20; int count=0, size1=0; cout<<"Size of array"<<"\t"<<"Comparisions"<<"\n"; for (int i=0;i<size;i++) { input obj; size1=obj.input_file(); count=obj.getdata(); cout<<"\t"<<size1<<"\t\t"<<count<<"\n"; } return 0; }