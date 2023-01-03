#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<map>
#include<cmath>


int main()
{
	
	int number;cin>>number;
	while(number--)
	{
		int n;cin>>n;
		map<int,vector<int>>hash;//´æ´¢ÐÐ 
		for(int i=0;i<n;i++)
		{
			int x,y;cin>>x>>y;
			hash[y].push_back(x);
		}
		bool f1=false;
		bool f2=true;
		for(auto&e:hash)
		{
			sort(e.second.begin(),e.second.end());
			int mid;
			if(!f1)
			{
				 mid=(e.second[0]+e.second[e.second.size()-1]);
				f1=true;
			}
			for(int i=0;i<e.second.size();i++)
			{
				if(e.second[i]+e.second[e.second.size()-i-1]!=mid)
				{
					f2=false;
					break;
				}
			}
			if(!f2)break;
		}
		if(f2)
		{
			cout<<"YES"<<endl;
		}
		else
		{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}
