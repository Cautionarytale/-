#include<iostream>
using namespace std;
#include<sstream>
#include<vector>
#include<string>
#include<algorithm>
void print(string s,int len){
	cout<<s;
	for(int i=0;i<len-s.size();i++)
	{
		cout<<' ';
	}
}
vector<string>word[1010];
int maxlen[1010];
int main()
{
	string s,w;
	int cnt=0;
	while(getline(cin,s))
	{
		stringstream ss(s);
		while(ss>>w)
		{
			word[cnt].push_back(w);
		}
		cnt++;
	}
	for(int i=0;i<cnt;i++)
	{
		for(int j=0;j<word[i].size();j++)
		{
			maxlen[j] = max(maxlen[j], int(word[i][j].size()) + 1);
		}
	}
	for(int i=0;i<cnt;i++)
	{
		for(int j=0;j<word[i].size();j++)
		{
			if(j==word[i].size()-1)cout<<word[i][j];
			else print(word[i][j],maxlen[j]);
		}
		cout<<endl;
	}
	return 0;
}
