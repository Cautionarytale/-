#include<iostream>
using namespace std;
#include<map>
#include<vector>
typedef pair<int,int> P;
map<string,int>IDcache;//把字符串映射为ID
vector<string>Scache;//根据ID取字符串
int ID(string s)
{
	if(IDcache.count(s))return IDcache[s];
	Scache.push_back(s);//添加新字符串
	return IDcache[s]=Scache.size()-1; 
} 
char ch;
int main()
{
	int n,m;//cin>>n>>m;//n行m列
	while(cin>>n>>m)
	{
		Scache.clear();
		IDcache.clear();
		bool flag=true;
		vector<vector<int>>v(n,vector<int>(m));
		getchar();
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				string s;
				while(1)
				{
					 ch=getchar();
					if(ch==','||ch=='\n'||ch=='\r'||ch==EOF)break;
					s.push_back(ch);
				}
				v[i][j]=ID(s);
			}
		} 
		map<P,int>hash;
		for(int j1=1;j1<m;j1++)
		{
			for(int j2=0;j2<j1;j2++)
			{
				for(int i=0;i<n&&flag;i++)
				{
					if(hash.count({v[i][j1],v[i][j2]})){
						flag=false;
						cout<<"NO"<<endl;
						cout<<hash[{v[i][j1],v[i][j2]}]+1<<' '<<i+1<<endl;
						cout<<j2+1<<' '<<j1+1<<endl;
						break;
					}
					else hash[{v[i][j1],v[i][j2]}]=i;
				}
			}
		 } 
		 if(flag)cout<<"YES"<<endl;
	}
	return 0;
}
