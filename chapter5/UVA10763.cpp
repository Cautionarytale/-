#include<iostream>
using namespace std;
#include<unordered_map>
#include<queue>
#include<vector> 
#include<algorithm>
int main()
{
	int n;
	while(cin>>n,n!=0)
	{
		vector<int>from,to;
		for(int i=0;i<n;i++)
		{
			int x,y;cin>>x>>y;
			from.push_back(x);
			to.push_back(y);
		}
		sort(from.begin(),from.end());
		sort(to.begin(),to.end());
		if(from==to)
		{
			cout<<"YES"<<endl;
		}
		else cout<<"NO"<<endl;
	}
	return 0;
}
