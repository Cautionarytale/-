#include<iostream>
using namespace std;
#include<vector>
#include<string>
#include<map> 
#include<sstream>
#include<cctype>
#include<algorithm>
vector<string>words;
map<string,int>hash1;
string standardization(const string&s)//标准化 化为小写，排好序 
{
	string ans=s;
	for(auto&e:ans)
	{
		e=tolower(e);
	}
	sort(ans.begin(),ans.end());
	return ans;
}
int main()
{
	string s;
	while(cin>>s)
	{
		if(s=="#")break;
		if(!hash1[standardization(s)])
		{
			hash1[standardization(s)]=0;
		}
		hash1[standardization(s)]++;
		words.push_back(s);
	}
	sort(words.begin(),words.end());
	for(auto&e:words)
	{
		if(hash1[standardization(e)]==1)
		{
			cout<<e<<endl;
		}
	}
	return 0;
}
