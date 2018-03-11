#include<iostream> #include<fstream> #include<stdlib.h> #include<vector> #include<string> #include<time.h>
using namespace std;
class input { int size; vector<int> ar; public: input() { size=rand()%1000; input_file(); } void input_file(); void getdata(int&); int returnsize(); int partition(int,int,int&); void quicksort(int,int,int&); };
void input :: input_file() { ofstream out; out.open("input.txt", ios::trunc); for (int j =0;j<size;j++) out<<rand()%15<<' '; out<<'\n'; out.close(); }
void input :: getdata(int& count) { ifstream in; in.open("input.txt", ios::in); int x; ar.clear(); while(!in.eof()) { in>>x; ar.push_back(x); } int vecs=ar.size(); quicksort(0,vecs-1,count); in.close(); }
int input :: partition(int p, int r, int& cnt) { int i=(p-1); int j=p; while (j!=r) { cnt++; if (ar[j] < ar[r]) { cnt++; if (ar[j-1] > ar[r]) { int temp = ar[i+1]; ar[i+1]=ar[j]; ar[j]=temp; i++; j++; } else { i++; j++; } } else { j++; } } int temp1 = ar[i+1]; ar[i+1] = ar[r]; ar[r] = temp1; return (i+1); }
void input :: quicksort(int p, int r, int& noc) { if (p<r) {int q = partition (p,r,noc); quicksort(p,q-1,noc); quicksort(q+1,r,noc); } }
int input :: returnsize() { return size; }
int main() { srand(time(NULL)); int size=20; int size1=0; int ctr=0; cout<<"Size of array"<<"\t"<<"Comparisions"<<"\n"; for (int i=0;i<size;i++) { ctr=0; input obj; obj.getdata(ctr); cout<<"\t"<<obj.returnsize()<<"\t\t"<<ctr<<"\n"; } return 0; }