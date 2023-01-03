#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
int a[16];
int main()
{
	int number;cin>>number;
	while(number--)
	{
		int n;cin>>n;
		//vector<int>v(n);
		for(int i=0;i<n;i++)
		{
			int temp;cin>>temp;
			//v[i]=temp;
			a[i]=temp;
		}
		a[n]=a[0];
		for(int i=0;i<1000;i++)
		{
			for(int j=0;j<n;j++)
			{
				a[j]=abs(a[j]-a[j+1]);
			}
			a[n]=a[0];
		}
		bool flag=false;
		for(int i=0;i<n;i++)
		{
			if(a[i])
			{
				flag=true;
				break;
			}
		}
		if(flag)
		{
			cout<<"LOOP"<<endl;
		}
		else
		{
			cout<<"ZERO"<<endl;
		}
	}
	return 0;
}
