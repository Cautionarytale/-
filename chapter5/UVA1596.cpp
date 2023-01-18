#include<iostream>
#include<map>
#include<cstdio>
using namespace std;
map<char,pair<int,map<int,int>>>m;
bool flag=false;
int go()
{
	int value;
	if(scanf("%d",&value)==1){
		return value;//如果是数字，直接返回 
	}
	char ch=getchar();//读取数组名
	getchar();//[
	value=go();//数组下标
	getchar();//]
	if(flag){
		return 0;
	} 
	if(value<0||value>=m[ch].first||!m[ch].second.count(value)){//前两个条件是判断数组越界，第三个条件是判断元素未初始化 
		flag=true;
		return 0;
	}
	return m[ch].second[value]; 
}
int main()
{
	char ch,c;
	int line;
	while((ch=getchar())!='.'){//遍历每一组 ch为每一组的数组名 
		flag=false;
		line=0;
		m.clear();
		while(1){//遍历每一行 
			++line;
			getchar();//[
			int value=go();//下标
			if(flag){
				printf("%d\n",line);
				while((c=getchar())!='.')
					;
				getchar();//.
				break;
			} 
			getchar();//]
			if(getchar()=='=')
			{
				if(value<0||value>=m[ch].first)//赋值语句，不必判断初始化 
				{
					printf("%d\n",line);
					while((c=getchar())!='.')
						;
					getchar();//.
					break;
				}
				int rvalue=go();//右值
				if(flag)
				{
					printf("%d\n",line);
					while((c=getchar())!='.');
					getchar();//.
					break;
				}
				//合法
				m[ch].second[value]=rvalue;
				getchar();//. 
			}
			else//声明 
			{
				m[ch].first=value;
			}
			if((ch=getchar())=='.')
			{
				puts("0");
				getchar();//.
				break;
			}
		}
	}
	return 0;
}
