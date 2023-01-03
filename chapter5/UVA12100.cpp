#include<iostream>
using namespace std;
#include<queue>
struct node{
	int index;//Ë÷Òý
	int value;//Öµ 
};
int main()
{
	int T;cin>>T;
	while(T--)
	{
		node t;
		queue<node>q;
		priority_queue<int,vector<int>,less<int>>pq;
		int N,TOP;cin>>N>>TOP;
		for(int i=0;i<N;i++)
		{
			int val;cin>>val;
			t.index=i;t.value=val;
			q.push(t);pq.push(val);
		}	
		int time=0;
		while(1)
		{
			if(q.front().value==pq.top())
			{
				time++;
				if(q.front().index==TOP)
				{
					break;
				}
				q.pop();pq.pop();
			}
			else
			{
				q.push(q.front());
				q.pop();
			}
		}
		cout<<time<<endl;
	}
	return 0;
}
