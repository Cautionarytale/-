#include<iostream>
using namespace std;
#include<string>
#include<vector>
#include<algorithm>
void print(string s,int len,char c)
{
	cout<<s;
	for(int i=0;i<len-s.length();i++)
	{
		cout<<c;
	}
}
int main()
{
	int n;
	while(cin>>n)
	{
		print("",60,'-');cout<<endl;
		//cout<<"------------------------------------------------------------"<<endl;
		int maximum=0;
		vector<string>vs;
		for(int i=0;i<n;i++)
		{
			string s;cin>>s;
			vs.push_back(s);
			maximum=maximum>s.length()?maximum:s.length();
		}
		sort(vs.begin(),vs.end());//≈≈–Ú 
		int col=1+(60-maximum)/(maximum+2);
		int row=(n-1)/col+1;
		for(int i=0;i<row;i++)
		{
			for(int j=i;j<n;j+=row)
			{
				print(vs[j],j>=row*(col-1)?maximum:maximum+2,' ');
			}
			cout<<endl;
		}
	}
	return 0;
}
