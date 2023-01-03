#include<iostream>
using namespace std;
#include<vector>
#include<string>
#include<stack>
//#include<numeric>
const int maxn=30;
int n;
vector<int>blocks[maxn];
void Find(int number,int& p,int& h)
{
	for(p=0;p<n;p++)
	{
		//bool flag=false;
		for(h=0;h<blocks[p].size();h++)
		{
			if(blocks[p][h]==number)
			{
				return;
			}
		}
		
	}
}
void remove(int p,int h)//把第p堆高度大于h的blocks归位 
{
	for(int i=h+1;i<blocks[p].size();i++)
	{
		int temp=blocks[p][i];
		blocks[temp].push_back(temp);
	} 
	blocks[p].resize(h+1);
}
void put(int p,int h,int p2)//把第p堆高度大于等于h的blocks放在p2堆上面 
{
	for(int i=h;i<blocks[p].size();i++)
	{
		blocks[p2].push_back(blocks[p][i]);
	}
	blocks[p].resize(h);
}
int main()
{
	int a,b;
	string s1,s2;
	cin>>n;
	//iota(blocks.begin(),blocks.end(),0);
	for(int i=0;i<n;i++)
	{
		blocks[i].push_back(i);
	}
	while(cin>>s1,s1!="quit")
	{
		cin>>a>>s2>>b;
		//string option;getline(cin,option);
		int number1=a;
		int number2=b;
		int p1,h1,p2,h2;
		Find(number1,p1,h1);
		Find(number2,p2,h2);
		if(p1==p2)continue;
		if(s1=="move")
		{
			remove(p1,h1);
		}

		if(s2=="onto")
		{
			remove(p2,h2);
			
		}
		put(p1,h1,p2);
	}
	for(int i=0;i<n;i++)
	{
		cout<<i<<":";
		for(auto&e:blocks[i])
		{
			cout<<" "<<e;
		}
		cout<<endl;
	}
	return 0;
}
