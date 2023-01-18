#include<iostream>
using namespace std;
#include<queue>
#include<map>
#include<vector>
#include<algorithm>
const int INF = 0x3f3f3f3f;
struct Topic{
	int t;//ĳ�������������Ĵ���ʱ��
	queue<int>table;//ĳ������������Ŀ�ʼʱ��� 
};
map<int,Topic>topic;//�����tid���䱾���ӳ��
struct Person{
	int pid;//���˱��
	int k;//�ܴ����������Ŀ
	int time;//�����굱ǰ�����ʱ��
	int start_time;//��һ������Ŀ�ʼʱ��
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
		int time=INF;//time��ʾ��ǰʱ��
		int ans=0;//���
		topic.clear();
		for(int i=0;i<N;i++)
		{
			int tid,num,t0,dt;
			Topic temp;
			scanf("%d%d%d%d%d",&tid,&num,&t0,&temp.t,&dt);
			time=min(time,t0);//�Ե�ǰʱ���ά������time��ʼ��Ϊ��������������������翪ʼʱ��
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
			int jump_time=INF;//jump_time��ʾ�����������ȴ����������ʱ��㣨��p.time����Сֵ���������пյ��˵�ʱ��㣩 
			sort(person.begin(),person.end());
			for(auto&p:person)
			{
				int next_time=INF;//ά����ǰ����˵��´οɴ��������ʱ���
				if(p.time>time)//��æ
					next_time=p.time; 
				else//��æ 
				{
					for(int i=0;i<p.k;i++)//�������˿ɴ�������� 
					{
						Topic&x=topic[p.tid[i]];//x������
						if(x.table.empty())continue;//�����������������ȫ���������
						if(x.table.front()<next_time) //�������޷���
							 next_time=x.table.front();
						if(x.table.front()<=time)//����������� (��ǰʱ��ڵ�ʱ�����������ѱ�����)
						{
							next_time=time+x.t;//�ӵ�ǰʱ�俪ʼ���������
							ans=max(ans,next_time);
							p.start_time=time;
							x.table.pop();
							if(x.table.empty())N--; 
							break;//���˽���һ��������˳������ٿ��������ȼ���������
							 
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
