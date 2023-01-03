#include<iostream>
using namespace std;
#include<queue>
int main()
{
	int n;
	while(cin>>n,n!=0)
	{
		if(n==1)
		{
			cout<<"Discarded cards:"<<endl;
			cout<<"Remaining card: 1"<<endl;
		//	continue;
		}
		else
		{
			queue<int>q;
		for(int i=1;i<=n;i++)
		{
			q.push(i);
		}
		cout<<"Discarded cards: ";
		cout<<q.front();q.pop(); 
		while(q.size()>1)
		{
			int temp=q.front();q.pop();
			q.push(temp);
			cout<<", "<<q.front();q.pop();
		}
		cout<<endl;
		cout<<"Remaining card: "<<q.front()<<endl;
	}
		}
	return 0;
}
