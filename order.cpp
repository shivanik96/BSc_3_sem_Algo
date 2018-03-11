#include<iostream>
using namespace std;
int cnt;
int partition(int ar[], int p, int r) { int i=(p-1); int j=p; while (j!=r) { cnt++; if (ar[j] < ar[r]) { cnt++; if (ar[j-1] > ar[r]) { int temp = ar[i+1]; ar[i+1]=ar[j]; ar[j]=temp; i++; j++; } else { i++; j++; } } else { j++; } } int temp1 = ar[i+1]; ar[i+1] = ar[r]; ar[r] = temp1; return (i+1); }
int rand_select(int ar[], int p, int r, int i) { if (p==r)
return ar[p]; int q = partition(ar,p,r); int k = q-p+1; if (i==k) return ar[q]; else if (i<k) rand_select(ar,p,q-1,i); else rand_select(ar,q+1,r,i-k);
}
int main() { int ar[10]; int n, i, val; cout<<"Enter the size : "; cin>>n; cout<<"Enter unsorted elements :\n"; for (i=1;i<=n;i++) cin>>ar[i]; cout<<"Enter an index : "; cin>>val; cout<<"Number supposed to be at that index in a sorted array -> "; cout<<rand_select(ar,1,n,val); cout<<"\nNumber of comparisions required : "<<cnt; cout<<endl; }