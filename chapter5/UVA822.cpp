#include<iostream>
using namespace std;
#include<queue>
#include<map>
#include<vector>
#include<algorithm>
const int INF = 0x3f3f3f3f;
struct Topic{
	int t;//某主题的所有请求的处理时间
	queue<int>table;//某主题所有请求的开始时间表 
};
map<int,Topic>topic;//主题的tid到其本身的映射
struct Person{
	int pid;//个人编号
	int k;//能处理的主题数目
	int time;//处理完当前请求的时间
	int start_time;//上一次请求的开始时间
	int tid[25];
	bool operator<(const Person&p)const
	{
		if(start_time!=p.start_time)return start_time<p.start_time;
		return pid<p.pid;
	} 
}; 

int main()
{
	int N,M;
	int Scenario=1;
	while(~scanf("%d",&N),N){
		int time=INF;//time表示当前时间
		int ans=0;//结果
		topic.clear();
		for(int i=0;i<N;i++)
		{
			int tid,num,t0,dt;
			Topic temp;
			scanf("%d%d%d%d%d",&tid,&num,&t0,&temp.t,&dt);
			time=min(time,t0);//对当前时间的维护，将time初始化为所有主题所有请求的最早开始时间
			Topic&x=(topic[tid]=temp);
			while(num--)
			{
				x.table.push(t0);
				t0+=dt;
			}
		} 
		scanf("%d",&M);
		vector<Person>person(M);
		for(int i=0;i<M;i++)
		{
			scanf("%d%d",&person[i].pid,&person[i].k);
			for(int j=0;j<person[i].k;j++)
			{
				scanf("%d",&person[i].tid[j]);
			}
			
		}
		while(N)
		{
			int jump_time=INF;//jump_time表示所有人中最先处理完请求的时间点（即p.time的最小值，即最先有空的人的时间点） 
			sort(person.begin(),person.end());
			for(auto&p:person)
			{
				int next_time=INF;//维护当前这个人的下次可处理请求的时间点
				if(p.time>time)//在忙
					next_time=p.time; 
				else//不忙 
				{
					for(int i=0;i<p.k;i++)//遍历该人可处理的主题 
					{
						Topic&x=topic[p.tid[i]];//x是主题
						if(x.table.empty())continue;//该主题的所有请求已全部处理完毕
						if(x.table.front()<next_time) //该请求无法做
							 next_time=x.table.front();
						if(x.table.front()<=time)//该请求可以做 (当前时间节点时，该请求早已被发出)
						{
							next_time=time+x.t;//从当前时间开始处理该请求
							ans=max(ans,next_time);
							p.start_time=time;
							x.table.pop();
							if(x.table.empty())N--; 
							break;//该人接了一个任务就退出，不再看后面优先级的任务了
							 
						}	  
					}
					p.time=next_time;
				}
				jump_time=min(jump_time,next_time);	 
			}
			time=jump_time;
		}
		printf("Scenario %d: All requests are serviced within %d minutes.\n", Scenario++, ans);
	} 
	return 0;
}
