#include<iostream>
using namespace std;
#include<vector> 
#include<algorithm>
int main()
{
	int N,Q;
	int cnt=0;
	while(1)
	{
		cnt++;
		cin>>N>>Q;
		if(N==0&&Q==0)
		{
			break;
		}
		vector<int>marbles(N);
		for(int i=0;i<N;i++)
		{
			int value;cin>>value;
			marbles[i]=value;
		}
		vector<int>queries(Q);
		for(int i=0;i<Q;i++)
		{
			int value;cin>>value;
			queries[i]=value;
		}
		sort(marbles.begin(),marbles.end());
		cout<<"CASE# "<<cnt<<":"<<endl;
		for(int i=0;i<Q;i++)
		{
			bool flag=false;
			for(int j=0;j<N;j++)
			{
				if(queries[i]==marbles[j])
				{
					flag=true;
					cout<<queries[i]<<" found at "<<j+1<<endl;
					break;
				}
			}
			if(!flag)
			{
				cout<<queries[i]<<" not found"<<endl;
			}
		}
	}
	
	return 0;
}

