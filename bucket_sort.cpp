#include<iostream> #include<vector> #include<stdlib.h> #include<fstream>
using namespace std;
class bucketsort { int size; float arr[10]; vector<float> bucket[10]; int bucket_size; public: bucketsort() { cout<<"\nEnter Size: "; cin>>size; cout<<"\nEnter elements ->\n"; for (int i=0;i<size;i++) cin>>arr[i]; bucket_size=size; for (int j=0;j<bucket_size;j++) bucket[j].clear(); /*for (int k=0;k<bucket[j].size();k++) bucket[j][k]=0;*/ } void display_arr(); void generate_buckets(); void insertsort(vector<float>&); void display_buckets(); void sort_buckets(); void concatenate(); };
void bucketsort :: display_arr() { for (int i=0;i<size;i++) cout<<arr[i]<<" "; cout<<endl; }
void bucketsort :: generate_buckets() { int index=0; for (int i=0;i<size;i++) { index=(arr[i]*bucket_size); bucket[index].push_back(arr[i]); } }
void bucketsort :: display_buckets() { for (int i=0;i<bucket_size;i++) { cout<<"\n"<<i<<" number wali bucket =\n"; for (int j=0;j<bucket[i].size();j++) cout<<bucket[i][j]<<" "; } cout<<endl; }
void bucketsort :: sort_buckets() { for (int i=0;i<bucket_size;i++) insertsort(bucket[i]); }
void bucketsort :: insertsort(vector<float>& data) { float temp=0.0; for (int i=0;i<data.size();i++) { for (int j=i;j>0;j--) { if (data[j]<data[j-1]) { temp=data[j]; data[j]=data[j-1]; data[j-1]=temp; } else break; } } }
void bucketsort :: concatenate() { int k=0; for (int i=0;i<bucket_size;i++) { for (int j=0;j<bucket[i].size();j++) { arr[k]=bucket[i][j]; k++; } } }
int main() {
bucketsort obj; cout<<"\nInput array ->\n"; obj.display_arr(); obj.generate_buckets(); cout<<"\nGenerated buckets ->\n"; obj.display_buckets(); obj.sort_buckets(); cout<<"\nSorted buckets ->\n"; obj.display_buckets(); obj.concatenate(); cout<<"\nSorted array ->\n"; obj.display_arr(); return 0;
}