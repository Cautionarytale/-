#include<iostream>
using namespace std;
#include<queue>
#include<vector>
#include<unordered_map>
#include<string>


int main()
{
	int cnt=0;
	int t;
	while(cin>>t,t!=0)
	{
		cnt++;
		cout<<"Scenario #"<<cnt<<endl;
		queue<int>q;
		queue<int>a[1001];
		
	int tt=t;
	unordered_map<int,int>hash;
	while(tt--)
	{
		int n;cin>>n;
		while(n--)
		{
			int x;cin>>x;
			hash[x]=tt;
		}
	}
	//vector<int>ret;
	string s;
	while(cin>>s)
	{
		if(s=="STOP")
		{
			cout<<endl;
			break;
		}
		if(s[0]=='E')
		{
			int val;cin>>val;
			//Enque(hash,ret,val);
			if(a[hash[val]].empty())
			{
				q.push(hash[val]);
			}
			a[hash[val]].push(val);
		}
		else
		{
			//Deque(ret);
			int c=q.front();
			cout<<a[c].front()<<endl;
			a[c].pop();
			if(a[c].empty())q.pop();
		}
	}
	}
	
	return 0;
}
