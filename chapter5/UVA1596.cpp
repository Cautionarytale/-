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
		return value;//��������֣�ֱ�ӷ��� 
	}
	char ch=getchar();//��ȡ������
	getchar();//[
	value=go();//�����±�
	getchar();//]
	if(flag){
		return 0;
	} 
	if(value<0||value>=m[ch].first||!m[ch].second.count(value)){//ǰ�����������ж�����Խ�磬�������������ж�Ԫ��δ��ʼ�� 
		flag=true;
		return 0;
	}
	return m[ch].second[value]; 
}
int main()
{
	char ch,c;
	int line;
	while((ch=getchar())!='.'){//����ÿһ�� chΪÿһ��������� 
		flag=false;
		line=0;
		m.clear();
		while(1){//����ÿһ�� 
			++line;
			getchar();//[
			int value=go();//�±�
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
				if(value<0||value>=m[ch].first)//��ֵ��䣬�����жϳ�ʼ�� 
				{
					printf("%d\n",line);
					while((c=getchar())!='.')
						;
					getchar();//.
					break;
				}
				int rvalue=go();//��ֵ
				if(flag)
				{
					printf("%d\n",line);
					while((c=getchar())!='.');
					getchar();//.
					break;
				}
				//�Ϸ�
				m[ch].second[value]=rvalue;
				getchar();//. 
			}
			else//���� 
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
