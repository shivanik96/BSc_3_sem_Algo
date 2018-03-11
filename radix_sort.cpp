#include<iostream> #include<vector>
using namespace std;
class input { int size; int a[10]; int b[10]; public: input() { cout<<"\nEnter size\n"; cin>>size; cout<<"\nEnter array elements (Only 3 digits)\n"; for (int i=0;i<size;i++) cin>>a[i]; } void radix(); void count(int[]); void display(); };
void input :: radix() { int a1[10]; int a2[10]; int a3[10]; for (int i=0;i<size;i++) { a1[i]=a[i]%10; } count(a1); for (int i=0;i<size;i++) { a2[i]=(a[i]/10)%10; } count(a2); for (int i=0;i<size;i++) { a3[i]=((a[i]/10)/10)%10; } count(a3); }
void input :: count(int input[]) { int c[10]={0}; int i, j, value=0; for (i=0;i<size;i++)
{
c[input[i]]++;
}
for (j=9;j>=0;j--) { value=0; for (int k=j-1;k>=0;k--) { value=value+c[k]; } c[j]=c[j]+value; } cout<<"\nInput Array 'input' is ->\n"; for (i=0;i<size;i++) cout<<input[i]<<" ";
cout<<"\nAuxilliary Array 'c' is ->\n"; for (j=0;j<10;j++) cout<<c[j]<<" ";
cout<<"\n\nSORTING PART!\n"; for (i=size-1;i>=0;i--) { b[c[input[i]]-1]=a[i]; c[input[i]]--; }
for (i=0;i<size;i++) a[i]=b[i];
}
void input :: display() { for (int i=0;i<size;i++) cout<<b[i]<<" "; cout<<endl; }
int main() { input obj; obj.radix(); cout<<"\n\nThe Final sorted array is ->\n"; obj.display(); return 0; }
