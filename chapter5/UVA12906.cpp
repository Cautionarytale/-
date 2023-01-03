#include<iostream>
using namespace std;
#include<algorithm>
#include<stack>
#include<set>
#include<map>
#include<vector>
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
typedef set<int> Set;
map<Set,int>IDcache;
vector<Set>Setcache;
int getID(Set x)//ID即为集合x在Setcache中的索引 
{
	if(IDcache.count(x))
	{
		return IDcache[x];
	}	
	Setcache.push_back(x);
	return IDcache[x]=Setcache.size()-1;
}
int main()
{
	int n;cin>>n;
	while(n--)
	{
		stack<int>s;
		int m;cin>>m;
		while(m--)
		{
			string op;cin>>op;
			if(op[0]=='P')s.push(getID(Set()));
			else if(op[0]=='D')s.push(s.top());
			else
			{
				Set x1=Setcache[s.top()];s.pop();
				Set x2=Setcache[s.top()];s.pop();
				Set x;
				if(op[0]=='U')set_union(ALL(x1),ALL(x2),INS(x));
				else if(op[0]=='I')set_intersection(ALL(x1),ALL(x2),INS(x));
				else//ADD
				{
					x=x2;
					x.insert(getID(x1));
				}
				s.push(getID(x));
			}
			cout<<Setcache[s.top()].size()<<endl;
		}
		cout<<"***"<<endl;
	
		
	}
	return 0;
}
