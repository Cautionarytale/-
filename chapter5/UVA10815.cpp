#include<iostream>
using namespace std;
#include<set>
#include<string>
#include<cctype>
#include<sstream>
int main()
{
	set<string>s;
	string ss,buf;
	while(cin>>ss)
	{
		stringstream sss;
		for(auto&e:ss)
		{
			if(isalpha(e))
			{
				e=tolower(e);
			}
			else
			{
				e=' ';
			}
		}
		sss<<ss;
		while(sss>>buf)
		{
			s.insert(buf);
		}

	}
	for(auto&e:s)
	{
		cout<<e<<endl;
	}
	return 0;
}
