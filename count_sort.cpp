#include<iostream>

using namespace std;

int main()
{
	int a[50], b[50]={0};
	int n, value=0;
	int i, j, k;
	cout<<"\nHow many elements?\n";
	cin>>n;
	cout<<"\nEnter Elements\n";
	for (i=0;i<n;i++)
		cin>>a[i];
	int c[10]={0};
	for (j=0;j<n;j++)
	{
		c[a[j]]++;
		/*switch (a[j])
		{
			case 0 : c[0]++;
			break;
			case 1 : c[1]++;
			break;
			case 2 : c[2]++;
			break;
			case 3 : c[3]++;
			break;
			case 4 : c[4]++;
			break;
			case 5 : c[5]++;
			break;
			case 6 : c[6]++;
			break;
			case 7 : c[7]++;
			break;
			case 8 : c[8]++;
			break;
			case 9 : c[9]++;
			break;
			default : cout<<"Wrong Input!";
			break;
		}*/
	}

	for (k=9;k>=0;k--)
	{
		value=0;
		for (int m=k-1;m>=0;m--)
		{
			value=value+c[m];
		}
		c[k]=c[k]+value;
	}

	cout<<"\nInput Array 'a' is ->\n";
	for (i=0;i<n;i++)
		cout<<a[i]<<" ";

	cout<<"\nAuxilliary Array 'c' is ->\n";
	for (j=0;j<10;j++)
		cout<<c[j]<<" ";

	cout<<"\n\nSORTING PART!\n";
	for (i=n-1;i>=0;i--)
	{
		b[c[a[i]]--]=a[i];
	}

	cout<<"\nSorted Array 'b' is ->\n";
	for (i=0;i<n;i++)
		cout<<b[i]<<" ";
	cout<<endl;

	return 0;
}
