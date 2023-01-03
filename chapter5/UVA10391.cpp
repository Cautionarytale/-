#include<iostream>
using namespace std;
#include<vector>
#include<string>
#include<map>
map<string,int>m;
vector<string>vs;
bool isCompound(string& s)
{
	for(int i=1;i<s.length();i++)
	{
		string sub1=s.substr(0,i);
		string sub2=s.substr(i);
		if(m.count(sub1)&&m.count(sub2))return true;
	}
	return false;
}
int main()
{
	string s;
	while(cin>>s)
	{
		vs.push_back(s);
		m[s]=1;
	}
	for(auto&e:vs)
	{
		if(isCompound(e))
		{
			cout<<e<<endl; 
		}
	}
	return 0;
}
