#include<iostream> 
using namespace std; 
int LCS_length(char x[], char y[], int n1, int n2) { int c[n1][n2]; char b[n1][n2]; int i,j; for (i=1;i<n1;i++) { c[i][0]=0; b[i][0]='.'; } for (j=0;j<n2;j++) { c[0][j]=0; b[0][j]='.'; } 
for(i=0;i<n1;i++) for (j=0;j<n2;j++) { if (x[i]==y[j]) { c[i+1][j+1]=c[i-1+1][j-1+1]+1; b[i+1][j+1]='\''; } else if (c[i-1][j]>=c[i][j-1]) { c[i+1][j+1]=c[i-1+1][j+1]; b[i+1][j+1]='|'; } else { c[i+1][j+1]=c[i+1][j-1+1]; b[i+1][j+1]='-'; } } cout<<"The c array is :\n"; for(i=0;i<n1;i++) { for (j=0;j<n2;j++) cout<<c[i][j]<<" "; cout<<endl; } cout<<"\n\nThe b array is :\n"; for(i=0;i<n1;i++) { for (j=0;j<n2;j++) cout<<b[i][j]<<" "; cout<<endl; } int ans = c[n1-1][n2-1]; return ans; 
} 
int main() { char x[10]; char y[10]; int n1, n2, i; cout<<"\nEnter sequence x length : "; cin>>n1; cout<<"\nEnter sequence x :\n"; for (i=0;i<n1;i++) cin>>x[i]; 
cout<<"\nEnter sequence y length : "; cin>>n2; cout<<"\nEnter sequence y :\n"; for (i=0;i<n2;i++) 
cin>>y[i]; 
int len = LCS_length(x,y,n1,n2); cout<<"The length of LCS is : "<<len; cout<<endl; 
} 