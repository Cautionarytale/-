#include<iostream>
#include<set>
#include<queue>
using namespace std;
typedef long long LL;
int main()
{
	int basic[3]={2,3,5};
	set<LL>s;s.insert(1);
	priority_queue<LL,vector<LL>,greater<LL>>pq;pq.push(1);
	for(int i=1;;i++)
	{
		LL x=pq.top();pq.pop();
		if(i==1500)
		{
			cout<<"The 1500'th ugly number is "<<x<<"."<<endl;
			return 0;
		}
		for(auto&e:basic)
		{
			LL xx=x*e;
			if(!s.count(xx))
			{
				s.insert(xx);
				pq.push(xx);
			}
		}
	}
	return 0;
}
